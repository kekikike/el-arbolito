"""
simulation.py — Motor de simulación del Autómata Celular.

Complejidad por tick: O(rows × cols) — cada celda se evalúa exactamente una vez.
Memoria: arreglos paralelos planos de rows×cols enteros (buffer doble + metadata).
Diseño pensado para migración directa a C++/ESP32:
  - Estados como enteros planos (uint8_t)
  - Arrays paralelos: state[], tree_type[], burn_timer[]
  - Vecindario de Moore (8 vecinos) con probabilidades ponderadas por viento
  - Sin asignación dinámica de memoria dentro del bucle de simulación
"""

import random
from typing import List, Tuple, Optional

from .config import (
    CellState, SimParams, WindDirection, TreeType,
    TreeProperties, TREE_SPECIES, EditTool, TICKS_PER_HOUR,
)


class FireSimulation:
    """
    Motor de simulación de propagación de incendios forestales.

    Arrays paralelos por celda:
      _current[]      — estado del autómata (EMPTY/TREE/FIRE/BURNED)
      _tree_type[]    — especie del árbol (solo relevante si state==TREE)
      _burn_timer[]   — ticks restantes de combustión (solo si state==FIRE)

    Buffer doble para actualización sincrónica:
      Se escribe en _next + _next_type + _next_burn
      Luego se intercambian punteros (swap O(1)).
    """

    NEIGHBORS = [
        (-1,  0), (-1,  1), ( 0,  1), ( 1,  1),
        ( 1,  0), ( 1, -1), ( 0, -1), (-1, -1),
    ]

    WIND_MAP = {
        WindDirection.NORTH: 0,
        WindDirection.SOUTH: 4,
        WindDirection.EAST:  2,
        WindDirection.WEST:  6,
    }
    OPPOSITE = {0: 4, 4: 0, 2: 6, 6: 2}

    def __init__(self, params: Optional[SimParams] = None):
        self.params = params or SimParams()
        self.tick_count = 0
        self.running = False
        self.perculated = False

        # Métricas de conteo
        self.tree_count = 0
        self.fire_count = 0
        self.burned_count = 0
        self.empty_count = 0
        self.pine_count = 0
        self.eucalyptus_count = 0
        self.oak_count = 0

        # Buffers principales
        self.rows = self.params.rows
        self.cols = self.params.cols
        self.size = self.rows * self.cols

        self._current:    List[int] = [CellState.EMPTY] * self.size
        self._next:       List[int] = [CellState.EMPTY] * self.size
        self._tree_type:  List[int] = [TreeType.NONE]   * self.size
        self._next_type:  List[int] = [TreeType.NONE]   * self.size
        self._burn_timer: List[int] = [0]               * self.size
        self._next_burn:  List[int] = [0]               * self.size

        # Probabilidades de propagación por vecino Moore
        self._probs: List[float] = [0.0] * 8

        # --- Métricas predictivas ---
        # Posición mínima de fila con fuego (para velocidad de avance)
        self._prev_fire_min_row: int = 0
        self._fire_min_row: int = self.rows
        # Número de celdas que se prenden por tick (para estimar extinción)
        self._new_fires_per_tick: int = 0
        self._fire_history: List[int] = []  # Nuevos fuegos por tick (últimos 10)

        self._init_grid()
        self._compute_probabilities()

    # ------------------------------------------------------------------
    # Inicialización
    # ------------------------------------------------------------------
    def _init_grid(self) -> None:
        """Genera la cuadrícula inicial con tipos de árbol aleatorios."""
        species = [TreeType.PINE, TreeType.EUCALYPTUS, TreeType.OAK]
        species_weights = [0.4, 0.3, 0.3]  # Distribución ponderada

        for i in range(self.size):
            if random.random() < self.params.density:
                self._current[i] = CellState.TREE
                self._tree_type[i] = random.choices(species, weights=species_weights, k=1)[0]
            else:
                self._current[i] = CellState.EMPTY
                self._tree_type[i] = TreeType.NONE
        self._update_metrics()

    def _compute_probabilities(self) -> None:
        """Calcula probabilidades base por vecino Moore con factor de distancia."""
        base = self.params.spread_base
        w_dir = self.params.wind_dir
        w_int = self.params.wind_intensity

        dist_factors = [1.0, 0.707, 1.0, 0.707, 1.0, 0.707, 1.0, 0.707]
        probs = [base * f for f in dist_factors]

        if w_int > 0.0 and w_dir != WindDirection.NONE:
            w_idx = self.WIND_MAP.get(w_dir)
            if w_idx is not None:
                opp_idx = self.OPPOSITE[w_idx]
                boost = base * w_int * 0.6
                probs[w_idx] += boost
                probs[(w_idx - 1) % 8] += boost * 0.3
                probs[(w_idx + 1) % 8] += boost * 0.3
                probs[opp_idx] -= boost * 0.7
                probs[(opp_idx - 1) % 8] -= boost * 0.3
                probs[(opp_idx + 1) % 8] -= boost * 0.3

        for i in range(8):
            probs[i] = max(0.0, min(1.0, probs[i]))
        self._probs = probs

    # ------------------------------------------------------------------
    # Índice y acceso
    # ------------------------------------------------------------------
    def _idx(self, row: int, col: int) -> int:
        return row * self.cols + col

    def get_state(self, row: int, col: int) -> int:
        return self._current[self._idx(row, col)]

    def get_tree_type(self, row: int, col: int) -> int:
        return self._tree_type[self._idx(row, col)]

    def set_state(self, row: int, col: int, state: int) -> None:
        self._current[self._idx(row, col)] = state

    # ------------------------------------------------------------------
    # Core de simulación
    # ------------------------------------------------------------------
    def step(self) -> bool:
        """
        Avanza un tick de simulación (actualización sincrónica).

        Reglas de transición:
          - TREE → FIRE: vecino Moore en fuego supera probabilidad
            (probabilidad modificada por inflamabilidad de la especie)
          - FIRE → BURNED: cuando burn_timer llega a 0
          - FIRE: decrementar burn_timer cada tick
          - EMPTY / BURNED: sin cambios

        Retorna True si hay fuego activo.
        """
        current = self._current
        nxt = self._next
        ttype = self._tree_type
        ntype = self._next_type
        btimer = self._burn_timer
        nburn = self._next_burn
        rows = self.rows
        cols = self.cols
        probs = self._probs
        neighbors = self.NEIGHBORS
        _idx = self._idx
        _FIRE = CellState.FIRE
        _TREE = CellState.TREE
        _BURNED = CellState.BURNED

        has_fire = False
        new_fires = 0
        fire_min_row = rows

        for r in range(rows):
            row_offset = r * cols
            for c in range(cols):
                idx = row_offset + c
                state = current[idx]

                if state == _TREE:
                    tt = ttype[idx]
                    # Factor de inflamabilidad de la especie
                    species_data = TREE_SPECIES.get(tt)
                    inflam_factor = species_data.inflamability if species_data else 1.0

                    ignited = False
                    for d, (dy, dx) in enumerate(neighbors):
                        nr, nc = r + dy, c + dx
                        if 0 <= nr < rows and 0 <= nc < cols:
                            if current[nr * cols + nc] == _FIRE:
                                # Probabilidad ajustada por inflamabilidad
                                effective_prob = min(1.0, probs[d] * inflam_factor)
                                if random.random() < effective_prob:
                                    ignited = True
                                    break

                    if ignited:
                        nxt[idx] = _FIRE
                        ntype[idx] = tt
                        # Timer de quemado según especie
                        species_data = TREE_SPECIES.get(tt)
                        nburn[idx] = species_data.burn_time if species_data else 2
                        new_fires += 1
                        if r < fire_min_row:
                            fire_min_row = r
                        has_fire = True
                    else:
                        nxt[idx] = _TREE
                        ntype[idx] = tt
                        nburn[idx] = 0

                elif state == _FIRE:
                    timer = btimer[idx] - 1
                    if timer <= 0:
                        nxt[idx] = _BURNED
                        ntype[idx] = TreeType.NONE
                        nburn[idx] = 0
                    else:
                        nxt[idx] = _FIRE
                        ntype[idx] = ttype[idx]
                        nburn[idx] = timer
                    has_fire = True
                    if r < fire_min_row:
                        fire_min_row = r

                else:
                    nxt[idx] = state
                    ntype[idx] = ttype[idx]
                    nburn[idx] = 0

        # Swap buffers
        self._current, self._next = nxt, current
        self._tree_type, self._next_type = ntype, ttype
        self._burn_timer, self._next_burn = nburn, btimer

        self.tick_count += 1
        self._new_fires_per_tick = new_fires
        self._fire_history.append(new_fires)
        if len(self._fire_history) > 10:
            self._fire_history.pop(0)

        # Velocidad de avance (celdas nuevas / tick promedio)
        self._prev_fire_min_row = self._fire_min_row
        self._fire_min_row = fire_min_row

        self._update_metrics()
        self._check_percolation()
        self.running = has_fire
        return has_fire

    # ------------------------------------------------------------------
    # Métricas
    # ------------------------------------------------------------------
    def _update_metrics(self) -> None:
        trees = fires = burned = empty = 0
        pines = euca = oaks = 0
        for i in range(self.size):
            s = self._current[i]
            if s == CellState.TREE:
                trees += 1
                tt = self._tree_type[i]
                if tt == TreeType.PINE:
                    pines += 1
                elif tt == TreeType.EUCALYPTUS:
                    euca += 1
                elif tt == TreeType.OAK:
                    oaks += 1
            elif s == CellState.FIRE:
                fires += 1
            elif s == CellState.BURNED:
                burned += 1
            else:
                empty += 1
        self.tree_count = trees
        self.fire_count = fires
        self.burned_count = burned
        self.empty_count = empty
        self.pine_count = pines
        self.eucalyptus_count = euca
        self.oak_count = oaks

    def _check_percolation(self) -> None:
        if self.perculated:
            return
        start = self._idx(self.rows - 1, 0)
        end   = self._idx(self.rows - 1, self.cols)
        for i in range(start, end):
            s = self._current[i]
            if s == CellState.FIRE or s == CellState.BURNED:
                self.perculated = True
                return

    # ------------------------------------------------------------------
    # Métricas predictivas (para el panel lateral)
    # ------------------------------------------------------------------
    def get_real_time_str(self) -> str:
        """Convierte ticks a tiempo real simulado (1 tick = 15 min)."""
        total_minutes = self.tick_count * 15
        days = total_minutes // 1440
        hours = (total_minutes % 1440) // 60
        minutes = total_minutes % 60
        if days > 0:
            return f"{days}d {hours:02d}h {minutes:02d}m"
        elif hours > 0:
            return f"{hours}h {minutes:02d}m"
        else:
            return f"{minutes}m"

    def get_fire_speed(self) -> float:
        """
        Velocidad de avance del frente de fuego en celdas/hora simulada.
        Calculada como celdas nuevas por tick promedio * TICKS_PER_HOUR.
        """
        if len(self._fire_history) < 2:
            return 0.0
        avg_new = sum(self._fire_history) / len(self._fire_history)
        return avg_new * TICKS_PER_HOUR

    def get_estimated_extinction_ticks(self) -> Optional[int]:
        """
        Estima ticks restantes hasta extinción basándose en:
        - Fuego activo actual
        - Tasa promedio de extinción (celdas que se apagan por tick)
        """
        if self.fire_count == 0:
            return 0
        # Estimación simple: fuego activo / tasa de consumo promedio
        # Usamos el promedio de nuevos fuegos como proxy de actividad
        if len(self._fire_history) < 3:
            return None  # Datos insuficientes
        avg_activity = sum(self._fire_history) / len(self._fire_history)
        if avg_activity <= 0:
            return 1  # Se extinguirá en el siguiente tick
        # Estimamos ~10 ticks por celda de fuego como tiempo promedio de vida
        est = int(self.fire_count / max(avg_activity, 0.1))
        return max(1, est)

    # ------------------------------------------------------------------
    # Control externo
    # ------------------------------------------------------------------
    def ignite_row(self, row: int = 0) -> None:
        """Prende fuego a todas las celdas con árboles en una fila dada."""
        for c in range(self.cols):
            idx = self._idx(row, c)
            if self._current[idx] == CellState.TREE:
                self._current[idx] = CellState.FIRE
                tt = self._tree_type[idx]
                sp = TREE_SPECIES.get(tt)
                self._burn_timer[idx] = sp.burn_time if sp else 2
        self.running = True

    def reset(self, density: Optional[float] = None) -> None:
        """Reinicia la simulación con nueva o misma densidad."""
        if density is not None:
            self.params.density = density
        self.tick_count = 0
        self.running = False
        self.perculated = False
        self._fire_history.clear()
        self._new_fires_per_tick = 0
        self._fire_min_row = self.rows
        self._prev_fire_min_row = self.rows
        self._init_grid()

    # ------------------------------------------------------------------
    # Edición manual (Modo Dibujo)
    # ------------------------------------------------------------------
    def paint_cell(self, row: int, col: int, tool: EditTool) -> None:
        """Pinta una celda con la herramienta de edición seleccionada."""
        if not (0 <= row < self.rows and 0 <= col < self.cols):
            return
        idx = self._idx(row, col)

        if tool == EditTool.ERASER:
            self._current[idx] = CellState.EMPTY
            self._tree_type[idx] = TreeType.NONE
            self._burn_timer[idx] = 0

        elif tool == EditTool.FIRE:
            if self._current[idx] == CellState.TREE:
                self._current[idx] = CellState.FIRE
                tt = self._tree_type[idx]
                sp = TREE_SPECIES.get(tt)
                self._burn_timer[idx] = sp.burn_time if sp else 2
                self.running = True

        elif tool == EditTool.BARRIER:
            self._current[idx] = CellState.EMPTY
            self._tree_type[idx] = TreeType.NONE
            self._burn_timer[idx] = 0

        else:
            # Herramientas de árbol: PINE, EUCALYPTUS, OAK
            tree_map = {
                EditTool.PINE:      TreeType.PINE,
                EditTool.EUCALYPTUS: TreeType.EUCALYPTUS,
                EditTool.OAK:       TreeType.OAK,
            }
            tt = tree_map.get(tool, TreeType.PINE)
            if self._current[idx] != CellState.BURNED:
                self._current[idx] = CellState.TREE
                self._tree_type[idx] = tt
                self._burn_timer[idx] = 0

        self._update_metrics()

    def paint_brush(self, row: int, col: int, tool: EditTool, brush_size: int) -> None:
        """Pinta un área rectangular de brush_size × brush_size centrada en (row, col)."""
        half = brush_size // 2
        for dr in range(-half, half + 1):
            for dc in range(-half, half + 1):
                self.paint_cell(row + dr, col + dc, tool)

    def get_fire_front(self) -> List[Tuple[int, int]]:
        """Retorna lista de posiciones (row, col) de celdas en fuego activo."""
        front = []
        for r in range(self.rows):
            for c in range(self.cols):
                if self._current[self._idx(r, c)] == CellState.FIRE:
                    front.append((r, c))
        return front

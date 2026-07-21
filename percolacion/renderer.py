"""
renderer.py — Capa de visualización gráfica con Pygame.

Renderiza la cuadrícula del autómata celular y un panel lateral
con métricas en tiempo real, modo edición y métricas predictivas.

Complejidad de renderizado: O(rows × cols) por frame.
"""

import pygame
import random as _random
from typing import Optional, List, Tuple

from .config import (
    CellState, SimParams, WindDirection, TreeType, EditTool,
    TREE_SPECIES, TOOL_NAMES, TOOL_COLORS, BRUSH_SIZES,
    COLOR_EMPTY, COLOR_TREE, COLOR_FIRE_1, COLOR_FIRE_2,
    COLOR_BURNED, COLOR_BARRIER, COLOR_BG, COLOR_TEXT, COLOR_ACCENT,
    COLOR_GRID, COLOR_EDIT_ON, COLOR_BRUSH,
    GRID_CELL_SIZE, PANEL_WIDTH, WINDOW_PADDING,
)
from .simulation import FireSimulation


class Renderer:
    """Renderizador Pygame con panel de control, modo edición y métricas."""

    def __init__(self, sim: FireSimulation):
        self.sim = sim
        params = sim.params

        # Dimensiones de la ventana
        self.grid_w = params.cols * GRID_CELL_SIZE
        self.grid_h = params.rows * GRID_CELL_SIZE
        self.win_w = self.grid_w + PANEL_WIDTH + WINDOW_PADDING * 3
        self.win_h = max(self.grid_h + WINDOW_PADDING * 2, 580)
        self.panel_x = self.grid_w + WINDOW_PADDING * 2

        # Inicializar Pygame
        pygame.init()
        pygame.display.set_caption("Percolacion de Incendios Forestales")
        self.screen = pygame.display.set_mode((self.win_w, self.win_h))
        self.clock = pygame.time.Clock()

        # Fuentes
        self.font_title = pygame.font.SysFont("Consolas", 15, bold=True)
        self.font_main  = pygame.font.SysFont("Consolas", 12)
        self.font_small = pygame.font.SysFont("Consolas", 10)
        self.font_tiny  = pygame.font.SysFont("Consolas", 9)

        # Superficie de la cuadrícula
        self.grid_surf = pygame.Surface((self.grid_w, self.grid_h))

        # Estado de UI
        self.paused = False
        self.show_grid_lines = False

        # --- Modo edición ---
        self.edit_mode = False
        self.edit_tool = EditTool.PINE
        self.brush_size = 1
        self.brush_idx = 0  # Índice en BRUSH_SIZES

        # Ratón (posición en coordenadas de grilla)
        self._mouse_grid_r = -1
        self._mouse_grid_c = -1
        self._mouse_in_grid = False

    # ------------------------------------------------------------------
    # Renderizado principal
    # ------------------------------------------------------------------
    def draw_grid(self) -> None:
        """Renderiza la cuadrícula con colores por tipo de árbol."""
        cs = GRID_CELL_SIZE
        sim = self.sim
        grid_surf = self.grid_surf

        for r in range(sim.rows):
            row_offset = r * sim.cols
            for c in range(sim.cols):
                idx = row_offset + c
                state = sim._current[idx]

                if state == CellState.TREE:
                    tt = sim._tree_type[idx]
                    sp = TREE_SPECIES.get(tt)
                    color = sp.color if sp else COLOR_TREE
                elif state == CellState.FIRE:
                    tt = sim._tree_type[idx]
                    # Variación de color por especie y efecto de fuego
                    if tt == TreeType.EUCALYPTUS:
                        color = (255, 60, 0) if _random.random() > 0.5 else (255, 100, 20)
                    elif tt == TreeType.OAK:
                        color = (200, 100, 20) if _random.random() > 0.5 else (180, 80, 10)
                    else:
                        color = COLOR_FIRE_1 if _random.random() > 0.5 else COLOR_FIRE_2
                elif state == CellState.BURNED:
                    color = COLOR_BURNED
                else:
                    color = COLOR_EMPTY

                pygame.draw.rect(grid_surf, color, (c * cs, r * cs, cs, cs))

        if self.show_grid_lines:
            for r in range(sim.rows + 1):
                pygame.draw.line(grid_surf, COLOR_GRID,
                                 (0, r * cs), (self.grid_w, r * cs))
            for c in range(sim.cols + 1):
                pygame.draw.line(grid_surf, COLOR_GRID,
                                 (c * cs, 0), (c * cs, self.grid_h))

        self.screen.blit(self.grid_surf, (WINDOW_PADDING, WINDOW_PADDING))

        # --- Dibujar indicador del pincel ---
        if self.edit_mode and self._mouse_in_grid:
            self._draw_brush_cursor()

    def _draw_brush_cursor(self) -> None:
        """Dibuja el contorno del pincel sobre la grilla."""
        cs = GRID_CELL_SIZE
        half = self.brush_size // 2
        r0 = self._mouse_grid_r - half
        c0 = self._mouse_grid_c - half
        x = WINDOW_PADDING + c0 * cs
        y = WINDOW_PADDING + r0 * cs
        w = self.brush_size * cs
        h = self.brush_size * cs

        tool_color = TOOL_COLORS.get(self.edit_tool, COLOR_BRUSH)
        # Dibujar borde semitransparente
        s = pygame.Surface((w, h), pygame.SRCALPHA)
        s.fill((*tool_color, 60))
        self.screen.blit(s, (x, y))
        pygame.draw.rect(self.screen, tool_color, (x, y, w, h), 2)

    # ------------------------------------------------------------------
    # Panel lateral
    # ------------------------------------------------------------------
    def draw_panel(self) -> None:
        """Renderiza el panel lateral completo con todas las secciones."""
        x = self.panel_x
        y = WINDOW_PADDING
        w = PANEL_WIDTH

        # Fondo del panel
        pygame.draw.rect(self.screen, COLOR_BG,
                         (x, y, w, self.win_h - WINDOW_PADDING * 2),
                         border_radius=8)

        y += 10
        self._draw_text("PERCOLACION FORESTAL", self.font_title,
                        COLOR_ACCENT, x + 12, y)
        y += 18
        self._draw_text("Autómatas Celulares + Monte Carlo", self.font_tiny,
                        (120, 120, 120), x + 12, y)
        y += 16
        pygame.draw.line(self.screen, COLOR_ACCENT,
                         (x + 12, y), (x + w - 12, y), 1)
        y += 8

        # --- MODO EDICIÓN (si está activo) ---
        if self.edit_mode:
            self._draw_edit_section(x, y, w)
            y += 82
            pygame.draw.line(self.screen, COLOR_EDIT_ON,
                             (x + 12, y), (x + w - 12, y), 1)
            y += 8

        # --- Métricas de simulación ---
        self._draw_section("SIMULACION", x, y)
        y += 18

        total_veg = self.sim.tree_count + self.sim.fire_count + self.sim.burned_count
        consumed = (self.sim.burned_count / total_veg * 100) if total_veg > 0 else 0.0

        self._draw_metric("Tick:", f"{self.sim.tick_count}", x, y); y += 17
        self._draw_metric("Estado:", self._sim_status(), x, y); y += 17

        # Conteos por especie
        self._draw_metric("Pinos:", f"{self.sim.pine_count}", x, y,
                          TREE_SPECIES[TreeType.PINE].color); y += 17
        self._draw_metric("Eucaliptos:", f"{self.sim.eucalyptus_count}", x, y,
                          TREE_SPECIES[TreeType.EUCALYPTUS].color); y += 17
        self._draw_metric("Robles:", f"{self.sim.oak_count}", x, y,
                          TREE_SPECIES[TreeType.OAK].color); y += 17

        self._draw_metric("Fuego activo:", f"{self.sim.fire_count}", x, y); y += 17
        self._draw_metric("Quemados:", f"{self.sim.burned_count}", x, y); y += 17
        self._draw_metric("Vacíos:", f"{self.sim.empty_count}", x, y); y += 17

        y += 2
        self._draw_metric("Bosque consumido:", f"{consumed:.1f}%", x, y, COLOR_ACCENT)
        y += 17

        # Barra de progreso
        bar_x, bar_y, bar_w, bar_h = x + 12, y, w - 24, 8
        pygame.draw.rect(self.screen, (50, 50, 50),
                         (bar_x, bar_y, bar_w, bar_h), border_radius=3)
        fill_w = int(bar_w * (consumed / 100.0))
        if fill_w > 0:
            pygame.draw.rect(self.screen, COLOR_ACCENT,
                             (bar_x, bar_y, fill_w, bar_h), border_radius=3)
        y += 14

        self._draw_metric("Percolacion:", "SI" if self.sim.perculated else "No",
                          x, y,
                          (0, 255, 80) if self.sim.perculated else COLOR_TEXT)
        y += 20

        # --- Métricas predictivas ---
        self._draw_section("TIEMPO REAL", x, y)
        y += 18
        real_time = self.sim.get_real_time_str()
        self._draw_metric("Tiempo simulado:", real_time, x, y, COLOR_ACCENT)
        y += 17

        speed = self.sim.get_fire_speed()
        self._draw_metric("Vel. avance:", f"{speed:.1f} celdas/h", x, y)
        y += 17

        est = self.sim.get_estimated_extinction_ticks()
        if est is not None:
            est_str = f"~{est} ticks"
            if est > 0:
                est_min = est * 15
                if est_min >= 60:
                    est_str += f" ({est_min // 60}h {est_min % 60:02d}m)"
                else:
                    est_str += f" ({est_min}m)"
        else:
            est_str = "Calculando..."
        self._draw_metric("Extincion est.:", est_str, x, y)
        y += 20

        pygame.draw.line(self.screen, (50, 50, 50),
                         (x + 12, y), (x + w - 12, y), 1)
        y += 8

        # --- Parámetros ---
        self._draw_section("PARAMETROS", x, y)
        y += 18
        p = self.sim.params
        self._draw_metric("Densidad (p):", f"{p.density:.3f}", x, y); y += 17
        self._draw_metric("Grilla:", f"{p.rows}x{p.cols}", x, y); y += 17
        self._draw_metric("Propagacion:", f"{p.spread_base:.2f}", x, y); y += 17
        wind_names = ["Norte", "Sur", "Este", "Oeste", "Sin viento"]
        self._draw_metric("Viento:",
                          f"{wind_names[p.wind_dir]} ({p.wind_intensity:.1f})",
                          x, y); y += 17

        y += 4
        pygame.draw.line(self.screen, (50, 50, 50),
                         (x + 12, y), (x + w - 12, y), 1)
        y += 8

        # --- Controles ---
        self._draw_section("CONTROLES", x, y)
        y += 18
        controls = [
            "ESPACIO  — Iniciar / Pausa",
            "R        — Reiniciar",
            "E        — Modo edicion",
            "G        — Lineas de grilla",
            "F        — Igniciar fila 0",
            "M        — Monte Carlo",
            "Flechas  — Densidad/Viento",
            "+/-      — Intensidad viento",
            "1/2/3    — Tipo de arbol",
            "Scroll   — Tamano pincel",
            "ESC / Q  — Salir",
        ]
        for ctrl in controls:
            self._draw_text(ctrl, self.font_tiny, (160, 160, 160), x + 12, y)
            y += 13

        # Pie
        y = self.win_h - WINDOW_PADDING - 14
        fps = self.clock.get_fps()
        edit_label = f"EDICION: {TOOL_NAMES[self.edit_tool]} {self.brush_size}x{self.brush_size}" \
            if self.edit_mode else ""
        self._draw_text(f"FPS: {fps:.0f}  {edit_label}", self.font_tiny,
                        (80, 80, 80), x + 12, y)

    # ------------------------------------------------------------------
    # Sección de edición
    # ------------------------------------------------------------------
    def _draw_edit_section(self, x: int, y: int, w: int) -> None:
        """Dibuja el panel de herramientas de edición."""
        self._draw_section("MODO EDICION", x, y)
        y += 18

        # Herramienta actual
        tool_color = TOOL_COLORS.get(self.edit_tool, COLOR_BRUSH)
        tool_name = TOOL_NAMES.get(self.edit_tool, "?")
        self._draw_metric("Herramienta:", tool_name, x, y, tool_color)
        y += 17

        # Tamaño del pincel
        self._draw_metric("Pincel:", f"{self.brush_size}x{self.brush_size}", x, y)
        y += 17

        # Barra de tamaños
        bar_x = x + 12
        for i, sz in enumerate(BRUSH_SIZES):
            bw = 30
            bx = bar_x + i * (bw + 4)
            is_sel = (sz == self.brush_size)
            bg = tool_color if is_sel else (60, 60, 60)
            pygame.draw.rect(self.screen, bg, (bx, y, bw, 14), border_radius=3)
            lbl = self.font_tiny.render(str(sz), True,
                                        (0, 0, 0) if is_sel else COLOR_TEXT)
            self.screen.blit(lbl, (bx + 10, y + 1))
        y += 22

        # Lista de herramientas
        self._draw_text("1:Pino 2:Eucal 3:Roble", self.font_tiny,
                        (160, 160, 160), x + 12, y)
        y += 13
        self._draw_text("4:Fuego 5:Barrera 6:Borra", self.font_tiny,
                        (160, 160, 160), x + 12, y)

    # ------------------------------------------------------------------
    # Métodos auxiliares
    # ------------------------------------------------------------------
    def _draw_text(self, text: str, font: pygame.font.Font,
                   color: Tuple[int, int, int], x: int, y: int) -> None:
        surf = font.render(text, True, color)
        self.screen.blit(surf, (x, y))

    def _draw_section(self, title: str, x: int, y: int) -> None:
        self._draw_text(f"> {title}", self.font_title, COLOR_ACCENT, x + 12, y)

    def _draw_metric(self, label: str, value: str, x: int, y: int,
                     color: Tuple[int, int, int] = COLOR_TEXT) -> None:
        self._draw_text(label, self.font_main, (130, 130, 130), x + 12, y)
        self._draw_text(value, self.font_main, color, x + 145, y)

    def _sim_status(self) -> str:
        if self.sim.fire_count > 0:
            return "ACTIVO"
        elif self.sim.tick_count > 0:
            return "DETENIDO"
        return "LISTO"

    # ------------------------------------------------------------------
    # Eventos
    # ------------------------------------------------------------------
    def handle_events(self) -> bool:
        """
        Procesa eventos de Pygame.
        Retorna: True=normal, False=salir, str=comando especial.
        """
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return False

            elif event.type == pygame.MOUSEMOTION:
                self._update_mouse_grid(event.pos)

            elif event.type == pygame.MOUSEWHEEL:
                if self.edit_mode:
                    # Rueda del ratón: cambiar tamaño de pincel
                    self.brush_idx = max(0, min(
                        len(BRUSH_SIZES) - 1,
                        self.brush_idx + (1 if event.y > 0 else -1)))
                    self.brush_size = BRUSH_SIZES[self.brush_idx]

            elif event.type == pygame.MOUSEBUTTONDOWN:
                if self.edit_mode and self._mouse_in_grid:
                    if event.button == 1:
                        # Clic izquierdo: pintar
                        self.sim.paint_brush(
                            self._mouse_grid_r, self._mouse_grid_c,
                            self.edit_tool, self.brush_size)
                    elif event.button == 3:
                        # Clic derecho: borrar
                        self.sim.paint_brush(
                            self._mouse_grid_r, self._mouse_grid_c,
                            EditTool.ERASER, self.brush_size)

            elif event.type == pygame.MOUSEBUTTONUP:
                pass

            elif event.type == pygame.KEYDOWN:
                if event.key in (pygame.K_ESCAPE, pygame.K_q):
                    return False

                elif event.key == pygame.K_SPACE:
                    if self.edit_mode:
                        pass  # No hacer nada en modo edición con espacio
                    elif not self.sim.running and self.sim.tick_count == 0:
                        self.sim.ignite_row(0)
                        self.sim.running = True
                    else:
                        self.paused = not self.paused

                elif event.key == pygame.K_r:
                    self.sim.reset()
                    self.paused = False

                elif event.key == pygame.K_e:
                    self.edit_mode = not self.edit_mode
                    if not self.edit_mode:
                        self._mouse_in_grid = False

                elif event.key == pygame.K_g:
                    self.show_grid_lines = not self.show_grid_lines

                elif event.key == pygame.K_UP:
                    self.sim.params.density = min(1.0, self.sim.params.density + 0.01)
                    self.sim.reset()

                elif event.key == pygame.K_DOWN:
                    self.sim.params.density = max(0.01, self.sim.params.density - 0.01)
                    self.sim.reset()

                elif event.key == pygame.K_LEFT:
                    d = self.sim.params.wind_dir
                    self.sim.params.wind_dir = WindDirection((d - 1) % 5)
                    self.sim._compute_probabilities()

                elif event.key == pygame.K_RIGHT:
                    d = self.sim.params.wind_dir
                    self.sim.params.wind_dir = WindDirection((d + 1) % 5)
                    self.sim._compute_probabilities()

                elif event.key in (pygame.K_PLUS, pygame.K_EQUALS, pygame.K_KP_PLUS):
                    self.sim.params.wind_intensity = min(
                        1.0, self.sim.params.wind_intensity + 0.1)
                    self.sim._compute_probabilities()

                elif event.key in (pygame.K_MINUS, pygame.K_KP_MINUS):
                    self.sim.params.wind_intensity = max(
                        0.0, self.sim.params.wind_intensity - 0.1)
                    self.sim._compute_probabilities()

                elif event.key == pygame.K_f:
                    if not self.edit_mode:
                        self.sim.ignite_row(0)

                elif event.key == pygame.K_m:
                    if not self.edit_mode:
                        return "monte_carlo"

                # Teclas 1-6: seleccionar herramienta de edición
                elif event.key == pygame.K_1:
                    self.edit_tool = EditTool.PINE
                    self.edit_mode = True
                elif event.key == pygame.K_2:
                    self.edit_tool = EditTool.EUCALYPTUS
                    self.edit_mode = True
                elif event.key == pygame.K_3:
                    self.edit_tool = EditTool.OAK
                    self.edit_mode = True
                elif event.key == pygame.K_4:
                    self.edit_tool = EditTool.FIRE
                    self.edit_mode = True
                elif event.key == pygame.K_5:
                    self.edit_tool = EditTool.BARRIER
                    self.edit_mode = True
                elif event.key == pygame.K_6:
                    self.edit_tool = EditTool.ERASER
                    self.edit_mode = True

        # Pintar mientras se mantiene el botón del ratón (drag painting)
        if self.edit_mode and self._mouse_in_grid:
            mouse_buttons = pygame.mouse.get_pressed()
            if mouse_buttons[0]:
                self.sim.paint_brush(
                    self._mouse_grid_r, self._mouse_grid_c,
                    self.edit_tool, self.brush_size)
            elif mouse_buttons[2]:
                self.sim.paint_brush(
                    self._mouse_grid_r, self._mouse_grid_c,
                    EditTool.ERASER, self.brush_size)

        return True

    def _update_mouse_grid(self, pos: Tuple[int, int]) -> None:
        """Convierte coordenadas de pantalla a coordenadas de grilla."""
        mx, my = pos
        gx = mx - WINDOW_PADDING
        gy = my - WINDOW_PADDING
        cs = GRID_CELL_SIZE
        c = gx // cs
        r = gy // cs
        if 0 <= r < self.sim.rows and 0 <= c < self.sim.cols:
            self._mouse_grid_r = r
            self._mouse_grid_c = c
            self._mouse_in_grid = True
        else:
            self._mouse_in_grid = False

    # ------------------------------------------------------------------
    # Tick / Frame
    # ------------------------------------------------------------------
    def tick(self) -> int:
        """Ejecuta un paso de simulación si no está pausado y hay fuego."""
        if not self.paused and self.sim.running:
            self.sim.step()
        self.clock.tick(1000 // max(self.sim.params.tick_rate_ms, 1))
        return self.clock.get_time()

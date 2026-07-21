"""
config.py — Constantes, enumeraciones y parámetros globales.

Diseñado para portabilidad a C++/ESP32: los estados se representan
como enteros planos en arreglos 1D o 2D sin dependencias de objetos.
"""

from enum import IntEnum
from dataclasses import dataclass, field
from typing import Tuple, Dict

# ---------------------------------------------------------------------------
# Estados del Autómata Celular (enteros planos para compatibilidad ESP32)
# ---------------------------------------------------------------------------
class CellState(IntEnum):
    EMPTY  = 0  # Terreno sin vegetación / barrera
    TREE   = 1  # Vegetación viva
    FIRE   = 2  # Celda en ignición activa
    BURNED = 3  # Ceniza / vegetación consumida


# ---------------------------------------------------------------------------
# Tipos de árbol / vegetación
# ---------------------------------------------------------------------------
class TreeType(IntEnum):
    NONE        = 0  # No es árbol
    PINE        = 1  # Pino / Conífera — inflamabilidad alta
    EUCALYPTUS  = 2  # Eucalipto — inflamabilidad muy alta
    OAK         = 3  # Roble / Caduco — inflamabilidad baja


# ---------------------------------------------------------------------------
# Herramientas de edición
# ---------------------------------------------------------------------------
class EditTool(IntEnum):
    PINE        = 0  # Pintar pino
    EUCALYPTUS  = 1  # Pintar eucalipto
    OAK         = 2  # Pintar roble
    FIRE        = 3  # Colocar foco de fuego
    BARRIER     = 4  # Cortafuegos / barrera
    ERASER      = 5  # Borrar celda


# ---------------------------------------------------------------------------
# Direcciones del viento
# ---------------------------------------------------------------------------
class WindDirection(IntEnum):
    NORTH = 0
    SOUTH = 1
    EAST  = 2
    WEST  = 3
    NONE  = 4


# ---------------------------------------------------------------------------
# Propiedades físicas de cada especie de árbol
# ---------------------------------------------------------------------------
@dataclass(frozen=True)
class TreeProperties:
    name: str
    inflamability: float   # Factor multiplicador sobre spread_base (1.0 = normal)
    burn_time: int         # Ticks que permanece en estado FIRE antes de quemarse
    color: Tuple[int, int, int]

TREE_SPECIES: Dict[int, TreeProperties] = {
    TreeType.PINE:       TreeProperties("Pino",       1.3, 2, ( 20, 100,  20)),
    TreeType.EUCALYPTUS: TreeProperties("Eucalipto",  1.5, 1, ( 80, 200,  80)),
    TreeType.OAK:        TreeProperties("Roble",      0.7, 4, ( 85, 120,  45)),
}

# Colores para fuego por tipo de árbol (variaciones para efecto visual)
COLOR_FIRE_PINE      = (255, 140,   0)   # Naranja
COLOR_FIRE_EUCALYPTUS = (255,  60,   0)  # Rojo intenso
COLOR_FIRE_OAK       = (200, 100,  20)   # Naranja apagado


# ---------------------------------------------------------------------------
# Parámetros de simulación
# ---------------------------------------------------------------------------
@dataclass
class SimParams:
    """Parámetros configurables de la simulación."""
    rows: int = 80
    cols: int = 80
    density: float = 0.55          # Probabilidad de que una celda sea árbol
    wind_dir: WindDirection = WindDirection.NONE
    wind_intensity: float = 0.0    # 0.0 = sin viento, 1.0 = viento máximo
    spread_base: float = 0.85      # Probabilidad base de propagación
    ignition_threshold: float = 0.0
    tick_rate_ms: int = 80


# ---------------------------------------------------------------------------
# Equivalencia temporal: 1 tick = 15 minutos reales
# ---------------------------------------------------------------------------
TICKS_PER_HOUR = 4    # 60 min / 15 min = 4 ticks por hora simulada


# ---------------------------------------------------------------------------
# Colores (R, G, B) para Pygame
# ---------------------------------------------------------------------------
COLOR_EMPTY     = (139,  90,  43)   # Marrón tierra
COLOR_TREE      = ( 34, 139,  34)   # Verde bosque (genérico)
COLOR_FIRE_1    = (255, 165,   0)   # Naranja
COLOR_FIRE_2    = (255,  69,   0)   # Rojo-naranja
COLOR_BURNED    = ( 40,  40,  40)   # Gris oscuro / ceniza
COLOR_BARRIER   = ( 30,  80, 160)   # Azul agua / cortafuegos
COLOR_BG        = ( 20,  20,  20)   # Fondo del panel
COLOR_TEXT      = (220, 220, 220)   # Texto claro
COLOR_ACCENT    = (  0, 180, 255)   # Acento para métricas
COLOR_GRID      = ( 60,  60,  60)   # Líneas de cuadrícula
COLOR_EDIT_ON   = (255, 220,   0)   # Indicador modo edición activo
COLOR_BRUSH     = (255, 255, 255)   # Outline del pincel


# ---------------------------------------------------------------------------
# Layout de la ventana
# ---------------------------------------------------------------------------
GRID_CELL_SIZE = 8     # Píxeles por celda
PANEL_WIDTH    = 300   # Ancho del panel lateral
WINDOW_PADDING = 10

# Brush sizes disponibles
BRUSH_SIZES = [1, 3, 5]

# Nombres de herramientas de edición (para UI)
TOOL_NAMES = {
    EditTool.PINE:       "Pino",
    EditTool.EUCALYPTUS: "Eucalipto",
    EditTool.OAK:        "Roble",
    EditTool.FIRE:       "Fuego",
    EditTool.BARRIER:    "Barrera",
    EditTool.ERASER:     "Borrador",
}

# Colores de las herramientas de edición (para indicador en UI)
TOOL_COLORS = {
    EditTool.PINE:       TREE_SPECIES[TreeType.PINE].color,
    EditTool.EUCALYPTUS: TREE_SPECIES[TreeType.EUCALYPTUS].color,
    EditTool.OAK:        TREE_SPECIES[TreeType.OAK].color,
    EditTool.FIRE:       COLOR_FIRE_1,
    EditTool.BARRIER:    COLOR_BARRIER,
    EditTool.ERASER:     COLOR_EMPTY,
}

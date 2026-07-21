"""
Paquete: Percolacion de Incendios Forestales
Modelo de Autómatas Celulares con Métodos de Monte Carlo
"""

from .config import (
    CellState, TreeType, EditTool, WindDirection,
    TreeProperties, TREE_SPECIES,
    SimParams, TOOL_NAMES, TOOL_COLORS, BRUSH_SIZES,
)
from .simulation import FireSimulation
from .monte_carlo import MonteCarloAnalyzer
from .renderer import Renderer

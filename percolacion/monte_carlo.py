"""
monte_carlo.py — Motor de Análisis Predictivo con Métodos de Monte Carlo.

Ejecuta N iteraciones por cada valor de densidad p ∈ [p_min, p_max]
para estimar la probabilidad de percolación y localizar el umbral
crítico pc ≈ 0.5928 para percolación en rejilla cuadrada 2D.

Complejidad: O(N × M × steps_max) donde N = número de densidades,
M = iteraciones por densidad, steps_max = ticks máximos por simulación.
"""

from typing import List, Tuple, Optional, Callable
import time

from .config import SimParams, WindDirection
from .simulation import FireSimulation


class MonteCarloResult:
    """Resultado del análisis Monte Carlo para un valor de densidad."""

    __slots__ = ('density', 'iterations', 'percolation_count',
                 'percolation_prob', 'avg_burned_pct', 'avg_ticks')

    def __init__(self, density: float, iterations: int,
                 percolation_count: int, percolation_prob: float,
                 avg_burned_pct: float, avg_ticks: float):
        self.density = density
        self.iterations = iterations
        self.percolation_count = percolation_count
        self.percolation_prob = percolation_prob
        self.avg_burned_pct = avg_burned_pct
        self.avg_ticks = avg_ticks

    def __repr__(self) -> str:
        return (f"p={self.density:.3f}  P(percol)={self.percolation_prob:.3f}  "
                f"burned={self.avg_burned_pct:.1f}%  ticks={self.avg_ticks:.0f}")


class MonteCarloAnalyzer:
    """
    Ejecuta análisis Monte Carlo para determinar la probabilidad
    de percolación como función de la densidad de vegetación.
    """

    def __init__(self, base_params: Optional[SimParams] = None,
                 density_min: float = 0.30,
                 density_max: float = 0.85,
                 density_steps: int = 20,
                 iterations: int = 50,
                 max_ticks: int = 500,
                 progress_callback: Optional[Callable] = None):
        """
        Args:
            base_params: Parámetros base de simulación (se modifica density).
            density_min: Densidad mínima a explorar.
            density_max: Densidad máxima a explorar.
            density_steps: Número de puntos de densidad a muestrear.
            iterations: Número de simulaciones por punto de densidad.
            max_ticks: Ticks máximos antes de detener una simulación.
            progress_callback: Callable(fraction, message) para reportar progreso.
        """
        self.base_params = base_params or SimParams()
        self.density_min = density_min
        self.density_max = density_max
        self.density_steps = density_steps
        self.iterations = iterations
        self.max_ticks = max_ticks
        self.progress_callback = progress_callback

        self.results: List[MonteCarloResult] = []
        self.is_running = False
        self.critical_density_estimate: Optional[float] = None

    def run(self) -> List[MonteCarloResult]:
        """
        Ejecuta el análisis completo de Monte Carlo.

        Retorna lista de MonteCarloResult ordenada por densidad.
        """
        self.results = []
        self.is_running = True

        densities = [
            self.density_min + i * (self.density_max - self.density_min)
            / (self.density_steps - 1)
            for i in range(self.density_steps)
        ]

        total = self.density_steps
        pc_estimate = None
        prev_prob = 0.0

        for step_i, density in enumerate(densities):
            if not self.is_running:
                break

            perc_count = 0
            total_burned = 0.0
            total_ticks = 0.0

            for trial in range(self.iterations):
                if not self.is_running:
                    break

                sim = FireSimulation(self.base_params)
                sim.reset(density=density)
                sim.ignite_row(0)

                ticks_used = 0
                while sim.running and ticks_used < self.max_ticks:
                    sim.step()
                    ticks_used += 1

                if sim.perculated:
                    perc_count += 1

                if sim.burned_count + sim.fire_count + sim.tree_count > 0:
                    burned_pct = (sim.burned_count / (sim.tree_count
                                  + sim.burned_count + sim.fire_count)) * 100
                else:
                    burned_pct = 0.0

                total_burned += burned_pct
                total_ticks += ticks_used

            iters_done = min(trial + 1, self.iterations)
            prob = perc_count / iters_done
            avg_burned = total_burned / iters_done
            avg_ticks = total_ticks / iters_done

            result = MonteCarloResult(
                density=density,
                iterations=iters_done,
                percolation_count=perc_count,
                percolation_prob=prob,
                avg_burned_pct=avg_burned,
                avg_ticks=avg_ticks,
            )
            self.results.append(result)

            # Detectar umbral crítico: mayor salto en probabilidad
            if prob - prev_prob > 0.1 and pc_estimate is None and step_i > 0:
                pc_estimate = density
            prev_prob = prob

            # Callback de progreso
            if self.progress_callback:
                fraction = (step_i + 1) / total
                self.progress_callback(
                    fraction,
                    f"Densidad {density:.3f} | "
                    f"P(percol)={prob:.3f} | "
                    f"Iteración {step_i+1}/{total}"
                )

        self.critical_density_estimate = pc_estimate
        self.is_running = False
        return self.results

    def stop(self) -> None:
        """Detiene el análisis en curso."""
        self.is_running = False

    def get_critical_density(self) -> Optional[float]:
        """Retorna la estimación del umbral crítico."""
        return self.critical_density_estimate

    def get_summary(self) -> str:
        """Retorna un resumen textual de los resultados."""
        if not self.results:
            return "No hay resultados. Ejecute el análisis primero."

        lines = ["=" * 60]
        lines.append("  ANÁLISIS MONTE CARLO — PERCOLACIÓN DE INCENDIOS")
        lines.append("=" * 60)
        lines.append(f"  Densidad rango: [{self.density_min:.2f}, {self.density_max:.2f}]")
        lines.append(f"  Puntos muestreados: {self.density_steps}")
        lines.append(f"  Iteraciones por punto: {self.iterations}")
        lines.append("-" * 60)
        lines.append(f"  {'p':>6s}  {'P(percol)':>10s}  {'Quemado%':>9s}  {'Ticks':>6s}")
        lines.append("-" * 60)

        for r in self.results:
            bar = "#" * int(r.percolation_prob * 20)
            lines.append(
                f"  {r.density:6.3f}  {r.percolation_prob:10.3f}  "
                f"{r.avg_burned_pct:8.1f}%  {r.avg_ticks:6.0f}  {bar}"
            )

        lines.append("-" * 60)
        if self.critical_density_estimate:
            lines.append(
                f"  Umbral critico estimado: "
                f"pc ~ {self.critical_density_estimate:.3f}"
            )
        else:
            lines.append("  Umbral critico: no detectado (ajustar rango)")
        lines.append("=" * 60)
        return "\n".join(lines)

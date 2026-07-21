"""
main.py — Punto de entrada de la aplicación.

Inicia la simulación en tiempo real con visualización Pygame.
Presiona M en la ventana para ejecutar el análisis Monte Carlo.
Presiona E para entrar en modo edición y dibujar el bosque manualmente.

Ejecutar:
    pip install pygame-ce
    python main.py
"""

import sys
import os
import time
import pygame

# Asegurar que el paquete sea importable desde el directorio raíz
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from percolacion.config import SimParams, WindDirection
from percolacion.simulation import FireSimulation
from percolacion.monte_carlo import MonteCarloAnalyzer
from percolacion.renderer import Renderer


def run_monte_carlo_analysis(renderer: Renderer, sim: FireSimulation) -> None:
    """Ejecuta el análisis Monte Carlo con ventana de progreso."""
    win_w, win_h = 520, 200
    progress_screen = pygame.display.set_mode((win_w, win_h))
    pygame.display.set_caption("Monte Carlo - Analizando...")
    font = pygame.font.SysFont("Consolas", 14)
    font_title = pygame.font.SysFont("Consolas", 16, bold=True)

    def progress_callback(fraction, message):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                analyzer.stop()
                return
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    analyzer.stop()
                    return

        progress_screen.fill((25, 25, 30))

        title = font_title.render("Analisis Monte Carlo", True, (0, 180, 255))
        progress_screen.blit(title, (20, 20))

        msg = font.render(message, True, (200, 200, 200))
        progress_screen.blit(msg, (20, 55))

        bar_x, bar_y, bar_w, bar_h = 20, 90, win_w - 40, 24
        pygame.draw.rect(progress_screen, (50, 50, 50),
                         (bar_x, bar_y, bar_w, bar_h), border_radius=4)
        fill_w = int(bar_w * fraction)
        if fill_w > 0:
            pygame.draw.rect(progress_screen, (0, 180, 255),
                             (bar_x, bar_y, fill_w, bar_h), border_radius=4)

        pct_text = font.render(f"{fraction * 100:.0f}%", True, (255, 255, 255))
        progress_screen.blit(pct_text, (bar_x + bar_w // 2 - 15, bar_y + 4))

        esc_text = font.render("Presiona ESC para cancelar", True, (120, 120, 120))
        progress_screen.blit(esc_text, (20, 135))

        pygame.display.flip()

    mc_params = SimParams(
        rows=sim.params.rows,
        cols=sim.params.cols,
        density=0.55,
        wind_dir=sim.params.wind_dir,
        wind_intensity=sim.params.wind_intensity,
        spread_base=1.0,
        tick_rate_ms=sim.params.tick_rate_ms,
    )
    analyzer = MonteCarloAnalyzer(
        base_params=mc_params,
        density_min=0.30,
        density_max=0.85,
        density_steps=25,
        iterations=40,
        max_ticks=400,
        progress_callback=progress_callback,
    )

    start_time = time.time()
    results = analyzer.run()
    elapsed = time.time() - start_time

    # Volver a la ventana principal
    renderer.screen = pygame.display.set_mode((renderer.win_w, renderer.win_h))
    pygame.display.set_caption("Percolacion de Incendios Forestales")

    print(analyzer.get_summary())
    print(f"\n  Tiempo total: {elapsed:.1f}s")


def main() -> None:
    """Funcion principal - loop de la aplicacion."""
    params = SimParams(
        rows=80,
        cols=80,
        density=0.55,
        wind_dir=WindDirection.NONE,
        wind_intensity=0.0,
        spread_base=0.85,
        tick_rate_ms=50,
    )

    sim = FireSimulation(params)
    renderer = Renderer(sim)

    clock = pygame.time.Clock()
    running = True

    while running:
        result = renderer.handle_events()

        if result is False:
            running = False
            break
        elif result == "monte_carlo":
            run_monte_carlo_analysis(renderer, sim)

        renderer.tick()
        renderer.draw_grid()
        renderer.draw_panel()

        pygame.display.flip()
        clock.tick(1000 // max(params.tick_rate_ms, 1))

    pygame.quit()
    sys.exit()


if __name__ == "__main__":
    main()

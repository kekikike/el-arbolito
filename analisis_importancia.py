import pandas as pd
import numpy as np
import joblib
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt

artifact = joblib.load("modelo_desercion.pkl")
model = artifact["model"]
feature_names = artifact["feature_names"]

# ============================================================
# PASO 1-2: Tabla ordenada + CSV
# ============================================================

nombres_legibles = {
    "estado_civil": "Estado civil",
    "modalidad_admision": "Modalidad de admision",
    "carrera": "Carrera",
    "turno": "Turno",
    "genero": "Genero",
    "internacional": "Internacional",
    "beca": "Beca",
    "desplazado": "Desplazado",
    "pagos_al_dia": "Pagos al dia",
    "nivel_educ_padre": "Nivel educ. padre",
    "nivel_educ_madre": "Nivel educ. madre",
    "ocupacion_padre": "Ocupacion padre",
    "ocupacion_madre": "Ocupacion madre",
    "inscritas_1er_sem": "Unidades inscritas 1er sem",
    "nota_1er_sem": "Nota promedio 1er sem",
    "aprobadas_1er_sem": "Unidades aprobadas 1er sem",
    "inscritas_2do_sem": "Unidades inscritas 2do sem",
    "nota_2do_sem": "Nota promedio 2do sem",
    "aprobadas_2do_sem": "Unidades aprobadas 2do sem",
}

imp = pd.DataFrame({
    "variable": feature_names,
    "nombre": [nombres_legibles.get(f, f) for f in feature_names],
    "importancia": model.feature_importances_,
})
imp = imp.sort_values("importancia", ascending=False).reset_index(drop=True)
imp["ranking"] = range(1, len(imp) + 1)
imp["porcentaje"] = imp["importancia"] * 100

print("=" * 65)
print("TABLA DE IMPORTANCIA DE VARIABLES")
print("=" * 65)
print(f"  {'#':>2s}  {'Variable':30s} {'Importancia':>12s}")
print(f"  {'-'*2}  {'-'*30} {'-'*12}")
for _, row in imp.iterrows():
    bar = "#" * int(row["importancia"] * 150)
    print(f"  {row['ranking']:2d}. {row['nombre']:30s} {row['porcentaje']:5.2f}%  {bar}")

total = imp["importancia"].sum()
print(f"\n  Total: {total*100:.2f}%")

imp_export = imp[["ranking", "nombre", "variable", "porcentaje"]].copy()
imp_export.columns = ["Ranking", "Variable", "Codigo", "Importancia (%)"]
imp_export.to_csv("importancia_variables.csv", index=False, encoding="utf-8-sig")
print("  Exportado: importancia_variables.csv")

# ============================================================
# PASO 3: Grafico de barras horizontales
# ============================================================

fig, ax = plt.subplots(figsize=(10, 8))

imp_plot = imp.sort_values("importancia", ascending=True)
colors = []
for f in imp_plot["variable"]:
    if f in ("inscritas_1er_sem", "nota_1er_sem", "aprobadas_1er_sem",
             "inscritas_2do_sem", "nota_2do_sem", "aprobadas_2do_sem"):
        colors.append("#2980b9")
    elif f in ("nivel_educ_padre", "nivel_educ_madre", "ocupacion_padre", "ocupacion_madre"):
        colors.append("#27ae60")
    else:
        colors.append("#e67e22")

ax.barh(imp_plot["nombre"], imp_plot["importancia"] * 100, color=colors, edgecolor="white", height=0.7)

ax.set_xlabel("Importancia (%)", fontsize=12)
ax.set_title("Importancia de variables en la prediccion de desercion estudiantil\nRandom Forest (19 features, n=10, depth=7, accuracy 74.6%)",
             fontsize=13, fontweight="bold", pad=15)
ax.tick_params(axis="y", labelsize=10)
ax.tick_params(axis="x", labelsize=10)
ax.set_xlim(0, max(imp["importancia"]) * 100 * 1.15)

for i, (_, row) in enumerate(imp_plot.iterrows()):
    ax.text(row["importancia"] * 100 + 0.2, i, f"{row['porcentaje']:.2f}%",
            va="center", fontsize=9, color="#333")

from matplotlib.patches import Patch
legend_elements = [
    Patch(facecolor="#2980b9", label="Rendimiento academico"),
    Patch(facecolor="#27ae60", label="Datos familiares"),
    Patch(facecolor="#e67e22", label="Datos generales"),
]
ax.legend(handles=legend_elements, loc="lower right", fontsize=10, framealpha=0.9)

ax.spines["top"].set_visible(False)
ax.spines["right"].set_visible(False)
ax.grid(axis="x", alpha=0.3, linestyle="--")

plt.tight_layout()
plt.savefig("importancia_variables.png", dpi=300, bbox_inches="tight", facecolor="white")
print("  Exportado: importancia_variables.png (300 dpi)")

# ============================================================
# PASO 4: Agrupacion por categoria conceptual
# ============================================================

cat_rendimiento = ["inscritas_1er_sem", "nota_1er_sem", "aprobadas_1er_sem",
                   "inscritas_2do_sem", "nota_2do_sem", "aprobadas_2do_sem"]
cat_familia = ["nivel_educ_padre", "nivel_educ_madre", "ocupacion_padre", "ocupacion_madre"]
cat_general = [f for f in feature_names if f not in cat_rendimiento and f not in cat_familia]

imp_rendimiento = imp[imp.variable.isin(cat_rendimiento)]["importancia"].sum()
imp_familia = imp[imp.variable.isin(cat_familia)]["importancia"].sum()
imp_general = imp[imp.variable.isin(cat_general)]["importancia"].sum()
imp_total = imp_rendimiento + imp_familia + imp_general

print()
print("=" * 65)
print("IMPORTANCIA POR CATEGORIA CONCEPTUAL")
print("=" * 65)
print(f"  Rendimiento academico (6 vars):  {imp_rendimiento*100:5.2f}%  {'#' * int(imp_rendimiento*200)}")
print(f"  Datos generales  (9 vars):       {imp_general*100:5.2f}%  {'#' * int(imp_general*200)}")
print(f"  Datos familiares (4 vars):       {imp_familia*100:5.2f}%  {'#' * int(imp_familia*200)}")
print(f"  {'-'*45}")
print(f"  TOTAL:                           {imp_total*100:5.2f}%")
print()
print(f"  Rendimiento academico representa el {imp_rendimiento/imp_total*100:.1f}% del poder predictivo total")
print(f"  con solo el {6/19*100:.0f}% de las variables (6 de 19)")

# ============================================================
# PASO 5: Interpretacion
# ============================================================

print()
print("=" * 65)
print("INTERPRETACION")
print("=" * 65)
print(f"""
El rendimiento academico (unidades aprobadas, notas e inscritas de ambos
semestres) concentra el {imp_rendimiento/imp_total*100:.0f}% del poder predictivo del modelo, a pesar de
representar solo el {6/19*100:.0f}% de las variables. Las notas y aprobadas del 2do
semestre son las mas relevantes, lo cual es coherente: un estudiante que
viene arrastrando mal rendimiento desde el primer semestre tiene mayor
probabilidad de desertar. Las variables demographicas y familiares
(estado civil, turno, nivel educativo, ocupacion) aportan marginalmente,
lo que indica que en estos datos el desempeno academico domina la
decision de continuar o abandonar, por encima de factores personales.
""")

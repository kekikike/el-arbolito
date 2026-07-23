import pandas as pd
import numpy as np

df = pd.read_csv("data.csv", sep=";")

# ============================================================
# MAPEOS
# ============================================================

# --- Modalidad de admision -> 5 categorias ---
MODALIDAD_MAP = {
    1: 1,   # 1ra fase - contingente general
    2: 1,   # Ordinancia 612/93 (variante de contingente general)
    5: 1,   # 1ra fase - contingente especial (Acores)
    16: 1,  # 1ra fase - contingente especial (Madeira)
    17: 1,  # 2da fase - contingente general
    18: 1,  # 3ra fase - contingente general
    39: 2,  # Mayor de 23 anos
    15: 3,  # Estudiante internacional
    57: 3,  # Cambio de institucion/curso (internacional)
    42: 4,  # Transferencia
    43: 4,  # Cambio de carrera
    51: 4,  # Cambio de institucion/curso
    7: 5,   # Titulares de otros cursos superiores
    10: 5,  # Ordinancia 854-B/99
    26: 5,  # Plan diferente (Ord. 533-A/99)
    27: 5,  # Otra institucion (Ord. 533-A/99)
    44: 5,  # Diplomado de especializacion tecnologica
    53: 5,  # Diplomado de ciclos cortos
}

MODALIDAD_ETIQUETAS = {
    1: "1ra fase - contingente general",
    2: "Mayor de 23 anos",
    3: "Estudiante internacional",
    4: "Cambio de carrera/institucion",
    5: "Otra via de ingreso",
}

# --- Nivel educativo padres/madres -> 6 categorias ---
# Grupo 1: Sin estudios / no sabe leer (35,36)
# Grupo 2: Educacion basica (26-30, 37,38, 9,10,11,12,14,18-20,22,25,27,29)
# Grupo 3: Educacion secundaria (1,2,3,4,5,6,13,31,33)
# Grupo 4: Educacion superior grado (40,41,42)
# Grupo 5: Postgrado (43,44)
# Grupo 6: Desconocido (34)
EDUCACION_MAP = {
    35: 1, 36: 1,                          # Sin estudios
    9: 2, 10: 2, 11: 2, 12: 2, 14: 2,     # Educacion basica (incompleta)
    18: 2, 19: 2, 20: 2, 22: 2, 25: 2,    # Educacion basica (cursos)
    26: 2, 27: 2, 29: 2, 30: 2,           # Educacion basica (anios escolares)
    37: 2, 38: 2,                          # Educacion basica (ciclos)
    1: 3, 2: 3, 3: 3, 4: 3, 5: 3, 6: 3,   # Secundaria completa
    13: 3, 31: 3, 33: 3,                   # Secundaria (complementarios)
    40: 4, 41: 4, 42: 4,                   # Superior grado
    43: 5, 44: 5,                           # Postgrado
    34: 6,                                  # Desconocido
}

EDUCACION_ETIQUETAS = {
    1: "Sin estudios/no sabe leer",
    2: "Educacion basica",
    3: "Educacion secundaria",
    4: "Educacion superior (grado/licenciatura)",
    5: "Postgrado (maestria/doctorado)",
    6: "Desconocido",
}

# --- Ocupacion -> 5 grupos (ya existente) ---
OCUPACION_MAP = {
    1: 1, 2: 1, 3: 1, 4: 1, 5: 1, 6: 1,
    11: 1, 12: 1, 13: 1, 14: 1, 22: 1,
    9: 2, 10: 2, 18: 2, 19: 2, 20: 2,
    25: 2, 26: 2, 27: 2, 31: 2, 33: 2,
    37: 3, 38: 3, 39: 3, 40: 3, 41: 3, 42: 3, 43: 3, 44: 3,
    29: 4,
    30: 5, 34: 5, 35: 5, 36: 5,
}

OCUPACION_ETIQUETAS = {
    1: "Profesional/tecnico",
    2: "Comerciante/independiente",
    3: "Obrero/operario",
    4: "Desempleado",
    5: "Otro/no especificado",
}

# --- Estado civil ->そのまま (1-6, solo 6 valores) ---
ESTADO_CIVIL_ETIQUETAS = {
    1: "Soltero/a",
    2: "Casado/a",
    3: "Viudo/a",
    4: "Divorciado/a",
    5: "Union de hecho",
    6: "Separado/a legalmente",
}

def mapear(codigo, diccionario, default=99):
    return diccionario.get(codigo, default)

# ============================================================
# GENERAR DATASET
# ============================================================

col_padre = [c for c in df.columns if "Father" in c][0]
col_madre = [c for c in df.columns if "Mother" in c][0]
col_turno = [c for c in df.columns if "Daytime" in c][0]

target_map = {"Dropout": "Abandono", "Enrolled": "Matriculado", "Graduate": "Graduado"}

df_r = pd.DataFrame({
    # Datos generales
    "estado_civil": df["Marital status"].values,
    "modalidad_admision": df["Application mode"].apply(lambda x: mapear(x, MODALIDAD_MAP, 5)).values,
    "carrera": df["Course"].values,
    "turno": df[col_turno].values,
    "genero": df["Gender"].values,
    "internacional": df["International"].values,
    "beca": df["Scholarship holder"].values,
    "desplazado": df["Displaced"].values,
    "pagos_al_dia": df["Tuition fees up to date"].values,
    # Datos familiares
    "nivel_educ_padre": df[col_padre].apply(lambda x: mapear(x, EDUCACION_MAP, 6)).values,
    "nivel_educ_madre": df[col_madre].apply(lambda x: mapear(x, EDUCACION_MAP, 6)).values,
    "ocupacion_padre": df[col_padre].apply(lambda x: mapear(x, OCUPACION_MAP, 5)).values,
    "ocupacion_madre": df[col_madre].apply(lambda x: mapear(x, OCUPACION_MAP, 5)).values,
    # 1er semestre
    "inscritas_1er_sem": df["Curricular units 1st sem (enrolled)"].values,
    "nota_1er_sem": df["Curricular units 1st sem (grade)"].values,
    "aprobadas_1er_sem": df["Curricular units 1st sem (approved)"].values,
    # 2do semestre
    "inscritas_2do_sem": df["Curricular units 2nd sem (enrolled)"].values,
    "nota_2do_sem": df["Curricular units 2nd sem (grade)"].values,
    "aprobadas_2do_sem": df["Curricular units 2nd sem (approved)"].values,
})

df_r["resultado"] = df["Target"].map(target_map)

df_r.to_csv("dataset_reducido.csv", index=False)

# ============================================================
# MOSTRAR MAPEOS COMPLETOS
# ============================================================

print("=" * 70)
print("MAPEO MODALIDAD DE ADMISION")
print("=" * 70)
print("Codigo UCI -> Grupo -> Etiqueta")
print("-" * 50)
for cod in sorted(df["Application mode"].unique()):
    grupo = mapear(cod, MODALIDAD_MAP, 5)
    etiq = MODALIDAD_ETIQUETAS[grupo]
    cant = (df["Application mode"] == cod).sum()
    print(f"  Codigo {cod:2d} -> Grupo {grupo} -> {etiq:35s} ({cant})")

print()
print("=" * 70)
print("MAPEO NIVEL EDUCATIVO PADRES/MADRES")
print("=" * 70)
print("Codigo UCI -> Grupo -> Etiqueta")
print("-" * 50)
todos_codigos = sorted(set(list(df[col_padre].unique()) + list(df[col_madre].unique())))
for cod in todos_codigos:
    grupo = mapear(cod, EDUCACION_MAP, 6)
    etiq = EDUCACION_ETIQUETAS[grupo]
    cant_p = (df[col_padre] == cod).sum()
    cant_m = (df[col_madre] == cod).sum()
    print(f"  Codigo {cod:2d} -> Grupo {grupo} -> {etiq:45s} (P:{cant_p:4d} M:{cant_m:4d})")

print()
print("=" * 70)
print("DISTRIBUCION POR GRUPO")
print("=" * 70)
print()
print("NIVEL EDUCATIVO PADRES:")
for g in sorted(EDUCACION_ETIQUETAS.keys()):
    cant = df[col_padre].apply(lambda x: mapear(x, EDUCACION_MAP, 6)).eq(g).sum()
    print(f"  Grupo {g} - {EDUCACION_ETIQUETAS[g]:45s}: {cant:5d} ({cant/len(df)*100:.1f}%)")
print()
print("NIVEL EDUCATIVO MADRES:")
for g in sorted(EDUCACION_ETIQUETAS.keys()):
    cant = df[col_madre].apply(lambda x: mapear(x, EDUCACION_MAP, 6)).eq(g).sum()
    print(f"  Grupo {g} - {EDUCACION_ETIQUETAS[g]:45s}: {cant:5d} ({cant/len(df)*100:.1f}%)")

print()
print("=" * 70)
print("DATASET GENERADO")
print("=" * 70)
print(f"Filas: {df_r.shape[0]}, Columnas: {df_r.shape[1]}")
print(f"Features: {df_r.shape[1] - 1}")
print(f"Columnas: {list(df_r.columns)}")
print()
print("Distribucion resultado:")
print(df_r["resultado"].value_counts().to_string())

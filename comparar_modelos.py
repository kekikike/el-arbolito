import pandas as pd
import numpy as np
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report

# --- PASO 3: Entrenar modelo reducido (20 features) ---

features_reducidas = [
    "Curricular units 2nd sem (approved)",
    "Curricular units 1st sem (approved)",
    "Curricular units 2nd sem (grade)",
    "Curricular units 1st sem (grade)",
    "Tuition fees up to date",
    "Curricular units 2nd sem (evaluations)",
    "Age at enrollment",
    "Curricular units 1st sem (evaluations)",
    "Course",
    "Admission grade",
    "Curricular units 2nd sem (enrolled)",
    "Scholarship holder",
    "Previous qualification (grade)",
    "Curricular units 1st sem (enrolled)",
    "Application mode",
    "GDP",
    "Father's occupation",
    "Unemployment rate",
    "Mother's occupation",
    "Inflation rate",
]

features_descartadas = [
    "Mother's qualification",
    "Father's qualification",
    "Debtor",
    "Gender",
    "Application order",
    "Curricular units 1st sem (credited)",
    "Displaced",
    "Curricular units 2nd sem (credited)",
    "Previous qualification",
    "Curricular units 1st sem (without evaluations)",
    "Curricular units 2nd sem (without evaluations)",
    "Daytime/evening attendance",
    "Marital status",
    "Nacionality",
    "International",
    "Educational special needs",
]

df = pd.read_csv("data.csv", sep=";")
feature_cols_all = [c for c in df.columns if c != "Target"]

le_target = LabelEncoder()
y = le_target.fit_transform(df["Target"])
class_names = le_target.classes_

# --- Modelo REDUCIDO (20 features) ---
X_red = df[features_reducidas].copy()
for col in X_red.select_dtypes(include="object").columns:
    X_red[col] = LabelEncoder().fit_transform(X_red[col].astype(str))

Xr_train, Xr_test, yr_train, yr_test = train_test_split(
    X_red.values, y, test_size=0.20, random_state=42, stratify=y
)

rf_red = RandomForestClassifier(
    n_estimators=200,
    max_depth=12,
    min_samples_split=10,
    min_samples_leaf=5,
    random_state=42,
    n_jobs=-1,
)
rf_red.fit(Xr_train, yr_train)
yr_pred = rf_red.predict(Xr_test)
acc_red = accuracy_score(yr_test, yr_pred)

print("=" * 70)
print("MODELO REDUCIDO - 20 FEATURES")
print("=" * 70)
print(f"Features usadas: {len(features_reducidas)}")
print(f"Features descartadas: {len(features_descartadas)}")
print(f"Accuracy TEST: {acc_red:.4f}")
print()

print("MATRIZ DE CONFUSION (reducido)")
print("-" * 70)
cm = confusion_matrix(yr_test, yr_pred)
cm_df = pd.DataFrame(cm, index=class_names, columns=class_names)
print(cm_df)
print()

print("PRECISION / RECALL / F1 POR CLASE (reducido)")
print("-" * 70)
print(classification_report(yr_test, yr_pred, target_names=class_names))

# --- PASO 4: Comparacion lado a lado ---

acc_completo = 0.7672  # del explore_data.py

print("=" * 70)
print("TABLA COMPARATIVA")
print("=" * 70)
print()
print(f"{'':30s} {'36 features':>14s} {'20 features':>14s}")
print("-" * 60)
print(f"{'Accuracy test':30s} {acc_completo:>14.4f} {acc_red:>14.4f}")
print(f"{'Features usadas':30s} {'36':>14s} {str(len(features_reducidas)):>14s}")
print(f"{'Features descartadas':30s} {'0':>14s} {str(len(features_descartadas)):>14s}")
print(f"{'Diferencia de accuracy':30s} {'':>14s} {acc_red - acc_completo:>+14.4f}")
print()

if abs(acc_completo - acc_red) < 0.01:
    print("RECOMENDACION: Usar las 20 features reducidas.")
    print("La diferencia de accuracy es menor al 1%. Con 16 features menos,")
    print("el modelo es mas simple, mas rapido, y mas facil de interpretar")
    print("sin sacrificar precision.")
elif acc_completo > acc_red:
    diff = (acc_completo - acc_red) * 100
    print(f"RECOMENDACION: Evaluar si los {diff:.2f}% de accuracy perdidos")
    print("justifican mantener 16 features extra. Para un sistema embebido")
    print("(ESP32), la version reducida seguramente conviene mas.")
else:
    print("RECOMENDACION: Usar las 20 features reducidas.")
    print("El modelo reducido incluso mejora al completo (posible ruido")

# Guardar dataset reducido
df_reducido = df[features_reducidas + ["Target"]].copy()
df_reducido.to_csv("dataset_reducido.csv", index=False)
print()
print(f"Dataset reducido guardado: dataset_reducido.csv ({df_reducido.shape[0]} x {df_reducido.shape[1]})")

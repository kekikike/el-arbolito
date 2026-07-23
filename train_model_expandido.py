import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report
import pickle
from sklearn.preprocessing import LabelEncoder

df = pd.read_csv("dataset_reducido.csv")

X = df.drop("resultado", axis=1)
y = df["resultado"]

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42, stratify=y
)

rf = RandomForestClassifier(
    n_estimators=10,
    max_depth=7,
    min_samples_split=10,
    min_samples_leaf=5,
    random_state=42,
    n_jobs=-1,
)
le = LabelEncoder()
y_encoded = le.fit_transform(y)
rf.fit(X_train, le.transform(y_train))
y_pred_encoded = rf.predict(X_test)
y_pred = le.inverse_transform(y_pred_encoded)
acc = accuracy_score(le.transform(y_test), y_pred_encoded)

print("=" * 60)
print(f"MODELO NUEVO (19 features) - Accuracy: {acc:.4f} ({acc*100:.1f}%)")
print("=" * 60)
print(confusion_matrix(le.transform(y_test), y_pred_encoded, labels=le.transform(["Abandono","Graduado","Matriculado"])))
print(classification_report(le.transform(y_test), y_pred_encoded, labels=le.transform(["Abandono","Graduado","Matriculado"]), target_names=["Abandono","Graduado","Matriculado"]))

importancias = pd.DataFrame({
    "feature": X.columns,
    "importancia": rf.feature_importances_
}).sort_values("importancia", ascending=False)

print("Importancia de features:")
for _, row in importancias.iterrows():
    bar = "#" * int(row["importancia"] * 100)
    print(f"  {row['feature']:25s} {row['importancia']:.4f}  {bar}")

print()
print("=" * 60)
print("COMPARACION CON MODELO ANTERIOR")
print("=" * 60)
print(f"  Modelo viejo (9 features) : 73.1%")
print(f"  Modelo nuevo (19 features): {acc*100:.1f}%")
print(f"  Diferencia: +{(acc*100 - 73.1):.1f}%")

artifact = {
    "model": rf,
    "label_encoder": le,
    "feature_names": list(X.columns),
    "accuracy": float(acc),
    "feature_count": int(X.shape[1]),
    "n_estimators": 10,
    "max_depth": 7,
    "min_samples_split": 10,
    "min_samples_leaf": 5,
    "mapping_modalidad": {1: "1ra fase - contingente general", 2: "Mayor de 23 anos", 3: "Estudiante internacional", 4: "Cambio de carrera/institucion", 5: "Otra via de ingreso"},
    "mapping_educacion": {1: "Sin estudios/no sabe leer", 2: "Educacion basica", 3: "Educacion secundaria", 4: "Educacion superior (grado/licenciatura)", 5: "Postgrado (maestria/doctorado)", 6: "Desconocido"},
    "mapping_ocupacion": {1: "Profesional/tecnico", 2: "Comerciante/independiente", 3: "Obrero/operario", 4: "Desempleado", 5: "Otro/no especificado"},
}

with open("modelo_desercion.pkl", "wb") as f:
    pickle.dump(artifact, f, protocol=4)

print(f"\nModelo guardado en modelo_desercion.pkl ({X.shape[1]} features)")

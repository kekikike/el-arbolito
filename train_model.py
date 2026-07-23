import pandas as pd
import joblib
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report
from sklearn.preprocessing import LabelEncoder
import numpy as np

df = pd.read_csv("dataset_reducido.csv")

feature_cols = [c for c in df.columns if c != "resultado"]
X = df[feature_cols].values
y_raw = df["resultado"].values

le = LabelEncoder()
y = le.fit_transform(y_raw)
class_names = le.classes_

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.20, random_state=42, stratify=y
)

print(f"Train: {X_train.shape[0]} muestras | Test: {X_test.shape[0]} muestras")
print(f"Features: {len(feature_cols)} -> {feature_cols}")
print()

rf = RandomForestClassifier(
    n_estimators=200,
    max_depth=10,
    min_samples_split=10,
    min_samples_leaf=5,
    random_state=42,
    n_jobs=-1,
)
rf.fit(X_train, y_train)

y_train_pred = rf.predict(X_train)
y_test_pred = rf.predict(X_test)

acc_train = accuracy_score(y_train, y_train_pred)
acc_test = accuracy_score(y_test, y_test_pred)

print("=" * 60)
print("RESULTADOS - MODELO 9 FEATURES (traducido)")
print("=" * 60)
print(f"Accuracy TRAIN: {acc_train:.4f}")
print(f"Accuracy TEST:  {acc_test:.4f}")
print(f"Diferencia:     {acc_train - acc_test:.4f}")
print()

if acc_train - acc_test > 0.05:
    print("[!] Posible overfitting: la diferencia train-test es significativa.")
else:
    print("[OK] El modelo generaliza bien: diferencia train-test es pequena.")
print()

print("=" * 60)
print("MATRIZ DE CONFUSION (test)")
print("=" * 60)
cm = confusion_matrix(y_test, y_test_pred)
cm_df = pd.DataFrame(cm, index=class_names, columns=class_names)
print(cm_df)
print()

print("=" * 60)
print("PRECISION / RECALL / F1 POR CLASE (test)")
print("=" * 60)
print(classification_report(y_test, y_test_pred, target_names=class_names))

print("=" * 60)
print("COMPARACION CON MODELOS ANTERIORES")
print("=" * 60)
acc_36 = 0.7672
acc_20 = 0.7718
acc_6 = 0.7322
print(f"  36 features (ingles):  {acc_36:.4f}")
print(f"  20 features (ingles):  {acc_20:.4f}")
print(f"   6 features (espanol): {acc_6:.4f}")
print(f"   9 features (espanol): {acc_test:.4f}")
print()
diff = acc_test - acc_20
if abs(diff) < 0.05:
    print(f"[OK] Diferencia vs mejor modelo anterior: {diff:+.4f}")
    print("    El modelo de 9 features mantiene rendimiento competitivo.")
else:
    print(f"[!] Diferencia vs mejor modelo anterior: {diff:+.4f}")
print()

importances = rf.feature_importances_
ranking = pd.Series(importances, index=feature_cols).sort_values(ascending=False)
print("IMPORTANCIA DE FEATURES:")
for feat, imp in ranking.items():
    print(f"  {feat:25s} {imp:.4f}")

model_artifact = {
    "model": rf,
    "label_encoder": le,
    "feature_cols": feature_cols,
    "accuracy_test": acc_test,
}
joblib.dump(model_artifact, "modelo_desercion.pkl")
print()
print("Modelo guardado en modelo_desercion.pkl")

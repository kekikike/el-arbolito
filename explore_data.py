import pandas as pd
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder
from sklearn.metrics import accuracy_score
import numpy as np

df = pd.read_csv("data.csv", sep=";")

print("=" * 70)
print("DISTRIBUCION DE LA COLUMNA OBJETIVO (Target)")
print("=" * 70)
print(df["Target"].value_counts().to_string())
print()
print("Proporciones:")
print(df["Target"].value_counts(normalize=True).round(4).to_string())
print()

feature_cols = [c for c in df.columns if c != "Target"]
X = df[feature_cols].copy()

for col in X.select_dtypes(include="object").columns:
    X[col] = LabelEncoder().fit_transform(X[col].astype(str))

le_target = LabelEncoder()
y = le_target.fit_transform(df["Target"])

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.20, random_state=42, stratify=y
)

print(f"Split: {X_train.shape[0]} train / {X_test.shape[0]} test")
print(f"Features totales: {X.shape[1]}")
print()

rf = RandomForestClassifier(
    n_estimators=200,
    max_depth=12,
    min_samples_split=10,
    min_samples_leaf=5,
    random_state=42,
    n_jobs=-1,
)
rf.fit(X_train, y_train)

y_pred = rf.predict(X_test)
acc_test = accuracy_score(y_test, y_pred)

print("=" * 70)
print(f"RANDOM FOREST CON 36 FEATURES - ACCURACY TEST: {acc_test:.4f}")
print("=" * 70)
print()

importances = rf.feature_importances_
ranking = pd.Series(importances, index=feature_cols).sort_values(ascending=False)

print("=" * 70)
print("RANKING COMPLETO DE IMPORTANCIA (36 features)")
print("=" * 70)
cumsum = 0.0
for i, (feat, imp) in enumerate(ranking.items(), 1):
    cumsum += imp
    print(f"{i:2d}. {feat:55s} {imp:.4f}  (acum: {cumsum:.4f})")

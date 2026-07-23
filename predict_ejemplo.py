import joblib
import numpy as np

artifact = joblib.load("modelo_desercion.pkl")
model = artifact["model"]
le = artifact["label_encoder"]
feature_cols = artifact["feature_cols"]

ejemplo = {
    "Curricular units 2nd sem (approved)": 5,
    "Curricular units 1st sem (approved)": 6,
    "Curricular units 2nd sem (grade)": 13.5,
    "Curricular units 1st sem (grade)": 14.0,
    "Tuition fees up to date": 1,
    "Curricular units 2nd sem (evaluations)": 6,
    "Age at enrollment": 19,
    "Curricular units 1st sem (evaluations)": 6,
    "Course": 9119,
    "Admission grade": 140.0,
    "Curricular units 2nd sem (enrolled)": 6,
    "Scholarship holder": 1,
    "Previous qualification (grade)": 130.0,
    "Curricular units 1st sem (enrolled)": 6,
    "Application mode": 1,
    "GDP": 1.74,
    "Father's occupation": 9,
    "Unemployment rate": 10.8,
    "Mother's occupation": 5,
    "Inflation rate": 1.4,
}

X_new = np.array([[ejemplo[f] for f in feature_cols]])
pred = model.predict(X_new)
prob = model.predict_proba(X_new)

print("Features de entrada:")
for k, v in ejemplo.items():
    print(f"  {k}: {v}")
print()

pred_label = le.inverse_transform(pred)[0]
print(f"Prediccion: {pred_label}")
print()
print("Probabilidades por clase:")
for cls, p in zip(le.classes_, prob[0]):
    print(f"  {cls}: {p:.3f}")

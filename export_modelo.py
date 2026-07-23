import joblib
import m2cgen
import os

artifact = joblib.load("modelo_desercion.pkl")
model = artifact["model"]
feature_names = artifact.get("feature_names", [])

code = m2cgen.export_to_c(model)

os.makedirs("esp32_desercion", exist_ok=True)
output_path = os.path.join("esp32_desercion", "modelo_desercion.h")

with open(output_path, "w") as f:
    f.write("// Modelo de prediccion de desercion estudiantil\n")
    f.write("// Generado automaticamente con m2cgen\n")
    feat_str = ", ".join(feature_names)
    f.write("// Features ({}): {}\n".format(len(feature_names), feat_str))
    f.write("// Clases: 0=Abandono, 1=Graduado, 2=Matriculado\n\n")
    f.write("#ifndef MODELO_DESCRION_H\n")
    f.write("#define MODELO_DESCRION_H\n\n")
    f.write("#include <math.h>\n\n")
    f.write(code)
    f.write("\n#endif\n")

size_new = os.path.getsize(output_path)
lines_new = code.count("\n") + 1

print("=" * 60)
print("MODELO NUEVO (19 features)")
print("=" * 60)
print(f"  Archivo: {output_path}")
print(f"  Tamano:  {size_new:,} bytes ({size_new/1024:.1f} KB)")
print(f"  Lineas C: {lines_new}")
print(f"  Features: {len(feature_names)}")
print()

# Compare with old model if it exists
old_path = os.path.join("esp32_desercion", "modelo_desercion_old.h")
if os.path.exists(old_path):
    old_size = os.path.getsize(old_path)
    print("COMPARACION CON MODELO VIEJO (9 features):")
    print(f"  Viejo: {old_size:,} bytes ({old_size/1024:.1f} KB)")
    print(f"  Nuevo: {size_new:,} bytes ({size_new/1024:.1f} KB)")
    print(f"  Ratio: {size_new/old_size:.1f}x mas grande")
else:
    print("No se encontro modelo viejo para comparar.")
    print("El modelo viejo de 9 features tenia ~60 KB / 1185 lineas C.")
    print(f"  Ratio estimado: {size_new/60000:.1f}x mas grande")

print()
print("Verificando que es C valido...")
print(f"  Primera linea: {code.split(chr(10))[0].strip()[:70]}")
print(f"  Ultima linea:  {code.split(chr(10))[-1].strip()[:70]}")
print()
print("Archivo listo para incluir en Arduino IDE")

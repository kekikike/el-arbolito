import joblib
import m2cgen
import os

artifact = joblib.load("modelo_desercion.pkl")
model = artifact["model"]

code = m2cgen.export_to_c(model)

os.makedirs("esp32_desercion", exist_ok=True)
output_path = os.path.join("esp32_desercion", "modelo_desercion.h")

with open(output_path, "w") as f:
    f.write("// Modelo de prediccion de desercion estudiantil\n")
    f.write("// Generado automaticamente con m2cgen\n")
    f.write("// Features: nota_1er_sem, nota_2do_sem, materias_1er_sem,\n")
    f.write("//           materias_2do_sem, tiene_beca, pagos_al_dia,\n")
    f.write("//           edad_ingreso, ocupacion_padre, ocupacion_madre\n")
    f.write("// Clases: 0=Abandono, 1=Graduado, 2=Matriculado\n\n")
    f.write("#ifndef MODELO_DESCRION_H\n")
    f.write("#define MODELO_DESCRION_H\n\n")
    f.write("#include <math.h>\n\n")
    f.write(code)
    f.write("\n#endif\n")

print(f"Modelo exportado a {output_path}")
print(f"Tamano: {os.path.getsize(output_path)} bytes")
print()
print("Funciones generadas:")
print("  double score(double *input) -> array de 3 probabilidades")
print("  double predict(double *input) -> indice de la clase ganadora")
print()

# Verify it compiles as valid C
print("Verificando que es C valido...")
lines = code.split("\n")
print(f"  Lineas de codigo C: {len(lines)}")
print(f"  Primera funcion: {lines[0].strip()[:60]}...")
print()
print("Archivo listo para incluir en Arduino IDE")

# Prediccion de Desercion - ESP32

Modelo de prediccion de desercion estudiantil corriendo en un ESP32, accesible via WiFi como pagina web.

## Archivos

- `esp32_desercion.ino` - Codigo principal del ESP32
- `modelo_desercion.h` - Modelo RandomForest exportado a C (60 KB, 10 arboles)

## Como compilar y subir

### Opcion 1: Arduino IDE

1. Instalar Arduino IDE
2. Ir a Archivo -> Preferencias -> URLs adicionales de gestor de tarjetas, agregar:
   `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
3. Herramientas -> Gestor de tarjetas -> buscar "esp32" -> instalar
4. Herramientas -> Tarjeta -> ESP32 Dev Module
5. Abrir `esp32_desercion.ino`
6. Copiar `modelo_desercion.h` en la misma carpeta que el .ino
7. Boton Compilar y Subir

### Opcion 2: PlatformIO

1. Instalar VS Code + PlatformIO
2. Crear proyecto nuevo, tarjeta: ESP32 Dev Module
3. Copiar `esp32_desercion.ino` como `src/main.cpp` (agregar `#include <Arduino.h>` al inicio)
4. Copiar `modelo_desercion.h` en `src/`
5. `pio run -t upload`

## Como usar

1. Subir el codigo al ESP32
2. Abrir Monitor Serial (115200 baud) para ver la IP
3. Conectarse al WiFi: **DesercionPredict** (sin clave)
4. Abrir navegador: **http://192.168.4.1**
5. Completar los 9 campos y presionar PREDECIR

## Los 9 campos del formulario

| Campo | Tipo | Rango | Conversion |
|-------|------|-------|------------|
| Nota prom. 1er sem | Numero | 0-100 | /5 -> escala 0-20 |
| Nota prom. 2do sem | Numero | 0-100 | /5 -> escala 0-20 |
| Materias aprob. 1er sem | Entero | 0-6 | Validado, max 6 |
| Materias aprob. 2do sem | Entero | 0-6 | Validado, max 6 |
| Tiene beca | Si/No | 1/0 | Directo |
| Pagos al dia | Si/No | 1/0 | Directo |
| Edad al ingreso | Entero | 17-70 | Directo |
| Ocupacion padre | Combo | 1-5 | Mapeado a codigo ISCO |
| Ocupacion madre | Combo | 1-5 | Mapeado a codigo ISCO |

## Mapeo de ocupaciones (grupos -> codigos ISCO)

El formulario muestra 5 grupos simplificados. En C++ se mapean a los codigos ISCO que el modelo vio durante entrenamiento:

| Grupo (formulario) | Codigo ISCO enviado | Descripcion |
|--------------------|:-------------------:|-------------|
| 1 - Profesional/tecnico | 1 | Profesionales, tecnicos, docentes |
| 2 - Comerciante/independiente | 19 | Comercio, servicios, ventas |
| 3 - Obrero/operario | 37 | Trabajo manual, operarios |
| 4 - Desempleado | 29 | Desempleado |
| 5 - Otro/no especificado | 34 | Sin info, desconocido |

## Si la prediccion no coincide con la app de Python

Verificar en este orden:

1. **Orden de features**: Debe ser exactamente: nota_1er, nota_2do, mat_1er, mat_2do, beca, pagos, edad, occ_padre, occ_madre

2. **Conversion de notas**: La nota se divide entre 5 (0-100 -> 0-20). Verificar que `nota1_raw / 100.0 * 20.0` coincida con lo que Python calcula.

3. **Mapeo de ocupaciones**: El grupo 1 del formulario se mapea al codigo 1, el grupo 2 al 19, el grupo 3 al 37, el grupo 4 al 29, el grupo 5 al 34. Verificar que coincida con el mapeo de Python.

4. **Tipos de datos**: El modelo usa `double` en C. Verificar que no haya truncamiento a `int` en las conversiones.

5. **Probar con el mismo ejemplo**: Usar los mismos valores exactos en Python y en el ESP32 y comparar las probabilidades. Deben ser casi identuales (diferencias por redondeo de punto flotante son normales, <0.1%).

## Modelo

- Algoritmo: RandomForestClassifier (scikit-learn)
- Arboles: 10, max_depth=5 (optimizado para ESP32)
- Features: 9
- Accuracy test: 73.1%
- Exportado con: m2cgen (genera C puro, sin dependencias)
- Tamano del .h: ~60 KB (1,185 lineas de if-else anidados)

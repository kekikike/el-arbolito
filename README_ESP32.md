# Prediccion de Desercion - ESP32

Modelo RandomForest (19 features, 10 arboles, depth 5) corriendo en un ESP32, accesible via WiFi como pagina web.

## Archivos

- `esp32_desercion.ino` - Codigo principal (WiFi AP + servidor + formulario + handler)
- `modelo_desercion.h` - Modelo exportado a C con m2cgen (~60 KB)

## Tamano total

```
esp32_desercion.ino: 400 lineas, 15 KB
modelo_desercion.h:  1193 lineas, 59 KB
TOTAL:               1593 lineas, 75 KB
```

El modelo con 19 features ocupa practicamente lo mismo que el de 9 features (~60 KB) porque `max_depth=5` limita la profundidad de los arboles independientemente de cuantas features haya.

## Como compilar y subir

### Arduino IDE

1. Instalar Arduino IDE
2. Archivo -> Preferencias -> URLs adicionales:
   `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
3. Herramientas -> Gestor de tarjetas -> buscar "esp32" -> instalar
4. Herramientas -> Tarjeta -> ESP32 Dev Module
5. Abrir `esp32_desercion.ino`
6. Copiar `modelo_desercion.h` en la misma carpeta
7. Compilar y subir

### PlatformIO

1. VS Code + PlatformIO
2. Proyecto nuevo, tarjeta: ESP32 Dev Module
3. `esp32_desercion.ino` como `src/main.cpp` (agregar `#include <Arduino.h>`)
4. `modelo_desercion.h` en `src/`
5. `pio run -t upload`

## Como usar

1. Subir al ESP32
2. Monitor Serial (115200 baud) para ver la IP
3. Conectarse al WiFi: **DesercionPredict** (sin clave)
4. Abrir: **http://192.168.4.1**
5. Completar los 19 campos y presionar PREDECIR

## Los 19 campos del formulario

### Datos generales (9 campos)

| Campo | Tipo | Opciones |
|-------|------|----------|
| Estado civil | Combo (6) | Soltero/a, Casado/a, Viudo/a, Divorciado/a, Union de hecho, Separado/a legalmente |
| Modalidad de admision | Combo (5) | 1ra fase, Mayor de 23, Internacional, Cambio de carrera, Otra via |
| Carrera | Combo (17) | Las 17 carreras UCI en espanol |
| Turno | Radio | Diurno / Vespertino |
| Genero | Radio | Masculino / Femenino |
| Internacional | Radio | Si / No |
| Tiene beca | Radio | Si / No |
| Desplazado | Radio | Si / No (hint: "Se mudó de su residencia habitual para estudiar") |
| Pagos al dia | Radio | Si / No |

### Datos familiares (4 campos)

| Campo | Tipo | Opciones |
|-------|------|----------|
| Nivel educativo del padre | Combo (6) | Sin estudios, Basica, Secundaria, Superior, Postgrado, Desconocido |
| Nivel educativo de la madre | Combo (6) | Mismas 6 |
| Ocupacion del padre | Combo (5) | Profesional, Comerciante, Obrero, Desempleado, Otro |
| Ocupacion de la madre | Combo (5) | Mismas 5 |

### Rendimiento academico (6 campos)

| Campo | Tipo | Rango | Conversion |
|-------|------|-------|------------|
| Unidades inscritas 1er sem | Numero | 0-6 | Maximo 6, validado |
| Nota promedio 1er sem | Numero | 0-100 | /5 -> escala 0-20 |
| Unidades aprobadas 1er sem | Numero | 0-6 | Maximo 6, validado |
| Unidades inscritas 2do sem | Numero | 0-6 | Maximo 6, validado |
| Nota promedio 2do sem | Numero | 0-100 | /5 -> escala 0-20 |
| Unidades aprobadas 2do sem | Numero | 0-6 | Maximo 6, validado |

## Mapeos completos (HTML value -> Codigo modelo)

### Modalidad de admision

| HTML value | Etiqueta | Codigo modelo |
|:----------:|----------|:-------------:|
| 1 | 1ra fase - contingente general | 1 |
| 2 | Mayor de 23 anos | 39 |
| 3 | Estudiante internacional | 15 |
| 4 | Cambio de carrera/institucion | 42 |
| 5 | Otra via de ingreso | 7 |

### Nivel educativo (padres y madre)

| HTML value | Etiqueta | Codigo modelo |
|:----------:|----------|:-------------:|
| 1 | Sin estudios/no sabe leer | 35 |
| 2 | Educacion basica | 37 |
| 3 | Educacion secundaria | 1 |
| 4 | Educacion superior (grado/licenciatura) | 40 |
| 5 | Postgrado (maestria/doctorado) | 43 |
| 6 | Desconocido | 34 |

### Ocupacion (padres y madre)

| HTML value | Etiqueta | Codigo modelo |
|:----------:|----------|:-------------:|
| 1 | Profesional/tecnico | 1 |
| 2 | Comerciante/independiente | 19 |
| 3 | Obrero/operario | 37 |
| 4 | Desempleado | 29 |
| 5 | Otro/no especificado | 34 |

### Carrera (sin mapeo, codigo UCI directo)

| HTML value | Etiqueta |
|:----------:|----------|
| 33 | Tecnologias de biocombustibles |
| 171 | Animacion y diseno multimedia |
| 8014 | Servicio social (vespertino) |
| 9003 | Agronomia |
| 9070 | Diseno de comunicacion |
| 9085 | Enfermeria veterinaria |
| 9119 | Ingenieria informatica |
| 9130 | Equinicultura |
| 9147 | Gestion |
| 9238 | Servicio social |
| 9254 | Turismo |
| 9500 | Enfermeria |
| 9556 | Higiene oral |
| 9670 | Gestion publicidad y marketing |
| 9773 | Periodismo y comunicacion |
| 9853 | Educacion basica |
| 9991 | Gestion (vespertino) |

## Orden del vector de entrada

El modelo espera los 19 features en este orden exacto:

```
[0]  estado_civil        (1-6, directo)
[1]  modalidad_admision  (mapeada: 1,39,15,42,7)
[2]  carrera             (codigo UCI directo)
[3]  turno               (1=diurno, 0=vespertino)
[4]  genero              (1=masculino, 0=femenino)
[5]  internacional       (1/0)
[6]  beca                (1/0)
[7]  desplazado          (1/0)
[8]  pagos_al_dia        (1/0)
[9]  nivel_educ_padre    (mapeada: 35,37,1,40,43,34)
[10] nivel_educ_madre    (mapeada: 35,37,1,40,43,34)
[11] ocupacion_padre     (mapeada: 1,19,37,29,34)
[12] ocupacion_madre     (mapeada: 1,19,37,29,34)
[13] inscritas_1er_sem   (0-6)
[14] nota_1er_sem        (0-20, convertida de /5)
[15] aprobadas_1er_sem   (0-6)
[16] inscritas_2do_sem   (0-6)
[17] nota_2do_sem        (0-20, convertida de /5)
[18] aprobadas_2do_sem   (0-6)
```

## Respuesta JSON

```json
{
  "clase": "Graduado",
  "abandono": 0.0870,
  "graduado": 0.7680,
  "matriculado": 0.1450
}
```

## Si aparece "dangerous relocation: l32r"

Este error ocupa cuando el .h es demasiado grande para el linker del ESP32. Pasos concretos:

### Opcion 1: Bajar n_estimators (recomendado primero)

En Python, cambiar `n_estimators=10` a `n_estimators=5` y reentrenar:

```python
rf = RandomForestClassifier(n_estimators=5, max_depth=5, ...)
```

Luego re-exportar con m2cgen. Cada arbol reduce ~6 KB, asi que 5 arboles = ~30 KB.

### Opcion 2: Bajar max_depth

```python
rf = RandomForestClassifier(n_estimators=10, max_depth=3, ...)
```

Esto reduce la profundidad de cada arbol, generando menos if-else. Impacto en accuracy: probar y comparar.

### Opcion 3: Combinar ambas

```python
rf = RandomForestClassifier(n_estimators=5, max_depth=4, ...)
```

### Opcion 4: Migrar a emlearn

Si m2cgen sigue generando archivos muy grandes, usar la libreria [emlearn](https://github.com/emlearn-micropython/emlearn):

```python
import emlearn
c_code = emlearn.convert(rf, kind='classifier')
```

emlearn genera codigo C mas compacto y esta optimizado para microcontroladores. Requiere cambiar el .ino para usar las funciones de emlearn en vez de `score()`.

## Si la prediccion no coincide con Python

1. Verificar el **orden de features** (comentario en el .ino, linea por linea)
2. Verificar los **mapeos** (tablas arriba,对照 linea por linea contra `generar_dataset_reducido.py`)
3. Verificar la **conversion de notas** (/5)
4. Verificar que **no haya truncamiento** a int en C (usar `toFloat()` no `toInt()`)
5. Probar con el **mismo ejemplo** en Python y ESP32, comparar probabilidades (deben ser <0.1% diferentes)

## Modelo

- Algoritmo: RandomForestClassifier (scikit-learn)
- Arboles: 10, max_depth=5
- Features: 19
- Accuracy test: 74.2%
- Exportado con: m2cgen
- Tamano del .h: ~60 KB (1193 lineas)

# Interfaz de Escritorio - Prediccion de Desercion Estudiantil

Aplicacion grafica en Tkinter con 19 campos de entrada organizados en 4 secciones, todo en espanol.

## Como correr

```bash
python app_interfaz.py
```

Requiere `modelo_desercion.pkl` (generado por `train_model_expandido.py`).

## Secciones del formulario

### 1. Datos generales (9 campos)

| Campo | Tipo | Opciones/Validacion |
|-------|------|---------------------|
| Estado civil | Combo (6) | Soltero/a, Casado/a, Viudo/a, Divorciado/a, Union de hecho, Separado/a legalmente |
| Modalidad de admision | Combo (5) | 1ra fase, Mayor de 23 anos, Internacional, Cambio de carrera, Otra via |
| Carrera | Combo (17) | Las 17 carreras del dataset UCI (sin agrupar) |
| Turno | Radio | Diurno / Vespertino |
| Genero | Radio | Masculino / Femenino |
| Estudiante internacional | Radio | Si / No |
| Tiene beca | Radio | Si / No |
| Desplazado | Radio | Si / No (ver nota abajo) |
| Pagos al dia | Radio | Si / No |

**Nota sobre "Desplazado":** El campo incluye un tooltip que explica: "Se mudó de su residencia habitual para estudiar".

### 2. Datos familiares (4 campos)

| Campo | Tipo | Opciones |
|-------|------|----------|
| Nivel educativo del padre | Combo (6) | Sin estudios, Basica, Secundaria, Superior, Postgrado, Desconocido |
| Nivel educativo de la madre | Combo (6) | Mismas 6 opciones |
| Ocupacion del padre | Combo (5) | Profesional, Comerciante, Obrero, Desempleado, Otro |
| Ocupacion de la madre | Combo (5) | Mismas 5 opciones |

### 3. 1er semestre (3 campos)

| Campo | Tipo | Validacion |
|-------|------|------------|
| Unidades inscritas | Entry entero | 0-6 (MATERIAS_POR_SEMESTRE) |
| Nota promedio | Entry decimal | 0-100 (dividido entre 5 para el modelo) |
| Unidades aprobadas | Entry entero | 0-6 (MATERIAS_POR_SEMESTRE) |

### 4. 2do semestre (3 campos)

Mismos 3 campos que el 1er semestre.

## Conversion de notas

El usuario ingresa notas en escala 0-100 (boliviana). El modelo usa escala 0-20.

```
nota_modelo = nota_usuario / 100 * 20
Ejemplo: 70 -> 14.0
```

## Validacion de unidades (maximo 6)

La constante `MATERIAS_POR_SEMESTRE = 6` limita las unidades inscritas y aprobadas en ambos semestres. Si el usuario ingresa mas de 6, aparece un aviso de error.

## Regla automatica de deudor

El campo "Deudor" NO aparece en la interfaz. Se calcula automaticamente a partir de "Pagos al dia":

```
pagos_al_dia = Si  -> deudor = No (0)
pagos_al_dia = No  -> deudor = Si (1)
```

Sin embargo, "deudor" no esta incluido como feature del modelo actual (19 features), por lo que este calculo no afecta la prediccion. Se mantiene como referencia.

## Tablas de mapeo

### Modalidad de admision (5 grupos)

| Grupo | Etiqueta | Codigos UCI | Cantidad |
|-------|----------|-------------|----------|
| 1 | 1ra fase - contingente general | 1, 2, 5, 16, 17, 18 | 2761 |
| 2 | Mayor de 23 anos | 39 | 785 |
| 3 | Estudiante internacional | 15, 57 | 31 |
| 4 | Cambio de carrera/institucion | 42, 43, 51 | 448 |
| 5 | Otra via de ingreso | 7, 10, 26, 27, 44, 53 | 399 |

### Nivel educativo padres/madres (6 grupos)

| Grupo | Etiqueta | Codigos UCI (ejemplos) |
|-------|----------|------------------------|
| 1 | Sin estudios/no sabe leer | 35, 36 |
| 2 | Educacion basica | 9-12, 14, 18-20, 22, 25-27, 29-30, 37-38 |
| 3 | Educacion secundaria | 1-6, 13, 31, 33 |
| 4 | Educacion superior (grado/licenciatura) | 40, 41, 42 |
| 5 | Postgrado (maestria/doctorado) | 43, 44 |
| 6 | Desconocido | 34, 39 |

Distribucion padres: 66.8% basica, 29.7% secundaria, 3.0% desconocido.
Distribucion madres: 58.6% basica, 37.6% secundaria, 3.1% desconocido.

### Ocupacion padres/madres (5 grupos)

| Grupo | Etiqueta | Codigos UCI |
|-------|----------|-------------|
| 1 | Profesional/tecnico | 1-6, 11-14, 22 |
| 2 | Comerciante/independiente | 9-10, 18-20, 25-27, 31, 33 |
| 3 | Obrero/operario | 37-44 |
| 4 | Desempleado | 29 |
| 5 | Otro/no especificado | 30, 34-36 |

### Carrera (17 opciones, sin agrupar)

Codigos UCI: 33, 171, 8014, 9003, 9070, 9085, 9119, 9130, 9147, 9238, 9254, 9500, 9556, 9670, 9773, 9851, 9991.

## Botones

- **PREDECIR**: Aplica todas las conversiones y muestra prediccion con probabilidades.
- **Cargar ejemplo**: Rellena todos los campos con un estudiante ejemplo (soltero, 1ra fase, Ing. Informatica, diurno, masculino, no internacional, becado, desplazado, pagos al dia, padre basica/madre secundaria, obreros, 6 inscritas, nota 70/67.5, 5 aprobadas).
- **Limpiar**: Borra todos los campos.

## Precision del modelo

| Modelo | Features | Accuracy |
|--------|:--------:|:--------:|
| Original (ingles, 36 feat) | 36 | 76.7% |
| Reducido (ingles, 20 feat) | 20 | 77.2% |
| Traducido (6 feat) | 6 | 73.2% |
| Modelo 1 (9 feat, espanol) | 9 | 73.1% |
| **Modelo 2 (19 feat, espanol)** | **19** | **74.2%** |

El modelo de 19 features mejora +1.1% contra el de 9 features, sumando informacion demografica y academica sin perder compatibilidad con ESP32.

## Importancia de features (modelo 19 feat)

```
aprobadas_2do_sem         0.2390  #######################
aprobadas_1er_sem         0.2141  #####################
nota_1er_sem              0.1656  ################
nota_2do_sem              0.1344  #############
pagos_al_dia              0.0649  ######
beca                      0.0434  ####
inscritas_1er_sem         0.0325  ###
carrera                   0.0322  ###
inscritas_2do_sem         0.0254  ##
genero                    0.0231  ##
modalidad_admision        0.0075
nivel_educ_madre          0.0038
desplazado                0.0037
ocupacion_madre           0.0037
ocupacion_padre           0.0035
nivel_educ_padre          0.0020
estado_civil              0.0013
turno                     0.0000
internacional             0.0000
```

Las notas y aprobadas siguen siendo dominantes (~75% de importancia). Las nuevas features suman ~2.5% adicional.

## Columnas del dataset

| Original (ingles) | Traducida (espanol) | Tipo |
|-------------------|---------------------|------|
| Marital status | estado_civil | 1-6 |
| Application mode | modalidad_admision | 1-5 (agrupada) |
| Course | carrera | 17 opciones |
| Daytime/evening attendance | turno | 0/1 |
| Gender | genero | 0/1 |
| International | internacional | 0/1 |
| Scholarship holder | beca | 0/1 |
| Displaced | desplazado | 0/1 |
| Tuition fees up to date | pagos_al_dia | 0/1 |
| Father's qualification | nivel_educ_padre | 1-6 (agrupada) |
| Mother's qualification | nivel_educ_madre | 1-6 (agrupada) |
| Father's occupation | ocupacion_padre | 1-5 (agrupada) |
| Mother's occupation | ocupacion_madre | 1-5 (agrupada) |
| Curricular units 1st sem (enrolled) | inscritas_1er_sem | 0-6 |
| Curricular units 1st sem (grade) | nota_1er_sem | 0-20 |
| Curricular units 1st sem (approved) | aprobadas_1er_sem | 0-6 |
| Curricular units 2nd sem (enrolled) | inscritas_2do_sem | 0-6 |
| Curricular units 2nd sem (grade) | nota_2do_sem | 0-20 |
| Curricular units 2nd sem (approved) | aprobadas_2do_sem | 0-6 |
| Target | resultado | Abandono/Matriculado/Graduado |

## Archivos

- `app_interfaz.py` - Interfaz grafica (19 campos, 4 secciones)
- `modelo_desercion.pkl` - Modelo entrenado (19 features, 10 arboles, depth 5)
- `dataset_reducido.csv` - Dataset traducido (4424 filas, 20 columnas)
- `train_model_expandido.py` - Entrena y guarda el modelo
- `generar_dataset_reducido.py` - Genera dataset desde data.csv con todos los mapeos

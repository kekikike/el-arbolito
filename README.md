# Prediccion de Desercion Estudiantil

Modelo de machine learning para predecir si un estudiante va a desertar, seguir inscrito o graduarse, usando el dataset "Predict Students Dropout and Academic Success" de UCI.

## Pipeline completo

| Paso | Script | Descripcion |
|------|--------|-------------|
| 1 | `explore_data.py` | Explora las 36 features, muestra ranking completo |
| 2 | `comparar_modelos.py` | Compara 36 vs 20 features |
| 3 | `generar_dataset_reducido.py` | Genera `dataset_reducido.csv` con 19 features en espanol |
| 4 | `train_model_expandido.py` | Entrena RandomForest (10 arboles, depth 5), guarda pkl |
| 5 | `app_interfaz.py` | Interfaz Tkinter con 19 campos, 4 secciones |
| 6 | `esp32_desercion/` | Port a ESP32 como herramienta web WiFi |

## Evolucion del modelo

| Modelo | Features | Accuracy |
|--------|:--------:|:--------:|
| Original (36 feat, ingles) | 36 | 76.7% |
| Reducido (20 feat, ingles) | 20 | 77.2% |
| Traducido (6 feat) | 6 | 73.2% |
| Modelo 1 (9 feat, espanol) | 9 | 73.1% |
| **Modelo 2 (19 feat, espanol)** | **19** | **74.2%** |

## Features del modelo final (19)

### Datos generales
| Feature | Tipo | Valores |
|---------|------|---------|
| estado_civil | Entero | 1-6 (6 categorias) |
| modalidad_admision | Entero | 1-5 (agrupada) |
| carrera | Entero | 17 carreras UCI |
| turno | Binario | 1=diurno, 0=vespertino |
| genero | Binario | 1=masculino, 0=femenino |
| internacional | Binario | 1/0 |
| beca | Binario | 1/0 |
| desplazado | Binario | 1/0 |
| pagos_al_dia | Binario | 1/0 |

### Datos familiares
| Feature | Tipo | Valores |
|---------|------|---------|
| nivel_educ_padre | Entero | 1-6 (agrupada) |
| nivel_educ_madre | Entero | 1-6 (agrupada) |
| ocupacion_padre | Entero | 1-5 (agrupada) |
| ocupacion_madre | Entero | 1-5 (agrupada) |

### Semestres
| Feature | Tipo | Valores |
|---------|------|---------|
| inscritas_1er_sem | Entero | 0-6 |
| nota_1er_sem | Float | 0-20 (nota/5) |
| aprobadas_1er_sem | Entero | 0-6 |
| inscritas_2do_sem | Entero | 0-6 |
| nota_2do_sem | Float | 0-20 (nota/5) |
| aprobadas_2do_sem | Entero | 0-6 |

## Importancia de features

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
```

## Como correr

```bash
pip install pandas scikit-learn joblib

# Generar dataset
python generar_dataset_reducido.py

# Entrenar modelo
python train_model_expandido.py

# Interfaz de escritorio
python app_interfaz.py
```

## Archivos principales

- `data.csv` - Dataset original UCI (4424 muestras, 36 features)
- `dataset_reducido.csv` - Dataset traducido y agrupado (19 features + resultado)
- `modelo_desercion.pkl` - Modelo serializado (19 features, 10 arboles, depth 5)
- `app_interfaz.py` - Interfaz grafica Tkinter (19 campos, 4 secciones)
- `train_model_expandido.py` - Entrena y guarda el modelo
- `generar_dataset_reducido.py` - Genera dataset desde data.csv
- `explore_data.py` - Explora las 36 features originales
- `comparar_modelos.py` - Compara 36 vs 20 features
- `predict_ejemplo.py` - Ejemplo de prediccion end-to-end
- `esp32_desercion/` - Port a ESP32 como herramienta web WiFi

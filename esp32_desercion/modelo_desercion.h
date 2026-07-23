// Modelo de prediccion de desercion estudiantil
// Generado automaticamente con m2cgen
// Features (19): estado_civil, modalidad_admision, carrera, turno, genero, internacional, beca, desplazado, pagos_al_dia, nivel_educ_padre, nivel_educ_madre, ocupacion_padre, ocupacion_madre, inscritas_1er_sem, nota_1er_sem, aprobadas_1er_sem, inscritas_2do_sem, nota_2do_sem, aprobadas_2do_sem
// Clases: 0=Abandono, 1=Graduado, 2=Matriculado

#ifndef MODELO_DESCRION_H
#define MODELO_DESCRION_H

#include <math.h>

#include <string.h>
void add_vectors(double *v1, double *v2, int size, double *result) {
    for(int i = 0; i < size; ++i)
        result[i] = v1[i] + v2[i];
}
void mul_vector_number(double *v1, double num, int size, double *result) {
    for(int i = 0; i < size; ++i)
        result[i] = v1[i] * num;
}
void score(double * input, double * output) {
    double var0[3];
    double var1[3];
    double var2[3];
    double var3[3];
    double var4[3];
    double var5[3];
    double var6[3];
    double var7[3];
    double var8[3];
    double var9[3];
    double var10[3];
    if (input[14] <= 10.083333492279053) {
        if (input[17] <= 5.0) {
            if (input[8] <= 0.5) {
                if (input[11] <= 1.5) {
                    if (input[2] <= 9192.5) {
                        if (input[1] <= 3.0) {
                            memcpy(var10, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                        } else {
                            memcpy(var10, (double[]){0.7272727272727273, 0.0, 0.2727272727272727}, 3 * sizeof(double));
                        }
                    } else {
                        memcpy(var10, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    if (input[13] <= 2.0) {
                        memcpy(var10, (double[]){0.8181818181818182, 0.09090909090909091, 0.09090909090909091}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[6] <= 0.5) {
                    if (input[10] <= 3.5) {
                        if (input[1] <= 1.5) {
                            if (input[13] <= 0.5) {
                                memcpy(var10, (double[]){0.39705882352941174, 0.5294117647058824, 0.07352941176470588}, 3 * sizeof(double));
                            } else {
                                memcpy(var10, (double[]){0.9504950495049505, 0.0, 0.04950495049504951}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[7] <= 0.5) {
                                memcpy(var10, (double[]){0.963963963963964, 0.0, 0.036036036036036036}, 3 * sizeof(double));
                            } else {
                                memcpy(var10, (double[]){0.782608695652174, 0.021739130434782608, 0.1956521739130435}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        memcpy(var10, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    if (input[4] <= 0.5) {
                        memcpy(var10, (double[]){0.4090909090909091, 0.5, 0.09090909090909091}, 3 * sizeof(double));
                    } else {
                        if (input[13] <= 2.5) {
                            memcpy(var10, (double[]){0.29411764705882354, 0.5294117647058824, 0.17647058823529413}, 3 * sizeof(double));
                        } else {
                            memcpy(var10, (double[]){0.7777777777777778, 0.0, 0.2222222222222222}, 3 * sizeof(double));
                        }
                    }
                }
            }
        } else {
            if (input[2] <= 9813.0) {
                if (input[10] <= 2.5) {
                    if (input[18] <= 1.5) {
                        memcpy(var10, (double[]){0.6666666666666666, 0.0, 0.3333333333333333}, 3 * sizeof(double));
                    } else {
                        if (input[7] <= 0.5) {
                            memcpy(var10, (double[]){0.25, 0.0, 0.75}, 3 * sizeof(double));
                        } else {
                            memcpy(var10, (double[]){0.3888888888888889, 0.0, 0.6111111111111112}, 3 * sizeof(double));
                        }
                    }
                } else {
                    if (input[2] <= 9124.5) {
                        memcpy(var10, (double[]){0.2222222222222222, 0.0, 0.7777777777777778}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.6875, 0.125, 0.1875}, 3 * sizeof(double));
                    }
                }
            } else {
                memcpy(var10, (double[]){0.9090909090909091, 0.0, 0.09090909090909091}, 3 * sizeof(double));
            }
        }
    } else {
        if (input[18] <= 4.5) {
            if (input[15] <= 3.5) {
                if (input[8] <= 0.5) {
                    if (input[2] <= 9138.5) {
                        if (input[2] <= 9124.5) {
                            memcpy(var10, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                        } else {
                            memcpy(var10, (double[]){0.8181818181818182, 0.0, 0.18181818181818182}, 3 * sizeof(double));
                        }
                    } else {
                        memcpy(var10, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    if (input[10] <= 4.5) {
                        if (input[18] <= 2.5) {
                            if (input[18] <= 0.5) {
                                memcpy(var10, (double[]){0.9333333333333333, 0.0, 0.06666666666666667}, 3 * sizeof(double));
                            } else {
                                memcpy(var10, (double[]){0.5972222222222222, 0.0, 0.4027777777777778}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[16] <= 5.5) {
                                memcpy(var10, (double[]){0.21686746987951808, 0.13253012048192772, 0.6506024096385542}, 3 * sizeof(double));
                            } else {
                                memcpy(var10, (double[]){0.4, 0.0, 0.6}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        memcpy(var10, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[13] <= 6.5) {
                    if (input[17] <= 5.0) {
                        if (input[7] <= 0.5) {
                            memcpy(var10, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                        } else {
                            if (input[12] <= 1.5) {
                                memcpy(var10, (double[]){0.9090909090909091, 0.0, 0.09090909090909091}, 3 * sizeof(double));
                            } else {
                                memcpy(var10, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[1] <= 1.5) {
                            if (input[9] <= 2.5) {
                                memcpy(var10, (double[]){0.24120603015075376, 0.36683417085427134, 0.39195979899497485}, 3 * sizeof(double));
                            } else {
                                memcpy(var10, (double[]){0.2978723404255319, 0.30851063829787234, 0.39361702127659576}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[17] <= 11.416666507720947) {
                                memcpy(var10, (double[]){0.6190476190476191, 0.11904761904761904, 0.2619047619047619}, 3 * sizeof(double));
                            } else {
                                memcpy(var10, (double[]){0.23529411764705882, 0.21568627450980393, 0.5490196078431373}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    if (input[17] <= 12.125) {
                        if (input[17] <= 5.0) {
                            memcpy(var10, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                        } else {
                            if (input[15] <= 5.5) {
                                memcpy(var10, (double[]){0.9375, 0.0, 0.0625}, 3 * sizeof(double));
                            } else {
                                memcpy(var10, (double[]){0.7142857142857143, 0.14285714285714285, 0.14285714285714285}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[10] <= 2.5) {
                            memcpy(var10, (double[]){0.8666666666666667, 0.0, 0.13333333333333333}, 3 * sizeof(double));
                        } else {
                            memcpy(var10, (double[]){0.2222222222222222, 0.1111111111111111, 0.6666666666666666}, 3 * sizeof(double));
                        }
                    }
                }
            }
        } else {
            if (input[8] <= 0.5) {
                if (input[17] <= 12.583333492279053) {
                    if (input[13] <= 6.5) {
                        if (input[1] <= 1.5) {
                            memcpy(var10, (double[]){0.4166666666666667, 0.16666666666666666, 0.4166666666666667}, 3 * sizeof(double));
                        } else {
                            memcpy(var10, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                        }
                    } else {
                        memcpy(var10, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    if (input[17] <= 14.5625) {
                        if (input[15] <= 5.5) {
                            if (input[17] <= 13.349999904632568) {
                                memcpy(var10, (double[]){0.7777777777777778, 0.0, 0.2222222222222222}, 3 * sizeof(double));
                            } else {
                                memcpy(var10, (double[]){0.3, 0.2, 0.5}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[14] <= 13.525640964508057) {
                                memcpy(var10, (double[]){0.2857142857142857, 0.6428571428571429, 0.07142857142857142}, 3 * sizeof(double));
                            } else {
                                memcpy(var10, (double[]){0.125, 0.125, 0.75}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        memcpy(var10, (double[]){0.75, 0.25, 0.0}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[13] <= 9.5) {
                    if (input[18] <= 5.5) {
                        if (input[2] <= 9246.0) {
                            if (input[17] <= 11.550000190734863) {
                                memcpy(var10, (double[]){0.05172413793103448, 0.7241379310344828, 0.22413793103448276}, 3 * sizeof(double));
                            } else {
                                memcpy(var10, (double[]){0.06692913385826772, 0.8661417322834646, 0.06692913385826772}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[3] <= 0.5) {
                                memcpy(var10, (double[]){0.057692307692307696, 0.8269230769230769, 0.11538461538461539}, 3 * sizeof(double));
                            } else {
                                memcpy(var10, (double[]){0.13259668508287292, 0.5248618784530387, 0.3425414364640884}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[16] <= 6.5) {
                            if (input[2] <= 9721.5) {
                                memcpy(var10, (double[]){0.0378619153674833, 0.9064587973273942, 0.0556792873051225}, 3 * sizeof(double));
                            } else {
                                memcpy(var10, (double[]){0.15436241610738255, 0.7986577181208053, 0.04697986577181208}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[15] <= 5.5) {
                                memcpy(var10, (double[]){0.17857142857142858, 0.10714285714285714, 0.7142857142857143}, 3 * sizeof(double));
                            } else {
                                memcpy(var10, (double[]){0.039182282793867124, 0.8705281090289608, 0.09028960817717206}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    if (input[14] <= 11.720779418945312) {
                        if (input[15] <= 9.5) {
                            if (input[2] <= 9882.0) {
                                memcpy(var10, (double[]){0.45454545454545453, 0.0, 0.5454545454545454}, 3 * sizeof(double));
                            } else {
                                memcpy(var10, (double[]){0.5714285714285714, 0.0, 0.42857142857142855}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[14] <= 10.925824165344238) {
                                memcpy(var10, (double[]){0.0, 0.875, 0.125}, 3 * sizeof(double));
                            } else {
                                memcpy(var10, (double[]){0.5882352941176471, 0.23529411764705882, 0.17647058823529413}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[2] <= 9676.5) {
                            if (input[9] <= 2.5) {
                                memcpy(var10, (double[]){0.0547945205479452, 0.8767123287671232, 0.0684931506849315}, 3 * sizeof(double));
                            } else {
                                memcpy(var10, (double[]){0.11627906976744186, 0.627906976744186, 0.2558139534883721}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[17] <= 12.528340339660645) {
                                memcpy(var10, (double[]){0.4166666666666667, 0.5833333333333334, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var10, (double[]){0.6666666666666666, 0.3333333333333333, 0.0}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            }
        }
    }
    double var11[3];
    if (input[15] <= 4.5) {
        if (input[14] <= 10.099999904632568) {
            if (input[13] <= 0.5) {
                if (input[8] <= 0.5) {
                    memcpy(var11, (double[]){0.7647058823529411, 0.17647058823529413, 0.058823529411764705}, 3 * sizeof(double));
                } else {
                    memcpy(var11, (double[]){0.37272727272727274, 0.509090909090909, 0.11818181818181818}, 3 * sizeof(double));
                }
            } else {
                if (input[17] <= 10.25) {
                    if (input[11] <= 1.5) {
                        if (input[1] <= 3.0) {
                            if (input[2] <= 9377.0) {
                                memcpy(var11, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var11, (double[]){0.9285714285714286, 0.0, 0.07142857142857142}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[16] <= 5.5) {
                                memcpy(var11, (double[]){0.6842105263157895, 0.0, 0.3157894736842105}, 3 * sizeof(double));
                            } else {
                                memcpy(var11, (double[]){0.8333333333333334, 0.0, 0.16666666666666666}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[11] <= 3.5) {
                            if (input[18] <= 0.5) {
                                memcpy(var11, (double[]){0.960431654676259, 0.0, 0.039568345323741004}, 3 * sizeof(double));
                            } else {
                                memcpy(var11, (double[]){0.8333333333333334, 0.0, 0.16666666666666666}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var11, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                        }
                    }
                } else {
                    if (input[17] <= 11.833333492279053) {
                        if (input[11] <= 1.5) {
                            memcpy(var11, (double[]){0.4166666666666667, 0.0, 0.5833333333333334}, 3 * sizeof(double));
                        } else {
                            if (input[13] <= 5.5) {
                                memcpy(var11, (double[]){0.375, 0.0, 0.625}, 3 * sizeof(double));
                            } else {
                                memcpy(var11, (double[]){0.42857142857142855, 0.0, 0.5714285714285714}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[9] <= 2.5) {
                            if (input[4] <= 0.5) {
                                memcpy(var11, (double[]){0.8571428571428571, 0.0, 0.14285714285714285}, 3 * sizeof(double));
                            } else {
                                memcpy(var11, (double[]){0.5294117647058824, 0.11764705882352941, 0.35294117647058826}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var11, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                        }
                    }
                }
            }
        } else {
            if (input[1] <= 1.5) {
                if (input[17] <= 5.0) {
                    if (input[12] <= 1.5) {
                        memcpy(var11, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        if (input[16] <= 5.5) {
                            memcpy(var11, (double[]){0.625, 0.0, 0.375}, 3 * sizeof(double));
                        } else {
                            memcpy(var11, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                        }
                    }
                } else {
                    if (input[8] <= 0.5) {
                        if (input[13] <= 5.5) {
                            if (input[9] <= 2.5) {
                                memcpy(var11, (double[]){0.9, 0.0, 0.1}, 3 * sizeof(double));
                            } else {
                                memcpy(var11, (double[]){0.4, 0.0, 0.6}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[17] <= 11.59000015258789) {
                                memcpy(var11, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var11, (double[]){0.625, 0.0, 0.375}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[18] <= 3.5) {
                            if (input[2] <= 9102.0) {
                                memcpy(var11, (double[]){0.0, 0.16666666666666666, 0.8333333333333334}, 3 * sizeof(double));
                            } else {
                                memcpy(var11, (double[]){0.36792452830188677, 0.02830188679245283, 0.6037735849056604}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[15] <= 3.5) {
                                memcpy(var11, (double[]){0.10344827586206896, 0.29310344827586204, 0.603448275862069}, 3 * sizeof(double));
                            } else {
                                memcpy(var11, (double[]){0.2265625, 0.5390625, 0.234375}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            } else {
                if (input[15] <= 3.5) {
                    if (input[10] <= 2.5) {
                        if (input[2] <= 9377.0) {
                            if (input[18] <= 3.5) {
                                memcpy(var11, (double[]){0.7941176470588235, 0.058823529411764705, 0.14705882352941177}, 3 * sizeof(double));
                            } else {
                                memcpy(var11, (double[]){0.10526315789473684, 0.47368421052631576, 0.42105263157894735}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[4] <= 0.5) {
                                memcpy(var11, (double[]){0.6774193548387096, 0.06451612903225806, 0.25806451612903225}, 3 * sizeof(double));
                            } else {
                                memcpy(var11, (double[]){0.9444444444444444, 0.0, 0.05555555555555555}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[18] <= 3.5) {
                            if (input[2] <= 9124.5) {
                                memcpy(var11, (double[]){0.6764705882352942, 0.0, 0.3235294117647059}, 3 * sizeof(double));
                            } else {
                                memcpy(var11, (double[]){0.9230769230769231, 0.0, 0.07692307692307693}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var11, (double[]){0.38461538461538464, 0.23076923076923078, 0.38461538461538464}, 3 * sizeof(double));
                        }
                    }
                } else {
                    if (input[13] <= 5.5) {
                        if (input[4] <= 0.5) {
                            if (input[17] <= 11.828571319580078) {
                                memcpy(var11, (double[]){0.10526315789473684, 0.47368421052631576, 0.42105263157894735}, 3 * sizeof(double));
                            } else {
                                memcpy(var11, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[17] <= 12.625) {
                                memcpy(var11, (double[]){0.5625, 0.125, 0.3125}, 3 * sizeof(double));
                            } else {
                                memcpy(var11, (double[]){0.0, 0.25, 0.75}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[17] <= 11.083333492279053) {
                            if (input[14] <= 11.625) {
                                memcpy(var11, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var11, (double[]){0.8823529411764706, 0.0, 0.11764705882352941}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[8] <= 0.5) {
                                memcpy(var11, (double[]){0.8888888888888888, 0.0, 0.1111111111111111}, 3 * sizeof(double));
                            } else {
                                memcpy(var11, (double[]){0.2571428571428571, 0.2, 0.5428571428571428}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            }
        }
    } else {
        if (input[18] <= 4.5) {
            if (input[8] <= 0.5) {
                if (input[10] <= 2.5) {
                    if (input[18] <= 3.5) {
                        memcpy(var11, (double[]){0.9166666666666666, 0.0, 0.08333333333333333}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.8181818181818182, 0.18181818181818182, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    if (input[17] <= 11.833333492279053) {
                        memcpy(var11, (double[]){0.9, 0.0, 0.1}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.5555555555555556, 0.0, 0.4444444444444444}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[6] <= 0.5) {
                    if (input[15] <= 5.5) {
                        if (input[2] <= 9528.0) {
                            if (input[18] <= 3.5) {
                                memcpy(var11, (double[]){0.2222222222222222, 0.044444444444444446, 0.7333333333333333}, 3 * sizeof(double));
                            } else {
                                memcpy(var11, (double[]){0.125, 0.4166666666666667, 0.4583333333333333}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[11] <= 1.5) {
                                memcpy(var11, (double[]){0.0, 0.125, 0.875}, 3 * sizeof(double));
                            } else {
                                memcpy(var11, (double[]){0.53125, 0.125, 0.34375}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[18] <= 2.5) {
                            if (input[14] <= 12.558333396911621) {
                                memcpy(var11, (double[]){0.6666666666666666, 0.0, 0.3333333333333333}, 3 * sizeof(double));
                            } else {
                                memcpy(var11, (double[]){0.875, 0.0, 0.125}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[10] <= 2.5) {
                                memcpy(var11, (double[]){0.058823529411764705, 0.38235294117647056, 0.5588235294117647}, 3 * sizeof(double));
                            } else {
                                memcpy(var11, (double[]){0.1, 0.5333333333333333, 0.36666666666666664}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    if (input[14] <= 11.633333683013916) {
                        if (input[18] <= 3.5) {
                            memcpy(var11, (double[]){0.0, 0.5555555555555556, 0.4444444444444444}, 3 * sizeof(double));
                        } else {
                            memcpy(var11, (double[]){0.0, 0.5, 0.5}, 3 * sizeof(double));
                        }
                    } else {
                        if (input[12] <= 2.5) {
                            if (input[17] <= 11.833333492279053) {
                                memcpy(var11, (double[]){0.2727272727272727, 0.5454545454545454, 0.18181818181818182}, 3 * sizeof(double));
                            } else {
                                memcpy(var11, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var11, (double[]){0.6428571428571429, 0.35714285714285715, 0.0}, 3 * sizeof(double));
                        }
                    }
                }
            }
        } else {
            if (input[14] <= 12.158173084259033) {
                if (input[6] <= 0.5) {
                    if (input[8] <= 0.5) {
                        if (input[13] <= 6.5) {
                            memcpy(var11, (double[]){0.9, 0.1, 0.0}, 3 * sizeof(double));
                        } else {
                            memcpy(var11, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                        }
                    } else {
                        if (input[1] <= 1.5) {
                            if (input[16] <= 9.5) {
                                memcpy(var11, (double[]){0.08823529411764706, 0.7549019607843137, 0.1568627450980392}, 3 * sizeof(double));
                            } else {
                                memcpy(var11, (double[]){0.5, 0.25, 0.25}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[13] <= 13.5) {
                                memcpy(var11, (double[]){0.2524271844660194, 0.3786407766990291, 0.36893203883495146}, 3 * sizeof(double));
                            } else {
                                memcpy(var11, (double[]){0.125, 0.8333333333333334, 0.041666666666666664}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    if (input[18] <= 5.5) {
                        if (input[12] <= 2.5) {
                            memcpy(var11, (double[]){0.05555555555555555, 0.8333333333333334, 0.1111111111111111}, 3 * sizeof(double));
                        } else {
                            memcpy(var11, (double[]){0.12, 0.52, 0.36}, 3 * sizeof(double));
                        }
                    } else {
                        if (input[9] <= 2.5) {
                            if (input[2] <= 9369.0) {
                                memcpy(var11, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var11, (double[]){0.0, 0.7777777777777778, 0.2222222222222222}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var11, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                        }
                    }
                }
            } else {
                if (input[14] <= 13.251874923706055) {
                    if (input[0] <= 3.0) {
                        if (input[18] <= 5.5) {
                            if (input[13] <= 6.5) {
                                memcpy(var11, (double[]){0.0975609756097561, 0.7235772357723578, 0.17886178861788618}, 3 * sizeof(double));
                            } else {
                                memcpy(var11, (double[]){0.25, 0.15, 0.6}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[18] <= 7.5) {
                                memcpy(var11, (double[]){0.04024767801857585, 0.8792569659442725, 0.0804953560371517}, 3 * sizeof(double));
                            } else {
                                memcpy(var11, (double[]){0.12408759124087591, 0.7737226277372263, 0.10218978102189781}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        memcpy(var11, (double[]){0.25, 0.375, 0.375}, 3 * sizeof(double));
                    }
                } else {
                    if (input[8] <= 0.5) {
                        if (input[2] <= 9161.5) {
                            memcpy(var11, (double[]){0.5000000000000001, 0.33333333333333337, 0.16666666666666669}, 3 * sizeof(double));
                        } else {
                            memcpy(var11, (double[]){0.18181818181818182, 0.7272727272727273, 0.09090909090909091}, 3 * sizeof(double));
                        }
                    } else {
                        if (input[16] <= 7.5) {
                            if (input[13] <= 6.5) {
                                memcpy(var11, (double[]){0.06265060240963856, 0.8746987951807229, 0.06265060240963856}, 3 * sizeof(double));
                            } else {
                                memcpy(var11, (double[]){0.06578947368421052, 0.6842105263157895, 0.25}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[18] <= 6.5) {
                                memcpy(var11, (double[]){0.125, 0.375, 0.5}, 3 * sizeof(double));
                            } else {
                                memcpy(var11, (double[]){0.052631578947368425, 0.9210526315789475, 0.026315789473684213}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var10, var11, 3, var9);
    double var12[3];
    if (input[2] <= 9813.0) {
        if (input[17] <= 10.696969985961914) {
            if (input[7] <= 0.5) {
                if (input[2] <= 4092.5) {
                    memcpy(var12, (double[]){0.6060606060606061, 0.21212121212121213, 0.18181818181818182}, 3 * sizeof(double));
                } else {
                    if (input[17] <= 5.0) {
                        if (input[9] <= 2.5) {
                            if (input[10] <= 2.5) {
                                memcpy(var12, (double[]){0.9938650306748467, 0.0, 0.006134969325153374}, 3 * sizeof(double));
                            } else {
                                memcpy(var12, (double[]){0.9487179487179487, 0.0, 0.05128205128205128}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[8] <= 0.5) {
                                memcpy(var12, (double[]){0.9705882352941176, 0.0, 0.029411764705882353}, 3 * sizeof(double));
                            } else {
                                memcpy(var12, (double[]){0.9433962264150944, 0.0, 0.05660377358490566}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[1] <= 2.5) {
                            if (input[12] <= 2.5) {
                                memcpy(var12, (double[]){0.3181818181818182, 0.09090909090909091, 0.5909090909090909}, 3 * sizeof(double));
                            } else {
                                memcpy(var12, (double[]){0.56, 0.08, 0.36}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var12, (double[]){0.09090909090909091, 0.0, 0.9090909090909091}, 3 * sizeof(double));
                        }
                    }
                }
            } else {
                if (input[15] <= 2.5) {
                    if (input[2] <= 4092.5) {
                        if (input[8] <= 0.5) {
                            memcpy(var12, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                        } else {
                            if (input[1] <= 3.0) {
                                memcpy(var12, (double[]){0.30337078651685395, 0.550561797752809, 0.14606741573033707}, 3 * sizeof(double));
                            } else {
                                memcpy(var12, (double[]){0.8181818181818182, 0.0, 0.18181818181818182}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[2] <= 9721.5) {
                            if (input[10] <= 2.5) {
                                memcpy(var12, (double[]){0.974025974025974, 0.0, 0.025974025974025976}, 3 * sizeof(double));
                            } else {
                                memcpy(var12, (double[]){0.9310344827586207, 0.0, 0.06896551724137931}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[11] <= 2.5) {
                                memcpy(var12, (double[]){0.5454545454545454, 0.0, 0.45454545454545453}, 3 * sizeof(double));
                            } else {
                                memcpy(var12, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    if (input[16] <= 5.5) {
                        if (input[9] <= 2.5) {
                            memcpy(var12, (double[]){0.23076923076923078, 0.0, 0.7692307692307693}, 3 * sizeof(double));
                        } else {
                            memcpy(var12, (double[]){0.6, 0.0, 0.4}, 3 * sizeof(double));
                        }
                    } else {
                        if (input[18] <= 2.5) {
                            if (input[8] <= 0.5) {
                                memcpy(var12, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var12, (double[]){0.8, 0.0, 0.2}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[15] <= 4.5) {
                                memcpy(var12, (double[]){0.6666666666666666, 0.0, 0.3333333333333333}, 3 * sizeof(double));
                            } else {
                                memcpy(var12, (double[]){0.08333333333333333, 0.5833333333333334, 0.3333333333333333}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            }
        } else {
            if (input[16] <= 5.5) {
                if (input[18] <= 4.5) {
                    if (input[12] <= 2.5) {
                        if (input[18] <= 2.5) {
                            if (input[17] <= 11.75) {
                                memcpy(var12, (double[]){0.6923076923076923, 0.0, 0.3076923076923077}, 3 * sizeof(double));
                            } else {
                                memcpy(var12, (double[]){0.6, 0.0, 0.4}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[18] <= 3.5) {
                                memcpy(var12, (double[]){0.23255813953488372, 0.046511627906976744, 0.7209302325581395}, 3 * sizeof(double));
                            } else {
                                memcpy(var12, (double[]){0.16666666666666666, 0.2833333333333333, 0.55}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[11] <= 2.5) {
                            memcpy(var12, (double[]){0.16666666666666666, 0.125, 0.7083333333333334}, 3 * sizeof(double));
                        } else {
                            if (input[0] <= 1.5) {
                                memcpy(var12, (double[]){0.17777777777777778, 0.4, 0.4222222222222222}, 3 * sizeof(double));
                            } else {
                                memcpy(var12, (double[]){0.07692307692307693, 0.3076923076923077, 0.6153846153846154}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    if (input[9] <= 2.5) {
                        if (input[17] <= 12.633333683013916) {
                            if (input[15] <= 3.5) {
                                memcpy(var12, (double[]){0.0, 0.5454545454545454, 0.45454545454545453}, 3 * sizeof(double));
                            } else {
                                memcpy(var12, (double[]){0.02040816326530612, 0.8571428571428571, 0.12244897959183673}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[1] <= 1.5) {
                                memcpy(var12, (double[]){0.06666666666666667, 0.9, 0.03333333333333333}, 3 * sizeof(double));
                            } else {
                                memcpy(var12, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[7] <= 0.5) {
                            memcpy(var12, (double[]){0.1935483870967742, 0.7096774193548387, 0.0967741935483871}, 3 * sizeof(double));
                        } else {
                            if (input[12] <= 1.5) {
                                memcpy(var12, (double[]){0.2916666666666667, 0.375, 0.3333333333333333}, 3 * sizeof(double));
                            } else {
                                memcpy(var12, (double[]){0.0, 0.7647058823529411, 0.23529411764705882}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            } else {
                if (input[8] <= 0.5) {
                    if (input[18] <= 4.5) {
                        if (input[17] <= 11.125) {
                            memcpy(var12, (double[]){0.5, 0.0, 0.5}, 3 * sizeof(double));
                        } else {
                            if (input[2] <= 9077.5) {
                                memcpy(var12, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var12, (double[]){0.8095238095238095, 0.0, 0.19047619047619047}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[9] <= 2.5) {
                            if (input[17] <= 11.900000095367432) {
                                memcpy(var12, (double[]){0.375, 0.5, 0.125}, 3 * sizeof(double));
                            } else {
                                memcpy(var12, (double[]){0.6842105263157895, 0.18421052631578946, 0.13157894736842105}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[15] <= 7.5) {
                                memcpy(var12, (double[]){0.6, 0.06666666666666667, 0.3333333333333333}, 3 * sizeof(double));
                            } else {
                                memcpy(var12, (double[]){0.36363636363636365, 0.18181818181818182, 0.45454545454545453}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    if (input[18] <= 4.5) {
                        if (input[12] <= 2.5) {
                            if (input[18] <= 3.5) {
                                memcpy(var12, (double[]){0.38095238095238093, 0.09523809523809523, 0.5238095238095238}, 3 * sizeof(double));
                            } else {
                                memcpy(var12, (double[]){0.17894736842105263, 0.4, 0.42105263157894735}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[17] <= 12.125) {
                                memcpy(var12, (double[]){0.4, 0.45, 0.15}, 3 * sizeof(double));
                            } else {
                                memcpy(var12, (double[]){0.5178571428571429, 0.17857142857142858, 0.30357142857142855}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[18] <= 5.5) {
                            if (input[16] <= 6.5) {
                                memcpy(var12, (double[]){0.0860655737704918, 0.7295081967213115, 0.18442622950819673}, 3 * sizeof(double));
                            } else {
                                memcpy(var12, (double[]){0.34285714285714286, 0.11428571428571428, 0.5428571428571428}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[17] <= 13.084523677825928) {
                                memcpy(var12, (double[]){0.07550335570469799, 0.790268456375839, 0.1342281879194631}, 3 * sizeof(double));
                            } else {
                                memcpy(var12, (double[]){0.04310344827586207, 0.9252873563218391, 0.031609195402298854}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            }
        }
    } else {
        if (input[10] <= 4.5) {
            if (input[18] <= 4.5) {
                if (input[8] <= 0.5) {
                    memcpy(var12, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                } else {
                    if (input[15] <= 1.5) {
                        if (input[13] <= 5.5) {
                            if (input[0] <= 1.5) {
                                memcpy(var12, (double[]){0.9230769230769231, 0.0, 0.07692307692307693}, 3 * sizeof(double));
                            } else {
                                memcpy(var12, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var12, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                        }
                    } else {
                        if (input[1] <= 3.0) {
                            if (input[13] <= 5.5) {
                                memcpy(var12, (double[]){0.3, 0.0, 0.7}, 3 * sizeof(double));
                            } else {
                                memcpy(var12, (double[]){0.6363636363636364, 0.0, 0.36363636363636365}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var12, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                        }
                    }
                }
            } else {
                if (input[8] <= 0.5) {
                    memcpy(var12, (double[]){0.8333333333333334, 0.0, 0.16666666666666666}, 3 * sizeof(double));
                } else {
                    if (input[16] <= 7.5) {
                        if (input[17] <= 11.5) {
                            memcpy(var12, (double[]){0.38095238095238093, 0.2857142857142857, 0.3333333333333333}, 3 * sizeof(double));
                        } else {
                            if (input[11] <= 2.5) {
                                memcpy(var12, (double[]){0.08771929824561403, 0.7192982456140351, 0.19298245614035087}, 3 * sizeof(double));
                            } else {
                                memcpy(var12, (double[]){0.0, 0.9583333333333334, 0.041666666666666664}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[18] <= 7.0) {
                            memcpy(var12, (double[]){0.8888888888888888, 0.1111111111111111, 0.0}, 3 * sizeof(double));
                        } else {
                            if (input[13] <= 13.5) {
                                memcpy(var12, (double[]){0.17647058823529413, 0.35294117647058826, 0.47058823529411764}, 3 * sizeof(double));
                            } else {
                                memcpy(var12, (double[]){0.5833333333333334, 0.4166666666666667, 0.0}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            }
        } else {
            memcpy(var12, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
        }
    }
    add_vectors(var9, var12, 3, var8);
    double var13[3];
    if (input[18] <= 4.5) {
        if (input[17] <= 5.0) {
            if (input[6] <= 0.5) {
                if (input[2] <= 4092.5) {
                    if (input[12] <= 2.5) {
                        if (input[11] <= 2.5) {
                            if (input[12] <= 1.5) {
                                memcpy(var13, (double[]){0.46938775510204084, 0.3673469387755102, 0.16326530612244897}, 3 * sizeof(double));
                            } else {
                                memcpy(var13, (double[]){0.3333333333333333, 0.2, 0.4666666666666667}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var13, (double[]){0.26666666666666666, 0.4, 0.3333333333333333}, 3 * sizeof(double));
                        }
                    } else {
                        memcpy(var13, (double[]){0.782608695652174, 0.21739130434782608, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    if (input[7] <= 0.5) {
                        if (input[10] <= 2.5) {
                            if (input[16] <= 5.5) {
                                memcpy(var13, (double[]){0.9772727272727273, 0.0, 0.022727272727272728}, 3 * sizeof(double));
                            } else {
                                memcpy(var13, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var13, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                        }
                    } else {
                        if (input[13] <= 5.5) {
                            if (input[3] <= 0.5) {
                                memcpy(var13, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var13, (double[]){0.9137931034482759, 0.0, 0.08620689655172414}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[8] <= 0.5) {
                                memcpy(var13, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var13, (double[]){0.9493670886075949, 0.0, 0.05063291139240506}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            } else {
                if (input[2] <= 4092.5) {
                    if (input[11] <= 2.5) {
                        memcpy(var13, (double[]){0.30434782608695654, 0.6521739130434783, 0.043478260869565216}, 3 * sizeof(double));
                    } else {
                        if (input[4] <= 0.5) {
                            memcpy(var13, (double[]){0.5, 0.125, 0.375}, 3 * sizeof(double));
                        } else {
                            memcpy(var13, (double[]){0.5714285714285715, 0.14285714285714288, 0.28571428571428575}, 3 * sizeof(double));
                        }
                    }
                } else {
                    if (input[16] <= 5.5) {
                        memcpy(var13, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.9375, 0.0, 0.0625}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[8] <= 0.5) {
                if (input[15] <= 3.5) {
                    if (input[13] <= 5.5) {
                        memcpy(var13, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        if (input[17] <= 11.166666507720947) {
                            memcpy(var13, (double[]){0.8571428571428571, 0.0, 0.14285714285714285}, 3 * sizeof(double));
                        } else {
                            memcpy(var13, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                        }
                    }
                } else {
                    if (input[10] <= 2.5) {
                        if (input[7] <= 0.5) {
                            if (input[1] <= 3.0) {
                                memcpy(var13, (double[]){0.9090909090909091, 0.0, 0.09090909090909091}, 3 * sizeof(double));
                            } else {
                                memcpy(var13, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var13, (double[]){0.6153846153846154, 0.3076923076923077, 0.07692307692307693}, 3 * sizeof(double));
                        }
                    } else {
                        if (input[17] <= 12.800000190734863) {
                            if (input[2] <= 9102.0) {
                                memcpy(var13, (double[]){0.375, 0.0, 0.625}, 3 * sizeof(double));
                            } else {
                                memcpy(var13, (double[]){0.9444444444444444, 0.0, 0.05555555555555555}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var13, (double[]){0.4166666666666667, 0.0, 0.5833333333333334}, 3 * sizeof(double));
                        }
                    }
                }
            } else {
                if (input[9] <= 5.0) {
                    if (input[17] <= 11.329166412353516) {
                        if (input[1] <= 3.5) {
                            if (input[15] <= 3.5) {
                                memcpy(var13, (double[]){0.5274725274725275, 0.04395604395604396, 0.42857142857142855}, 3 * sizeof(double));
                            } else {
                                memcpy(var13, (double[]){0.26548672566371684, 0.25663716814159293, 0.4778761061946903}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[1] <= 4.5) {
                                memcpy(var13, (double[]){0.8387096774193549, 0.0, 0.16129032258064516}, 3 * sizeof(double));
                            } else {
                                memcpy(var13, (double[]){0.6111111111111112, 0.05555555555555555, 0.3333333333333333}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[15] <= 4.5) {
                            if (input[6] <= 0.5) {
                                memcpy(var13, (double[]){0.36401673640167365, 0.13807531380753138, 0.497907949790795}, 3 * sizeof(double));
                            } else {
                                memcpy(var13, (double[]){0.12121212121212122, 0.12121212121212122, 0.7575757575757576}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[6] <= 0.5) {
                                memcpy(var13, (double[]){0.13559322033898305, 0.3644067796610169, 0.5}, 3 * sizeof(double));
                            } else {
                                memcpy(var13, (double[]){0.24324324324324326, 0.6756756756756757, 0.08108108108108109}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    if (input[18] <= 3.5) {
                        memcpy(var13, (double[]){0.8666666666666667, 0.13333333333333333, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.46153846153846156, 0.38461538461538464, 0.15384615384615385}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[2] <= 9813.0) {
            if (input[14] <= 11.654762268066406) {
                if (input[13] <= 9.5) {
                    if (input[14] <= 10.535714149475098) {
                        memcpy(var13, (double[]){0.0, 0.375, 0.625}, 3 * sizeof(double));
                    } else {
                        if (input[8] <= 0.5) {
                            memcpy(var13, (double[]){0.9, 0.1, 0.0}, 3 * sizeof(double));
                        } else {
                            if (input[4] <= 0.5) {
                                memcpy(var13, (double[]){0.032520325203252036, 0.7642276422764228, 0.2032520325203252}, 3 * sizeof(double));
                            } else {
                                memcpy(var13, (double[]){0.1388888888888889, 0.5833333333333334, 0.2777777777777778}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    if (input[17] <= 11.196428775787354) {
                        memcpy(var13, (double[]){0.0, 0.5555555555555556, 0.4444444444444444}, 3 * sizeof(double));
                    } else {
                        if (input[14] <= 11.178571224212646) {
                            memcpy(var13, (double[]){0.14285714285714285, 0.2857142857142857, 0.5714285714285714}, 3 * sizeof(double));
                        } else {
                            memcpy(var13, (double[]){0.75, 0.08333333333333333, 0.16666666666666666}, 3 * sizeof(double));
                        }
                    }
                }
            } else {
                if (input[6] <= 0.5) {
                    if (input[14] <= 13.455843925476074) {
                        if (input[14] <= 13.43571424484253) {
                            if (input[1] <= 1.5) {
                                memcpy(var13, (double[]){0.09558823529411764, 0.7941176470588235, 0.11029411764705882}, 3 * sizeof(double));
                            } else {
                                memcpy(var13, (double[]){0.1635514018691589, 0.6542056074766356, 0.18224299065420563}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var13, (double[]){0.5714285714285714, 0.42857142857142855, 0.0}, 3 * sizeof(double));
                        }
                    } else {
                        if (input[11] <= 1.5) {
                            if (input[8] <= 0.5) {
                                memcpy(var13, (double[]){0.2, 0.2, 0.6}, 3 * sizeof(double));
                            } else {
                                memcpy(var13, (double[]){0.09756097560975611, 0.8170731707317074, 0.0853658536585366}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[13] <= 9.5) {
                                memcpy(var13, (double[]){0.04184100418410042, 0.9163179916317992, 0.04184100418410042}, 3 * sizeof(double));
                            } else {
                                memcpy(var13, (double[]){0.22727272727272727, 0.7727272727272727, 0.0}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    if (input[18] <= 5.5) {
                        if (input[2] <= 9192.5) {
                            if (input[14] <= 14.099999904632568) {
                                memcpy(var13, (double[]){0.0, 0.8857142857142857, 0.11428571428571428}, 3 * sizeof(double));
                            } else {
                                memcpy(var13, (double[]){0.375, 0.5, 0.125}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var13, (double[]){0.3, 0.5, 0.2}, 3 * sizeof(double));
                        }
                    } else {
                        if (input[4] <= 0.5) {
                            if (input[12] <= 1.5) {
                                memcpy(var13, (double[]){0.050359712230215826, 0.8848920863309353, 0.06474820143884892}, 3 * sizeof(double));
                            } else {
                                memcpy(var13, (double[]){0.009966777408637875, 0.9601328903654486, 0.029900332225913626}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[2] <= 9036.5) {
                                memcpy(var13, (double[]){0.0, 0.6666666666666666, 0.3333333333333333}, 3 * sizeof(double));
                            } else {
                                memcpy(var13, (double[]){0.03389830508474576, 0.8983050847457628, 0.06779661016949153}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            }
        } else {
            if (input[17] <= 11.564393997192383) {
                if (input[0] <= 1.5) {
                    if (input[1] <= 1.5) {
                        memcpy(var13, (double[]){0.5882352941176471, 0.058823529411764705, 0.35294117647058826}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.4666666666666667, 0.5333333333333333, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var13, (double[]){0.3333333333333333, 0.0, 0.6666666666666666}, 3 * sizeof(double));
                }
            } else {
                if (input[17] <= 12.845237731933594) {
                    if (input[13] <= 8.0) {
                        if (input[7] <= 0.5) {
                            if (input[14] <= 12.291666507720947) {
                                memcpy(var13, (double[]){0.0, 0.6666666666666666, 0.3333333333333333}, 3 * sizeof(double));
                            } else {
                                memcpy(var13, (double[]){0.0, 0.8333333333333334, 0.16666666666666666}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[10] <= 2.5) {
                                memcpy(var13, (double[]){0.3333333333333333, 0.4166666666666667, 0.25}, 3 * sizeof(double));
                            } else {
                                memcpy(var13, (double[]){0.0, 0.15384615384615385, 0.8461538461538461}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[4] <= 0.5) {
                            if (input[0] <= 1.5) {
                                memcpy(var13, (double[]){0.3333333333333333, 0.6666666666666666, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var13, (double[]){0.625, 0.375, 0.0}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var13, (double[]){0.5, 0.3, 0.2}, 3 * sizeof(double));
                        }
                    }
                } else {
                    if (input[13] <= 6.5) {
                        if (input[11] <= 2.5) {
                            if (input[10] <= 2.5) {
                                memcpy(var13, (double[]){0.0, 0.8181818181818182, 0.18181818181818182}, 3 * sizeof(double));
                            } else {
                                memcpy(var13, (double[]){0.0, 0.7142857142857143, 0.2857142857142857}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[4] <= 0.5) {
                                memcpy(var13, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var13, (double[]){0.1, 0.7, 0.2}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[14] <= 12.19444465637207) {
                            memcpy(var13, (double[]){0.11111111111111112, 0.6666666666666667, 0.22222222222222224}, 3 * sizeof(double));
                        } else {
                            memcpy(var13, (double[]){0.5, 0.5, 0.0}, 3 * sizeof(double));
                        }
                    }
                }
            }
        }
    }
    add_vectors(var8, var13, 3, var7);
    double var14[3];
    if (input[4] <= 0.5) {
        if (input[14] <= 10.099999904632568) {
            if (input[18] <= 3.5) {
                if (input[16] <= 0.5) {
                    if (input[8] <= 0.5) {
                        memcpy(var14, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        if (input[10] <= 2.5) {
                            if (input[12] <= 2.5) {
                                memcpy(var14, (double[]){0.3333333333333333, 0.5555555555555556, 0.1111111111111111}, 3 * sizeof(double));
                            } else {
                                memcpy(var14, (double[]){0.9333333333333333, 0.06666666666666667, 0.0}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var14, (double[]){0.32432432432432434, 0.5135135135135135, 0.16216216216216217}, 3 * sizeof(double));
                        }
                    }
                } else {
                    if (input[17] <= 12.5) {
                        if (input[16] <= 7.5) {
                            if (input[17] <= 10.785714149475098) {
                                memcpy(var14, (double[]){0.9698795180722891, 0.0, 0.030120481927710843}, 3 * sizeof(double));
                            } else {
                                memcpy(var14, (double[]){0.8333333333333334, 0.0, 0.16666666666666666}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var14, (double[]){0.7083333333333334, 0.0, 0.2916666666666667}, 3 * sizeof(double));
                        }
                    } else {
                        memcpy(var14, (double[]){0.5555555555555556, 0.0, 0.4444444444444444}, 3 * sizeof(double));
                    }
                }
            } else {
                memcpy(var14, (double[]){0.09090909090909091, 0.18181818181818182, 0.7272727272727273}, 3 * sizeof(double));
            }
        } else {
            if (input[14] <= 12.035714149475098) {
                if (input[13] <= 5.5) {
                    if (input[9] <= 2.5) {
                        if (input[8] <= 0.5) {
                            memcpy(var14, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                        } else {
                            if (input[3] <= 0.5) {
                                memcpy(var14, (double[]){0.12121212121212122, 0.30303030303030304, 0.5757575757575758}, 3 * sizeof(double));
                            } else {
                                memcpy(var14, (double[]){0.11578947368421053, 0.47368421052631576, 0.4105263157894737}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[12] <= 1.5) {
                            memcpy(var14, (double[]){0.3157894736842105, 0.10526315789473684, 0.5789473684210527}, 3 * sizeof(double));
                        } else {
                            memcpy(var14, (double[]){0.5625, 0.375, 0.0625}, 3 * sizeof(double));
                        }
                    }
                } else {
                    if (input[18] <= 4.5) {
                        if (input[18] <= 3.5) {
                            if (input[14] <= 11.535714149475098) {
                                memcpy(var14, (double[]){0.5952380952380952, 0.14285714285714285, 0.2619047619047619}, 3 * sizeof(double));
                            } else {
                                memcpy(var14, (double[]){0.8205128205128205, 0.02564102564102564, 0.15384615384615385}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[17] <= 11.224999904632568) {
                                memcpy(var14, (double[]){0.23529411764705882, 0.058823529411764705, 0.7058823529411765}, 3 * sizeof(double));
                            } else {
                                memcpy(var14, (double[]){0.35714285714285715, 0.39285714285714285, 0.25}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[17] <= 10.387499809265137) {
                            memcpy(var14, (double[]){0.4, 0.0, 0.6}, 3 * sizeof(double));
                        } else {
                            if (input[13] <= 8.5) {
                                memcpy(var14, (double[]){0.13924050632911392, 0.7383966244725738, 0.12236286919831224}, 3 * sizeof(double));
                            } else {
                                memcpy(var14, (double[]){0.39622641509433965, 0.49056603773584906, 0.11320754716981132}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            } else {
                if (input[16] <= 7.5) {
                    if (input[17] <= 11.083333492279053) {
                        if (input[18] <= 1.5) {
                            memcpy(var14, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                        } else {
                            if (input[14] <= 13.375) {
                                memcpy(var14, (double[]){0.5294117647058824, 0.14705882352941177, 0.3235294117647059}, 3 * sizeof(double));
                            } else {
                                memcpy(var14, (double[]){0.0, 0.09090909090909091, 0.9090909090909091}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[8] <= 0.5) {
                            if (input[16] <= 5.5) {
                                memcpy(var14, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var14, (double[]){0.4166666666666667, 0.3333333333333333, 0.25}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[18] <= 4.5) {
                                memcpy(var14, (double[]){0.15306122448979592, 0.3979591836734694, 0.4489795918367347}, 3 * sizeof(double));
                            } else {
                                memcpy(var14, (double[]){0.05157593123209169, 0.8553008595988538, 0.09312320916905444}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    if (input[9] <= 4.5) {
                        if (input[6] <= 0.5) {
                            if (input[8] <= 0.5) {
                                memcpy(var14, (double[]){0.42857142857142855, 0.35714285714285715, 0.21428571428571427}, 3 * sizeof(double));
                            } else {
                                memcpy(var14, (double[]){0.09689922480620156, 0.7945736434108527, 0.10852713178294573}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[17] <= 12.281428337097168) {
                                memcpy(var14, (double[]){0.3333333333333333, 0.6666666666666666, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var14, (double[]){0.010810810810810811, 0.9621621621621622, 0.02702702702702703}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        memcpy(var14, (double[]){0.6, 0.4, 0.0}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[15] <= 4.5) {
            if (input[14] <= 5.0) {
                if (input[2] <= 4092.5) {
                    if (input[1] <= 1.5) {
                        if (input[6] <= 0.5) {
                            if (input[8] <= 0.5) {
                                memcpy(var14, (double[]){0.8181818181818182, 0.09090909090909091, 0.09090909090909091}, 3 * sizeof(double));
                            } else {
                                memcpy(var14, (double[]){0.42857142857142855, 0.37142857142857144, 0.2}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var14, (double[]){0.07692307692307693, 0.7692307692307693, 0.15384615384615385}, 3 * sizeof(double));
                        }
                    } else {
                        if (input[9] <= 2.5) {
                            memcpy(var14, (double[]){0.7692307692307693, 0.15384615384615385, 0.07692307692307693}, 3 * sizeof(double));
                        } else {
                            memcpy(var14, (double[]){0.8333333333333334, 0.16666666666666666, 0.0}, 3 * sizeof(double));
                        }
                    }
                } else {
                    if (input[2] <= 9124.5) {
                        if (input[2] <= 9036.5) {
                            if (input[1] <= 3.0) {
                                memcpy(var14, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var14, (double[]){0.7272727272727273, 0.0, 0.2727272727272727}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[11] <= 2.5) {
                                memcpy(var14, (double[]){0.6666666666666666, 0.0, 0.3333333333333333}, 3 * sizeof(double));
                            } else {
                                memcpy(var14, (double[]){0.896551724137931, 0.0, 0.10344827586206896}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[0] <= 1.5) {
                            memcpy(var14, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                        } else {
                            memcpy(var14, (double[]){0.95, 0.0, 0.05}, 3 * sizeof(double));
                        }
                    }
                }
            } else {
                if (input[11] <= 1.5) {
                    if (input[10] <= 2.5) {
                        if (input[2] <= 9200.5) {
                            memcpy(var14, (double[]){0.6, 0.13333333333333333, 0.26666666666666666}, 3 * sizeof(double));
                        } else {
                            memcpy(var14, (double[]){0.9444444444444444, 0.05555555555555555, 0.0}, 3 * sizeof(double));
                        }
                    } else {
                        if (input[17] <= 10.833333492279053) {
                            if (input[17] <= 10.416666507720947) {
                                memcpy(var14, (double[]){0.85, 0.0, 0.15}, 3 * sizeof(double));
                            } else {
                                memcpy(var14, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[1] <= 3.5) {
                                memcpy(var14, (double[]){0.4583333333333333, 0.16666666666666666, 0.375}, 3 * sizeof(double));
                            } else {
                                memcpy(var14, (double[]){0.3333333333333333, 0.06666666666666667, 0.6}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    if (input[18] <= 0.5) {
                        memcpy(var14, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        if (input[2] <= 9036.5) {
                            memcpy(var14, (double[]){0.9230769230769231, 0.0, 0.07692307692307693}, 3 * sizeof(double));
                        } else {
                            if (input[12] <= 4.0) {
                                memcpy(var14, (double[]){0.3202614379084967, 0.13725490196078433, 0.5424836601307189}, 3 * sizeof(double));
                            } else {
                                memcpy(var14, (double[]){0.7272727272727273, 0.09090909090909091, 0.18181818181818182}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            }
        } else {
            if (input[8] <= 0.5) {
                if (input[9] <= 2.5) {
                    if (input[13] <= 6.5) {
                        memcpy(var14, (double[]){0.9, 0.0, 0.1}, 3 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    if (input[15] <= 5.5) {
                        memcpy(var14, (double[]){0.7777777777777778, 0.0, 0.2222222222222222}, 3 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.9166666666666666, 0.08333333333333333, 0.0}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[14] <= 13.319560527801514) {
                    if (input[2] <= 4092.5) {
                        memcpy(var14, (double[]){0.0625, 0.125, 0.8125}, 3 * sizeof(double));
                    } else {
                        if (input[1] <= 3.5) {
                            if (input[18] <= 3.5) {
                                memcpy(var14, (double[]){0.28571428571428575, 0.163265306122449, 0.5510204081632654}, 3 * sizeof(double));
                            } else {
                                memcpy(var14, (double[]){0.07692307692307693, 0.6923076923076923, 0.23076923076923078}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[17] <= 12.16233777999878) {
                                memcpy(var14, (double[]){0.20588235294117646, 0.3235294117647059, 0.47058823529411764}, 3 * sizeof(double));
                            } else {
                                memcpy(var14, (double[]){0.21951219512195122, 0.6097560975609756, 0.17073170731707318}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    if (input[2] <= 9102.0) {
                        if (input[0] <= 1.5) {
                            if (input[1] <= 1.5) {
                                memcpy(var14, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var14, (double[]){0.0, 0.8846153846153846, 0.11538461538461539}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var14, (double[]){0.09090909090909091, 0.9090909090909091, 0.0}, 3 * sizeof(double));
                        }
                    } else {
                        if (input[14] <= 13.921904563903809) {
                            if (input[1] <= 1.5) {
                                memcpy(var14, (double[]){0.09259259259259259, 0.9074074074074074, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var14, (double[]){0.29166666666666674, 0.6666666666666667, 0.04166666666666667}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[1] <= 1.5) {
                                memcpy(var14, (double[]){0.075, 0.875, 0.05}, 3 * sizeof(double));
                            } else {
                                memcpy(var14, (double[]){0.13636363636363635, 0.5, 0.36363636363636365}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var7, var14, 3, var6);
    double var15[3];
    if (input[18] <= 3.5) {
        if (input[18] <= 1.5) {
            if (input[16] <= 0.5) {
                if (input[8] <= 0.5) {
                    if (input[9] <= 2.5) {
                        memcpy(var15, (double[]){0.9285714285714286, 0.07142857142857142, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.8888888888888888, 0.1111111111111111, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    if (input[6] <= 0.5) {
                        if (input[1] <= 3.0) {
                            if (input[9] <= 2.5) {
                                memcpy(var15, (double[]){0.5652173913043479, 0.4130434782608696, 0.02173913043478261}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){0.2413793103448276, 0.4827586206896552, 0.27586206896551724}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var15, (double[]){0.6153846153846154, 0.15384615384615385, 0.23076923076923078}, 3 * sizeof(double));
                        }
                    } else {
                        memcpy(var15, (double[]){0.13157894736842105, 0.7894736842105263, 0.07894736842105263}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[18] <= 0.5) {
                    if (input[14] <= 13.130000114440918) {
                        if (input[11] <= 2.5) {
                            if (input[8] <= 0.5) {
                                memcpy(var15, (double[]){0.9761904761904762, 0.0, 0.023809523809523808}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){0.9214659685863874, 0.0, 0.07853403141361257}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[3] <= 0.5) {
                                memcpy(var15, (double[]){0.9384615384615385, 0.0, 0.06153846153846154}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        memcpy(var15, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    if (input[8] <= 0.5) {
                        memcpy(var15, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        if (input[17] <= 10.5) {
                            if (input[9] <= 2.5) {
                                memcpy(var15, (double[]){0.42857142857142855, 0.0, 0.5714285714285714}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){0.5, 0.0, 0.5}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[11] <= 1.5) {
                                memcpy(var15, (double[]){0.9375, 0.0, 0.0625}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){0.65625, 0.0, 0.34375}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            }
        } else {
            if (input[14] <= 12.622499942779541) {
                if (input[1] <= 1.5) {
                    if (input[12] <= 2.5) {
                        if (input[2] <= 9102.0) {
                            if (input[17] <= 13.0) {
                                memcpy(var15, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){0.28571428571428575, 0.4285714285714286, 0.28571428571428575}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[6] <= 0.5) {
                                memcpy(var15, (double[]){0.5164835164835165, 0.04395604395604396, 0.43956043956043955}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){0.16666666666666666, 0.4166666666666667, 0.4166666666666667}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[2] <= 9721.5) {
                            if (input[15] <= 3.5) {
                                memcpy(var15, (double[]){0.1111111111111111, 0.0, 0.8888888888888888}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){0.2857142857142857, 0.3333333333333333, 0.38095238095238093}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[17] <= 10.833333492279053) {
                                memcpy(var15, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){0.625, 0.0, 0.375}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    if (input[0] <= 1.5) {
                        if (input[1] <= 2.5) {
                            if (input[10] <= 2.5) {
                                memcpy(var15, (double[]){0.4117647058823529, 0.17647058823529413, 0.4117647058823529}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[15] <= 3.5) {
                                memcpy(var15, (double[]){0.41379310344827586, 0.0, 0.5862068965517241}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){0.7857142857142857, 0.0, 0.21428571428571427}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[15] <= 4.5) {
                            if (input[17] <= 11.416666507720947) {
                                memcpy(var15, (double[]){0.8571428571428572, 0.07142857142857144, 0.07142857142857144}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var15, (double[]){0.6666666666666666, 0.3333333333333333, 0.0}, 3 * sizeof(double));
                        }
                    }
                }
            } else {
                if (input[13] <= 6.5) {
                    if (input[14] <= 14.266666412353516) {
                        if (input[15] <= 3.5) {
                            if (input[12] <= 1.5) {
                                memcpy(var15, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){0.7894736842105263, 0.0, 0.21052631578947367}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[6] <= 0.5) {
                                memcpy(var15, (double[]){0.024390243902439025, 0.0975609756097561, 0.8780487804878049}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){0.2222222222222222, 0.2222222222222222, 0.5555555555555556}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        memcpy(var15, (double[]){0.625, 0.25, 0.125}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var15, (double[]){0.75, 0.0, 0.25}, 3 * sizeof(double));
                }
            }
        }
    } else {
        if (input[6] <= 0.5) {
            if (input[7] <= 0.5) {
                if (input[17] <= 13.316666603088379) {
                    if (input[8] <= 0.5) {
                        if (input[17] <= 11.442307472229004) {
                            memcpy(var15, (double[]){0.7333333333333334, 0.13333333333333336, 0.13333333333333336}, 3 * sizeof(double));
                        } else {
                            if (input[11] <= 2.5) {
                                memcpy(var15, (double[]){0.92, 0.0, 0.08}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[4] <= 0.5) {
                            if (input[15] <= 4.5) {
                                memcpy(var15, (double[]){0.10526315789473684, 0.3157894736842105, 0.5789473684210527}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){0.09836065573770492, 0.6612021857923497, 0.24043715846994534}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[16] <= 7.5) {
                                memcpy(var15, (double[]){0.15151515151515152, 0.40404040404040403, 0.4444444444444444}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){0.20754716981132076, 0.6037735849056604, 0.18867924528301888}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    if (input[17] <= 14.651515483856201) {
                        if (input[1] <= 1.5) {
                            if (input[2] <= 9721.5) {
                                memcpy(var15, (double[]){0.0, 0.8783783783783784, 0.12162162162162163}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){0.07692307692307693, 0.5384615384615384, 0.38461538461538464}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[14] <= 15.045454502105713) {
                                memcpy(var15, (double[]){0.1643835616438356, 0.6027397260273972, 0.2328767123287671}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){0.2857142857142857, 0.2857142857142857, 0.42857142857142855}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[16] <= 7.5) {
                            if (input[17] <= 15.550000190734863) {
                                memcpy(var15, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){0.0, 0.8181818181818182, 0.18181818181818182}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[11] <= 2.5) {
                                memcpy(var15, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){0.36363636363636365, 0.6363636363636364, 0.0}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            } else {
                if (input[14] <= 13.755555629730225) {
                    if (input[17] <= 11.958333015441895) {
                        if (input[9] <= 2.5) {
                            if (input[8] <= 0.5) {
                                memcpy(var15, (double[]){0.875, 0.0, 0.125}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){0.19827586206896552, 0.49137931034482757, 0.3103448275862069}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[17] <= 11.336666584014893) {
                                memcpy(var15, (double[]){0.22580645161290322, 0.5161290322580645, 0.25806451612903225}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){0.43243243243243246, 0.05405405405405406, 0.5135135135135135}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[18] <= 4.5) {
                            if (input[11] <= 1.5) {
                                memcpy(var15, (double[]){0.16666666666666666, 0.3333333333333333, 0.5}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){0.07317073170731707, 0.5365853658536586, 0.3902439024390244}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[12] <= 1.5) {
                                memcpy(var15, (double[]){0.0903954802259887, 0.7175141242937854, 0.192090395480226}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){0.08333333333333333, 0.7990196078431373, 0.11764705882352941}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    if (input[11] <= 1.5) {
                        if (input[17] <= 12.732142925262451) {
                            memcpy(var15, (double[]){0.0, 0.5454545454545454, 0.45454545454545453}, 3 * sizeof(double));
                        } else {
                            if (input[8] <= 0.5) {
                                memcpy(var15, (double[]){0.6153846153846154, 0.38461538461538464, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){0.15, 0.825, 0.025}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[15] <= 5.5) {
                            if (input[12] <= 1.5) {
                                memcpy(var15, (double[]){0.0, 0.8181818181818182, 0.18181818181818182}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){0.2777777777777778, 0.5555555555555556, 0.16666666666666666}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[1] <= 3.0) {
                                memcpy(var15, (double[]){0.011494252873563218, 0.896551724137931, 0.09195402298850575}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            }
        } else {
            if (input[14] <= 11.071428775787354) {
                if (input[16] <= 5.5) {
                    memcpy(var15, (double[]){0.0, 0.26666666666666666, 0.7333333333333333}, 3 * sizeof(double));
                } else {
                    if (input[11] <= 2.5) {
                        memcpy(var15, (double[]){0.07142857142857142, 0.5714285714285714, 0.35714285714285715}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.058823529411764705, 0.47058823529411764, 0.47058823529411764}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[17] <= 11.224999904632568) {
                    if (input[1] <= 1.5) {
                        memcpy(var15, (double[]){0.15, 0.7, 0.15}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.25, 0.3125, 0.4375}, 3 * sizeof(double));
                    }
                } else {
                    if (input[16] <= 7.5) {
                        if (input[15] <= 4.5) {
                            if (input[16] <= 5.5) {
                                memcpy(var15, (double[]){0.1111111111111111, 0.4444444444444444, 0.4444444444444444}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){0.0, 0.6842105263157895, 0.3157894736842105}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[14] <= 14.266666412353516) {
                                memcpy(var15, (double[]){0.04189944134078212, 0.8938547486033519, 0.06424581005586592}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){0.1, 0.8, 0.1}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[15] <= 6.5) {
                            if (input[11] <= 1.5) {
                                memcpy(var15, (double[]){0.16666666666666669, 0.6666666666666667, 0.16666666666666669}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){0.0, 0.9565217391304348, 0.043478260869565216}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[15] <= 7.5) {
                                memcpy(var15, (double[]){0.024096385542168676, 0.963855421686747, 0.012048192771084338}, 3 * sizeof(double));
                            } else {
                                memcpy(var15, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var6, var15, 3, var5);
    double var16[3];
    if (input[6] <= 0.5) {
        if (input[15] <= 4.5) {
            if (input[17] <= 5.0) {
                if (input[2] <= 4092.5) {
                    if (input[1] <= 1.5) {
                        if (input[9] <= 2.5) {
                            if (input[11] <= 2.5) {
                                memcpy(var16, (double[]){0.8095238095238095, 0.19047619047619047, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var16, (double[]){0.4117647058823529, 0.47058823529411764, 0.11764705882352941}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[4] <= 0.5) {
                                memcpy(var16, (double[]){0.2173913043478261, 0.5652173913043479, 0.2173913043478261}, 3 * sizeof(double));
                            } else {
                                memcpy(var16, (double[]){0.21428571428571427, 0.7857142857142857, 0.0}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[7] <= 0.5) {
                            memcpy(var16, (double[]){0.9, 0.1, 0.0}, 3 * sizeof(double));
                        } else {
                            memcpy(var16, (double[]){0.8, 0.2, 0.0}, 3 * sizeof(double));
                        }
                    }
                } else {
                    if (input[2] <= 9246.0) {
                        if (input[10] <= 2.5) {
                            if (input[15] <= 0.5) {
                                memcpy(var16, (double[]){0.9827586206896551, 0.0, 0.017241379310344827}, 3 * sizeof(double));
                            } else {
                                memcpy(var16, (double[]){0.9230769230769231, 0.0, 0.07692307692307693}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[9] <= 3.5) {
                                memcpy(var16, (double[]){0.8958333333333334, 0.0, 0.10416666666666667}, 3 * sizeof(double));
                            } else {
                                memcpy(var16, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[11] <= 2.5) {
                            memcpy(var16, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                        } else {
                            if (input[7] <= 0.5) {
                                memcpy(var16, (double[]){0.9705882352941176, 0.0, 0.029411764705882353}, 3 * sizeof(double));
                            } else {
                                memcpy(var16, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            } else {
                if (input[8] <= 0.5) {
                    if (input[11] <= 1.5) {
                        if (input[2] <= 9323.5) {
                            memcpy(var16, (double[]){0.5333333333333333, 0.0, 0.4666666666666667}, 3 * sizeof(double));
                        } else {
                            memcpy(var16, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                        }
                    } else {
                        if (input[18] <= 3.5) {
                            memcpy(var16, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                        } else {
                            if (input[17] <= 12.083333492279053) {
                                memcpy(var16, (double[]){0.96, 0.0, 0.04}, 3 * sizeof(double));
                            } else {
                                memcpy(var16, (double[]){0.6, 0.2, 0.2}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    if (input[15] <= 2.5) {
                        if (input[11] <= 2.5) {
                            if (input[14] <= 14.75) {
                                memcpy(var16, (double[]){0.17543859649122806, 0.017543859649122806, 0.8070175438596491}, 3 * sizeof(double));
                            } else {
                                memcpy(var16, (double[]){0.7142857142857143, 0.14285714285714285, 0.14285714285714285}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[18] <= 2.5) {
                                memcpy(var16, (double[]){0.6176470588235294, 0.0, 0.38235294117647056}, 3 * sizeof(double));
                            } else {
                                memcpy(var16, (double[]){0.3333333333333333, 0.047619047619047616, 0.6190476190476191}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[16] <= 5.5) {
                            if (input[3] <= 0.5) {
                                memcpy(var16, (double[]){0.2702702702702703, 0.13513513513513514, 0.5945945945945946}, 3 * sizeof(double));
                            } else {
                                memcpy(var16, (double[]){0.16666666666666666, 0.4382716049382716, 0.3950617283950617}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[17] <= 11.416666507720947) {
                                memcpy(var16, (double[]){0.6666666666666666, 0.11904761904761904, 0.21428571428571427}, 3 * sizeof(double));
                            } else {
                                memcpy(var16, (double[]){0.36752136752136755, 0.2222222222222222, 0.41025641025641024}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            }
        } else {
            if (input[17] <= 12.05654764175415) {
                if (input[8] <= 0.5) {
                    if (input[2] <= 9246.0) {
                        if (input[16] <= 6.5) {
                            memcpy(var16, (double[]){0.6, 0.0, 0.4}, 3 * sizeof(double));
                        } else {
                            memcpy(var16, (double[]){0.9166666666666666, 0.08333333333333333, 0.0}, 3 * sizeof(double));
                        }
                    } else {
                        if (input[1] <= 1.5) {
                            memcpy(var16, (double[]){0.8181818181818182, 0.0, 0.18181818181818182}, 3 * sizeof(double));
                        } else {
                            memcpy(var16, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                        }
                    }
                } else {
                    if (input[4] <= 0.5) {
                        if (input[2] <= 9813.0) {
                            if (input[7] <= 0.5) {
                                memcpy(var16, (double[]){0.05172413793103448, 0.7586206896551724, 0.1896551724137931}, 3 * sizeof(double));
                            } else {
                                memcpy(var16, (double[]){0.15853658536585366, 0.524390243902439, 0.3170731707317073}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[18] <= 4.5) {
                                memcpy(var16, (double[]){0.75, 0.0, 0.25}, 3 * sizeof(double));
                            } else {
                                memcpy(var16, (double[]){0.27586206896551724, 0.27586206896551724, 0.4482758620689655}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[13] <= 8.5) {
                            if (input[13] <= 6.5) {
                                memcpy(var16, (double[]){0.20253164556962025, 0.3670886075949367, 0.43037974683544306}, 3 * sizeof(double));
                            } else {
                                memcpy(var16, (double[]){0.25, 0.3, 0.45}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[18] <= 10.5) {
                                memcpy(var16, (double[]){0.5909090909090909, 0.22727272727272727, 0.18181818181818182}, 3 * sizeof(double));
                            } else {
                                memcpy(var16, (double[]){0.2, 0.8, 0.0}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            } else {
                if (input[12] <= 4.0) {
                    if (input[8] <= 0.5) {
                        if (input[17] <= 13.416666507720947) {
                            if (input[15] <= 8.5) {
                                memcpy(var16, (double[]){0.6818181818181818, 0.13636363636363635, 0.18181818181818182}, 3 * sizeof(double));
                            } else {
                                memcpy(var16, (double[]){0.9, 0.1, 0.0}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[2] <= 9184.0) {
                                memcpy(var16, (double[]){0.4444444444444444, 0.1111111111111111, 0.4444444444444444}, 3 * sizeof(double));
                            } else {
                                memcpy(var16, (double[]){0.1875, 0.6875, 0.125}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[17] <= 13.09166669845581) {
                            if (input[15] <= 5.5) {
                                memcpy(var16, (double[]){0.07446808510638298, 0.5851063829787234, 0.3404255319148936}, 3 * sizeof(double));
                            } else {
                                memcpy(var16, (double[]){0.0625, 0.7578125, 0.1796875}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[15] <= 6.5) {
                                memcpy(var16, (double[]){0.08130081300813008, 0.8021680216802168, 0.11653116531165311}, 3 * sizeof(double));
                            } else {
                                memcpy(var16, (double[]){0.06276150627615062, 0.899581589958159, 0.03765690376569038}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    memcpy(var16, (double[]){0.6666666666666666, 0.3333333333333333, 0.0}, 3 * sizeof(double));
                }
            }
        }
    } else {
        if (input[15] <= 4.5) {
            if (input[2] <= 4092.5) {
                if (input[4] <= 0.5) {
                    memcpy(var16, (double[]){0.2777777777777778, 0.7222222222222222, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var16, (double[]){0.2631578947368421, 0.5789473684210527, 0.15789473684210525}, 3 * sizeof(double));
                }
            } else {
                if (input[18] <= 3.5) {
                    if (input[13] <= 6.5) {
                        if (input[4] <= 0.5) {
                            if (input[2] <= 9192.5) {
                                memcpy(var16, (double[]){0.7619047619047619, 0.047619047619047616, 0.19047619047619047}, 3 * sizeof(double));
                            } else {
                                memcpy(var16, (double[]){0.8947368421052632, 0.10526315789473684, 0.0}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[14] <= 10.900000095367432) {
                                memcpy(var16, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var16, (double[]){0.5294117647058824, 0.0, 0.47058823529411764}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        memcpy(var16, (double[]){0.7, 0.0, 0.3}, 3 * sizeof(double));
                    }
                } else {
                    if (input[15] <= 3.5) {
                        memcpy(var16, (double[]){0.0, 0.13333333333333333, 0.8666666666666667}, 3 * sizeof(double));
                    } else {
                        if (input[9] <= 2.5) {
                            if (input[12] <= 2.5) {
                                memcpy(var16, (double[]){0.0, 0.4444444444444444, 0.5555555555555556}, 3 * sizeof(double));
                            } else {
                                memcpy(var16, (double[]){0.14285714285714285, 0.2857142857142857, 0.5714285714285714}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var16, (double[]){0.2727272727272727, 0.6363636363636364, 0.09090909090909091}, 3 * sizeof(double));
                        }
                    }
                }
            }
        } else {
            if (input[18] <= 2.5) {
                memcpy(var16, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
            } else {
                if (input[15] <= 5.5) {
                    if (input[17] <= 11.224999904632568) {
                        if (input[2] <= 9369.0) {
                            memcpy(var16, (double[]){0.0, 0.7692307692307693, 0.23076923076923078}, 3 * sizeof(double));
                        } else {
                            memcpy(var16, (double[]){0.5, 0.375, 0.125}, 3 * sizeof(double));
                        }
                    } else {
                        if (input[2] <= 9246.0) {
                            if (input[11] <= 2.5) {
                                memcpy(var16, (double[]){0.1282051282051282, 0.8205128205128205, 0.05128205128205128}, 3 * sizeof(double));
                            } else {
                                memcpy(var16, (double[]){0.0, 0.9512195121951219, 0.04878048780487805}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[14] <= 11.869999885559082) {
                                memcpy(var16, (double[]){0.0, 0.8235294117647058, 0.17647058823529413}, 3 * sizeof(double));
                            } else {
                                memcpy(var16, (double[]){0.08, 0.6, 0.32}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    if (input[2] <= 9721.5) {
                        if (input[2] <= 9138.5) {
                            if (input[15] <= 6.5) {
                                memcpy(var16, (double[]){0.020618556701030927, 0.8865979381443299, 0.09278350515463918}, 3 * sizeof(double));
                            } else {
                                memcpy(var16, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[18] <= 5.5) {
                                memcpy(var16, (double[]){0.24, 0.64, 0.12}, 3 * sizeof(double));
                            } else {
                                memcpy(var16, (double[]){0.00911854103343465, 0.9665653495440729, 0.0243161094224924}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[12] <= 1.5) {
                            if (input[7] <= 0.5) {
                                memcpy(var16, (double[]){0.25, 0.75, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var16, (double[]){0.29166666666666674, 0.6666666666666667, 0.04166666666666667}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[17] <= 12.845237731933594) {
                                memcpy(var16, (double[]){0.14705882352941177, 0.8529411764705882, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var16, (double[]){0.0, 0.967741935483871, 0.03225806451612903}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var5, var16, 3, var4);
    double var17[3];
    if (input[8] <= 0.5) {
        if (input[12] <= 2.5) {
            if (input[1] <= 2.5) {
                if (input[16] <= 5.5) {
                    if (input[12] <= 1.5) {
                        if (input[2] <= 4092.5) {
                            memcpy(var17, (double[]){0.6666666666666666, 0.08333333333333333, 0.25}, 3 * sizeof(double));
                        } else {
                            memcpy(var17, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                        }
                    } else {
                        memcpy(var17, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    if (input[16] <= 6.5) {
                        if (input[18] <= 3.5) {
                            memcpy(var17, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                        } else {
                            if (input[12] <= 1.5) {
                                memcpy(var17, (double[]){0.36363636363636365, 0.2727272727272727, 0.36363636363636365}, 3 * sizeof(double));
                            } else {
                                memcpy(var17, (double[]){0.3333333333333333, 0.1111111111111111, 0.5555555555555556}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        memcpy(var17, (double[]){0.9285714285714286, 0.07142857142857142, 0.0}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[5] <= 0.5) {
                    if (input[18] <= 5.5) {
                        if (input[18] <= 3.5) {
                            if (input[13] <= 6.5) {
                                memcpy(var17, (double[]){0.75, 0.0, 0.25}, 3 * sizeof(double));
                            } else {
                                memcpy(var17, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var17, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                        }
                    } else {
                        memcpy(var17, (double[]){0.46153846153846156, 0.38461538461538464, 0.15384615384615385}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var17, (double[]){0.38461538461538464, 0.6153846153846154, 0.0}, 3 * sizeof(double));
                }
            }
        } else {
            if (input[17] <= 12.083333492279053) {
                if (input[6] <= 0.5) {
                    memcpy(var17, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var17, (double[]){0.75, 0.1875, 0.0625}, 3 * sizeof(double));
                }
            } else {
                if (input[13] <= 6.5) {
                    memcpy(var17, (double[]){0.6, 0.3333333333333333, 0.06666666666666667}, 3 * sizeof(double));
                } else {
                    memcpy(var17, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                }
            }
        }
    } else {
        if (input[18] <= 4.5) {
            if (input[14] <= 10.099999904632568) {
                if (input[18] <= 1.5) {
                    if (input[2] <= 4092.5) {
                        if (input[1] <= 1.5) {
                            if (input[11] <= 2.5) {
                                memcpy(var17, (double[]){0.33962264150943394, 0.5094339622641509, 0.1509433962264151}, 3 * sizeof(double));
                            } else {
                                memcpy(var17, (double[]){0.18181818181818185, 0.6666666666666667, 0.15151515151515155}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[11] <= 2.5) {
                                memcpy(var17, (double[]){0.1875, 0.5, 0.3125}, 3 * sizeof(double));
                            } else {
                                memcpy(var17, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[18] <= 0.5) {
                            if (input[1] <= 3.0) {
                                memcpy(var17, (double[]){0.9528301886792453, 0.0, 0.04716981132075472}, 3 * sizeof(double));
                            } else {
                                memcpy(var17, (double[]){0.8666666666666667, 0.0, 0.13333333333333333}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[1] <= 1.5) {
                                memcpy(var17, (double[]){0.8571428571428571, 0.0, 0.14285714285714285}, 3 * sizeof(double));
                            } else {
                                memcpy(var17, (double[]){0.631578947368421, 0.0, 0.3684210526315789}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    if (input[18] <= 2.5) {
                        if (input[16] <= 5.5) {
                            memcpy(var17, (double[]){0.4166666666666667, 0.0, 0.5833333333333334}, 3 * sizeof(double));
                        } else {
                            memcpy(var17, (double[]){0.5714285714285714, 0.0, 0.42857142857142855}, 3 * sizeof(double));
                        }
                    } else {
                        if (input[12] <= 2.5) {
                            memcpy(var17, (double[]){0.2857142857142857, 0.0, 0.7142857142857143}, 3 * sizeof(double));
                        } else {
                            memcpy(var17, (double[]){0.0, 0.1111111111111111, 0.8888888888888888}, 3 * sizeof(double));
                        }
                    }
                }
            } else {
                if (input[13] <= 5.5) {
                    if (input[10] <= 4.5) {
                        if (input[1] <= 1.5) {
                            if (input[18] <= 3.5) {
                                memcpy(var17, (double[]){0.4174757281553398, 0.1262135922330097, 0.4563106796116505}, 3 * sizeof(double));
                            } else {
                                memcpy(var17, (double[]){0.06741573033707865, 0.5730337078651685, 0.3595505617977528}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[0] <= 1.5) {
                                memcpy(var17, (double[]){0.30434782608695654, 0.043478260869565216, 0.6521739130434783}, 3 * sizeof(double));
                            } else {
                                memcpy(var17, (double[]){0.375, 0.16666666666666666, 0.4583333333333333}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        memcpy(var17, (double[]){0.7272727272727273, 0.18181818181818182, 0.09090909090909091}, 3 * sizeof(double));
                    }
                } else {
                    if (input[14] <= 11.449999809265137) {
                        if (input[17] <= 12.550000190734863) {
                            if (input[14] <= 11.329166412353516) {
                                memcpy(var17, (double[]){0.43283582089552236, 0.1791044776119403, 0.3880597014925373}, 3 * sizeof(double));
                            } else {
                                memcpy(var17, (double[]){0.1, 0.1, 0.8}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var17, (double[]){0.11764705882352941, 0.8235294117647058, 0.058823529411764705}, 3 * sizeof(double));
                        }
                    } else {
                        if (input[1] <= 4.5) {
                            if (input[11] <= 2.5) {
                                memcpy(var17, (double[]){0.4785276073619632, 0.1656441717791411, 0.3558282208588957}, 3 * sizeof(double));
                            } else {
                                memcpy(var17, (double[]){0.6637168141592921, 0.1415929203539823, 0.19469026548672566}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[15] <= 5.5) {
                                memcpy(var17, (double[]){0.4482758620689655, 0.0, 0.5517241379310345}, 3 * sizeof(double));
                            } else {
                                memcpy(var17, (double[]){0.1, 0.4, 0.5}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            }
        } else {
            if (input[9] <= 3.5) {
                if (input[1] <= 1.5) {
                    if (input[18] <= 5.5) {
                        if (input[6] <= 0.5) {
                            if (input[2] <= 9377.0) {
                                memcpy(var17, (double[]){0.05555555555555555, 0.8395061728395061, 0.10493827160493827}, 3 * sizeof(double));
                            } else {
                                memcpy(var17, (double[]){0.11111111111111112, 0.46913580246913583, 0.4197530864197531}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[11] <= 2.5) {
                                memcpy(var17, (double[]){0.19607843137254902, 0.6862745098039216, 0.11764705882352941}, 3 * sizeof(double));
                            } else {
                                memcpy(var17, (double[]){0.06779661016949153, 0.7457627118644068, 0.1864406779661017}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[9] <= 2.5) {
                            if (input[14] <= 11.951249599456787) {
                                memcpy(var17, (double[]){0.06329113924050633, 0.7848101265822784, 0.1518987341772152}, 3 * sizeof(double));
                            } else {
                                memcpy(var17, (double[]){0.03481012658227848, 0.9177215189873418, 0.04746835443037975}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[4] <= 0.5) {
                                memcpy(var17, (double[]){0.046218487394957986, 0.8361344537815126, 0.11764705882352941}, 3 * sizeof(double));
                            } else {
                                memcpy(var17, (double[]){0.027777777777777776, 0.7638888888888888, 0.20833333333333334}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    if (input[17] <= 12.652083396911621) {
                        if (input[11] <= 1.5) {
                            if (input[3] <= 0.5) {
                                memcpy(var17, (double[]){0.5294117647058824, 0.4117647058823529, 0.058823529411764705}, 3 * sizeof(double));
                            } else {
                                memcpy(var17, (double[]){0.24528301886792453, 0.41509433962264153, 0.33962264150943394}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[17] <= 10.878204822540283) {
                                memcpy(var17, (double[]){0.1, 0.0, 0.9}, 3 * sizeof(double));
                            } else {
                                memcpy(var17, (double[]){0.06060606060606061, 0.6606060606060606, 0.2787878787878788}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[13] <= 6.5) {
                            if (input[16] <= 5.5) {
                                memcpy(var17, (double[]){0.02702702702702703, 0.7837837837837838, 0.1891891891891892}, 3 * sizeof(double));
                            } else {
                                memcpy(var17, (double[]){0.034782608695652174, 0.9043478260869565, 0.06086956521739131}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[16] <= 7.5) {
                                memcpy(var17, (double[]){0.1276595744680851, 0.6170212765957447, 0.2553191489361702}, 3 * sizeof(double));
                            } else {
                                memcpy(var17, (double[]){0.08411214953271028, 0.8317757009345794, 0.08411214953271028}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            } else {
                if (input[10] <= 3.5) {
                    memcpy(var17, (double[]){0.0, 0.8888888888888888, 0.1111111111111111}, 3 * sizeof(double));
                } else {
                    if (input[3] <= 0.5) {
                        memcpy(var17, (double[]){0.16666666666666666, 0.8333333333333334, 0.0}, 3 * sizeof(double));
                    } else {
                        if (input[18] <= 11.5) {
                            memcpy(var17, (double[]){0.9166666666666666, 0.08333333333333333, 0.0}, 3 * sizeof(double));
                        } else {
                            memcpy(var17, (double[]){0.3333333333333333, 0.6666666666666666, 0.0}, 3 * sizeof(double));
                        }
                    }
                }
            }
        }
    }
    add_vectors(var4, var17, 3, var3);
    double var18[3];
    if (input[14] <= 11.581249713897705) {
        if (input[15] <= 2.5) {
            if (input[6] <= 0.5) {
                if (input[13] <= 0.5) {
                    if (input[9] <= 2.5) {
                        if (input[12] <= 2.5) {
                            memcpy(var18, (double[]){0.56, 0.28, 0.16}, 3 * sizeof(double));
                        } else {
                            memcpy(var18, (double[]){0.6764705882352942, 0.3235294117647059, 0.0}, 3 * sizeof(double));
                        }
                    } else {
                        if (input[7] <= 0.5) {
                            memcpy(var18, (double[]){0.5, 0.5, 0.0}, 3 * sizeof(double));
                        } else {
                            if (input[4] <= 0.5) {
                                memcpy(var18, (double[]){0.3703703703703704, 0.40740740740740744, 0.22222222222222224}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.5, 0.2, 0.3}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    if (input[17] <= 5.0) {
                        if (input[7] <= 0.5) {
                            if (input[8] <= 0.5) {
                                memcpy(var18, (double[]){0.990909090909091, 0.0, 0.00909090909090909}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.9545454545454546, 0.0, 0.045454545454545456}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[1] <= 3.0) {
                                memcpy(var18, (double[]){0.94, 0.0, 0.06}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.7272727272727273, 0.0, 0.2727272727272727}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[15] <= 0.5) {
                            if (input[2] <= 9124.5) {
                                memcpy(var18, (double[]){0.18181818181818182, 0.0, 0.8181818181818182}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.46153846153846156, 0.15384615384615385, 0.38461538461538464}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[4] <= 0.5) {
                                memcpy(var18, (double[]){0.5789473684210527, 0.0, 0.42105263157894735}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.8620689655172413, 0.0, 0.13793103448275862}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            } else {
                if (input[7] <= 0.5) {
                    if (input[2] <= 9377.0) {
                        memcpy(var18, (double[]){0.7142857142857143, 0.2857142857142857, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.5, 0.0, 0.5}, 3 * sizeof(double));
                    }
                } else {
                    if (input[17] <= 5.0) {
                        if (input[13] <= 2.5) {
                            if (input[12] <= 2.5) {
                                memcpy(var18, (double[]){0.22727272727272727, 0.7272727272727273, 0.045454545454545456}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.2777777777777778, 0.5555555555555556, 0.16666666666666666}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var18, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                        }
                    } else {
                        memcpy(var18, (double[]){0.5, 0.0, 0.5}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[6] <= 0.5) {
                if (input[8] <= 0.5) {
                    if (input[7] <= 0.5) {
                        if (input[13] <= 8.5) {
                            if (input[1] <= 1.5) {
                                memcpy(var18, (double[]){0.875, 0.0, 0.125}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var18, (double[]){0.8571428571428571, 0.0, 0.14285714285714285}, 3 * sizeof(double));
                        }
                    } else {
                        if (input[11] <= 1.5) {
                            memcpy(var18, (double[]){0.8571428571428571, 0.14285714285714285, 0.0}, 3 * sizeof(double));
                        } else {
                            memcpy(var18, (double[]){0.875, 0.125, 0.0}, 3 * sizeof(double));
                        }
                    }
                } else {
                    if (input[13] <= 5.5) {
                        if (input[2] <= 9408.5) {
                            if (input[17] <= 10.416666507720947) {
                                memcpy(var18, (double[]){0.8571428571428571, 0.0, 0.14285714285714285}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.1, 0.2, 0.7}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[12] <= 2.5) {
                                memcpy(var18, (double[]){0.3, 0.7, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.43333333333333335, 0.1, 0.4666666666666667}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[18] <= 4.5) {
                            if (input[0] <= 1.5) {
                                memcpy(var18, (double[]){0.5657894736842105, 0.06578947368421052, 0.3684210526315789}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.6153846153846154, 0.38461538461538464, 0.0}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[10] <= 4.5) {
                                memcpy(var18, (double[]){0.25, 0.52, 0.23}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.7777777777777778, 0.2222222222222222, 0.0}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            } else {
                if (input[18] <= 5.5) {
                    if (input[2] <= 9246.0) {
                        if (input[15] <= 4.5) {
                            if (input[17] <= 11.449999809265137) {
                                memcpy(var18, (double[]){0.375, 0.375, 0.25}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.25, 0.125, 0.625}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[17] <= 11.525000095367432) {
                                memcpy(var18, (double[]){0.0, 0.625, 0.375}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[12] <= 1.5) {
                            memcpy(var18, (double[]){0.08333333333333333, 0.5833333333333334, 0.3333333333333333}, 3 * sizeof(double));
                        } else {
                            if (input[13] <= 5.5) {
                                memcpy(var18, (double[]){0.0, 0.42857142857142855, 0.5714285714285714}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.5333333333333333, 0.2, 0.26666666666666666}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    if (input[11] <= 2.5) {
                        memcpy(var18, (double[]){0.0, 0.75, 0.25}, 3 * sizeof(double));
                    } else {
                        if (input[14] <= 11.267857074737549) {
                            memcpy(var18, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                        } else {
                            memcpy(var18, (double[]){0.0, 0.9, 0.1}, 3 * sizeof(double));
                        }
                    }
                }
            }
        }
    } else {
        if (input[1] <= 1.5) {
            if (input[17] <= 11.587500095367432) {
                if (input[14] <= 13.583333492279053) {
                    if (input[15] <= 4.5) {
                        if (input[18] <= 3.5) {
                            if (input[4] <= 0.5) {
                                memcpy(var18, (double[]){0.56, 0.0, 0.44}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.88, 0.0, 0.12}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[18] <= 5.5) {
                                memcpy(var18, (double[]){0.4, 0.35, 0.25}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.1, 0.7, 0.2}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[17] <= 10.775000095367432) {
                            if (input[11] <= 1.5) {
                                memcpy(var18, (double[]){0.36363636363636365, 0.09090909090909091, 0.5454545454545454}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.6666666666666666, 0.05555555555555555, 0.2777777777777778}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[13] <= 5.5) {
                                memcpy(var18, (double[]){0.0, 0.7058823529411765, 0.29411764705882354}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.2631578947368421, 0.5131578947368421, 0.2236842105263158}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    memcpy(var18, (double[]){0.75, 0.0, 0.25}, 3 * sizeof(double));
                }
            } else {
                if (input[15] <= 5.5) {
                    if (input[2] <= 9246.0) {
                        if (input[18] <= 3.5) {
                            if (input[2] <= 9138.5) {
                                memcpy(var18, (double[]){0.6153846153846154, 0.07692307692307693, 0.3076923076923077}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.2, 0.13333333333333333, 0.6666666666666666}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[14] <= 14.366666316986084) {
                                memcpy(var18, (double[]){0.03296703296703297, 0.8076923076923077, 0.15934065934065933}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.19444444444444445, 0.8055555555555556, 0.0}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[8] <= 0.5) {
                            memcpy(var18, (double[]){0.6666666666666666, 0.0, 0.3333333333333333}, 3 * sizeof(double));
                        } else {
                            if (input[4] <= 0.5) {
                                memcpy(var18, (double[]){0.05063291139240506, 0.5189873417721519, 0.43037974683544306}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.4166666666666667, 0.3333333333333333, 0.25}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    if (input[6] <= 0.5) {
                        if (input[8] <= 0.5) {
                            memcpy(var18, (double[]){0.4444444444444445, 0.33333333333333337, 0.22222222222222224}, 3 * sizeof(double));
                        } else {
                            if (input[18] <= 4.5) {
                                memcpy(var18, (double[]){0.0, 0.3181818181818182, 0.6818181818181818}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.07909604519774012, 0.8549905838041432, 0.06591337099811675}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[13] <= 6.5) {
                            if (input[18] <= 5.5) {
                                memcpy(var18, (double[]){0.22580645161290322, 0.7096774193548387, 0.06451612903225806}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.08139534883720931, 0.877906976744186, 0.040697674418604654}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[17] <= 13.778124809265137) {
                                memcpy(var18, (double[]){0.07086614173228348, 0.9055118110236221, 0.02362204724409449}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            }
        } else {
            if (input[6] <= 0.5) {
                if (input[16] <= 7.5) {
                    if (input[15] <= 4.5) {
                        if (input[10] <= 4.5) {
                            if (input[16] <= 5.5) {
                                memcpy(var18, (double[]){0.49206349206349204, 0.14285714285714285, 0.36507936507936506}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.6777777777777778, 0.06666666666666667, 0.25555555555555554}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var18, (double[]){0.8947368421052632, 0.10526315789473684, 0.0}, 3 * sizeof(double));
                        }
                    } else {
                        if (input[17] <= 12.171428680419922) {
                            if (input[2] <= 8508.5) {
                                memcpy(var18, (double[]){0.25, 0.75, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.2280701754385965, 0.31578947368421056, 0.456140350877193}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[2] <= 9036.5) {
                                memcpy(var18, (double[]){0.015625, 0.875, 0.109375}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.17567567567567569, 0.6554054054054054, 0.16891891891891891}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    if (input[14] <= 13.690476417541504) {
                        if (input[17] <= 12.261363506317139) {
                            if (input[18] <= 6.5) {
                                memcpy(var18, (double[]){0.6666666666666666, 0.08333333333333333, 0.25}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.17142857142857143, 0.5714285714285714, 0.2571428571428571}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[8] <= 0.5) {
                                memcpy(var18, (double[]){0.75, 0.0, 0.25}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.20512820512820512, 0.717948717948718, 0.07692307692307693}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[17] <= 14.541666507720947) {
                            if (input[2] <= 9036.5) {
                                memcpy(var18, (double[]){0.09090909090909091, 0.9090909090909091, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[15] <= 12.0) {
                                memcpy(var18, (double[]){0.3333333333333333, 0.6666666666666666, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            } else {
                if (input[14] <= 12.874444484710693) {
                    if (input[7] <= 0.5) {
                        if (input[18] <= 4.5) {
                            memcpy(var18, (double[]){0.36363636363636365, 0.18181818181818182, 0.45454545454545453}, 3 * sizeof(double));
                        } else {
                            if (input[16] <= 6.5) {
                                memcpy(var18, (double[]){0.0, 0.9375, 0.0625}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.25, 0.625, 0.125}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        memcpy(var18, (double[]){0.1, 0.4, 0.5}, 3 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 3.0) {
                        if (input[12] <= 1.5) {
                            memcpy(var18, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                        } else {
                            if (input[17] <= 12.733333587646484) {
                                memcpy(var18, (double[]){0.0, 0.8571428571428571, 0.14285714285714285}, 3 * sizeof(double));
                            } else {
                                memcpy(var18, (double[]){0.0, 0.9767441860465116, 0.023255813953488372}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        memcpy(var18, (double[]){0.2857142857142857, 0.5714285714285714, 0.14285714285714285}, 3 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var3, var18, 3, var2);
    double var19[3];
    if (input[4] <= 0.5) {
        if (input[6] <= 0.5) {
            if (input[15] <= 4.5) {
                if (input[14] <= 10.291666507720947) {
                    if (input[2] <= 4092.5) {
                        if (input[9] <= 2.5) {
                            memcpy(var19, (double[]){0.42105263157894735, 0.42105263157894735, 0.15789473684210525}, 3 * sizeof(double));
                        } else {
                            memcpy(var19, (double[]){0.09523809523809523, 0.6666666666666666, 0.23809523809523808}, 3 * sizeof(double));
                        }
                    } else {
                        if (input[2] <= 9077.5) {
                            memcpy(var19, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                        } else {
                            if (input[17] <= 10.785714149475098) {
                                memcpy(var19, (double[]){0.9473684210526315, 0.0, 0.05263157894736842}, 3 * sizeof(double));
                            } else {
                                memcpy(var19, (double[]){0.5652173913043478, 0.08695652173913043, 0.34782608695652173}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    if (input[17] <= 10.224999904632568) {
                        if (input[16] <= 5.5) {
                            if (input[1] <= 1.5) {
                                memcpy(var19, (double[]){0.625, 0.125, 0.25}, 3 * sizeof(double));
                            } else {
                                memcpy(var19, (double[]){0.9375, 0.0, 0.0625}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var19, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                        }
                    } else {
                        if (input[13] <= 5.5) {
                            if (input[15] <= 3.5) {
                                memcpy(var19, (double[]){0.35106382978723405, 0.14893617021276595, 0.5}, 3 * sizeof(double));
                            } else {
                                memcpy(var19, (double[]){0.07352941176470588, 0.4852941176470588, 0.4411764705882353}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[8] <= 0.5) {
                                memcpy(var19, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var19, (double[]){0.3893805309734513, 0.20353982300884957, 0.40707964601769914}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            } else {
                if (input[15] <= 5.5) {
                    if (input[16] <= 5.5) {
                        if (input[0] <= 1.5) {
                            if (input[18] <= 4.5) {
                                memcpy(var19, (double[]){0.0, 0.47058823529411764, 0.5294117647058824}, 3 * sizeof(double));
                            } else {
                                memcpy(var19, (double[]){0.018867924528301886, 0.9433962264150944, 0.03773584905660377}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var19, (double[]){0.05555555555555555, 0.6666666666666666, 0.2777777777777778}, 3 * sizeof(double));
                        }
                    } else {
                        if (input[3] <= 0.5) {
                            if (input[14] <= 11.916666507720947) {
                                memcpy(var19, (double[]){0.42857142857142855, 0.5714285714285714, 0.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var19, (double[]){0.0, 0.8, 0.2}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[14] <= 11.815999984741211) {
                                memcpy(var19, (double[]){0.15384615384615385, 0.5641025641025641, 0.28205128205128205}, 3 * sizeof(double));
                            } else {
                                memcpy(var19, (double[]){0.3157894736842105, 0.19298245614035087, 0.49122807017543857}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    if (input[18] <= 5.5) {
                        if (input[17] <= 11.708333492279053) {
                            if (input[17] <= 10.800000190734863) {
                                memcpy(var19, (double[]){0.875, 0.0, 0.125}, 3 * sizeof(double));
                            } else {
                                memcpy(var19, (double[]){0.45, 0.4, 0.15}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[16] <= 6.5) {
                                memcpy(var19, (double[]){0.0898876404494382, 0.5842696629213483, 0.3258426966292135}, 3 * sizeof(double));
                            } else {
                                memcpy(var19, (double[]){0.75, 0.08333333333333333, 0.16666666666666666}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[16] <= 9.5) {
                            if (input[16] <= 6.5) {
                                memcpy(var19, (double[]){0.0365296803652968, 0.8904109589041096, 0.0730593607305936}, 3 * sizeof(double));
                            } else {
                                memcpy(var19, (double[]){0.05263157894736842, 0.8157894736842105, 0.13157894736842105}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[15] <= 14.5) {
                                memcpy(var19, (double[]){0.3611111111111111, 0.4861111111111111, 0.1527777777777778}, 3 * sizeof(double));
                            } else {
                                memcpy(var19, (double[]){0.06666666666666667, 0.9333333333333333, 0.0}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            }
        } else {
            if (input[18] <= 3.5) {
                if (input[8] <= 0.5) {
                    memcpy(var19, (double[]){0.8888888888888888, 0.0, 0.1111111111111111}, 3 * sizeof(double));
                } else {
                    if (input[17] <= 10.75) {
                        if (input[16] <= 2.5) {
                            memcpy(var19, (double[]){0.3, 0.65, 0.05}, 3 * sizeof(double));
                        } else {
                            if (input[14] <= 5.75) {
                                memcpy(var19, (double[]){0.8571428571428571, 0.0, 0.14285714285714285}, 3 * sizeof(double));
                            } else {
                                memcpy(var19, (double[]){0.8571428571428571, 0.14285714285714285, 0.0}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[12] <= 2.5) {
                            memcpy(var19, (double[]){0.16666666666666666, 0.4166666666666667, 0.4166666666666667}, 3 * sizeof(double));
                        } else {
                            memcpy(var19, (double[]){0.5384615384615384, 0.3076923076923077, 0.15384615384615385}, 3 * sizeof(double));
                        }
                    }
                }
            } else {
                if (input[17] <= 11.845237731933594) {
                    if (input[14] <= 10.690476417541504) {
                        memcpy(var19, (double[]){0.0, 0.08333333333333333, 0.9166666666666666}, 3 * sizeof(double));
                    } else {
                        if (input[11] <= 1.5) {
                            if (input[15] <= 5.5) {
                                memcpy(var19, (double[]){0.6666666666666666, 0.2222222222222222, 0.1111111111111111}, 3 * sizeof(double));
                            } else {
                                memcpy(var19, (double[]){0.2857142857142857, 0.7142857142857143, 0.0}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[2] <= 9377.0) {
                                memcpy(var19, (double[]){0.0, 0.8666666666666667, 0.13333333333333333}, 3 * sizeof(double));
                            } else {
                                memcpy(var19, (double[]){0.15, 0.5, 0.35}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    if (input[2] <= 9528.0) {
                        if (input[3] <= 0.5) {
                            memcpy(var19, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                        } else {
                            if (input[11] <= 2.5) {
                                memcpy(var19, (double[]){0.03184713375796178, 0.8662420382165605, 0.10191082802547771}, 3 * sizeof(double));
                            } else {
                                memcpy(var19, (double[]){0.010362694300518135, 0.9378238341968912, 0.05181347150259067}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[17] <= 13.88482141494751) {
                            if (input[10] <= 2.5) {
                                memcpy(var19, (double[]){0.06666666666666667, 0.8444444444444444, 0.08888888888888889}, 3 * sizeof(double));
                            } else {
                                memcpy(var19, (double[]){0.34782608695652173, 0.6521739130434783, 0.0}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var19, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                        }
                    }
                }
            }
        }
    } else {
        if (input[18] <= 3.5) {
            if (input[18] <= 1.5) {
                if (input[16] <= 0.5) {
                    if (input[1] <= 1.5) {
                        if (input[6] <= 0.5) {
                            if (input[11] <= 2.5) {
                                memcpy(var19, (double[]){0.52, 0.36, 0.12}, 3 * sizeof(double));
                            } else {
                                memcpy(var19, (double[]){0.3157894736842105, 0.5789473684210527, 0.10526315789473684}, 3 * sizeof(double));
                            }
                        } else {
                            memcpy(var19, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                        }
                    } else {
                        memcpy(var19, (double[]){0.5384615384615384, 0.23076923076923078, 0.23076923076923078}, 3 * sizeof(double));
                    }
                } else {
                    if (input[8] <= 0.5) {
                        memcpy(var19, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        if (input[7] <= 0.5) {
                            if (input[18] <= 0.5) {
                                memcpy(var19, (double[]){0.9772727272727273, 0.0, 0.022727272727272728}, 3 * sizeof(double));
                            } else {
                                memcpy(var19, (double[]){0.8333333333333334, 0.0, 0.16666666666666666}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[18] <= 0.5) {
                                memcpy(var19, (double[]){0.8641975308641975, 0.0, 0.13580246913580246}, 3 * sizeof(double));
                            } else {
                                memcpy(var19, (double[]){0.6470588235294118, 0.0, 0.35294117647058826}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            } else {
                if (input[10] <= 3.5) {
                    if (input[6] <= 0.5) {
                        if (input[15] <= 4.5) {
                            if (input[16] <= 5.5) {
                                memcpy(var19, (double[]){0.4805194805194805, 0.0, 0.5194805194805194}, 3 * sizeof(double));
                            } else {
                                memcpy(var19, (double[]){0.7727272727272727, 0.0, 0.22727272727272727}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[10] <= 2.5) {
                                memcpy(var19, (double[]){0.6086956521739131, 0.08695652173913043, 0.30434782608695654}, 3 * sizeof(double));
                            } else {
                                memcpy(var19, (double[]){0.18181818181818182, 0.09090909090909091, 0.7272727272727273}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[11] <= 2.5) {
                            memcpy(var19, (double[]){0.6666666666666666, 0.2222222222222222, 0.1111111111111111}, 3 * sizeof(double));
                        } else {
                            memcpy(var19, (double[]){0.0, 0.7142857142857143, 0.2857142857142857}, 3 * sizeof(double));
                        }
                    }
                } else {
                    memcpy(var19, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                }
            }
        } else {
            if (input[2] <= 4092.5) {
                if (input[17] <= 12.469696998596191) {
                    memcpy(var19, (double[]){0.16666666666666666, 0.16666666666666666, 0.6666666666666666}, 3 * sizeof(double));
                } else {
                    memcpy(var19, (double[]){0.0, 0.375, 0.625}, 3 * sizeof(double));
                }
            } else {
                if (input[2] <= 9813.0) {
                    if (input[17] <= 11.340238094329834) {
                        if (input[14] <= 11.733333110809326) {
                            if (input[15] <= 4.5) {
                                memcpy(var19, (double[]){0.5789473684210527, 0.10526315789473684, 0.3157894736842105}, 3 * sizeof(double));
                            } else {
                                memcpy(var19, (double[]){0.2, 0.65, 0.15}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[1] <= 1.5) {
                                memcpy(var19, (double[]){0.45454545454545453, 0.18181818181818182, 0.36363636363636365}, 3 * sizeof(double));
                            } else {
                                memcpy(var19, (double[]){0.4444444444444444, 0.0, 0.5555555555555556}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        if (input[18] <= 5.5) {
                            if (input[13] <= 6.5) {
                                memcpy(var19, (double[]){0.16022099447513813, 0.5414364640883977, 0.2983425414364641}, 3 * sizeof(double));
                            } else {
                                memcpy(var19, (double[]){0.761904761904762, 0.14285714285714288, 0.09523809523809525}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[13] <= 6.5) {
                                memcpy(var19, (double[]){0.037037037037037035, 0.9259259259259259, 0.037037037037037035}, 3 * sizeof(double));
                            } else {
                                memcpy(var19, (double[]){0.1, 0.7153846153846154, 0.18461538461538463}, 3 * sizeof(double));
                            }
                        }
                    }
                } else {
                    if (input[18] <= 4.5) {
                        memcpy(var19, (double[]){0.8, 0.0, 0.2}, 3 * sizeof(double));
                    } else {
                        if (input[17] <= 12.550000190734863) {
                            if (input[11] <= 2.5) {
                                memcpy(var19, (double[]){0.6, 0.26666666666666666, 0.13333333333333333}, 3 * sizeof(double));
                            } else {
                                memcpy(var19, (double[]){0.3333333333333333, 0.6666666666666666, 0.0}, 3 * sizeof(double));
                            }
                        } else {
                            if (input[11] <= 2.5) {
                                memcpy(var19, (double[]){0.0, 0.8571428571428571, 0.14285714285714285}, 3 * sizeof(double));
                            } else {
                                memcpy(var19, (double[]){0.045454545454545456, 0.7727272727272727, 0.18181818181818182}, 3 * sizeof(double));
                            }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var2, var19, 3, var1);
    mul_vector_number(var1, 0.1, 3, var0);
    memcpy(output, var0, 3 * sizeof(double));
}

#endif

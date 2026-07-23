// Modelo de prediccion de desercion estudiantil
// Generado automaticamente con m2cgen
// Features: nota_1er_sem, nota_2do_sem, materias_1er_sem,
//           materias_2do_sem, tiene_beca, pagos_al_dia,
//           edad_ingreso, ocupacion_padre, ocupacion_madre
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
    if (input[3] <= 4.5) {
        if (input[1] <= 5.0) {
            if (input[6] <= 22.5) {
                if (input[2] <= 0.5) {
                    if (input[6] <= 18.5) {
                        memcpy(var10, (double[]){0.6455696202531646, 0.25316455696202533, 0.10126582278481013}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.7669902912621359, 0.16990291262135923, 0.06310679611650485}, 3 * sizeof(double));
                    }
                } else {
                    if (input[7] <= 2.5) {
                        memcpy(var10, (double[]){0.8703703703703703, 0.0, 0.12962962962962962}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[8] <= 2.5) {
                    if (input[7] <= 2.5) {
                        memcpy(var10, (double[]){0.990990990990991, 0.0, 0.009009009009009009}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.9714285714285714, 0.0, 0.02857142857142857}, 3 * sizeof(double));
                    }
                } else {
                    if (input[6] <= 24.5) {
                        memcpy(var10, (double[]){0.7333333333333334, 0.13333333333333336, 0.13333333333333336}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.9583333333333334, 0.005952380952380952, 0.03571428571428571}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[2] <= 3.5) {
                if (input[3] <= 2.5) {
                    if (input[4] <= 0.5) {
                        memcpy(var10, (double[]){0.7103448275862069, 0.0, 0.2896551724137931}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.45454545454545453, 0.0, 0.5454545454545454}, 3 * sizeof(double));
                    }
                } else {
                    if (input[8] <= 4.0) {
                        memcpy(var10, (double[]){0.38509316770186336, 0.08074534161490683, 0.5341614906832298}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 11.366666316986084) {
                    if (input[6] <= 29.5) {
                        memcpy(var10, (double[]){0.39285714285714285, 0.2, 0.40714285714285714}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.68, 0.2, 0.12}, 3 * sizeof(double));
                    }
                } else {
                    if (input[6] <= 35.5) {
                        memcpy(var10, (double[]){0.23333333333333334, 0.31666666666666665, 0.45}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.7692307692307693, 0.11538461538461539, 0.11538461538461539}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[1] <= 10.881538391113281) {
            if (input[8] <= 1.5) {
                if (input[0] <= 11.657143115997314) {
                    memcpy(var10, (double[]){0.42857142857142855, 0.42857142857142855, 0.14285714285714285}, 3 * sizeof(double));
                } else {
                    memcpy(var10, (double[]){0.0, 0.3333333333333333, 0.6666666666666666}, 3 * sizeof(double));
                }
            } else {
                if (input[2] <= 4.5) {
                    memcpy(var10, (double[]){0.0, 0.5, 0.5}, 3 * sizeof(double));
                } else {
                    if (input[0] <= 10.900000095367432) {
                        memcpy(var10, (double[]){0.0, 0.75, 0.25}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.08695652173913043, 0.17391304347826086, 0.7391304347826086}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[6] <= 22.5) {
                if (input[3] <= 5.5) {
                    if (input[1] <= 12.460000038146973) {
                        memcpy(var10, (double[]){0.0972972972972973, 0.6324324324324324, 0.2702702702702703}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.10683760683760685, 0.7863247863247864, 0.10683760683760685}, 3 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 12.904285430908203) {
                        memcpy(var10, (double[]){0.07434052757793765, 0.8033573141486811, 0.1223021582733813}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.0572289156626506, 0.8945783132530121, 0.04819277108433735}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[5] <= 0.5) {
                    if (input[0] <= 12.792207717895508) {
                        memcpy(var10, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.4, 0.13333333333333333, 0.4666666666666667}, 3 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 13.72857141494751) {
                        memcpy(var10, (double[]){0.17391304347826086, 0.6583850931677019, 0.16770186335403728}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.026785714285714284, 0.9285714285714286, 0.044642857142857144}, 3 * sizeof(double));
                    }
                }
            }
        }
    }
    double var11[3];
    if (input[2] <= 4.5) {
        if (input[1] <= 10.208333492279053) {
            if (input[6] <= 22.5) {
                if (input[0] <= 5.0) {
                    if (input[4] <= 0.5) {
                        memcpy(var11, (double[]){0.7741935483870969, 0.14285714285714288, 0.08294930875576038}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.5344827586206896, 0.3793103448275862, 0.08620689655172414}, 3 * sizeof(double));
                    }
                } else {
                    if (input[3] <= 1.5) {
                        memcpy(var11, (double[]){0.9014084507042254, 0.0, 0.09859154929577464}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.4, 0.13333333333333333, 0.4666666666666667}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 14.449999809265137) {
                    if (input[5] <= 0.5) {
                        memcpy(var11, (double[]){0.9851851851851852, 0.0, 0.014814814814814815}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.9071729957805907, 0.02531645569620253, 0.06751054852320675}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var11, (double[]){0.7777777777777778, 0.2222222222222222, 0.0}, 3 * sizeof(double));
                }
            }
        } else {
            if (input[5] <= 0.5) {
                if (input[3] <= 3.5) {
                    if (input[3] <= 2.5) {
                        memcpy(var11, (double[]){0.8913043478260869, 0.0, 0.10869565217391304}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 12.958333492279053) {
                        memcpy(var11, (double[]){0.95, 0.0, 0.05}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.3333333333333333, 0.0, 0.6666666666666666}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[7] <= 4.0) {
                    if (input[6] <= 23.5) {
                        memcpy(var11, (double[]){0.2184873949579832, 0.27170868347338933, 0.5098039215686274}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.4585987261146497, 0.1592356687898089, 0.3821656050955414}, 3 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 11.708333492279053) {
                        memcpy(var11, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.47058823529411764, 0.23529411764705882, 0.29411764705882354}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[3] <= 4.5) {
            if (input[5] <= 0.5) {
                if (input[6] <= 22.0) {
                    if (input[3] <= 2.5) {
                        memcpy(var11, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.3125, 0.125, 0.5625}, 3 * sizeof(double));
                    }
                } else {
                    if (input[8] <= 1.5) {
                        memcpy(var11, (double[]){0.875, 0.0, 0.125}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[6] <= 35.5) {
                    if (input[1] <= 5.0) {
                        memcpy(var11, (double[]){0.8333333333333334, 0.0, 0.16666666666666666}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.1702127659574468, 0.34893617021276596, 0.4808510638297872}, 3 * sizeof(double));
                    }
                } else {
                    if (input[3] <= 2.5) {
                        memcpy(var11, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.375, 0.5, 0.125}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[5] <= 0.5) {
                if (input[4] <= 0.5) {
                    if (input[6] <= 20.5) {
                        memcpy(var11, (double[]){0.11764705882352941, 0.7058823529411765, 0.17647058823529413}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.8260869565217391, 0.043478260869565216, 0.13043478260869565}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var11, (double[]){0.14285714285714285, 0.6428571428571429, 0.21428571428571427}, 3 * sizeof(double));
                }
            } else {
                if (input[4] <= 0.5) {
                    if (input[0] <= 12.603125095367432) {
                        memcpy(var11, (double[]){0.15128205128205127, 0.617948717948718, 0.23076923076923078}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.07649513212795549, 0.8108484005563282, 0.11265646731571627}, 3 * sizeof(double));
                    }
                } else {
                    if (input[6] <= 23.5) {
                        memcpy(var11, (double[]){0.04137931034482759, 0.9172413793103449, 0.04137931034482759}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.058823529411764705, 0.8088235294117647, 0.1323529411764706}, 3 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var10, var11, 3, var9);
    double var12[3];
    if (input[6] <= 22.5) {
        if (input[3] <= 4.5) {
            if (input[0] <= 5.0) {
                if (input[5] <= 0.5) {
                    if (input[6] <= 21.0) {
                        memcpy(var12, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.875, 0.0, 0.125}, 3 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 5.0) {
                        memcpy(var12, (double[]){0.6517857142857143, 0.22767857142857142, 0.12053571428571429}, 3 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.16666666666666666, 0.05555555555555555, 0.7777777777777778}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[4] <= 0.5) {
                    if (input[3] <= 0.5) {
                        memcpy(var12, (double[]){0.9705882352941176, 0.0, 0.029411764705882353}, 3 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.3546099290780142, 0.1536643026004728, 0.491725768321513}, 3 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 10.285714149475098) {
                        memcpy(var12, (double[]){0.9333333333333333, 0.0, 0.06666666666666667}, 3 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.2631578947368421, 0.35526315789473684, 0.3815789473684211}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[2] <= 5.5) {
                if (input[7] <= 1.5) {
                    if (input[0] <= 14.449999809265137) {
                        memcpy(var12, (double[]){0.17424242424242425, 0.5075757575757576, 0.3181818181818182}, 3 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.04761904761904762, 0.8571428571428572, 0.09523809523809525}, 3 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 3.5) {
                        memcpy(var12, (double[]){0.0, 0.5862068965517241, 0.41379310344827586}, 3 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.09236947791164658, 0.7469879518072289, 0.1606425702811245}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 11.845237731933594) {
                    if (input[0] <= 11.309523582458496) {
                        memcpy(var12, (double[]){0.0, 0.4166666666666667, 0.5833333333333334}, 3 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.11494252873563218, 0.7471264367816092, 0.13793103448275862}, 3 * sizeof(double));
                    }
                } else {
                    if (input[3] <= 5.5) {
                        memcpy(var12, (double[]){0.14150943396226418, 0.7358490566037736, 0.12264150943396228}, 3 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.051648351648351645, 0.910989010989011, 0.03736263736263736}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[3] <= 3.5) {
            if (input[3] <= 0.5) {
                if (input[7] <= 2.5) {
                    if (input[8] <= 2.5) {
                        memcpy(var12, (double[]){0.963963963963964, 0.018018018018018018, 0.018018018018018018}, 3 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.8181818181818182, 0.09090909090909091, 0.09090909090909091}, 3 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 5.0) {
                        memcpy(var12, (double[]){0.9882352941176471, 0.0058823529411764705, 0.0058823529411764705}, 3 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[5] <= 0.5) {
                    if (input[1] <= 11.583333492279053) {
                        memcpy(var12, (double[]){0.8333333333333334, 0.0, 0.16666666666666666}, 3 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    if (input[8] <= 2.5) {
                        memcpy(var12, (double[]){0.4807692307692308, 0.038461538461538464, 0.4807692307692308}, 3 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.6923076923076923, 0.07692307692307693, 0.23076923076923078}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[5] <= 0.5) {
                if (input[2] <= 5.5) {
                    memcpy(var12, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                } else {
                    if (input[1] <= 12.583333492279053) {
                        memcpy(var12, (double[]){0.875, 0.125, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.4583333333333333, 0.041666666666666664, 0.5}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 4.5) {
                    if (input[4] <= 0.5) {
                        memcpy(var12, (double[]){0.23255813953488372, 0.27906976744186046, 0.4883720930232558}, 3 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.0, 0.8571428571428571, 0.14285714285714285}, 3 * sizeof(double));
                    }
                } else {
                    if (input[3] <= 12.5) {
                        memcpy(var12, (double[]){0.1275, 0.695, 0.1775}, 3 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.08823529411764706, 0.9117647058823529, 0.0}, 3 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var9, var12, 3, var8);
    double var13[3];
    if (input[3] <= 4.5) {
        if (input[2] <= 2.5) {
            if (input[6] <= 22.5) {
                if (input[3] <= 0.5) {
                    if (input[5] <= 0.5) {
                        memcpy(var13, (double[]){0.9482758620689655, 0.017241379310344827, 0.034482758620689655}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.691699604743083, 0.18181818181818182, 0.12648221343873517}, 3 * sizeof(double));
                    }
                } else {
                    if (input[5] <= 0.5) {
                        memcpy(var13, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.4714285714285714, 0.014285714285714285, 0.5142857142857142}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 1.5) {
                    if (input[3] <= 0.5) {
                        memcpy(var13, (double[]){0.9783393501805054, 0.007220216606498195, 0.01444043321299639}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.9, 0.0, 0.1}, 3 * sizeof(double));
                    }
                } else {
                    if (input[5] <= 0.5) {
                        memcpy(var13, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.6764705882352942, 0.029411764705882353, 0.29411764705882354}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[5] <= 0.5) {
                if (input[6] <= 24.5) {
                    if (input[2] <= 3.5) {
                        memcpy(var13, (double[]){0.9583333333333334, 0.0, 0.041666666666666664}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.6607142857142857, 0.07142857142857142, 0.26785714285714285}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var13, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                }
            } else {
                if (input[3] <= 3.5) {
                    if (input[1] <= 5.0) {
                        memcpy(var13, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.4057971014492754, 0.10507246376811594, 0.4891304347826087}, 3 * sizeof(double));
                    }
                } else {
                    if (input[6] <= 24.5) {
                        memcpy(var13, (double[]){0.20425531914893616, 0.425531914893617, 0.3702127659574468}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.21428571428571427, 0.21428571428571427, 0.5714285714285714}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[0] <= 11.654762268066406) {
            if (input[2] <= 9.5) {
                if (input[5] <= 0.5) {
                    memcpy(var13, (double[]){0.9090909090909091, 0.09090909090909091, 0.0}, 3 * sizeof(double));
                } else {
                    if (input[3] <= 6.5) {
                        memcpy(var13, (double[]){0.08287292817679558, 0.6629834254143646, 0.2541436464088398}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.0, 0.39285714285714285, 0.6071428571428571}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 10.925824165344238) {
                    memcpy(var13, (double[]){0.11111111111111112, 0.6666666666666667, 0.22222222222222224}, 3 * sizeof(double));
                } else {
                    if (input[8] <= 2.5) {
                        memcpy(var13, (double[]){0.625, 0.375, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.7692307692307693, 0.07692307692307693, 0.15384615384615385}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[6] <= 22.5) {
                if (input[2] <= 5.5) {
                    if (input[5] <= 0.5) {
                        memcpy(var13, (double[]){0.4117647058823529, 0.23529411764705882, 0.35294117647058826}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.07920792079207921, 0.7425742574257426, 0.1782178217821782}, 3 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 14.06458330154419) {
                        memcpy(var13, (double[]){0.07722513089005235, 0.849476439790576, 0.07329842931937172}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.034482758620689655, 0.9467084639498433, 0.018808777429467086}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[5] <= 0.5) {
                    if (input[8] <= 2.5) {
                        memcpy(var13, (double[]){0.5, 0.1, 0.4}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.9230769230769231, 0.0, 0.07692307692307693}, 3 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 12.261363506317139) {
                        memcpy(var13, (double[]){0.17777777777777778, 0.5555555555555556, 0.26666666666666666}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.14285714285714285, 0.7669172932330827, 0.09022556390977443}, 3 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var8, var13, 3, var7);
    double var14[3];
    if (input[6] <= 22.5) {
        if (input[2] <= 4.5) {
            if (input[3] <= 1.5) {
                if (input[1] <= 12.5) {
                    if (input[0] <= 5.0) {
                        memcpy(var14, (double[]){0.703448275862069, 0.20344827586206898, 0.09310344827586209}, 3 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.9295774647887324, 0.0, 0.07042253521126761}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var14, (double[]){0.375, 0.0, 0.625}, 3 * sizeof(double));
                }
            } else {
                if (input[5] <= 0.5) {
                    if (input[0] <= 12.583333492279053) {
                        memcpy(var14, (double[]){0.8571428571428571, 0.02857142857142857, 0.11428571428571428}, 3 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 11.366666316986084) {
                        memcpy(var14, (double[]){0.4230769230769231, 0.12307692307692308, 0.45384615384615384}, 3 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.12871287128712872, 0.37623762376237624, 0.49504950495049505}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[3] <= 4.5) {
                if (input[2] <= 5.5) {
                    if (input[5] <= 0.5) {
                        memcpy(var14, (double[]){0.7333333333333333, 0.0, 0.26666666666666666}, 3 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.1984732824427481, 0.3053435114503817, 0.4961832061068702}, 3 * sizeof(double));
                    }
                } else {
                    if (input[7] <= 2.5) {
                        memcpy(var14, (double[]){0.36764705882352944, 0.4411764705882353, 0.19117647058823528}, 3 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.3548387096774194, 0.22580645161290322, 0.41935483870967744}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[3] <= 5.5) {
                    if (input[5] <= 0.5) {
                        memcpy(var14, (double[]){0.38461538461538464, 0.07692307692307693, 0.5384615384615384}, 3 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.11564625850340136, 0.6938775510204082, 0.19047619047619047}, 3 * sizeof(double));
                    }
                } else {
                    if (input[4] <= 0.5) {
                        memcpy(var14, (double[]){0.05799373040752351, 0.8401253918495298, 0.10188087774294671}, 3 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.03777335984095427, 0.9244532803180915, 0.03777335984095427}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[1] <= 11.038461685180664) {
            if (input[3] <= 3.5) {
                if (input[0] <= 14.833333492279053) {
                    if (input[4] <= 0.5) {
                        memcpy(var14, (double[]){0.9243243243243243, 0.008108108108108109, 0.06756756756756757}, 3 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.5416666666666666, 0.08333333333333333, 0.375}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var14, (double[]){0.4, 0.4, 0.2}, 3 * sizeof(double));
                }
            } else {
                if (input[6] <= 37.0) {
                    if (input[2] <= 5.5) {
                        memcpy(var14, (double[]){0.20833333333333334, 0.16666666666666666, 0.625}, 3 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.6470588235294118, 0.17647058823529413, 0.17647058823529413}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var14, (double[]){0.2222222222222222, 0.7777777777777778, 0.0}, 3 * sizeof(double));
                }
            }
        } else {
            if (input[1] <= 12.151428699493408) {
                if (input[5] <= 0.5) {
                    if (input[6] <= 31.5) {
                        memcpy(var14, (double[]){0.9696969696969697, 0.0, 0.030303030303030304}, 3 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.8888888888888888, 0.1111111111111111, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    if (input[6] <= 26.5) {
                        memcpy(var14, (double[]){0.24324324324324326, 0.21621621621621623, 0.5405405405405406}, 3 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.2127659574468085, 0.5319148936170213, 0.2553191489361702}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 11.577777862548828) {
                    if (input[0] <= 11.313888549804688) {
                        memcpy(var14, (double[]){0.2894736842105263, 0.4473684210526316, 0.2631578947368421}, 3 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.7037037037037037, 0.0, 0.2962962962962963}, 3 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 4.5) {
                        memcpy(var14, (double[]){0.40540540540540543, 0.1891891891891892, 0.40540540540540543}, 3 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.12424242424242424, 0.7757575757575758, 0.1}, 3 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var7, var14, 3, var6);
    double var15[3];
    if (input[2] <= 4.5) {
        if (input[1] <= 5.0) {
            if (input[5] <= 0.5) {
                if (input[0] <= 5.0) {
                    if (input[7] <= 1.5) {
                        memcpy(var15, (double[]){0.9473684210526316, 0.01754385964912281, 0.03508771929824562}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.9905660377358491, 0.009433962264150943, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var15, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                }
            } else {
                if (input[4] <= 0.5) {
                    if (input[7] <= 1.5) {
                        memcpy(var15, (double[]){0.7703703703703704, 0.11851851851851852, 0.1111111111111111}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.8885017421602788, 0.06620209059233449, 0.04529616724738676}, 3 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 0.5) {
                        memcpy(var15, (double[]){0.38596491228070173, 0.5263157894736842, 0.08771929824561403}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[5] <= 0.5) {
                if (input[0] <= 12.125) {
                    if (input[8] <= 1.5) {
                        memcpy(var15, (double[]){0.9230769230769231, 0.0, 0.07692307692307693}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.9791666666666666, 0.020833333333333332, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    if (input[6] <= 20.5) {
                        memcpy(var15, (double[]){0.9411764705882353, 0.0, 0.058823529411764705}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.7916666666666666, 0.0, 0.20833333333333334}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[6] <= 21.5) {
                    if (input[3] <= 3.5) {
                        memcpy(var15, (double[]){0.4, 0.05405405405405406, 0.5459459459459459}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.12077294685990338, 0.42028985507246375, 0.45893719806763283}, 3 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 11.309523582458496) {
                        memcpy(var15, (double[]){0.5833333333333334, 0.2, 0.21666666666666667}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.4426229508196721, 0.07377049180327869, 0.48360655737704916}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[3] <= 4.5) {
            if (input[1] <= 5.0) {
                if (input[0] <= 12.808333396911621) {
                    memcpy(var15, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var15, (double[]){0.8333333333333334, 0.0, 0.16666666666666666}, 3 * sizeof(double));
                }
            } else {
                if (input[5] <= 0.5) {
                    if (input[1] <= 11.708333492279053) {
                        memcpy(var15, (double[]){0.7619047619047619, 0.0, 0.23809523809523808}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.8823529411764706, 0.058823529411764705, 0.058823529411764705}, 3 * sizeof(double));
                    }
                } else {
                    if (input[7] <= 1.5) {
                        memcpy(var15, (double[]){0.1368421052631579, 0.2631578947368421, 0.6}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.23529411764705882, 0.43790849673202614, 0.32679738562091504}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[6] <= 22.5) {
                if (input[0] <= 12.622499942779541) {
                    if (input[4] <= 0.5) {
                        memcpy(var15, (double[]){0.08996539792387544, 0.6955017301038062, 0.21453287197231835}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.03409090909090909, 0.8806818181818182, 0.08522727272727272}, 3 * sizeof(double));
                    }
                } else {
                    if (input[5] <= 0.5) {
                        memcpy(var15, (double[]){0.4, 0.6, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.044919786096256686, 0.8802139037433155, 0.0748663101604278}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 12.225397109985352) {
                    if (input[8] <= 1.5) {
                        memcpy(var15, (double[]){0.6, 0.16666666666666666, 0.23333333333333334}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.26666666666666666, 0.5037037037037037, 0.22962962962962963}, 3 * sizeof(double));
                    }
                } else {
                    if (input[5] <= 0.5) {
                        memcpy(var15, (double[]){0.5, 0.2, 0.3}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.10931174089068826, 0.7692307692307693, 0.1214574898785425}, 3 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var6, var15, 3, var5);
    double var16[3];
    if (input[1] <= 11.154762268066406) {
        if (input[3] <= 0.5) {
            if (input[5] <= 0.5) {
                if (input[6] <= 19.5) {
                    if (input[8] <= 1.5) {
                        memcpy(var16, (double[]){0.75, 0.25, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.9545454545454546, 0.045454545454545456, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    if (input[7] <= 1.5) {
                        memcpy(var16, (double[]){0.9811320754716981, 0.0, 0.018867924528301886}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[4] <= 0.5) {
                    if (input[2] <= 0.5) {
                        memcpy(var16, (double[]){0.815625, 0.13125, 0.053125}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.9058823529411765, 0.0, 0.09411764705882353}, 3 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 4.900000095367432) {
                        memcpy(var16, (double[]){0.4727272727272727, 0.41818181818181815, 0.10909090909090909}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[3] <= 5.5) {
                if (input[5] <= 0.5) {
                    if (input[0] <= 12.099999904632568) {
                        memcpy(var16, (double[]){0.9814814814814815, 0.0, 0.018518518518518517}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.7142857142857143, 0.0, 0.2857142857142857}, 3 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 13.295000076293945) {
                        memcpy(var16, (double[]){0.3907563025210084, 0.13445378151260504, 0.47478991596638653}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.0, 0.06666666666666667, 0.9333333333333333}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[7] <= 2.5) {
                    if (input[6] <= 20.5) {
                        memcpy(var16, (double[]){0.0, 0.8333333333333334, 0.16666666666666666}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.375, 0.625, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    if (input[4] <= 0.5) {
                        memcpy(var16, (double[]){0.0, 0.4444444444444444, 0.5555555555555556}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.0, 0.8461538461538461, 0.15384615384615385}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[3] <= 4.5) {
            if (input[4] <= 0.5) {
                if (input[5] <= 0.5) {
                    if (input[8] <= 1.5) {
                        memcpy(var16, (double[]){0.6486486486486487, 0.0, 0.35135135135135137}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.9565217391304348, 0.0, 0.043478260869565216}, 3 * sizeof(double));
                    }
                } else {
                    if (input[3] <= 3.5) {
                        memcpy(var16, (double[]){0.385, 0.06, 0.555}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.23316062176165805, 0.3678756476683938, 0.3989637305699482}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[5] <= 0.5) {
                    memcpy(var16, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                } else {
                    if (input[2] <= 4.5) {
                        memcpy(var16, (double[]){0.30303030303030304, 0.18181818181818182, 0.5151515151515151}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.2702702702702703, 0.7297297297297297, 0.0}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[4] <= 0.5) {
                if (input[2] <= 4.5) {
                    if (input[7] <= 2.5) {
                        memcpy(var16, (double[]){0.12698412698412698, 0.6507936507936508, 0.2222222222222222}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.36363636363636365, 0.36363636363636365, 0.2727272727272727}, 3 * sizeof(double));
                    }
                } else {
                    if (input[6] <= 22.5) {
                        memcpy(var16, (double[]){0.0625, 0.825, 0.1125}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.2529411764705882, 0.6029411764705882, 0.14411764705882352}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[3] <= 5.5) {
                    if (input[0] <= 11.387499809265137) {
                        memcpy(var16, (double[]){0.06666666666666667, 0.6, 0.3333333333333333}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.10679611650485436, 0.7669902912621359, 0.1262135922330097}, 3 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 13.295000076293945) {
                        memcpy(var16, (double[]){0.048109965635738834, 0.8934707903780069, 0.058419243986254296}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.007246376811594203, 0.9746376811594203, 0.018115942028985508}, 3 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var5, var16, 3, var4);
    double var17[3];
    if (input[0] <= 10.784615516662598) {
        if (input[3] <= 1.5) {
            if (input[6] <= 24.5) {
                if (input[8] <= 2.5) {
                    if (input[3] <= 0.5) {
                        memcpy(var17, (double[]){0.6736401673640168, 0.18410041841004185, 0.14225941422594143}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.5, 0.0, 0.5}, 3 * sizeof(double));
                    }
                } else {
                    if (input[6] <= 18.5) {
                        memcpy(var17, (double[]){0.6086956521739131, 0.30434782608695654, 0.08695652173913043}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.84375, 0.125, 0.03125}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[7] <= 1.5) {
                    if (input[6] <= 26.5) {
                        memcpy(var17, (double[]){0.8181818181818182, 0.09090909090909091, 0.09090909090909091}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.9772727272727273, 0.0, 0.022727272727272728}, 3 * sizeof(double));
                    }
                } else {
                    if (input[5] <= 0.5) {
                        memcpy(var17, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.9596774193548387, 0.0, 0.04032258064516129}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[5] <= 0.5) {
                if (input[2] <= 4.0) {
                    memcpy(var17, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var17, (double[]){0.7142857142857143, 0.2857142857142857, 0.0}, 3 * sizeof(double));
                }
            } else {
                if (input[4] <= 0.5) {
                    if (input[0] <= 10.732142925262451) {
                        memcpy(var17, (double[]){0.189873417721519, 0.189873417721519, 0.620253164556962}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.8421052631578947, 0.10526315789473684, 0.05263157894736842}, 3 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 3.5) {
                        memcpy(var17, (double[]){0.1, 0.1, 0.8}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.07692307692307693, 0.5384615384615384, 0.38461538461538464}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[3] <= 4.5) {
            if (input[8] <= 2.5) {
                if (input[1] <= 5.0) {
                    if (input[8] <= 1.5) {
                        memcpy(var17, (double[]){0.9782608695652174, 0.0, 0.021739130434782608}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.92, 0.0, 0.08}, 3 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 4.5) {
                        memcpy(var17, (double[]){0.4007936507936508, 0.11507936507936507, 0.48412698412698413}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.2468354430379747, 0.379746835443038, 0.37341772151898733}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[5] <= 0.5) {
                    if (input[1] <= 10.166666507720947) {
                        memcpy(var17, (double[]){0.9615384615384616, 0.0, 0.038461538461538464}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    if (input[3] <= 1.5) {
                        memcpy(var17, (double[]){0.9333333333333333, 0.0, 0.06666666666666667}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.366120218579235, 0.29508196721311475, 0.33879781420765026}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[3] <= 5.5) {
                if (input[0] <= 12.267857074737549) {
                    if (input[6] <= 20.5) {
                        memcpy(var17, (double[]){0.1297709923664122, 0.648854961832061, 0.22137404580152673}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.4065934065934066, 0.38461538461538464, 0.2087912087912088}, 3 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 13.775000095367432) {
                        memcpy(var17, (double[]){0.1016949152542373, 0.652542372881356, 0.2457627118644068}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.07291666666666667, 0.8020833333333334, 0.125}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[5] <= 0.5) {
                    if (input[0] <= 12.431818008422852) {
                        memcpy(var17, (double[]){0.9285714285714286, 0.07142857142857142, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.34615384615384615, 0.5769230769230769, 0.07692307692307693}, 3 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 12.549602508544922) {
                        memcpy(var17, (double[]){0.07906976744186046, 0.7348837209302326, 0.18604651162790697}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.043434343434343436, 0.8898989898989899, 0.06666666666666667}, 3 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var4, var17, 3, var3);
    double var18[3];
    if (input[2] <= 4.5) {
        if (input[5] <= 0.5) {
            if (input[4] <= 0.5) {
                if (input[1] <= 13.299999713897705) {
                    if (input[8] <= 1.5) {
                        memcpy(var18, (double[]){0.9239130434782609, 0.010869565217391304, 0.06521739130434782}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.989795918367347, 0.005102040816326531, 0.005102040816326531}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var18, (double[]){0.7692307692307693, 0.0, 0.23076923076923078}, 3 * sizeof(double));
                }
            } else {
                if (input[1] <= 5.0) {
                    memcpy(var18, (double[]){0.8, 0.2, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var18, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                }
            }
        } else {
            if (input[3] <= 2.5) {
                if (input[3] <= 0.5) {
                    if (input[6] <= 18.5) {
                        memcpy(var18, (double[]){0.41975308641975306, 0.37037037037037035, 0.20987654320987653}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.849624060150376, 0.08270676691729323, 0.06766917293233082}, 3 * sizeof(double));
                    }
                } else {
                    if (input[6] <= 27.5) {
                        memcpy(var18, (double[]){0.5098039215686274, 0.0, 0.49019607843137253}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.8979591836734694, 0.02040816326530612, 0.08163265306122448}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[3] <= 4.5) {
                    if (input[3] <= 3.5) {
                        memcpy(var18, (double[]){0.35833333333333334, 0.08333333333333333, 0.5583333333333333}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.18439716312056736, 0.2978723404255319, 0.5177304964539007}, 3 * sizeof(double));
                    }
                } else {
                    if (input[3] <= 5.5) {
                        memcpy(var18, (double[]){0.06481481481481481, 0.6296296296296297, 0.3055555555555556}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.16216216216216217, 0.6486486486486487, 0.1891891891891892}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[0] <= 11.651190757751465) {
            if (input[3] <= 10.5) {
                if (input[5] <= 0.5) {
                    if (input[2] <= 5.5) {
                        memcpy(var18, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.7142857142857143, 0.14285714285714285, 0.14285714285714285}, 3 * sizeof(double));
                    }
                } else {
                    if (input[4] <= 0.5) {
                        memcpy(var18, (double[]){0.2658227848101266, 0.42405063291139244, 0.31012658227848106}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.05333333333333334, 0.76, 0.18666666666666668}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 10.873376846313477) {
                    memcpy(var18, (double[]){0.375, 0.625, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var18, (double[]){0.8888888888888888, 0.05555555555555555, 0.05555555555555555}, 3 * sizeof(double));
                }
            }
        } else {
            if (input[5] <= 0.5) {
                if (input[8] <= 2.5) {
                    if (input[3] <= 3.5) {
                        memcpy(var18, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.4, 0.28, 0.32}, 3 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 12.361111164093018) {
                        memcpy(var18, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.5833333333333334, 0.25, 0.16666666666666666}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[4] <= 0.5) {
                    if (input[3] <= 4.5) {
                        memcpy(var18, (double[]){0.27350427350427353, 0.26495726495726496, 0.46153846153846156}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.08768656716417911, 0.7947761194029851, 0.11753731343283583}, 3 * sizeof(double));
                    }
                } else {
                    if (input[3] <= 3.5) {
                        memcpy(var18, (double[]){0.7142857142857143, 0.14285714285714285, 0.14285714285714285}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.057283142389525366, 0.8968903436988543, 0.04582651391162029}, 3 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var3, var18, 3, var2);
    double var19[3];
    if (input[0] <= 11.563491821289062) {
        if (input[1] <= 10.083333492279053) {
            if (input[5] <= 0.5) {
                if (input[3] <= 0.5) {
                    if (input[6] <= 22.5) {
                        memcpy(var19, (double[]){0.9433962264150944, 0.018867924528301886, 0.03773584905660377}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var19, (double[]){0.8888888888888888, 0.0, 0.1111111111111111}, 3 * sizeof(double));
                }
            } else {
                if (input[7] <= 3.5) {
                    if (input[0] <= 5.0) {
                        memcpy(var19, (double[]){0.739946380697051, 0.1769436997319035, 0.08310991957104558}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.7792207792207793, 0.0, 0.22077922077922077}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var19, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                }
            }
        } else {
            if (input[4] <= 0.5) {
                if (input[6] <= 20.5) {
                    if (input[3] <= 3.5) {
                        memcpy(var19, (double[]){0.4642857142857143, 0.023809523809523808, 0.5119047619047619}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.10476190476190476, 0.5333333333333333, 0.3619047619047619}, 3 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 4.5) {
                        memcpy(var19, (double[]){0.5973154362416108, 0.0738255033557047, 0.3288590604026846}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.41, 0.37, 0.22}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 10.690476417541504) {
                    if (input[7] <= 2.5) {
                        memcpy(var19, (double[]){0.5454545454545454, 0.2727272727272727, 0.18181818181818182}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.13333333333333333, 0.13333333333333333, 0.7333333333333333}, 3 * sizeof(double));
                    }
                } else {
                    if (input[6] <= 18.5) {
                        memcpy(var19, (double[]){0.1111111111111111, 0.8333333333333334, 0.05555555555555555}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.17857142857142858, 0.5714285714285714, 0.25}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[1] <= 11.340238094329834) {
            if (input[3] <= 1.5) {
                if (input[1] <= 5.0) {
                    memcpy(var19, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                } else {
                    if (input[0] <= 12.449999809265137) {
                        memcpy(var19, (double[]){0.9090909090909091, 0.0, 0.09090909090909091}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.6, 0.0, 0.4}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[3] <= 4.5) {
                    if (input[5] <= 0.5) {
                        memcpy(var19, (double[]){0.92, 0.0, 0.08}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.39473684210526316, 0.10526315789473684, 0.5}, 3 * sizeof(double));
                    }
                } else {
                    if (input[6] <= 20.5) {
                        memcpy(var19, (double[]){0.05405405405405406, 0.4864864864864865, 0.4594594594594595}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.5151515151515151, 0.2727272727272727, 0.21212121212121213}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[4] <= 0.5) {
                if (input[3] <= 4.5) {
                    if (input[0] <= 14.550000190734863) {
                        memcpy(var19, (double[]){0.3726937269372694, 0.22140221402214022, 0.4059040590405904}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.8888888888888888, 0.0, 0.1111111111111111}, 3 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 5.5) {
                        memcpy(var19, (double[]){0.11564625850340136, 0.6326530612244898, 0.25170068027210885}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.08502994011976048, 0.7976047904191617, 0.11736526946107785}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[5] <= 0.5) {
                    memcpy(var19, (double[]){0.5384615384615384, 0.38461538461538464, 0.07692307692307693}, 3 * sizeof(double));
                } else {
                    if (input[1] <= 12.90071439743042) {
                        memcpy(var19, (double[]){0.07053941908713693, 0.8091286307053942, 0.12033195020746888}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.03825136612021858, 0.912568306010929, 0.04918032786885246}, 3 * sizeof(double));
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

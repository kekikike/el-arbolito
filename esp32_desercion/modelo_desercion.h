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
                        memcpy(var10, (double[]){0.9210526315789473, 0.0, 0.07894736842105263}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    if (input[10] <= 2.5) {
                        memcpy(var10, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.9259259259259259, 0.037037037037037035, 0.037037037037037035}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[13] <= 0.5) {
                    if (input[12] <= 2.5) {
                        memcpy(var10, (double[]){0.32530120481927716, 0.5783132530120483, 0.09638554216867472}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.6571428571428571, 0.2571428571428571, 0.08571428571428572}, 3 * sizeof(double));
                    }
                } else {
                    if (input[10] <= 2.5) {
                        memcpy(var10, (double[]){0.9036144578313253, 0.0, 0.0963855421686747}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.9747899159663865, 0.0, 0.025210084033613446}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[1] <= 2.5) {
                if (input[8] <= 0.5) {
                    memcpy(var10, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                } else {
                    if (input[14] <= 5.0) {
                        memcpy(var10, (double[]){0.8333333333333334, 0.0, 0.16666666666666666}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.3333333333333333, 0.0, 0.6666666666666666}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[10] <= 2.5) {
                    memcpy(var10, (double[]){0.4117647058823529, 0.0, 0.5882352941176471}, 3 * sizeof(double));
                } else {
                    memcpy(var10, (double[]){0.5, 0.16666666666666666, 0.3333333333333333}, 3 * sizeof(double));
                }
            }
        }
    } else {
        if (input[15] <= 4.5) {
            if (input[17] <= 5.0) {
                if (input[2] <= 9102.0) {
                    if (input[9] <= 2.5) {
                        memcpy(var10, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.6666666666666666, 0.0, 0.3333333333333333}, 3 * sizeof(double));
                    }
                } else {
                    if (input[16] <= 5.5) {
                        memcpy(var10, (double[]){0.9629629629629629, 0.0, 0.037037037037037035}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[18] <= 3.5) {
                    if (input[8] <= 0.5) {
                        memcpy(var10, (double[]){0.9076923076923077, 0.0, 0.09230769230769231}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.5022222222222222, 0.03111111111111111, 0.4666666666666667}, 3 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 9246.0) {
                        memcpy(var10, (double[]){0.15675675675675677, 0.5351351351351351, 0.3081081081081081}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.3221476510067114, 0.26174496644295303, 0.4161073825503356}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[15] <= 5.5) {
                if (input[2] <= 9377.0) {
                    if (input[16] <= 6.5) {
                        memcpy(var10, (double[]){0.08847184986595175, 0.6621983914209115, 0.24932975871313673}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.8666666666666667, 0.06666666666666667, 0.06666666666666667}, 3 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 1.5) {
                        memcpy(var10, (double[]){0.18965517241379312, 0.37931034482758624, 0.4310344827586207}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.36046511627906974, 0.47674418604651164, 0.16279069767441862}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[17] <= 11.330952167510986) {
                    if (input[8] <= 0.5) {
                        memcpy(var10, (double[]){0.875, 0.0, 0.125}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.3373493975903614, 0.4819277108433735, 0.18072289156626506}, 3 * sizeof(double));
                    }
                } else {
                    if (input[14] <= 11.781745910644531) {
                        memcpy(var10, (double[]){0.1891891891891892, 0.6351351351351351, 0.17567567567567569}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.08702175543885972, 0.8237059264816204, 0.08927231807951988}, 3 * sizeof(double));
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
                        memcpy(var11, (double[]){0.9130434782608695, 0.0, 0.08695652173913043}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.9616519174041298, 0.0, 0.038348082595870206}, 3 * sizeof(double));
                    }
                } else {
                    if (input[17] <= 11.833333492279053) {
                        memcpy(var11, (double[]){0.4074074074074074, 0.0, 0.5925925925925926}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.7368421052631579, 0.05263157894736842, 0.21052631578947367}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[15] <= 2.5) {
                if (input[17] <= 5.0) {
                    if (input[9] <= 2.5) {
                        memcpy(var11, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.9444444444444444, 0.0, 0.05555555555555555}, 3 * sizeof(double));
                    }
                } else {
                    if (input[18] <= 2.5) {
                        memcpy(var11, (double[]){0.6909090909090909, 0.0, 0.3090909090909091}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.3191489361702128, 0.1276595744680851, 0.5531914893617021}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 1.5) {
                    if (input[11] <= 1.5) {
                        memcpy(var11, (double[]){0.4895833333333333, 0.15625, 0.3541666666666667}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.24786324786324787, 0.32051282051282054, 0.43162393162393164}, 3 * sizeof(double));
                    }
                } else {
                    if (input[13] <= 5.5) {
                        memcpy(var11, (double[]){0.3516483516483517, 0.21978021978021978, 0.42857142857142855}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.6739130434782609, 0.08695652173913043, 0.2391304347826087}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[1] <= 1.5) {
            if (input[14] <= 12.208571434020996) {
                if (input[16] <= 9.5) {
                    if (input[18] <= 4.5) {
                        memcpy(var11, (double[]){0.19834710743801653, 0.34710743801652894, 0.45454545454545453}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.09259259259259259, 0.7731481481481481, 0.13425925925925927}, 3 * sizeof(double));
                    }
                } else {
                    if (input[11] <= 2.5) {
                        memcpy(var11, (double[]){0.0, 0.5555555555555556, 0.4444444444444444}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.9090909090909091, 0.09090909090909091, 0.0}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[15] <= 5.5) {
                    if (input[7] <= 0.5) {
                        memcpy(var11, (double[]){0.06493506493506493, 0.7662337662337663, 0.16883116883116883}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.1527777777777778, 0.5486111111111112, 0.2986111111111111}, 3 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 9613.0) {
                        memcpy(var11, (double[]){0.059154929577464786, 0.8816901408450705, 0.059154929577464786}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.13157894736842107, 0.7736842105263159, 0.09473684210526317}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[6] <= 0.5) {
                if (input[17] <= 12.70714282989502) {
                    if (input[17] <= 10.633333683013916) {
                        memcpy(var11, (double[]){0.4782608695652174, 0.0, 0.5217391304347826}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.28294573643410853, 0.4263565891472868, 0.29069767441860467}, 3 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 9246.0) {
                        memcpy(var11, (double[]){0.22289156626506024, 0.5843373493975904, 0.1927710843373494}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.07692307692307693, 0.8021978021978022, 0.12087912087912088}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[17] <= 11.989999771118164) {
                    if (input[18] <= 5.5) {
                        memcpy(var11, (double[]){0.0, 0.5714285714285714, 0.42857142857142855}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.04347826086956522, 0.7391304347826088, 0.2173913043478261}, 3 * sizeof(double));
                    }
                } else {
                    if (input[12] <= 1.5) {
                        memcpy(var11, (double[]){0.11428571428571428, 0.8571428571428571, 0.02857142857142857}, 3 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.041666666666666664, 0.9583333333333334, 0.0}, 3 * sizeof(double));
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
                        memcpy(var12, (double[]){0.9757785467128027, 0.0, 0.02422145328719723}, 3 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.3793103448275862, 0.06896551724137931, 0.5517241379310345}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[13] <= 1.0) {
                    if (input[8] <= 0.5) {
                        memcpy(var12, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.36, 0.49, 0.15}, 3 * sizeof(double));
                    }
                } else {
                    if (input[18] <= 0.5) {
                        memcpy(var12, (double[]){0.967032967032967, 0.0, 0.03296703296703297}, 3 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.3620689655172414, 0.1206896551724138, 0.5172413793103449}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[13] <= 5.5) {
                if (input[18] <= 4.5) {
                    if (input[15] <= 2.5) {
                        memcpy(var12, (double[]){0.48333333333333334, 0.016666666666666666, 0.5}, 3 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.2159090909090909, 0.24431818181818182, 0.5397727272727273}, 3 * sizeof(double));
                    }
                } else {
                    if (input[11] <= 1.5) {
                        memcpy(var12, (double[]){0.16666666666666666, 0.6025641025641025, 0.23076923076923078}, 3 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.03676470588235294, 0.8308823529411765, 0.1323529411764706}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[18] <= 4.5) {
                    if (input[12] <= 2.5) {
                        memcpy(var12, (double[]){0.3425925925925926, 0.21296296296296297, 0.4444444444444444}, 3 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.5641025641025641, 0.23931623931623933, 0.19658119658119658}, 3 * sizeof(double));
                    }
                } else {
                    if (input[12] <= 4.5) {
                        memcpy(var12, (double[]){0.08255741775294848, 0.8063314711359404, 0.1111111111111111}, 3 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.5483870967741935, 0.45161290322580644, 0.0}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[18] <= 4.5) {
            if (input[14] <= 5.0) {
                if (input[1] <= 1.5) {
                    memcpy(var12, (double[]){0.9, 0.0, 0.1}, 3 * sizeof(double));
                } else {
                    memcpy(var12, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                }
            } else {
                if (input[16] <= 6.5) {
                    if (input[11] <= 4.0) {
                        memcpy(var12, (double[]){0.67, 0.0, 0.33}, 3 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var12, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                }
            }
        } else {
            if (input[8] <= 0.5) {
                memcpy(var12, (double[]){0.8333333333333334, 0.0, 0.16666666666666666}, 3 * sizeof(double));
            } else {
                if (input[6] <= 0.5) {
                    if (input[16] <= 7.5) {
                        memcpy(var12, (double[]){0.125, 0.7291666666666666, 0.14583333333333334}, 3 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.4864864864864865, 0.2972972972972973, 0.21621621621621623}, 3 * sizeof(double));
                    }
                } else {
                    if (input[18] <= 5.5) {
                        memcpy(var12, (double[]){0.1, 0.5, 0.4}, 3 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.0, 0.9047619047619048, 0.09523809523809523}, 3 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var9, var12, 3, var8);
    double var13[3];
    if (input[18] <= 4.5) {
        if (input[17] <= 5.0) {
            if (input[6] <= 0.5) {
                if (input[2] <= 4092.5) {
                    if (input[12] <= 2.5) {
                        memcpy(var13, (double[]){0.4050632911392405, 0.34177215189873417, 0.25316455696202533}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.782608695652174, 0.21739130434782608, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    if (input[7] <= 0.5) {
                        memcpy(var13, (double[]){0.992831541218638, 0.0, 0.007168458781362007}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.9545454545454546, 0.0, 0.045454545454545456}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[14] <= 5.0) {
                    if (input[1] <= 1.5) {
                        memcpy(var13, (double[]){0.4782608695652174, 0.3695652173913043, 0.15217391304347827}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var13, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                }
            }
        } else {
            if (input[13] <= 6.5) {
                if (input[2] <= 9813.0) {
                    if (input[18] <= 3.5) {
                        memcpy(var13, (double[]){0.4931506849315068, 0.0684931506849315, 0.4383561643835616}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.2328767123287671, 0.3904109589041096, 0.3767123287671233}, 3 * sizeof(double));
                    }
                } else {
                    if (input[17] <= 11.125) {
                        memcpy(var13, (double[]){0.6666666666666666, 0.08333333333333333, 0.25}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.5079365079365079, 0.0, 0.49206349206349204}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[7] <= 0.5) {
                    if (input[8] <= 0.5) {
                        memcpy(var13, (double[]){0.96, 0.0, 0.04}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.6216216216216216, 0.02702702702702703, 0.35135135135135137}, 3 * sizeof(double));
                    }
                } else {
                    if (input[16] <= 7.5) {
                        memcpy(var13, (double[]){0.6923076923076923, 0.3076923076923077, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.6666666666666666, 0.2222222222222222, 0.1111111111111111}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[18] <= 5.5) {
            if (input[13] <= 6.5) {
                if (input[16] <= 5.5) {
                    if (input[14] <= 11.366666316986084) {
                        memcpy(var13, (double[]){0.2222222222222222, 0.5555555555555556, 0.2222222222222222}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.058823529411764705, 0.8371040723981901, 0.10407239819004525}, 3 * sizeof(double));
                    }
                } else {
                    if (input[8] <= 0.5) {
                        memcpy(var13, (double[]){0.5416666666666666, 0.25, 0.20833333333333334}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.145748987854251, 0.6032388663967612, 0.25101214574898784}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[7] <= 0.5) {
                    if (input[0] <= 1.5) {
                        memcpy(var13, (double[]){0.8333333333333334, 0.041666666666666664, 0.125}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.45454545454545453, 0.0, 0.5454545454545454}, 3 * sizeof(double));
                    }
                } else {
                    if (input[11] <= 2.5) {
                        memcpy(var13, (double[]){0.16666666666666666, 0.08333333333333333, 0.75}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.25, 0.5, 0.25}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[16] <= 9.5) {
                if (input[2] <= 9922.0) {
                    if (input[15] <= 5.5) {
                        memcpy(var13, (double[]){0.06818181818181818, 0.7196969696969697, 0.21212121212121213}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.05570291777188329, 0.8894783377541998, 0.05481874447391689}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var13, (double[]){0.125, 0.375, 0.5}, 3 * sizeof(double));
                }
            } else {
                if (input[15] <= 8.5) {
                    if (input[14] <= 11.645833492279053) {
                        memcpy(var13, (double[]){0.07692307692307693, 0.07692307692307693, 0.8461538461538461}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.5000000000000001, 0.33333333333333337, 0.16666666666666669}, 3 * sizeof(double));
                    }
                } else {
                    if (input[17] <= 12.320512771606445) {
                        memcpy(var13, (double[]){0.3492063492063492, 0.4444444444444444, 0.20634920634920634}, 3 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.1368421052631579, 0.8105263157894737, 0.05263157894736842}, 3 * sizeof(double));
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
                        memcpy(var14, (double[]){0.4430379746835443, 0.4430379746835443, 0.11392405063291139}, 3 * sizeof(double));
                    }
                } else {
                    if (input[17] <= 12.5) {
                        memcpy(var14, (double[]){0.9336734693877551, 0.0, 0.0663265306122449}, 3 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.5555555555555556, 0.0, 0.4444444444444444}, 3 * sizeof(double));
                    }
                }
            } else {
                memcpy(var14, (double[]){0.09090909090909091, 0.18181818181818182, 0.7272727272727273}, 3 * sizeof(double));
            }
        } else {
            if (input[14] <= 12.035714149475098) {
                if (input[17] <= 11.071428775787354) {
                    if (input[2] <= 9246.0) {
                        memcpy(var14, (double[]){0.4065934065934066, 0.24175824175824176, 0.3516483516483517}, 3 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.6794871794871795, 0.08974358974358974, 0.23076923076923078}, 3 * sizeof(double));
                    }
                } else {
                    if (input[18] <= 4.5) {
                        memcpy(var14, (double[]){0.2913907284768212, 0.271523178807947, 0.4370860927152318}, 3 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.1465798045602606, 0.7296416938110749, 0.1237785016286645}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[8] <= 0.5) {
                    if (input[17] <= 12.879166603088379) {
                        memcpy(var14, (double[]){0.7727272727272728, 0.06818181818181819, 0.15909090909090912}, 3 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.3409090909090909, 0.45454545454545453, 0.20454545454545456}, 3 * sizeof(double));
                    }
                } else {
                    if (input[11] <= 1.5) {
                        memcpy(var14, (double[]){0.09653465346534654, 0.7252475247524752, 0.1782178217821782}, 3 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.08527131782945736, 0.8150609080841639, 0.09966777408637874}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[15] <= 4.5) {
            if (input[15] <= 0.5) {
                if (input[16] <= 1.0) {
                    if (input[9] <= 2.5) {
                        memcpy(var14, (double[]){0.5370370370370371, 0.37037037037037035, 0.09259259259259259}, 3 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.5172413793103449, 0.27586206896551724, 0.20689655172413793}, 3 * sizeof(double));
                    }
                } else {
                    if (input[13] <= 4.5) {
                        memcpy(var14, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.9242424242424242, 0.0, 0.07575757575757576}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[18] <= 0.5) {
                    if (input[2] <= 9192.5) {
                        memcpy(var14, (double[]){0.9459459459459459, 0.0, 0.05405405405405406}, 3 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    if (input[18] <= 3.5) {
                        memcpy(var14, (double[]){0.5526315789473685, 0.019736842105263157, 0.4276315789473684}, 3 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.30392156862745096, 0.2647058823529412, 0.43137254901960786}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[18] <= 3.5) {
                if (input[14] <= 12.449999809265137) {
                    if (input[2] <= 9102.0) {
                        memcpy(var14, (double[]){0.7142857142857143, 0.0, 0.2857142857142857}, 3 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.14285714285714285, 0.14285714285714285, 0.7142857142857143}, 3 * sizeof(double));
                    }
                } else {
                    if (input[14] <= 13.03000020980835) {
                        memcpy(var14, (double[]){0.875, 0.125, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.2, 0.2, 0.6}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 1.5) {
                    if (input[13] <= 11.5) {
                        memcpy(var14, (double[]){0.07420494699646643, 0.7703180212014135, 0.15547703180212014}, 3 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.18181818181818182, 0.3181818181818182, 0.5}, 3 * sizeof(double));
                    }
                } else {
                    if (input[14] <= 12.190000057220459) {
                        memcpy(var14, (double[]){0.4428571428571429, 0.27142857142857146, 0.28571428571428575}, 3 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.1476510067114094, 0.7315436241610739, 0.12080536912751678}, 3 * sizeof(double));
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
                        memcpy(var15, (double[]){0.46590909090909094, 0.39772727272727276, 0.13636363636363638}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.13157894736842105, 0.7894736842105263, 0.07894736842105263}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[18] <= 0.5) {
                    if (input[11] <= 2.5) {
                        memcpy(var15, (double[]){0.9409722222222222, 0.0, 0.059027777777777776}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.9854545454545455, 0.0, 0.014545454545454545}, 3 * sizeof(double));
                    }
                } else {
                    if (input[8] <= 0.5) {
                        memcpy(var15, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.6571428571428571, 0.0, 0.34285714285714286}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[2] <= 9377.0) {
                if (input[8] <= 0.5) {
                    if (input[13] <= 5.5) {
                        memcpy(var15, (double[]){0.9473684210526315, 0.0, 0.05263157894736842}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.6956521739130435, 0.0, 0.30434782608695654}, 3 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 9192.5) {
                        memcpy(var15, (double[]){0.32386363636363635, 0.08522727272727272, 0.5909090909090909}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.3684210526315789, 0.19298245614035087, 0.43859649122807015}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[8] <= 0.5) {
                    memcpy(var15, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                } else {
                    if (input[0] <= 1.5) {
                        memcpy(var15, (double[]){0.4225352112676056, 0.09859154929577464, 0.4788732394366197}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.8947368421052632, 0.05263157894736842, 0.05263157894736842}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[2] <= 9813.0) {
            if (input[6] <= 0.5) {
                if (input[15] <= 5.5) {
                    if (input[16] <= 6.5) {
                        memcpy(var15, (double[]){0.17633928571428573, 0.5357142857142857, 0.28794642857142855}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.5, 0.05357142857142857, 0.44642857142857145}, 3 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 9192.5) {
                        memcpy(var15, (double[]){0.15561959654178675, 0.6512968299711815, 0.1930835734870317}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.07747747747747748, 0.8144144144144144, 0.10810810810810811}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[15] <= 4.5) {
                    if (input[14] <= 10.900000095367432) {
                        memcpy(var15, (double[]){0.0, 0.058823529411764705, 0.9411764705882353}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.08888888888888889, 0.5777777777777777, 0.3333333333333333}, 3 * sizeof(double));
                    }
                } else {
                    if (input[17] <= 11.224999904632568) {
                        memcpy(var15, (double[]){0.15151515151515152, 0.6363636363636364, 0.21212121212121213}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.03767660910518053, 0.9120879120879121, 0.05023547880690738}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[17] <= 12.291666507720947) {
                if (input[17] <= 11.46875) {
                    if (input[13] <= 5.5) {
                        memcpy(var15, (double[]){0.07692307692307693, 0.23076923076923078, 0.6923076923076923}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.5652173913043478, 0.0, 0.43478260869565216}, 3 * sizeof(double));
                    }
                } else {
                    if (input[9] <= 2.5) {
                        memcpy(var15, (double[]){0.4285714285714286, 0.41071428571428575, 0.16071428571428575}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.2, 0.2, 0.6}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[10] <= 2.5) {
                    if (input[15] <= 4.5) {
                        memcpy(var15, (double[]){0.0, 0.1, 0.9}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.1016949152542373, 0.7966101694915254, 0.1016949152542373}, 3 * sizeof(double));
                    }
                } else {
                    if (input[9] <= 2.5) {
                        memcpy(var15, (double[]){0.0, 0.25, 0.75}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.2, 0.4, 0.4}, 3 * sizeof(double));
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
                        memcpy(var16, (double[]){0.42391304347826086, 0.4782608695652174, 0.09782608695652174}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.85, 0.15, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 9246.0) {
                        memcpy(var16, (double[]){0.9465648854961832, 0.0, 0.05343511450381679}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.990909090909091, 0.0, 0.00909090909090909}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[8] <= 0.5) {
                    if (input[10] <= 2.5) {
                        memcpy(var16, (double[]){0.953125, 0.015625, 0.03125}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.8444444444444444, 0.0, 0.15555555555555556}, 3 * sizeof(double));
                    }
                } else {
                    if (input[16] <= 5.5) {
                        memcpy(var16, (double[]){0.23448275862068965, 0.2689655172413793, 0.496551724137931}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.4847161572052402, 0.1615720524017467, 0.3537117903930131}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[8] <= 0.5) {
                if (input[7] <= 0.5) {
                    if (input[17] <= 13.416666507720947) {
                        memcpy(var16, (double[]){0.8360655737704918, 0.01639344262295082, 0.14754098360655737}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.2, 0.3, 0.5}, 3 * sizeof(double));
                    }
                } else {
                    if (input[18] <= 4.5) {
                        memcpy(var16, (double[]){0.9285714285714286, 0.0, 0.07142857142857142}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.46153846153846156, 0.358974358974359, 0.1794871794871795}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[17] <= 11.844791412353516) {
                    if (input[1] <= 3.5) {
                        memcpy(var16, (double[]){0.2182741116751269, 0.4517766497461929, 0.3299492385786802}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.39344262295081966, 0.3114754098360656, 0.29508196721311475}, 3 * sizeof(double));
                    }
                } else {
                    if (input[4] <= 0.5) {
                        memcpy(var16, (double[]){0.05691056910569106, 0.8075880758807589, 0.13550135501355015}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.1245674740484429, 0.71280276816609, 0.16262975778546712}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[15] <= 4.5) {
            if (input[17] <= 10.25) {
                if (input[16] <= 2.0) {
                    if (input[9] <= 2.5) {
                        memcpy(var16, (double[]){0.27586206896551724, 0.6206896551724138, 0.10344827586206896}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.25, 0.75, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    if (input[17] <= 5.0) {
                        memcpy(var16, (double[]){0.9302325581395349, 0.0, 0.06976744186046512}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.625, 0.125, 0.25}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[11] <= 1.5) {
                    memcpy(var16, (double[]){0.4666666666666667, 0.4666666666666667, 0.06666666666666667}, 3 * sizeof(double));
                } else {
                    if (input[1] <= 1.5) {
                        memcpy(var16, (double[]){0.2962962962962963, 0.2222222222222222, 0.48148148148148145}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.09090909090909091, 0.0, 0.9090909090909091}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[13] <= 6.5) {
                if (input[11] <= 1.5) {
                    if (input[13] <= 5.5) {
                        memcpy(var16, (double[]){0.1, 0.8, 0.1}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.05714285714285714, 0.9142857142857143, 0.02857142857142857}, 3 * sizeof(double));
                    }
                } else {
                    if (input[18] <= 2.5) {
                        memcpy(var16, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.07471264367816093, 0.867816091954023, 0.05747126436781609}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[15] <= 5.5) {
                    if (input[14] <= 12.453333377838135) {
                        memcpy(var16, (double[]){0.16666666666666666, 0.0, 0.8333333333333334}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.2857142857142857, 0.14285714285714285, 0.5714285714285714}, 3 * sizeof(double));
                    }
                } else {
                    if (input[7] <= 0.5) {
                        memcpy(var16, (double[]){0.0, 0.9882352941176471, 0.011764705882352941}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.029411764705882353, 0.9313725490196079, 0.0392156862745098}, 3 * sizeof(double));
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
                        memcpy(var17, (double[]){0.9111111111111111, 0.022222222222222223, 0.06666666666666667}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    if (input[18] <= 3.5) {
                        memcpy(var17, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.391304347826087, 0.21739130434782608, 0.391304347826087}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[7] <= 0.5) {
                    if (input[2] <= 9377.0) {
                        memcpy(var17, (double[]){0.8333333333333334, 0.05555555555555555, 0.1111111111111111}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    if (input[16] <= 6.5) {
                        memcpy(var17, (double[]){0.4090909090909091, 0.45454545454545453, 0.13636363636363635}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.625, 0.25, 0.125}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[7] <= 0.5) {
                if (input[18] <= 1.5) {
                    memcpy(var17, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                } else {
                    if (input[16] <= 6.5) {
                        memcpy(var17, (double[]){0.9166666666666666, 0.0, 0.08333333333333333}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[17] <= 12.083333492279053) {
                    if (input[15] <= 0.5) {
                        memcpy(var17, (double[]){0.92, 0.08, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.975609756097561, 0.024390243902439025, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var17, (double[]){0.4444444444444444, 0.5555555555555556, 0.0}, 3 * sizeof(double));
                }
            }
        }
    } else {
        if (input[14] <= 10.784615516662598) {
            if (input[17] <= 10.166666507720947) {
                if (input[2] <= 4092.5) {
                    if (input[9] <= 2.5) {
                        memcpy(var17, (double[]){0.4383561643835617, 0.4246575342465754, 0.13698630136986303}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.20930232558139536, 0.6046511627906976, 0.18604651162790697}, 3 * sizeof(double));
                    }
                } else {
                    if (input[15] <= 3.5) {
                        memcpy(var17, (double[]){0.919732441471572, 0.0, 0.0802675585284281}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.6666666666666666, 0.0, 0.3333333333333333}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[14] <= 10.732142925262451) {
                    if (input[18] <= 2.5) {
                        memcpy(var17, (double[]){0.5263157894736842, 0.0, 0.47368421052631576}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.07042253521126761, 0.29577464788732394, 0.6338028169014085}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var17, (double[]){0.6875, 0.25, 0.0625}, 3 * sizeof(double));
                }
            }
        } else {
            if (input[6] <= 0.5) {
                if (input[18] <= 4.5) {
                    if (input[16] <= 5.5) {
                        memcpy(var17, (double[]){0.2706422018348624, 0.22018348623853212, 0.5091743119266054}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.5143769968051118, 0.14696485623003194, 0.33865814696485624}, 3 * sizeof(double));
                    }
                } else {
                    if (input[17] <= 12.7619047164917) {
                        memcpy(var17, (double[]){0.10546139359698682, 0.6497175141242938, 0.2448210922787194}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.0681198910081744, 0.829700272479564, 0.10217983651226158}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[18] <= 3.5) {
                    if (input[7] <= 0.5) {
                        memcpy(var17, (double[]){0.36363636363636365, 0.3181818181818182, 0.3181818181818182}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.6666666666666666, 0.14814814814814814, 0.18518518518518517}, 3 * sizeof(double));
                    }
                } else {
                    if (input[10] <= 2.5) {
                        memcpy(var17, (double[]){0.042, 0.89, 0.068}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.08547008547008547, 0.7735042735042735, 0.14102564102564102}, 3 * sizeof(double));
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
                        memcpy(var18, (double[]){0.6271186440677966, 0.3050847457627119, 0.06779661016949153}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.4363636363636364, 0.3454545454545455, 0.2181818181818182}, 3 * sizeof(double));
                    }
                } else {
                    if (input[17] <= 5.0) {
                        memcpy(var18, (double[]){0.9488372093023256, 0.0, 0.05116279069767442}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.6043956043956044, 0.02197802197802198, 0.37362637362637363}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[13] <= 2.5) {
                    if (input[9] <= 2.5) {
                        memcpy(var18, (double[]){0.26315789473684215, 0.6315789473684211, 0.10526315789473685}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.25, 0.75, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    if (input[17] <= 5.0) {
                        memcpy(var18, (double[]){0.8620689655172413, 0.0, 0.13793103448275862}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.6, 0.0, 0.4}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[16] <= 5.5) {
                if (input[17] <= 10.166666507720947) {
                    memcpy(var18, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                } else {
                    if (input[0] <= 1.5) {
                        memcpy(var18, (double[]){0.18095238095238095, 0.3142857142857143, 0.5047619047619047}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.38461538461538464, 0.07692307692307693, 0.5384615384615384}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[18] <= 4.5) {
                    if (input[15] <= 5.5) {
                        memcpy(var18, (double[]){0.6565656565656566, 0.0707070707070707, 0.2727272727272727}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.28571428571428575, 0.4285714285714286, 0.28571428571428575}, 3 * sizeof(double));
                    }
                } else {
                    if (input[6] <= 0.5) {
                        memcpy(var18, (double[]){0.35537190082644626, 0.45454545454545453, 0.19008264462809918}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.07272727272727272, 0.7454545454545455, 0.18181818181818182}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[6] <= 0.5) {
            if (input[4] <= 0.5) {
                if (input[10] <= 5.5) {
                    if (input[14] <= 13.069047451019287) {
                        memcpy(var18, (double[]){0.21785714285714286, 0.5571428571428572, 0.225}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.09266409266409266, 0.7741312741312741, 0.13320463320463322}, 3 * sizeof(double));
                    }
                } else {
                    if (input[17] <= 10.583333492279053) {
                        memcpy(var18, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.6666666666666666, 0.2857142857142857, 0.047619047619047616}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[16] <= 7.5) {
                    if (input[8] <= 0.5) {
                        memcpy(var18, (double[]){0.8823529411764706, 0.0, 0.11764705882352941}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.265625, 0.5052083333333334, 0.22916666666666666}, 3 * sizeof(double));
                    }
                } else {
                    if (input[7] <= 0.5) {
                        memcpy(var18, (double[]){0.273972602739726, 0.6575342465753424, 0.0684931506849315}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.16666666666666666, 0.5833333333333334, 0.25}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[12] <= 3.5) {
                if (input[15] <= 4.5) {
                    if (input[4] <= 0.5) {
                        memcpy(var18, (double[]){0.18518518518518517, 0.6296296296296297, 0.18518518518518517}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.35714285714285715, 0.07142857142857142, 0.5714285714285714}, 3 * sizeof(double));
                    }
                } else {
                    if (input[18] <= 3.5) {
                        memcpy(var18, (double[]){0.7777777777777778, 0.1111111111111111, 0.1111111111111111}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.058637083993660855, 0.8890649762282092, 0.05229793977812995}, 3 * sizeof(double));
                    }
                }
            } else {
                memcpy(var18, (double[]){0.42857142857142855, 0.5714285714285714, 0.0}, 3 * sizeof(double));
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
                        memcpy(var19, (double[]){0.25, 0.55, 0.2}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.9147982062780269, 0.008968609865470852, 0.07623318385650224}, 3 * sizeof(double));
                    }
                } else {
                    if (input[9] <= 4.5) {
                        memcpy(var19, (double[]){0.43641618497109824, 0.1994219653179191, 0.36416184971098264}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.9047619047619048, 0.09523809523809523, 0.0}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 9813.0) {
                    if (input[18] <= 4.5) {
                        memcpy(var19, (double[]){0.31666666666666665, 0.23333333333333334, 0.45}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.08041504539559015, 0.7911802853437094, 0.12840466926070038}, 3 * sizeof(double));
                    }
                } else {
                    if (input[13] <= 11.0) {
                        memcpy(var19, (double[]){0.1839080459770115, 0.4482758620689655, 0.367816091954023}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.7894736842105263, 0.10526315789473684, 0.10526315789473684}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[17] <= 11.224999904632568) {
                if (input[17] <= 10.690476417541504) {
                    if (input[1] <= 1.5) {
                        memcpy(var19, (double[]){0.6, 0.375, 0.025}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.5, 0.07142857142857142, 0.42857142857142855}, 3 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 9377.0) {
                        memcpy(var19, (double[]){0.0, 0.47619047619047616, 0.5238095238095238}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.5454545454545454, 0.18181818181818182, 0.2727272727272727}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[17] <= 11.845237731933594) {
                    if (input[1] <= 1.5) {
                        memcpy(var19, (double[]){0.17857142857142858, 0.6428571428571429, 0.17857142857142858}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.0, 0.6923076923076923, 0.3076923076923077}, 3 * sizeof(double));
                    }
                } else {
                    if (input[14] <= 10.757143020629883) {
                        memcpy(var19, (double[]){0.375, 0.5, 0.125}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.04526748971193416, 0.8930041152263375, 0.06172839506172839}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[17] <= 11.340238094329834) {
            if (input[13] <= 0.5) {
                if (input[6] <= 0.5) {
                    if (input[10] <= 2.5) {
                        memcpy(var19, (double[]){0.46153846153846156, 0.5, 0.038461538461538464}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.41379310344827586, 0.3448275862068966, 0.2413793103448276}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var19, (double[]){0.18181818181818182, 0.8181818181818182, 0.0}, 3 * sizeof(double));
                }
            } else {
                if (input[15] <= 2.5) {
                    if (input[18] <= 1.5) {
                        memcpy(var19, (double[]){0.9511400651465798, 0.0, 0.048859934853420196}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.5, 0.0, 0.5}, 3 * sizeof(double));
                    }
                } else {
                    if (input[8] <= 0.5) {
                        memcpy(var19, (double[]){0.9487179487179487, 0.0, 0.05128205128205128}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.47770700636942676, 0.1464968152866242, 0.37579617834394907}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[8] <= 0.5) {
                if (input[7] <= 0.5) {
                    if (input[17] <= 13.199999809265137) {
                        memcpy(var19, (double[]){0.896551724137931, 0.0, 0.10344827586206896}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.26666666666666666, 0.0, 0.7333333333333333}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var19, (double[]){0.5714285714285714, 0.42857142857142855, 0.0}, 3 * sizeof(double));
                }
            } else {
                if (input[18] <= 3.5) {
                    if (input[15] <= 4.5) {
                        memcpy(var19, (double[]){0.6266666666666667, 0.013333333333333334, 0.36}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.3333333333333333, 0.21428571428571427, 0.4523809523809524}, 3 * sizeof(double));
                    }
                } else {
                    if (input[14] <= 13.34166669845581) {
                        memcpy(var19, (double[]){0.1282051282051282, 0.6217948717948718, 0.25}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.07407407407407407, 0.8465608465608465, 0.07936507936507936}, 3 * sizeof(double));
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

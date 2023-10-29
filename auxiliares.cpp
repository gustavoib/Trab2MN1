#include "auxiliares.h"

void substituicoesRetroativas(double **matriz, double *b, double *vetorResposta, int n) {
    vetorResposta[n] = b[n] / matriz[n][n];
    for (int i = n-1; i >= 1; i--) {
        double soma = 0;
        for (int j = i+1; j <= n; j++) {
            soma += matriz[i][j] * vetorResposta[j];
        }
        vetorResposta[i] = (b[i] - soma) / matriz[i][i];
    }
}
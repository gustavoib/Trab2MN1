#include "auxiliares.h"

void substituicoesRetroativas(double **A, double *b, double *x, int n) {
    x[n] = b[n] / A[n][n];
    for (int i = n-1; i >= 1; i--) {
        double soma = 0;
        for (int j = i+1; j <= n; j++) {
            soma += A[i][j] * x[j];
        }
        x[i] = (b[i] - soma) / A[i][i];
    }
}
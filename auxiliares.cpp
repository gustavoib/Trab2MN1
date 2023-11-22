#include <vector>
#include "auxiliares.h"

using namespace std;

vector<double> substituicoesRetroativas(double matriz[][3], double *b, int n) {
    vector<double> vetorResposta(n);

    vetorResposta[n-1] = b[n-1] / matriz[n-1][n-1];

    for (int i = n-2; i >= 0; i--) {
        double soma = 0;
        for (int j = i+1; j < n; j++) {
            soma += matriz[i][j] * vetorResposta[j];
        }
        vetorResposta[i] = (b[i] - soma) / matriz[i][i];
    }
    return vetorResposta;
}
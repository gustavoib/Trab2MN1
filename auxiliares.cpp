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

void geradorDeLU(int n, double matriz[][3], double matrizL[][3]){
    for(int k = 0; k < n; k++){
        for(int i = k+1; i < n; i++){
            double m = -matriz[i][k] / matriz[k][k];
            matriz[i][k] = 0;
            for(int j = k+1; j <= n; j++){
                matriz[i][j] = matriz[i][j] + m * matriz[k][j];
            }
            matrizL[i][k] = -m;
        }
    }

}
#include "metodos.h"
#include "auxiliares.h"
#include <vector>
using namespace std;

vector<double> eliminacaoDeGauss(int n, double matriz[][3], double *b){
    for(int k = 0; k < n; k++){
        for(int i = k+1; i <= n; i++){
            double m = -matriz[i][k] / matriz[k][k];
            matriz[i][k] = 0;
            for(int j = k+1; j <= n; j++){
                matriz[i][j] = matriz[i][j] + m * matriz[k][j];
            }
            b[i] = b[i] + m * b[k];
        }
    }
    return substituicoesRetroativas(matriz, b, n);
}
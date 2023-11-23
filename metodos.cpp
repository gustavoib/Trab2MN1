#include "metodos.h"
#include "auxiliares.h"
#include <vector>
using namespace std;

vector<double> eliminacaoDeGauss(int n, double matriz[][3], double *b){
    for(int k = 0; k < n; k++){
        for(int i = k+1; i < n; i++){
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

/*vector<double> fatoracaoLDP(int n, double matrizAU[][3], double *f){
  double matrizL[n][n];
  double matrizD[3][3] = {{1, 0, 0}, {0, 1, 0}, {0,0,1}};
  geradorDeLU();
  for(int k=0 ; k<3 ; k++) {
    for(int i=0 ; i<3 ; i++) {
      matrizD[k][i] = matrizD[k][i] * matrizAU[k][i];
}
*/
#include "metodos.h"
#include "auxiliares.h"
#include <vector>
#include <iostream>

using namespace std;

// Função para realizar a fatoração LU
vector<double> fatoracaoLU(const vector<vector<double>>& matrizA, vector<vector<double>>& matrizL, vector<vector<double>>& matrizU, vector<double> vetorB) {
    int n = matrizA.size();

    // Inicializar matrizL como uma matriz identidade e matrizU como uma cópia de matrizA
    matrizL = vector<vector<double>>(n, vector<double>(n, 0.0));
    matrizU = matrizA;

    for (int i = 0; i < n; i++) {
        matrizL[i][i] = 1.0; // Elementos diagonais de L são 1
        for (int j = i + 1; j < n; j++) {
            double multiplicador = matrizU[j][i] / matrizU[i][i];
            matrizL[j][i] = multiplicador;
            for (int k = i; k < n; k++) {
                matrizU[j][k] -= multiplicador * matrizU[i][k];
            }
        }
    }
    vector<double> y = resolverSistema(matrizL, vetorB);
    vector<double> x = resolverSistema(matrizU, y);

    return x;
}

// Função para realizar a fatoração LU
vector<vector<double>> gerarL(vector<vector<double>> &matrizA, vector<vector<double>> &matrizL, vector<vector<double>> &matrizU, vector<double> vetorB) {
    int n = matrizA.size();
  
    // Inicializar matrizL como uma matriz identidade e matrizU como uma cópia de matrizA
    matrizL = vector<vector<double>>(n, vector<double>(n, 0.0));
    matrizU = matrizA;
  
    for (int i = 0; i < n; i++) {
        matrizL[i][i] = 1.0; // Elementos diagonais de L são 1
        for (int j = i + 1; j < n; j++) {
            double multiplicador = matrizU[j][i] / matrizU[i][i];
            matrizL[j][i] = multiplicador;
            for (int k = i; k < n; k++) {
                matrizU[j][k] -= multiplicador * matrizU[i][k];
            }
        }
    }
    return matrizL;
}

vector<double> fatoracaoLDP(vector<vector<double>> &matrizA, vector<double> vetorF) {
  int n = matrizA.size();

  vector<vector<double>> matrizU;
  
  vector<vector<double>> matrizP = gerarMatrizP(matrizA);

  vector<vector<double>> matrizD = gerarMatrizD(matrizA);

  imprimirMatriz(matrizP);
  
  vector<vector<double>> matrizL;
  vector<vector<double>> matrizL2;
  
  matrizL = gerarL(matrizA, matrizL2, matrizU, vetorF);
  

  vector<double> y(n);
  vector<double> z(n);
  vector<double> d(n);
  
  y = resolverSistema(matrizL, vetorF);
  
  z = resolverSistema(matrizD, y);
  
  d = resolverSistema(matrizP, z);
  
  return d;
}




// vector<double> eliminacaoDeGauss(int n, double matriz[][3], double *b){
//     for(int k = 0; k < n; k++){
//         for(int i = k+1; i < n; i++){
//             double m = -matriz[i][k] / matriz[k][k];
//             matriz[i][k] = 0;
//             for(int j = k+1; j <= n; j++){
//                 matriz[i][j] = matriz[i][j] + m * matriz[k][j];
//             }
//             b[i] = b[i] + m * b[k];
//         }
//     }
//     return substituicoesRetroativas(matriz, b, n);
// }


// vector<double> fatoracaoLDP(int n, double matrizAU[][3], double *f){
  
//   double matrizL[n][n];
//   double matrizD[3][3] = {{1, 0, 0}, {0, 1, 0}, {0,0,1}};
  
//   geradorDeLU();


  
  // for(int k=0 ; k<3 ; k++) {
  //   for(int i=0 ; i<3 ; i++) {
  //     matrizD[k][i] = matrizD[k][i] * matrizAU[k][i];
// }

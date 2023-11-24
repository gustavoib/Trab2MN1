#include "auxiliares.h"
#include "metodos.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {

  vector<vector<double>> matriz = {
        {3, -2, 1},
        {1, -3, 4},
        {9, 4, -5}
  };

  // Vetor b
  vector<double> vetorB = {8, 6, 11};

  cout << "Matriz A:" << endl;
  imprimirMatriz(matriz);

  cout << "Vetor b:" << endl;
  imprimirVetor(vetorB);

  // Escalonar a matriz A
  vector<vector<double>> matrizEscalonada = escalonarMatriz(matriz);

  cout << "Matriz A escalonada:" << endl;
  imprimirMatriz(matrizEscalonada);

  // Resolver o sistema Ax = b
  vector<double> solucao = resolverSistema(matriz, vetorB);

  cout << "Solução do sistema:" << endl;
  imprimirVetor(solucao);

  cout << "Matriz A:" << endl;
  imprimirMatriz(matriz);

  // Fatorar matrizA em LU
  vector<vector<double>> matrizL, matrizU;
  vector<double> solucaoLU = fatoracaoLU(matriz, matrizL, matrizU, vetorB);

  cout << "Matriz L:" << endl;
  imprimirMatriz(matrizL);

  cout << "Matriz U:" << endl;
  imprimirMatriz(matrizU);

  cout << "Solução do sistema LU:" << endl;
  imprimirVetor(solucaoLU);

  
  // Fatorar matrizA em LDP
  vector<double> LDP = fatoracaoLDP(matriz, vetorB);
  cout << "Solução do sistema LDP:" << endl;
  imprimirVetor(LDP);

  
//     //menu();
//     double matriz[3][3] = {
//             {3, -2, 1},
//             {1, -3, 4},
//             {9, 4, -5}
//     };

//     double matriz2[3][3] = {
//             {3, -2, 1},
//             {1, -3, 4},
//             {9, 4, -5}
//     };
  
//     double b[3] = {8, 6, 11};

//     double matrizL[3][3] = {
//             {1, 0, 0},
//             {0, 1, 0},
//             {0, 0, 1}
//     };

//     double matrizL2[3][3] = {
//             {1, 0, 0},
//             {0, 1, 0},
//             {0, 0, 1}
//     };

//     int n = 3;
//     vector<double> y(n);
//     vector<double> x(n);
  
//     geradorDeLU(n, matriz, matrizL);

//     y = resolucaoAxb(n, matrizL, b);
//     x = resolucaoAxb(n, matriz, y.data());
  
//     for(int i = 0; i < n; i++){
//       cout << x[i] << "\n";
//     }

//     cout << "LDP" << endl;

//     fatoracaoLDP(n, matriz2, matrizL2, b);
  
//     return 0;
// }

// void menu() {

//     cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
//     cout << "               | 3  -2  1 |           | 8 |\n";
//     cout << "         [A] = | 1  -3  4 |     {f} = | 6 |\n";
//     cout << "               | 9   4 -5 |           | 11|\n\n";
//     cout << "Escolha qual item você deseja executar:" << endl << endl
//          << "[a] Obter valores do deslocamento d através da Fatoração LU" << endl
//          << "[b] Obter valores do deslocamento d através da Fatoração LDP" << endl
//          << "[c] Gerar quadro resposta para cada método, variando os valores de [A] e de {f}" << endl;
//     cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

//     char item;
//     cin >> item;
//     /*
//     if (item == 'a') {
//       fatoracaoLU();
//     } else if (item == 'b') {
//       fatoracaoLDP();
//     } else if (item == 'c') {
//       ;
//     }*/
  }

#include <iostream>
#include <vector>

using namespace std;

// Função para imprimir a matriz
void imprimirMatriz(const vector<vector<double>> &matriz) {
  int linhas = matriz.size();
  int colunas = matriz[0].size();

  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      cout << matriz[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

// Função para imprimir vetor
void imprimirVetor(const vector<double> &vetor) {
  int tamanho = vetor.size();

  for (int i = 0; i < tamanho; i++) {
    cout << vetor[i] << " ";
  }
  cout << endl;
  cout << endl;
}

// Função para escalonar a matriz sem garantir que o pivô seja 1
vector<vector<double>> escalonarMatriz(const vector<vector<double>>& matriz) {
    vector<vector<double>> matrizEscalonada = matriz;
    int linhas = matrizEscalonada.size();
    int colunas = matrizEscalonada[0].size();

    for (int i = 0; i < linhas; i++) {
        // Encontrar o pivô (o primeiro elemento não nulo na linha
        double pivo = matrizEscalonada[i][i];

        // Subtrair múltiplos da linha atual de outras linhas para zerar elementos abaixo do pivô
        for (int k = i + 1; k < linhas; k++) {
            double fator = matrizEscalonada[k][i] / pivo;
            for (int j = 0; j < colunas; j++) {
                matrizEscalonada[k][j] -= fator * matrizEscalonada[i][j];
            }
        }
    }

    return matrizEscalonada;
}

// Função para realizar o escalonamento da matriz
vector<vector<double>> gerarMatrizP(const vector<vector<double>> &matriz) {
  int linhas = matriz.size();
  int colunas = matriz[0].size();

  // Criar uma cópia da matriz original
  vector<vector<double>> matrizP = matriz;

  for (int i = 0; i < linhas; i++) {
    // Normalizando a linha atual
    double divisor = matrizP[i][i];
    for (int j = i; j < colunas; j++) {
      matrizP[i][j] /= divisor;
    }

    // Subtraindo a linha atual das linhas abaixo para zerar os elementos abaixo do pivô
    for (int k = i + 1; k < linhas; k++) {
      double multiplicador = matrizP[k][i];
      for (int j = i; j < colunas; j++) {
        matrizP[k][j] -= multiplicador * matrizP[i][j];
      }
    }
  }

  return matrizP;
}

vector<vector<double>> gerarMatrizD (const vector<vector<double>> &matriz) {
  int n = matriz.size();
  vector<vector<double>> matrizD;
  vector<vector<double>> matrizEscalonada;
  matrizD = vector<vector<double>>(n, vector<double>(n, 0.0));

  matrizEscalonada = escalonarMatriz(matriz);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        matrizD[i][j] = matrizEscalonada[i][j];
      }
    }
  }
  return matrizD;
}

// Função para realizar o escalonamento da matriz e resolver o sistema Ax = b
vector<double> resolverSistema(vector<vector<double>> matrizA, vector<double> vetorB) {
  int n = matrizA.size();

  for (int i = 0; i < n; i++) {
    // Normalizando a linha atual
    double divisor = matrizA[i][i];
    for (int j = i; j < n; j++) {
      matrizA[i][j] /= divisor;
    }
    vetorB[i] /= divisor;

    // Subtraindo a linha atual das linhas abaixo para zerar os elementos abaixo do pivô
    for (int k = i + 1; k < n; k++) {
      double multiplicador = matrizA[k][i];
      for (int j = i; j < n; j++) {
        matrizA[k][j] -= multiplicador * matrizA[i][j];
      }
      vetorB[k] -= multiplicador * vetorB[i];
    }
  }

  // Substituição retroativa
  vector<double> solucao(n, 0.0);
  for (int i = n - 1; i >= 0; i--) {
    solucao[i] = vetorB[i];
    for (int j = i + 1; j < n; j++) {
      solucao[i] -= matrizA[i][j] * solucao[j];
    }
  }

  return solucao;
}

// Função para realizar a substituição retroativa e encontrar a solução do sistema Ax = b 
vector<double> resolverSistema(const vector<vector<double>> &matrizA, const vector<double>& vetorB) {
    int n = matrizA.size();
    vector<double> solucao(n, 0.0);

    // Substituição retroativa
    for (int i = n - 1; i >= 0; i--) {
        solucao[i] = vetorB[i];
        for (int j = i + 1; j < n; j++) {
            solucao[i] -= matrizA[i][j] * solucao[j];
        }
        solucao[i] /= matrizA[i][i];
    }

    return solucao;
}

// vector<double> substituicoesRetroativas(const vector<vector<double>>& matriz,
// const vector<double>& vetorB) {

//   int n = vetorB.size();
//   vector<double> vetorResposta(n);

//   vetorResposta[n-1] = vetorB[n-1] / matriz[n-1][n-1];

//   for (int i = n-2; i >= 0; i--) {
//     double soma = 0;
//     for (int j = i+1; j < n; j++) {
//       soma += matriz[i][j] * vetorResposta[j];
//     }
//     vetorResposta[i] = (vetorB[i] - soma) / matriz[i][i];
//   }
//   return vetorResposta;
// }

// vector<double> resolucaoAxb(const vector<vector<double>> matriz, const
// vector<double> &b) {
//   int n = b.size();

//   for(int k = 0; k < n; k++) {
//     for(int i = k+1; i < n; i++) {
//       double m = -matriz[i][k] / matriz[k][k];
//       matriz[i][k] = 0;
//       for(int j = k+1; j <= n; j++) {
//         matriz[i][j] = matriz[i][j] + m * matriz[k][j];
//       }
//       b[i] = b[i] + m * b[k];
//     }
//   }
//   return resolverSistema(matriz, b);
// }

// void printaMatriz(double matriz[][3], int n) {
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             cout << "|" << matriz[i][j] << "|\t"; // Usando \t para separar
//             os elementos
//         }
//         cout << endl; // Nova linha após cada linha da matriz

//         // Adicionando uma linha horizontal após cada linha da matriz
//         for (int k = 0; k < n; k++) {
//             cout << "--------";
//         }
//         cout << endl;
//     }
//     cout << endl; // Linha em branco após a matriz
// }

// void geradorDeLU(int n, double matrizU[][3], double matrizL[][3]) {
//   for(int k = 0; k < n; k++) {
//     for(int i = k+1; i < n; i++) {
//       double m = -matrizU[i][k] / matrizU[k][k];
//       matrizU[i][k] = 0;
//       for(int j = k+1; j <= n; j++) {
//         matrizU[i][j] = matrizU[i][j] + m * matrizU[k][j];
//       }
//       matrizL[i][k] = -m;
//     }
//   }
//   cout << "matriz U: \n";
//   printaMatriz(matrizU, n);

//   cout << "matriz L: \n";
//   printaMatriz(matrizL, n);
// }

// void fatoracaoLDP(int n, double matrizU[][3], double matrizL[][3], double *f)
// {

//   geradorDeLU(n, matrizU, matrizL);

//   // definição matriz D
//   double matrizD[3][3] = {
//               {0, 0, 0},
//               {0, 0, 0},
//               {0, 0, 0}
//   };

//   for(int i = 0; i < n; i++) {
//     for(int j = 0; j < n; j++) {
//       if (i == j) {
//         matrizD[i][j] = matrizU[i][j];
//       }
//     }
//   }

//   // montagem da matriz P
//   double matrizP[3][3] = {
//               {1, 0, 0},
//               {0, 1, 0},
//               {0, 0, 1}
//   };

//   for(int i = 0; i < n; i++) {
//     for(int j = 0; j < n; j++) {
//       if (i == 0 && j == 1) {
//         matrizP[i][j] = matrizU[i][j];
//       }
//       if (i == 0 && j == 2) {
//         matrizP[i][j] = matrizU[i][j];
//       }
//       if (i == 1 && j == 2) {
//         matrizP[i][j] = matrizU[i][j];
//       }
//     }
//   }

//   vector<double> y(n);
//   vector<double> z(n);
//   vector<double> d(n);

//   y = resolucaoAxb(n, matrizL, f);
//   z = resolucaoAxb(n, matrizD, y.data());
//   d = resolucaoAxb(n, matrizP, z.data());

//   cout << "matriz D: \n";
//   printaMatriz(matrizD, n);

//   cout << "matriz P: \n";
//   printaMatriz(matrizP, n);

//   for(int i = 0; i < n; i++){
//     cout << d[i] << "\n";
//   }
// }

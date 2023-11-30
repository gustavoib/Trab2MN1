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
   cout<<"Matriz P:"<<endl;


   vector<vector<double>> matrizL;
   cout<<"Matriz D:"<<endl;


   vector<vector<double>> matrizL2;


   matrizL = gerarL(matrizA, matrizL2, matrizU, vetorF);
   cout<<"Matriz L:"<<endl<<endl;


   vector<double> y(n);
   vector<double> z(n);
   vector<double> d(n);


   y = resolverSistema(matrizL, vetorF);


   z = resolverSistema(matrizD, y);


   d = resolverSistema(matrizP, z);


   return d;
}

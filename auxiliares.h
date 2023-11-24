#ifndef TRAB2MN1_AUXILIARES_H
#define TRAB2MN1_AUXILIARES_H

#include <vector>

using namespace std;

vector<vector<double>> escalonarMatriz(const vector<vector<double>> &matriz);

vector<vector<double>> gerarMatrizD(const vector<vector<double>> &matriz);

void imprimirMatriz(const vector<vector<double>> &matriz);

vector<vector<double>> gerarMatrizP(const vector<vector<double>> &matriz);

vector<double> resolverSistema(vector<vector<double>> matrizA, vector<double> vetorB);

void imprimirVetor(const vector<double> &vetor);

// void fatoracaoLDP(int n, double matrizU[][3], double matrizL[][3], double *f);

//vector<double> resolucaoAxb(int n, vector<vector<double>> matriz, vector<double> &b);

// vector<double> substituicoesRetroativas(double matriz[][3], double *b, int n);

// void geradorDeLU(int n, double matriz[][3], double matrizL[][3]);

// void printaMatriz(double matriz[][3]);

#endif //TRAB2MN1_AUXILIARES_H

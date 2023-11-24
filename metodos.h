#ifndef TRAB2MN1_METODOS_H
#define TRAB2MN1_METODOS_H

#include <vector>

using namespace std;

vector<double> fatoracaoLU(const vector<vector<double>>& matrizA, vector<vector<double>>& matrizL,
vector<vector<double>>& matrizU, vector<double> vetorB);

vector<vector<double>> gerarLU(const vector<vector<double>>& matrizA, vector<vector<double>>& matrizL, vector<vector<double>>& matrizU, vector<double> vetorB);

vector<double> fatoracaoLDP(vector<vector<double>>& matrizA, vector<double> vetorB);

//vector<double>eliminacaoDeGauss(int n, double matriz[][3], double *b);

//vector<vector<double>> decomposicaoLU(int n, double matriz[][3]);
#endif //TRAB2MN1_METODOS_H

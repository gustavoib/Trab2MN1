#ifndef TRAB2MN1_FATORACOES_H
#define TRAB2MN1_FATORACOES_H

#include <vector>

using namespace std;

vector<double> fatoracaoLU(const vector<vector<double>> &matrizA, vector<vector<double>> &matrizL, vector<vector<double>> &matrizU, vector<double> vetorB);

vector<double> fatoracaoLDP(vector<vector<double>> &matrizA, vector<double> vetorB);

#endif //TRAB2MN1_FATORACOES_H

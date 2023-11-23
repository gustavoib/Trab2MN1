#ifndef TRAB2MN1_METODOS_H
#define TRAB2MN1_METODOS_H

#include <vector>

using namespace std;

vector<double>eliminacaoDeGauss(int n, double matriz[][3], double *b);

vector<vector<double>> decomposicaoLU(int n, double matriz[][3]);
#endif //TRAB2MN1_METODOS_H

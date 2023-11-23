#ifndef TRAB2MN1_AUXILIARES_H
#define TRAB2MN1_AUXILIARES_H

#include <vector>

using namespace std;

vector<double> substituicoesRetroativas(double matriz[][3], double *b, int n);

void geradorDeLU(int n, double matriz[][3], double matrizL[][3]);
#endif //TRAB2MN1_AUXILIARES_H

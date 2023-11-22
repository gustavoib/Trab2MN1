#include <iostream>
#include "metodos.h"
#include <vector>
using namespace std;

int main() {
    double matriz[3][3] = {{3, 2, 4},
        {1, 1, 2},
        {4, 3, -2}};
    double b[3] = {1, 2, 3};
    int n = 3;
    vector<double> x(n);

    x = eliminacaoDeGauss(n, matriz, b);
    return 0;
}

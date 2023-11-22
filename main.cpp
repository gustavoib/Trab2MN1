#include <iostream>
#include "metodos.h"
#include <vector>
using namespace std;

int main() {
    double matriz[3][3] = {{3, -2, 1},
        {1, -3, 4},
        {9,4,-5}};
    double b[3] = {8,6,11};
    int n = 3;
    vector<double> x(n);

    x = eliminacaoDeGauss(n, matriz, b);
    return 0;
}

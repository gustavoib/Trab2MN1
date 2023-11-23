#include "auxiliares.h"
#include "metodos.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {
    double matriz[3][3] = {{3, -2, 1},
        {1, -3, 4},
        {9,4,-5}};
    double b[3] = {8,6,11};

    double matrizL[3][3] = {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}
    };

    int n = 3;
    vector<double> y(n);
    vector<double> x(n);
    geradorDeLU(n, matriz, matrizL);

    y = eliminacaoDeGauss(n, matrizL, b);
    x = eliminacaoDeGauss(n, matriz, y.data());
    for(int i = 0; i < n; i++){
        cout << x[i] << "\n";
    }

    return 0;
}

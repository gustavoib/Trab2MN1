#include "auxiliares.h"
#include "metodos.h"
#include <vector>
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
    vector<double> x(n);

//    x = eliminacaoDeGauss(n, matriz, b);
    geradorDeLU(n, matriz, matrizL);
    return 0;
}

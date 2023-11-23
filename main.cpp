#include "auxiliares.h"
#include "metodos.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {
    //menu();
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

void menu() {

    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "               | 3  -2  1 |           | 8 |\n";
    cout << "         [A] = | 1  -3  4 |     {f} = | 6 |\n";
    cout << "               | 9   4 -5 |           | 11|\n\n";
    cout << "Escolha qual item você deseja executar:" << endl << endl
         << "[a] Obter valores do deslocamento d através da Fatoração LU" << endl
         << "[b] Obter valores do deslocamento d através da Fatoração LDP" << endl
         << "[c] Gerar quadro resposta para cada método, variando os valores de [A] e de {f}" << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

    char item;
    cin >> item;
    /*
    if (item == 'a') {
      fatoracaoLU();
    } else if (item == 'b') {
      fatoracaoLDP();
    } else if (item == 'c') {
      ;
    }*/
  }


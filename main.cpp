#include "auxiliares.h"
#include "metodos.h"
#include <vector>
#include <iostream>

using namespace std;

void inputUser() {
    int n = 0;
    cout << "Digite a ordem n da matriz quadrada com n maior ou igual a dois :" << endl;
    while (n < 2) {
        cin >> n;
        if (n < 2)
            cout << "Valor inválido." << endl;
    }

    cout << "Agora digite os valores da matriz:" << endl;

    vector<vector<double>> matrix(n, vector<double>(n, 0.0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Elemento a" << i << j << ": ";
            cin >> matrix[i][j];

            if (cin.fail()) {
                cout << "Entrada Inválida." << endl;
                return;
            }
        }
    }

    imprimirMatriz(matrix);
}

void itemC() {
    int n = 0;
    cout << "Digite a ordem n da matriz quadrada com n maior ou igual a dois :" << endl;
    while (n < 2) {
        cin >> n;
        if (n < 2)
            cout << "Valor inválido." << endl;
    }

    cout << "Agora digite os valores da matriz: " << endl;

    vector<vector<double>> matriz(n, vector<double>(n, 0.0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Elemento a" << i << j << ": ";
            cin >> matriz[i][j];

            if (cin.fail()) {
                cout << "Entrada Inválida." << endl;
                return;
            }
        }
    }

    cout << "Agora digite os valores do vetor F: " << endl;

    vector<double> F(n, 0.0);

    for (int i = 0; i < n; i++) {
        cout << "Elemento f[" << i << "]: ";
        cin >> F[i];

        if (cin.fail()) {
            cout << "Entrada Inválida." << endl;
            return;
        }
    }

    vector<vector<double>> matrizL, matrizU;

    cout << "Resultado da fatoração LU com os dados inseridos: " << endl;
    vector<double> solucaoLU = fatoracaoLU(matriz, matrizL, matrizU, F);
    cout << "Matriz L:" << endl;
    imprimirMatriz(matrizL);


    cout << "Matriz U:" << endl;
    imprimirMatriz(matrizU);


    cout << "Solucao do sistema LU:" << endl;
    imprimirVetor(solucaoLU);
    Teste_quebra(solucaoLU);

    cout << "Resultado da fatoração LPD com os dados inseridos: " << endl;
    vector<double> LDP =    fatoracaoLDP(matriz, F);


    imprimirVetor(LDP);
    Teste_quebra(LDP);
}

void menu() {
   char item;
   do {
       // Matriz
       vector<vector<double>> matriz = {
               {3, -2, 1},
               {1, -3, 4},
               {9, 4, -5}
       };

       // Vetor b
       vector<double> vetorB = {8, 6, 11};


       cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl
            << "            Matriz Padrao                                   " << endl;
       cout << "               | 3  -2  1 |           | 8 |\n";
       cout << "         [A] = | 1  -3  4 |     {f} = | 6 |\n";
       cout << "               | 9   4 -5 |           | 11|\n\n";
       cout << "Escolha qual item voce deseja executar:" << endl << endl
            << "[a] Obter valores do deslocamento d atraves da Fatoracao LU" << endl
            << "[b] Obter valores do deslocamento d atraves da Fatoracao LDP" << endl
            << "[L] Fazer o L"<<endl
            << "[c] Gerar quadro resposta para cada metodo, variando os valores de [A] e de {f}" << endl
            << "[d] Escolher valores para a matriz n X n com n > 1" <<endl
            << "[s] Sair" << endl;
       cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
       cout << "Item escolhido: ";
       cin >> item;
       vector<vector<double>> matrizL, matrizU;

       if (item == 'a') {

           vector<double> solucaoLU= fatoracaoLU(matriz, matrizL, matrizU, vetorB);
           cout << "Matriz L:" << endl;
           imprimirMatriz(matrizL);


           cout << "Matriz U:" << endl;
           imprimirMatriz(matrizU);


           cout << "Solucao do sistema LU:" << endl;
           imprimirVetor(solucaoLU);
           Teste_quebra(solucaoLU);


       } else if (item == 'b') {
           cout << "Solucao do sistema LDP:" << endl;
           vector<double> LDP =    fatoracaoLDP(matriz, vetorB);


           imprimirVetor(LDP);
           Teste_quebra(LDP);
       }
       else if (item == 'c') {
            itemC();
       }

       else if (item== 'd'){
           inputUser();
       }

   } while (item != 's');
}

int main() {

    menu();

}
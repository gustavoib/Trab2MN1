#include "auxiliares.h"
#include "metodos.h"
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

// Função para mostrar um quadro comparativo dos resultados  de cada método pra n matrizes
void itemD() {

    int num = 0;
    cout << "Digite o numero de variacoes desejado: ";
    cin >> num;

    // Inicialização de vetores utilizados
    vector<vector<vector<double>>> variacoesA(num, vector<vector<double>>(3, vector<double>(3, 0.0)));
    vector<vector<double>> variacoesF(num, vector<double>(3, 0.0));
    vector<vector<double>> resultadosLU(num, vector<double>(3, 0.0));
    vector<vector<double>> resultadosLDP(num, vector<double>(3, 0.0));

    // Recebimento das matrizes e dos F's
    for (int i = 0; i < num; i++) {
        cout << "Agora digite os valores da matriz " << i + 1 << ": " <<endl;

        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cout << "Elemento a" << j+1 << k+1 << ": ";
                cin >> variacoesA[i][j][k];

                if (cin.fail()) {
                    cout << "Entrada Invalida." << endl;
                    return;
                }
            }
        }

        cout << "Agora digite os valores do vetor F referente a ela: " << endl;

        for (int j = 0; j < 3; j++) {
            cout << "Elemento f[" << j << "]: ";
            cin >> variacoesF[i][j];

            if (cin.fail()) {
                cout << "Entrada Invalida." << endl;
                return;
            }
        }
    }

    // Cálculo dos resultados de cada método
    for (int i = 0; i < num; i++) {
        vector<vector<double>> matrizL, matrizU;
        resultadosLU[i] = fatoracaoLU(variacoesA[i], matrizL, matrizU, variacoesF[i]);
        resultadosLDP[i] = fatoracaoLDP(variacoesA[i], variacoesF[i]);

    }

    // Exibição dos resultados
    cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=- Quadro comparativo das matrizes =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    int linhas = resultadosLU.size();
    int colunas = resultadosLU[0].size();

    cout << endl << "Pela fatoracao LU:" << endl;
    for (int i = 0; i < linhas; i++) {
        exibirLinhas(linhas);
        cout << endl;
        cout << "||     Resultados da matriz " << i + 1 << "     ||" << endl;
        exibirLinhas(linhas);
        cout<< "\n|| ";
        for (int j = 0; j < colunas; j++) {
            cout<<setw(5)<<setprecision(5) << resultadosLU[i][j];
            if (j!= colunas-1)
                cout<< "   ||  ";
        }
        cout <<"   ||"<< endl;
    }
    exibirLinhas(linhas);
    cout << endl;

    cout << endl << "Pela fatoracao LDP:" << endl;
    for (int i = 0; i < linhas; i++) {
        exibirLinhas(linhas);
        cout << endl;
        cout << "||     Resultados da matriz " << i + 1 << "     ||" << endl;
        exibirLinhas(linhas);
        cout<< "\n|| ";
        for (int j = 0; j < colunas; j++) {
            cout<<setw(5)<<setprecision(5) << resultadosLDP[i][j];
            if (j!= colunas-1)
                cout<< "   ||  ";
        }
        cout <<"   ||"<< endl;
    }
    exibirLinhas(linhas);
    cout << endl;
}

// Função para retornar o resultado de cada método para uma matriz de tamanho n e um vetor F de tamanho n
void itemC() {
    // Recebimento do valor de n
    int n = 0;
    cout << "Digite a ordem n da matriz quadrada com n maior ou igual a dois :" << endl;
    while (n < 2) {
        cin >> n;
        if (n < 2)
            cout << "Valor invalido." << endl;
    }

    // Recebimento dos valores da matriz
    cout << "Agora digite os valores da matriz: " << endl;

    vector<vector<double>> matriz(n, vector<double>(n, 0.0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Elemento a" << i+1 << j+1 << ": ";
            cin >> matriz[i][j];

            if (cin.fail()) {
                cout << "Entrada Invalida." << endl;
                return;
            }
        }
    }

    // Recebimento dos valores do vetor F
    cout << "Agora digite os valores do vetor F: " << endl;

    vector<double> F(n, 0.0);

    for (int i = 0; i < n; i++) {
        cout << "Elemento f[" << i << "]: ";
        cin >> F[i];

        if (cin.fail()) {
            cout << "Entrada Invalida." << endl;
            return;
        }
    }

    // Cálculo dos resultados de cada método
    vector<vector<double>> matrizL, matrizU, aux1, aux2;

    // Exibindo resultados da Fatoração LU
    cout << "Resultado da fatoracao LU com os dados inseridos: " << endl;
    vector<double> solucaoLU = fatoracaoLU(matriz, matrizL, matrizU, F);

    // Exibição das matrizes L e U
    cout << "Matriz L:" << endl;
    imprimirMatriz(matrizL);

    cout << "Matriz U:" << endl;
    imprimirMatriz(matrizU);

    // Exibição dos Resultados
    cout << "Solucao do sistema LU:" << endl;
    imprimirVetor(solucaoLU);
    Teste_quebra(solucaoLU);

    // Exibindo resultados da Fatoração LDP
    cout << "Resultado da fatoracao LPD com os dados inseridos: " << endl;
    vector<double> LDP =    fatoracaoLDP(matriz, F);

    //Exibição das matrizes L, D e P
    cout << "Matriz L:" << endl;
    imprimirMatriz(gerarL(matriz, aux1, aux2, F));

    cout << "Matriz D:" << endl;
    imprimirMatriz(gerarMatrizD(matriz));

    cout << "Matriz P:" << endl;
    imprimirMatriz(gerarMatrizP(matriz));

    // Exibição dos Resultados
    cout << "Solucao do sistema LDP:" << endl;
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
           itemD();
       }

   } while (item != 's');
}

int main() {

    menu();

}
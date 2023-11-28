#include "auxiliares.h"
#include "metodos.h"
#include <vector>
#include <iostream>
#include <cctype>
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
   // double x=0.0;
   vector<vector<double>> matrix;
   for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++) {
           cin >> matrix[i][j];
           if (!isdigit(matrix[i][j])) {
               cout << "Dígito Inválido." << endl;
               inputUser();
           }
       }
   }
   imprimirMatriz(matrix);
}


void menu() {
   char item;
   do {




       vector<vector<double>> matriz = {
               {3, -2, 1},
               {1, -3, 4},
               {9, 4,  -5}
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


           }




       else if (item== 'd'){
           inputUser();
       }










   } while (item != 's');
}
int main() {


menu();
}
















/*
*     vector<vector<double>> matriz = {
           {3, -2, 1},
           {1, -3, 4},
           {9, 4,  -5}
   };


   // Vetor b
   vector<double> vetorB = {8, 6, 11};


   cout << "Matriz A:" << endl;
   imprimirMatriz(matriz);


   cout << "Vetor b:" << endl;
   imprimirVetor(vetorB);


   // Escalonar a matriz A
   vector<vector<double>> matrizEscalonada = escalonarMatriz(matriz);


   cout << "Matriz A escalonada:" << endl;
   imprimirMatriz(matrizEscalonada);


   // Resolver o sistema Ax = b
   vector<double> solucao = resolverSistema(matriz, vetorB);


   cout << "Solucao do sistema:" << endl;
   imprimirVetor(solucao);


   cout << "Matriz A:" << endl;
   imprimirMatriz(matriz);


   // Fatorar matrizA em LU
   vector<vector<double>> matrizL, matrizU;
   vector<double> solucaoLU = fatoracaoLU(matriz, matrizL, matrizU, vetorB);


   cout << "Matriz L:" << endl;
   imprimirMatriz(matrizL);


   cout << "Matriz U:" << endl;
   imprimirMatriz(matrizU);


   cout << "Solucao do sistema LU:" << endl;
   imprimirVetor(solucaoLU);




   // Fatorar matrizA em LDP
   vector<double> LDP = fatoracaoLDP(matriz, vetorB);
   cout << "Solucao do sistema LDP:" << endl;
   imprimirVetor(LDP);
* */
//     //menu();
//     double matriz[3][3] = {
//             {3, -2, 1},
//             {1, -3, 4},
//             {9, 4, -5}
//     };


//     double matriz2[3][3] = {
//             {3, -2, 1},
//             {1, -3, 4},
//             {9, 4, -5}
//     };


//     double b[3] = {8, 6, 11};


//     double matrizL[3][3] = {
//             {1, 0, 0},
//             {0, 1, 0},
//             {0, 0, 1}
//     };


//     double matrizL2[3][3] = {
//             {1, 0, 0},
//             {0, 1, 0},
//             {0, 0, 1}
//     };


//     int n = 3;
//     vector<double> y(n);
//     vector<double> x(n);


//     geradorDeLU(n, matriz, matrizL);


//     y = resolucaoAxb(n, matrizL, b);
//     x = resolucaoAxb(n, matriz, y.data());


//     for(int i = 0; i < n; i++){
//       cout << x[i] << "\n";
//     }


//     cout << "LDP" << endl;


//     fatoracaoLDP(n, matriz2, matrizL2, b);


//     return 0;
// }


// void menu() {


//     cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
//     cout << "               | 3  -2  1 |           | 8 |\n";
//     cout << "         [A] = | 1  -3  4 |     {f} = | 6 |\n";
//     cout << "               | 9   4 -5 |           | 11|\n\n";
//     cout << "Escolha qual item você deseja executar:" << endl << endl
//          << "[a] Obter valores do deslocamento d através da Fatoração LU" << endl
//          << "[b] Obter valores do deslocamento d através da Fatoração LDP" << endl
//          << "[c] Gerar quadro resposta para cada método, variando os valores de [A] e de {f}" << endl;
//     cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;


//     char item;
//     cin >> item;
//     /*
//     if (item == 'a') {
//       fatoracaoLU();
//     } else if (item == 'b') {
//       fatoracaoLDP();
//     } else if (item == 'c') {
//       ;
//     }*/

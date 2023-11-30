#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;


// Função para imprimir a matriz
void imprimirMatriz(const vector<vector<double>> &matriz) {
   int linhas = matriz.size();
   int colunas = matriz[0].size();


   for (int i = 0; i < linhas; i++) {
       for (int z = 0 ; z< linhas; z++) {
       cout<<"++--------++";
       }
       cout<< "\n|| ";
       for (int j = 0; j < colunas; j++) {
           cout<<setw(5)<<setprecision(5) << matriz[i][j] ;
           if (j!= colunas-1)
           cout<< "   ||  ";
       }
       cout <<"   ||"<< endl;
   }
   for (int z = 0 ; z< linhas; z++) {
       cout<<"++--------++";
   }
   cout << endl;
}


// Função para imprimir vetor
void imprimirVetor(const vector<double> &vetor) {
   int tamanho = vetor.size();
   cout<< "{d} = [ ";
   for (int i = 0; i < tamanho; i++) {
       cout <<vetor[i] ;
       if(i != tamanho-1)
       cout<< " , ";
   }
   cout<<" ]"<<endl;
   cout << endl;


}


// Função para avaliar se o deslocamentos das partes excede o limite:
void Teste_quebra(const vector<double> &vetor){
   int tamanho = vetor.size();


   for (int i = 0; i < tamanho; i++) {
       if(abs(vetor[i]) >2)
           printf("d%d ira quebrar.\n", i+1) ;
       else
           printf("d%d nao ira quebrar.\n", i+1) ;
   }


   cout << endl;


}


// Função para escalonar a matriz sem garantir que o pivô seja 1
vector<vector<double>> escalonarMatriz(const vector<vector<double>>& matriz) {
   vector<vector<double>> matrizEscalonada = matriz;
   int linhas = matrizEscalonada.size();
   int colunas = matrizEscalonada[0].size();


   for (int i = 0; i < linhas; i++) {
       // Encontrar o pivô (o primeiro elemento não nulo na linha
       double pivo = matrizEscalonada[i][i];


       // Subtrair múltiplos da linha atual de outras linhas para zerar elementos abaixo do pivô
       for (int k = i + 1; k < linhas; k++) {
           double fator = matrizEscalonada[k][i] / pivo;
           for (int j = 0; j < colunas; j++) {
               matrizEscalonada[k][j] -= fator * matrizEscalonada[i][j];
           }
       }
   }
   return matrizEscalonada;
}


// Função para realizar o escalonamento da matriz
vector<vector<double>> gerarMatrizP(const vector<vector<double>> &matriz) {
   int linhas = matriz.size();
   int colunas = matriz[0].size();


   // Criar uma cópia da matriz original
   vector<vector<double>> matrizP = matriz;


   for (int i = 0; i < linhas; i++) {
       // Normalizando a linha atual
       double divisor = matrizP[i][i];
       for (int j = i; j < colunas; j++) {
           matrizP[i][j] /= divisor;
       }


       // Subtraindo a linha atual das linhas abaixo para zerar os elementos abaixo do pivô
       for (int k = i + 1; k < linhas; k++) {
           double multiplicador = matrizP[k][i];
           for (int j = i; j < colunas; j++) {
               matrizP[k][j] -= multiplicador * matrizP[i][j];
           }
       }
   }


   return matrizP;
}


vector<vector<double>> gerarMatrizD (const vector<vector<double>> &matriz) {
   int n = matriz.size();
   vector<vector<double>> matrizD;
   vector<vector<double>> matrizEscalonada;
   matrizD = vector<vector<double>>(n, vector<double>(n, 0.0));


   matrizEscalonada = escalonarMatriz(matriz);


   for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++) {
           if (i == j) {
               matrizD[i][j] = matrizEscalonada[i][j];
           }
       }
   }
   return matrizD;
}


// Função para realizar o escalonamento da matriz e resolver o sistema Ax = b
vector<double> resolverSistema(vector<vector<double>> matrizA, vector<double> vetorB) {
   int n = matrizA.size();


   for (int i = 0; i < n; i++) {
       // Normalizando a linha atual
       double divisor = matrizA[i][i];
       for (int j = i; j < n; j++) {
           matrizA[i][j] /= divisor;
       }
       vetorB[i] /= divisor;


       // Subtraindo a linha atual das linhas abaixo para zerar os elementos abaixo do pivô
       for (int k = i + 1; k < n; k++) {
           double multiplicador = matrizA[k][i];
           for (int j = i; j < n; j++) {
               matrizA[k][j] -= multiplicador * matrizA[i][j];
           }
           vetorB[k] -= multiplicador * vetorB[i];
       }
   }


   // Substituição retroativa
   vector<double> solucao(n, 0.0);
   for (int i = n - 1; i >= 0; i--) {
       solucao[i] = vetorB[i];
       for (int j = i + 1; j < n; j++) {
           solucao[i] -= matrizA[i][j] * solucao[j];
       }
   }


   return solucao;
}


// Função para realizar a substituição retroativa e encontrar a solução do sistema Ax = b
vector<double> resolverSistema(const vector<vector<double>> &matrizA, const vector<double>& vetorB) {
   int n = matrizA.size();
   vector<double> solucao(n, 0.0);


   // Substituição retroativa
   for (int i = n - 1; i >= 0; i--) {
       solucao[i] = vetorB[i];
       for (int j = i + 1; j < n; j++) {
           solucao[i] -= matrizA[i][j] * solucao[j];
       }
       solucao[i] /= matrizA[i][i];
   }

   return solucao;
}

void exibirLinhas(int tamanho) {
    for (int z = 0 ; z <= tamanho + 1 ; z++) {
        cout<<"++--------++";
    }
}

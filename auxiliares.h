#ifndef TRAB2MN1_AUXILIARES_H
#define TRAB2MN1_AUXILIARES_H


#include <vector>


using namespace std;


vector<vector<double>> escalonarMatriz(const vector<vector<double>> &matriz);


vector<vector<double>> gerarMatrizD(const vector<vector<double>> &matriz);


void imprimirMatriz(const vector<vector<double>> &matriz);


vector<vector<double>> gerarMatrizP(const vector<vector<double>> &matriz);


vector<double> resolverSistema(vector<vector<double>> matrizA, vector<double> vetorB);


void imprimirVetor(const vector<double> &vetor);


void Teste_quebra(const vector<double> &vetor);


void exibirLinhas(int tamanho);


#endif //TRAB2MN1_AUXILIARES_H


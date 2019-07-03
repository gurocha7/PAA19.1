#ifndef GRAFO_HPP   
#define GRAFO_HPP

#include <string>
using namespace std;

class Grafo{
    int vertices;
    int **arestas;
    int *nAdjacencias;
    
    int contadorLinha, contadorColuna, tamanho;
    int **matrizSat;
    int **matrizAux;

    int* auxConjuntoIndependente(int*,int, int*, int);
    void complemento();
    bool eConsistente(int*);
    bool ePromissor(int*, int);
    int* listaDeAdjacencia(int);    //AQUI RETORNARÁ A LISTA DE ADJACENCIA DE UM VERTICE SELECIONADO
    bool eClique(int*);

public:

Grafo(string=""); // AQUI SERÁ POSSIVEL CRIAR UM GRAFO E JÁ ASSOCIÁ-LO A UM ARQUIVO
~Grafo();

void leGrafo(string);      //AQUI O CODIGO LERÁ UM ARQUIVO DE TEXTO CONTENDO OS DADOS DO GRAFO
void leSat(string);        //AQUI O CODIGO LERÁ UM ARQUIVO DE TEXTO CONTENDO OS DADOS DO PROBLEMA DE SATISFABILIDADE
void imprime(int);         //AQUI IMPRIMIRÁ DE ACORDO COM A CLASSIFICAÇÃO
void imprimeGrafo();       //AQUI IMPRIMIRÁ EXATAMENTE COMO ESTÁ NO ARQUIVO
void imprimeSat();         //AQUI IMPRIMIRÁ EXATAMENTE COMO ESTÁ NO ARQUIVO DE ENTRADA DO PROBLEMA SAT 

int* clique();                 //AQUI RESOLVERÁ O PROBLEMA DE CLIQUE E IMPRIMIRÁ O RESULTADO   *** DEVERÁ TIRAR AS CHAVES APÓS A IMPLEMENTAÇÃO NO CPP ***
int* conjuntoIndependete();    //AQUI RESOLVERÁ O PROBLEMA DE CONJUNTO INDEPENDENTE E IMPRIMIRÁ O RESULTADO *** DEVERÁ TIRAR AS CHAVES APÓS A IMPLEMENTAÇÃO NO CPP ***
int* satisfabilidade();        //AQUI RESOLVERA O PROBLEMA DE SATISFABILIDADE
int getVertices();
int getTamanho();
};


#endif
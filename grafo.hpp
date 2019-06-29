#ifndef GRAFO_HPP   
#define GRAFO_HPP

#include <string>
using namespace std;

class Grafo{
    int vertices;
    int **arestas;
    int *nAdjacencias;
    
    int contadorLinha, contadorColuna;

    int* auxConjuntoIndependente(int*,int, int*, int);
    void complemento();
    bool eConsistente(int*);
    bool ePromissor(int*, int);

public:

Grafo(string=""); // AQUI SERÁ POSSIVEL CRIAR UM GRAFO E JÁ ASSOCIÁ-LO A UM ARQUIVO
~Grafo();

void leGrafo(string);      //AQUI O CODIGO LERÁ UM ARQUIVO DE TEXTO CONTENDO OS DADOS DO GRAFO
void imprimeGrafo();       //AQUI IMPRIMIRÁ EXATAMENTE COMO ESTÁ NO ARQUIVO
void leSat(string);        //AQUI O CODIGO LERÁ UM ARQUIVO DE TEXTO CONTENDO OS DADOS DO PROBLEMA DE SATISFABILIDADE
void imprimeSat();         //AQUI IMPRIMIRÁ EXATAMENTE COMO ESTÁ NO ARQUIVO DE ENTRADA DO PROBLEMA SAT 

int* clique();                 //AQUI RESOLVERÁ O PROBLEMA DE CLIQUE E IMPRIMIRÁ O RESULTADO   *** DEVERÁ TIRAR AS CHAVES APÓS A IMPLEMENTAÇÃO NO CPP ***
int* conjuntoIndependete();    //AQUI RESOLVERÁ O PROBLEMA DE CONJUNTO INDEPENDENTE E IMPRIMIRÁ O RESULTADO *** DEVERÁ TIRAR AS CHAVES APÓS A IMPLEMENTAÇÃO NO CPP ***
void satisfabilidade();        //AQUI RESOLVERA O PROBLEMA DE SATISFABILIDADE E IMRIMIRA O RESULTADO
int getVertices();


int* listaDeAdjacencia(int);    //AQUI RETORNARÁ A LISTA DE ADJACENCIA DE UM VERTICE SELECIONADO

};


#endif
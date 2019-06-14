#ifndef GRAFO_HPP   
#define GRAFO_HPP

#include <string>
using namespace std;

class Grafo{
    int vertices;
    int **arestas;

public:

Grafo(string=""); // AQUI SERÁ POSSIVEL CRIAR UM GRAFO E JÁ ASSOCIÁ-LO A UM ARQUIVO
~Grafo();

void leGrafo(string);      //AQUI O CODIGO LERÁ UM ARQUIVO DE TEXTO CONTENDO OS DADOS DO GRAFO
void imprimeGrafo();       //AQUI IMPRIMIRÁ EXATAMENTE COMO ESTÁ NO ARQUIVO

void clique(){}                 //AQUI RESOLVERÁ O PROBLEMA DE CLIQUE E IMPRIMIRÁ O RESULTADO   *** DEVERÁ TIRAR AS CHAVES APÓS A IMPLEMENTAÇÃO NO CPP ***
void conjuntoIndependete(){}    //AQUI RESOLVERÁ O PROBLEMA DE CONJUNTO INDEPENDENTE E IMPRIMIRÁ O RESULTADO *** DEVERÁ TIRAR AS CHAVES APÓS A IMPLEMENTAÇÃO NO CPP ***

int* listaDeAdjacencia(int);    //AQUI RETORNARÁ A LISTA DE ADJACENCIA DE UM VERTICE SELECIONADO

};




#endif
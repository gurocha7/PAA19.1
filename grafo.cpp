#include <iostream>
#include "grafo.hpp"


#include <fstream>


Grafo::Grafo(string nomeDoArquivo){
    if(nomeDoArquivo != "")
        leGrafo(nomeDoArquivo);
    else{
        vertices=0;
        arestas = nullptr;
    }
}

Grafo::~Grafo(){
    for(int i=0; i< vertices-1; i++)
        delete [] arestas[i];
    delete [] arestas;
}

void Grafo::leGrafo(string nomeDoArquivo){

    ifstream arquivo(nomeDoArquivo);        //declara um objeto ja atribuindo ao nome do arquivo

   if (arquivo.is_open() && arquivo.good()){ // verifica se está tudo certo no arquivo 

    arquivo >> vertices;                    //faz a leitura do primeiro inteiro do arquivo, será referente ao numero de vertices

    arestas = new int*[vertices];           // cria a matriz de adjacencias
    for(int i=0; i< vertices; i++)
        arestas[i] = new int[vertices];


    int contador=0;           // controlará o percurso na matriz
    char lixo;              // receberá os espaços vazios do arquivo


    while(!arquivo.fail()){                                             // le a matriz de adjacencia
        arquivo >> arestas[contador/vertices][contador%vertices];      // le o inteiro
        contador++;
    }

        arquivo.close();
    }
}

void Grafo::imprimeGrafo(){

    cout << vertices << endl;
    for (int i = 0; i < vertices; i++){
        for (int j = 0; j < vertices; j++){
            cout << arestas[i][j] << "\t";
        }
        cout << endl;
    }
}


int* Grafo::listaDeAdjacencia(int coluna){
    return arestas[coluna];
}

int* Grafo::conjuntoIndependete(){
    int* conjunto = new int[vertices];
    for (int i = 0; i < vertices; i++) conjunto[i]=0;     // assume valores iniciais igual a 0 para indicar que nenhum valor pertence ao conjunto independente;
    

    for(int i=0; i < vertices; i++){
        conjunto = auxConjuntoIndependente(conjunto,i);             
    }
    for(int i=0; i< vertices; i++)
        cout << conjunto[i] << "\t";
    cout << endl;

    return conjunto;
}

int* Grafo::auxConjuntoIndependente(int* conjunto,int vertice){
    int* adjacencias = listaDeAdjacencia(vertice);        // recebe a lista de adjacencias do vertice

    int cont = 0;                                         // vai contar o numero de vizinhos que fazem parte do conjunto independente    
    for (int i = 0; i < vertices; i++) 
        if (adjacencias[i] == 1)                          // conta o numero de vizinhos do vertice
            cont ++;
    

    for (int i = 0; i < vertices; i++){                   // percorre a lista de adjacencia
        if(adjacencias[i] == 1 && i != vertice)           // se for 1 e se não for ele mesmo, continua
            if(conjunto[i] != 1){                         // se não fizer parte do conjunto independente, diminui o contador
                cont--;
            }   
    }
    if (cont == 0)                                         // todos os vizinhos não fizerem parte do conjunto independete
        conjunto[vertice] = 1;                             // este vertice passa a fazer parte do conjunto independente
    
    return conjunto;
}


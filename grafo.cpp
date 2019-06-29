#include <iostream>
#include "grafo.hpp"


#include <fstream>


Grafo::Grafo(string nomeDoArquivo){
    if(nomeDoArquivo != "")
        leGrafo(nomeDoArquivo);
    else{
        vertices=0;
        arestas = nullptr;
        nAdjacencias = nullptr;
    }
}

Grafo::~Grafo(){
    for(int i=0; i< vertices-1; i++)
        delete [] arestas[i];
    delete [] arestas;

    delete [] nAdjacencias;
}

void Grafo::leGrafo(string nomeDoArquivo){

    ifstream arquivo(nomeDoArquivo);        //declara um objeto ja atribuindo ao nome do arquivo

   if (arquivo.is_open() && arquivo.good()){ // verifica se está tudo certo no arquivo 

    arquivo >> vertices;                    //faz a leitura do primeiro inteiro do arquivo, será referente ao numero de vertices

    arestas = new int*[vertices];           // cria a matriz de adjacencias
    for(int i=0; i< vertices; i++)
        arestas[i] = new int[vertices];


    int contador=0;           // controlará o percurso na matriz

    while(!arquivo.fail()){                                             // le a matriz de adjacencia
        arquivo >> arestas[contador/vertices][contador%vertices];      // le o inteiro
        contador++;
    }

        arquivo.close();
    }

    nAdjacencias = new int [vertices];
    for(int i=0; i< vertices; i++ ) nAdjacencias[i] = 0;

    int cont;
    for(int i=0; i< vertices; i++ ){
        int* adjacencias = listaDeAdjacencia(i);        // recebe a lista de adjacencias do vertice
        cont =0;
        for(int j=0; j< vertices; j++){
            if (adjacencias[i] == 1)                          // conta o numero de vizinhos do vertice
                cont ++;
        }
        nAdjacencias[i]=cont;
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
    
    int melhor = 0;
    for(int i=0; i < vertices; i++){
        int* proposta = new int[vertices];
        for (int i = 0; i < vertices; i++) proposta[i]=0;
        proposta[i]=1;
        conjunto = auxConjuntoIndependente(conjunto,melhor,proposta,i);
        melhor=0;
        for(int j=0; j < vertices; j++) 
            if(conjunto[j]==1)
                melhor+=1;
    }

    return conjunto;
}

int* Grafo::auxConjuntoIndependente(int* melhorConjunto, int melhorTamanho, int* proposta, int vertice){
    int *adjacencias=listaDeAdjacencia(vertice);                                                        // recupera todas as adjacencias do vertice
    for(int i=0; i < vertices; i++){                                                                    // para todo vizinho do vertice
        if(proposta[i]!=1){
            proposta[i]=1;                                                                              // inclui na proposta
            if(eConsistente(proposta)){                                                                 // verifica se é consistente 
                proposta = auxConjuntoIndependente(melhorConjunto, melhorTamanho, proposta, i);         // se for, continua procurando mais valores
            }                                                                 
            else{
                proposta[i] = 0;                                                                        // se não for, zera o valor e     
            }   
        }                                                                         

        if(ePromissor(proposta,melhorTamanho)){                                                         // ao final das propostas, se ela for promissora
            melhorConjunto = proposta;                                                                  // assume como melhor conjunto
            melhorTamanho=0;
            for(int contador = 0; contador < vertice; contador ++)                                      // e conta seu tamanho
                if(melhorConjunto[contador] == 1)
                    melhorTamanho+=1;                                                                                
        }
    }

    return melhorConjunto;                                                                              // retorna o melhor conjunto
}

void Grafo::complemento(){
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++){
            if(arestas[i][j]==1)
                arestas[i][j]=0;
            else if( i!=j )
                arestas[i][j]=1;
        }
    
    for(int i=0; i < vertices; i++)
        nAdjacencias[i] = vertices - nAdjacencias[i];
}

int* Grafo::clique(){
    complemento();
    int* clique = conjuntoIndependete();
    complemento();
    return clique;
}

bool Grafo::eConsistente(int* solucao){
    for(int i=0; i < vertices; i++){
        if (solucao[i]==1){
            int* vizinhos=listaDeAdjacencia(i);
            for(int j=0; j < vertices; j++)
                if (vizinhos[j]==1 && solucao[j] == 1 )
                    return false;
        }   
    }
    return true;
}

bool Grafo::ePromissor(int* solucao, int melhor){
    int contador=0;
    for(int i=0; i < vertices; i++)
        if(solucao[i] == 1)
            contador++;
    return contador > melhor;
}

int Grafo::getVertices(){
    return vertices;
}
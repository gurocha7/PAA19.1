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
    if (cont == 0)/** 
                    * se for igual a zero ele contou o numero de vizinhos e os mesmos não fazem parte do conjunto independente, 
                    * logo, todos os vizinhos não fazem parte do conjunto independete 
                    */ 
        conjunto[vertice] = 1;                             // este vertice passa a fazer parte do conjunto independente
    
    return conjunto;
}

int* Grafo::redution(int* conjunto){

    int* array_aux = new int[vertices - conjunto.size()]; //constroi um vetor do com os vertices que nao estao no conjunto independente
    int sizeRedution = vertices - conjunto.size();   //pega a quantidade de vertices que nao estao no conjunto independente

    for (int j = 0; j < sizeRedution; ++j)
    {
        for (int i = 0; i < vertices; ++i)
        {
            if (find(conjunto.begin(), conjunto.end(), i)){
                //anything
            }else{
                array_aux[j] = i;   // se nao encontrar o vertice no conjunto independete, adicionamos ele no vetor de redução.
                j++;
            }
        }
    }

    return array_aux;
}

void Grafo::clique(int* array_aux){

    string clique = "";
    int i = 0;

    for (int j = 0; j < vertices; ++j)
    {

        while (arestas[array_aux[i]][j] == 1) { //se o vertice possui arestas para todos os outros vertices que nao sao cdo conjunto independente
            i++;
        } 

        if (i == array_aux.size()){
            string += " "+ j;       //se o vertice j possuir arestas para todos, ele e adicionado na string como parte da solucao do cique
        }

        i = 0;
    }

    cout << " vertices envolvidos na clique: " << string << endl; //exibimos a string que contem todos os vertices contidos na solucao

}

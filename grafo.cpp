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

    for(int j=0; j < tamanho-1; j++)
        delete [] matrizSat[j];
    delete[] matrizSat;

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

void Grafo::leSat(string nomeDoArquivo)
{
    string fimLinha;

    ifstream arquivo(nomeDoArquivo);

    if(arquivo.is_open() && arquivo.good()){

        contadorLinha = 0;

        while(getline(arquivo, fimLinha)){      // percorre todo o arquivo para pegar o numero total de linhas
            contadorLinha++;
        }

        arquivo.clear();                        // volta para o inicio do arquivo
        arquivo.seekg(0, ios::beg);

        arquivo >> vertices;
    
        arestas = new int*[contadorLinha-2];      // alocando memória para as linhas
        for(int i=0; i < contadorLinha-1; i++)
            arestas[i] = new int[vertices];       // alocando memória para as colunas

        matrizAux = new int*[contadorLinha-2];
        for (int i = 0; i < contadorLinha-1; i++)
        {
            matrizAux[i] = new int[vertices];
        }
        

        for(int j=0; j < contadorLinha-1; j++)   // preenche a matriz com zeros
            for(int k=0; k < vertices; k++)
                arestas[j][k] = 0;
        
        contadorLinha = 0;
        contadorColuna = 0;

        int qtd = 0;

        while(!arquivo.eof()){            
            arquivo >> arestas[contadorLinha][contadorColuna];

            contadorColuna++;

            if(contadorColuna == vertices){
                contadorLinha++;
                contadorColuna = 0;
            }
            
        }
        arquivo.close();
    }
}

void Grafo::imprimeSat()
{
    cout << vertices << endl;
    for(int i = 0; i < contadorLinha; i++){
        for(int j = 0; j < vertices; j++)
            cout << arestas[i][j] << " ";
    
        cout << endl;
    }
}

void Grafo::satisfabilidade()
{
    tamanho = 0;
    int contador = 0, aux = 0;
    int i = 0, j = 0, k = 0, m = 0;

    for(i = 0; i < contadorLinha; i++){     // Pega o total de variaveis diferentes de 2
        for(j = 0; j < vertices; j++)
            if(arestas[i][j] != 2)
                tamanho++;
    }

    matrizSat = new int*[tamanho];          // Cria uma matriz de tamanho = tamanho * tamanho
    for(i=0; i < tamanho; i++)
        matrizSat[i] = new int[tamanho];   

    for(i = 0; i < tamanho; i++)            // Preenche a matriz criada com zeros
        for(j = 0; j < tamanho; j++)
            matrizSat[i][j] = 0;

    for(i = 0; i < contadorLinha; i++){     // Percorre a matriz de entrada do SAT
        for(j = 0; j < vertices; j++){          
            if(arestas[i][j] != 2)          // Conta todos os valores da matriz diferentes de 2 na mesma linha 
                contador++;                 
            
            for(k = 0; k < contador; k++)          
                for(m = 0; m < contador; m++){
                    if(k != m)
                        matrizSat[k+aux][m+aux] = 1;    // Se não atribui valor 1 (ligação de variaveis da mesma clausula)
                }
        }
        aux += contador;
        contador = 0;
    }


    for(i = 0; i < tamanho; i++){      
        for(j = 0; j < tamanho; j++)
            cout << matrizSat[i][j] << " ";
        cout << endl;
    }
}


void Grafo::buildMatrizAux(){

    int qtd = 0;

    for(int i = 0; i < contadorLinha; i++){
        for(int j = 0; j < vertices; j++){
            if (arestas[i][j] == 2)
            {
                matrizAux[i][j] = -1;
            }else{
                matrizAux[i][j] = qtd;
                qtd++;
            }
        }
        cout << endl;
    }
}

void Grafo::readClause(){
    int j = 0;
    int aux = 1;
    int numCol = 1;
    int i = 0;
    int qtdEntrou = 0;

    cout << "Verticesss = " << vertices << endl;
    cout << "contadorLinha = " << contadorLinha << endl;

    while (numCol != vertices+1)
    {
        while (i != contadorLinha-1)
        {
            if (arestas[i][numCol-1] != 2 ){
                if (arestas[aux][numCol-1] != 2)
                {
                    if (arestas[aux][numCol-1] != arestas[i][numCol-1] )
                    {
                        //ligacao no grafo grande


                        int numeroColuna = matrizAux[i][numCol-1];
                        int numeroLinha =  matrizAux[aux][numCol-1];

                        cout << numeroColuna << ":";
                        cout << numeroLinha << endl;

                        matrizSat[numeroColuna][numeroLinha] = 1;
                        matrizSat[numeroLinha][numeroColuna] = 1;

                        qtdEntrou++;


                    }   
                }   
            }
            
            aux++;

            if (aux == contadorLinha ){
                i++;
                aux = i+1;
            }                        
        }   
        i=0;
        j++;
        aux=1; 
        numCol++;
    }
    
    for(i = 0; i < tamanho; i++){      
        for(j = 0; j < tamanho; j++)
            cout << matrizSat[i][j] << " ";
    cout << endl;
    }
} 
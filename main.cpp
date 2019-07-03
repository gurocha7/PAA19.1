#include <iostream>

#include "grafo.hpp"

using namespace std;

int main()
{
  Grafo grafo1("teste1.txt");
  Grafo grafo2("teste2.txt");
  Grafo grafo3("teste3.txt");

  int* conjuntoIndependente = grafo1.conjuntoIndependete();
  cout << "Conjunto Independete do Teste 1" << endl;
  for (int i = 0; i < grafo1.getVertices(); i++){
    cout << conjuntoIndependente[i] << " ";
  }
  cout << endl;
  conjuntoIndependente = grafo2.conjuntoIndependete();
  cout << "Conjunto Independete do Teste 2" << endl;
  for (int i = 0; i < grafo2.getVertices(); i++){
    cout << conjuntoIndependente[i] << " ";
  }
  cout << endl;
  conjuntoIndependente = grafo3.conjuntoIndependete();
  cout << "Conjunto Independete do Teste 3" << endl;
  for (int i = 0; i < grafo3.getVertices(); i++){
    cout << conjuntoIndependente[i] << " ";
  }
  cout << endl;
  int* clique = grafo1.clique();
  cout << endl << "Clique do Teste 1" << endl;
  for (int i = 0; i < grafo1.getVertices(); i++){
    cout << clique[i] << " ";
  }
  cout << endl;
  clique = grafo2.clique();
  cout << endl << "Clique do Teste 2" << endl;
  for (int i = 0; i < grafo2.getVertices(); i++){
    cout << clique[i] << " ";
  }
  cout << endl;
  clique = grafo3.clique();
  cout << endl << "Clique do Teste 3" << endl;
  for (int i = 0; i < grafo3.getVertices(); i++){
    cout << clique[i] << " ";
  }
  cout << endl;

  /* 
  Grafo grafoSat1;
  Grafo grafoSat2;
  Grafo grafoSat3;

  grafoSat1.leSat(COLOCAR OS NOMES DOS ARQUIVOS AQUI);
  grafoSat2.leSat(COLOCAR OS NOMES DOS ARQUIVOS AQUI);
  grafoSat3.leSat(COLOCAR OS NOMES DOS ARQUIVOS AQUI);

  int* satifabilidade = grafoSat1.satifabilidade();
  cout << endl << "Satifabilidade do Teste 1" << endl;
  for (int i = 0; i < grafoSat1.getVertices(); i++){
    cout << satifabilidade[i] << " ";
  }
  cout << endl;
  satifabilidade = grafo2.satifabilidade();
  cout << endl << "Satifabilidade do Teste 2" << endl;
  for (int i = 0; i < grafoSat2.getVertices(); i++){
    cout << satifabilidade[i] << " ";
  }
  cout << endl;
  satifabilidade = grafoSat3.satifabilidade();
  cout << endl << "Satifabilidade do Teste 3" << endl;
  for (int i = 0; i < grafoSat3.getVertices(); i++){
    cout << satifabilidade[i] << " ";
  }
  cout << endl;

  */
  return 0;
}
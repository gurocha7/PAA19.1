#include <iostream>
#include <time.h>
#include "grafo.hpp"

using namespace std;

int main()
{
  Grafo grafo1("teste1.txt");
  Grafo grafo2("teste2.txt");
  Grafo grafo3("teste3.txt");

  clock_t Ticks[2];
  Ticks[0] = clock();
  int* conjuntoIndependente = grafo1.conjuntoIndependete();
  cout << "Conjunto Independete do Teste 1" << endl;
  for (int i = 0; i < grafo1.getVertices(); i++){
    cout << conjuntoIndependente[i] << " ";
  }cout << endl;
  Ticks[1] = clock();
  double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  cout << " Tempo gasto: " << Tempo << " ms." <<endl;

  Ticks[0] = clock();
  conjuntoIndependente = grafo2.conjuntoIndependete();
  cout << "Conjunto Independete do Teste 2" << endl;
  for (int i = 0; i < grafo2.getVertices(); i++){
    cout << conjuntoIndependente[i] << " ";
  }cout << endl;
  Ticks[1] = clock();
  Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  cout << " Tempo gasto: " << Tempo << " ms." <<endl;

  Ticks[0] = clock();
  conjuntoIndependente = grafo3.conjuntoIndependete();
  cout << "Conjunto Independete do Teste 3" << endl;
  for (int i = 0; i < grafo3.getVertices(); i++){
    cout << conjuntoIndependente[i] << " ";
  }cout << endl;
  Ticks[1] = clock();
   Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  cout << " Tempo gasto: " << Tempo << " ms." <<endl;

  Ticks[0] = clock();
  int* clique = grafo1.clique();
  cout << endl << "Clique do Teste 1" << endl;
  for (int i = 0; i < grafo1.getVertices(); i++){
    cout << clique[i] << " ";
  }cout << endl;
  Ticks[1] = clock();
   Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  cout << " Tempo gasto: " << Tempo << " ms." <<endl;

  Ticks[0] = clock();
  clique = grafo2.clique();
  cout << endl << "Clique do Teste 2" << endl;
  for (int i = 0; i < grafo2.getVertices(); i++){
    cout << clique[i] << " ";
  }cout << endl;
  Ticks[1] = clock();
   Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  cout << " Tempo gasto: " << Tempo << " ms." <<endl;

  Ticks[0] = clock();
  clique = grafo3.clique();
  cout << endl << "Clique do Teste 3" << endl;
  for (int i = 0; i < grafo3.getVertices(); i++){
    cout << clique[i] << " ";
  }cout << endl;
  Ticks[1] = clock();
   Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  cout << " Tempo gasto: " << Tempo << " ms." <<endl;

  Grafo grafoSat1;
  Grafo grafoSat2;
  Grafo grafoSat3;

  cout << endl << "Satisfabilidade do Teste 1" << endl;
  Ticks[0] = clock();
  grafoSat1.leSat("testeSat.txt");
  int* satisfabilidade = grafoSat1.satisfabilidade();
  for (int i = 0; i < grafoSat1.getTamanho(); i++){
    cout << satisfabilidade[i] << " ";
  }cout << endl;
  Ticks[1] = clock();
   Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  cout << " Tempo gasto: " << Tempo << " ms." <<endl;

  cout << endl << "Satisfabilidade do Teste 2" << endl;
  Ticks[0] = clock();
  grafoSat2.leSat("testeSat2.txt");
  satisfabilidade = grafoSat2.satisfabilidade();
  for (int i = 0; i < grafoSat2.getTamanho(); i++){
    cout << satisfabilidade[i] << " ";
  }cout << endl;
  Ticks[1] = clock();
  Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  cout << " Tempo gasto: " << Tempo << " ms." <<endl;

  cout << endl << "Satisfabilidade do Teste 3" << endl;
  Ticks[0] = clock();
  grafoSat3.leSat("testeSat3.txt");
  satisfabilidade = grafoSat3.satisfabilidade();
  for (int i = 0; i < grafoSat3.getTamanho(); i++){
    cout << satisfabilidade[i] << " ";
  }cout << endl;
  Ticks[1] = clock();
  Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  cout << " Tempo gasto: " << Tempo << " ms." <<endl;

  return 0;
}

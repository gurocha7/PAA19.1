#include <iostream>

#include "grafo.hpp"

using namespace std;

int main()
{
  Grafo grafo("teste.txt");

  int* conjuntoIndependente = grafo.conjuntoIndependete();

  cout << "Conjunto Independete" << endl;

  for (int i = 0; i < 9; i++){
    cout << conjuntoIndependente[i] << " ";
  }

  cout << endl;

  int* clique = grafo.clique();


  cout << endl << "Clique" << endl;
  for(int i=0; i<9; i++){
    cout<< clique[i] << " ";
  }


  
  delete &grafo;

  return 0;
}
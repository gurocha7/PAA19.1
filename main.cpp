#include <iostream>

#include "grafo.hpp"

using namespace std;

int main()
{
  Grafo grafo("teste.txt");

/*   int* conjuntoIndependente = grafo.conjuntoIndependete();
  cout << "Conjunto Independete" << endl;

  for (int i = 0; i < grafo.getVertices(); i++){
    cout << conjuntoIndependente[i] << " ";
  }

  cout << endl;

  int* clique = grafo.clique();
  cout << endl << "Clique" << endl;

  for (int i = 0; i < grafo.getVertices(); i++){
    cout << clique[i] << " ";
  }
 */
  cout << endl;

  grafo.leSat("testeSat.txt");
  int * satisfabilidade = grafo.satisfabilidade();
  cout << endl << "Satisfabilidade" << endl;
  grafo.imprimeSat();

  delete &grafo;

  return 0;
}
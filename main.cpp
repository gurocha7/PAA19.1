#include <iostream>

#include "grafo.hpp"

using namespace std;

int main()
{
  Grafo grafo("teste.txt");
  grafo.imprimeGrafo();

  cout << endl;

  grafo.conjuntoIndependete();
  delete &grafo;

  return 0;
}
#include <iostream>

#include "grafo.hpp"

using namespace std;

int main()
{
  Grafo grafo("teste.txt");

  grafo.imprimeGrafo();
  delete &grafo;

  return 0;
}
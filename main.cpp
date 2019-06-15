#include <iostream>

#include "grafo.hpp"

using namespace std;

int main()
{
  cout << "Alterações apenas na própria branch";
  Grafo grafo("teste.txt");

  grafo.imprimeGrafo();
  delete &grafo;

  return 0;
}
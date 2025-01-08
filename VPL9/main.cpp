#include "vetor.hpp"

int main(){
  Vetor<int> v1(4);

  v1.AdicionaElemento(1);
  v1.AdicionaElemento(2);
  v1.AdicionaElemento(3);
  v1.AdicionaElemento(4);

  v1.Imprime();
  v1.SetElemento(1, 20);
  v1.Imprime();

  Vetor<int> v2(v1);

  v2.Imprime();

  return 0;
}
#include "HeapInt.hpp"

HeapInt::HeapInt(){
  this->valor = new int;
  *this->valor = 0;
}

HeapInt::HeapInt(int x){
  this->valor = new int;
  *this->valor = x;
}

HeapInt::HeapInt(const HeapInt& HeapInt){
  this->valor = new int;
  *this->valor = *HeapInt.valor;
}

HeapInt::~HeapInt(){
  delete this->valor;
}

HeapInt& HeapInt::operator = (const int& i){
  *this->valor = i;

  return *this;
}

HeapInt& HeapInt::operator = (const HeapInt& heapInt){
  if(this == &heapInt){
    return *this;
  }

  *this->valor = *heapInt.valor;

  return *this;
}

HeapInt HeapInt::operator + (const HeapInt& heapInt) {
  int soma = (*valor) + (*heapInt.valor);

  return HeapInt(soma);
}

HeapInt HeapInt::operator - (const HeapInt& heapInt){
  int subtracao = (*valor) - (*heapInt.valor);

  return HeapInt(subtracao);
}

bool HeapInt::operator == (const HeapInt& heapInt){
  return (*valor) == (*heapInt.valor);
}

istream& operator >> (istream &entrada, const HeapInt &heapInt){
  int valor;
  entrada >> valor;
  *heapInt.valor = valor;

  return entrada;
}

ostream& operator << (ostream &saida, const HeapInt& heapInt){
  cout << *heapInt.valor;

  return saida;
}
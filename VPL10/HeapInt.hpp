#ifndef HEAP_INT_H
#define HEAP_INT_H

#include <iostream>
#include <string>

using namespace std;

class HeapInt{
public:
  int* valor;

  HeapInt();
  HeapInt(int x);
  HeapInt(const HeapInt& HeapInt);

  ~HeapInt();

  HeapInt& operator = (const int& i);
  HeapInt& operator = (const HeapInt& heapInt);
  HeapInt operator + (const HeapInt& heapInt);
  HeapInt operator - (const HeapInt& heapInt);
  bool operator == (const HeapInt& heapInt);
  friend istream& operator >> (istream &entrada, const HeapInt &heapInt);
  friend ostream& operator << (ostream &saida, const HeapInt& heapInt);
};

#endif
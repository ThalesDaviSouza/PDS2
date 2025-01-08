#include <iostream>
#include <string>
#include <memory>

using namespace std;

template<typename T>
class Vetor{
private:
  T* array;
  bool* emUso;
  int maxSize;

public:
  Vetor(int n) : array(new T[n]), emUso(new bool[n]){
    this->maxSize = n; 

    bool* auxEmUso = emUso;

    for(int i = 0; i < n; i++){
      auxEmUso[i] = false;
    }
  }

  Vetor(Vetor<T>& original){
    T* origi = original.GetArray();
    int max = original.GetMaxSize();
    
    this->array = new T[max];
    this->emUso = new bool[max];
    this->maxSize = max;

    for(int pos = 0; pos < max; pos++){
      this->SetElemento(pos, origi[pos]);
    }
  }
  
  ~Vetor() {
    delete[] array;
    delete[] emUso;
  }
   
  void SetElemento(int i, T x){
    T* auxArray = array;
    bool* auxEmUso = emUso;
    
    auxArray[i] = x;
    auxEmUso[i] = true;
  
  }

  T* GetArray(){
    return array;
  }


  int GetMaxSize(){
    return maxSize;
  }

  T GetElemento(int i){
    return array[i];
  }

  void AdicionaElemento(T elem){
    T* auxArray = array;
    bool* auxEmUso = emUso;

    for(int i = 0; i < this->maxSize; i++){
      if(auxEmUso[i] == false){
        auxEmUso[i] = true;
        auxArray[i] = elem;
        return;
      }
    }

  }

  void Imprime(){
    T* auxArray = array;
    bool* auxEmUso = emUso;

    for(int i = 0; i < maxSize; i++){
      if(auxEmUso[i]){
        cout << auxArray[i] << " " << endl;
      }
    }
  }

};
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Teste{
private:
  int n;

public:
  Teste(){
    n = 0;
    cout << "Construtor " << n << endl;
  }

  Teste(int n){
    this->n = n;
    cout << "Construtor " << this->n << endl;
  }

  ~Teste(){
    cout << "Destrutor " << n << endl;
  }

  void setN(int n){
    this->n = n;
  }
};

int main(){
  int n;
  vector<Teste*> tradicionalPtrs;

  cin >> n;

  if(n % 2 == 0){
    for(int i = 1; i <= n; i++){
      Teste* tradicionalPtr = new Teste(i);
      unique_ptr<Teste> ptrUnique(new Teste(i));

      tradicionalPtrs.push_back(tradicionalPtr);
    }
    // Para evitar vazamento de memória
    // for(auto& ptr : tradicionalPtrs){
    //   delete ptr;
    // }
  }
  else{
    shared_ptr<Teste> ptrShared(new Teste());
    for(int i = 1; i <= n; i++){
      shared_ptr<Teste> ptr(ptrShared);

      ptr.get()->setN(i);

    }
    cout << ptrShared.use_count() << endl; 
  }


  return 0;
}
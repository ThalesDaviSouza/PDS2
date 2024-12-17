#include <iostream>
#include <vector>
#include <memory>

#define _USE_MATH_DEFINES
#include <cmath>

#include <iomanip>

using namespace std;

class Ponto {
private:
  int x;
  int y;

public:
  Ponto(): x(0), y(0) { }
  Ponto(int x, int y) : x(x), y(y) { }

  int getX() { return x; }
  int getY() { return y; }

  void setX(int X) { x = X; }
  void setY(int Y) { y = Y; }

};

class FiguraGeometrica{
private:
  Ponto centro;
  
public:
  FiguraGeometrica(int x, int y): centro(x, y) {}

  virtual void Desenha(){
    cout << centro.getX() << " " << centro.getY();
  }

  virtual float CalculaArea() = 0;

};

class Retangulo:public FiguraGeometrica{
private:
  int altura;
  int largura;

public:
  Retangulo(int alt, int larg, int x, int y)
  : altura(alt), largura(larg), FiguraGeometrica(x, y) { } 

  void Desenha() override {
    FiguraGeometrica::Desenha();
    cout << " RETANGULO" << endl;
  }

  float CalculaArea() override { return altura * largura; };

};

class Circulo:public FiguraGeometrica{
private:
  int raio;

public:
  Circulo(int raio, int x, int y)
  : raio(raio), FiguraGeometrica(x, y) { } 

  void Desenha() override {
    FiguraGeometrica::Desenha();
    cout << " CIRCULO" << endl;
  }

  float CalculaArea() { return M_PI * raio * raio; };

};

class Triangulo:public FiguraGeometrica{
private:
  int altura;
  int base;

public:
  Triangulo(int altura, int base, int x, int y)
  : altura(altura), base(base), FiguraGeometrica(x, y) 
  { } 

  void Desenha() override {
    FiguraGeometrica::Desenha();
    cout << " TRIANGULO" << endl;
  }

  float CalculaArea() { return base * altura / 2; };

};


int main(){
  vector<unique_ptr<FiguraGeometrica>> vetor;
  char acao = ' ';
  float total = 0;

  int x, y; // Posições no plano

  int alt, larg; // Retangulo

  int raio; // Ciruclo
  
  int base, altura; // Triangulo

  do{
    cin >> acao;

    switch (acao)
    {
    case 'R':
      cin >> x >> y >> alt >> larg;
      vetor.push_back(make_unique<Retangulo>(alt, larg, x, y));
      break;
      
    case 'C':
      cin >> x >> y >> raio;
      vetor.push_back(make_unique<Circulo>(raio, x, y));
      break;
      
    case 'T':
      cin >> x >> y >> base >> altura;
      vetor.push_back(make_unique<Triangulo>(altura, base, x, y));
      break;

    case 'D':
      for(auto &fig : vetor){
        fig->Desenha();
      }
      break;
    
    case 'A':
      total = 0;
      for(auto &fig : vetor){
        total += fig->CalculaArea();
      }
      cout << fixed
           << setprecision(2) 
           << total << endl;
      break;
    
    default:
      break;
    }


  }while(acao != 'E');



  return 0;
}
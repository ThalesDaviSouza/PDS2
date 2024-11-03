#ifndef ONIBUS_H
#define ONIBUS_H
#include <string>

using namespace std;

struct Onibus{
    string placa;
    int capacidadeMax;
    int lotacaoAtual;

    Onibus(string, int);
    bool SubirPassageiros(int);
    bool DescerPassageiros(int);
    bool TranferePassageiros(Onibus*, int);
    void ImprimeEstado();
};

#endif
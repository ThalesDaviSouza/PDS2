#ifndef EMPRESA_H
#define EMPRESA_H
#define kTOTAL_ONIBUS 20

#include "Onibus.hpp"

struct Empresa{
    int totalOnibus;
    Onibus* onibus[kTOTAL_ONIBUS];
    
    Empresa();
    Onibus* AdicionarOnibus(string, int);
    Onibus* BuscarOnibus(string);
    void ImprimirEstado();
};

#endif
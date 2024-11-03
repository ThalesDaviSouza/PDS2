#include "Empresa.hpp"
Empresa::Empresa(){
    this->totalOnibus = 0;
    for(int i = 0; i < kTOTAL_ONIBUS; i++){
        this->onibus[i] = nullptr;
    }
}

Onibus* Empresa::BuscarOnibus(string placa){
    for(int i = 0; i < this->totalOnibus; i++){
        if(this->onibus[i]->placa.compare(placa) == 0){
            return this->onibus[i];
        }
    }

    return nullptr;
}

Onibus* Empresa::AdicionarOnibus(string placa, int capacidadeMax){
    if(this->totalOnibus == kTOTAL_ONIBUS){
        return nullptr;
    }
    if(this->BuscarOnibus(placa) != nullptr){
        return nullptr;
    }

    this->onibus[this->totalOnibus] = new Onibus(placa, capacidadeMax);
    Onibus* retorno = this->onibus[this->totalOnibus];
    
    this->totalOnibus++;

    return retorno;
}

void Empresa::ImprimirEstado(){
    for(int i = 0; i < this->totalOnibus; i++){
        this->onibus[i]->ImprimeEstado();
    }
}

#include "Onibus.hpp"
#include <iostream>

using namespace std;

Onibus::Onibus(string placa, int capacidade) {
    this->capacidadeMax = capacidade;
    this->lotacaoAtual = 0;
    this->placa = placa;
}

bool Onibus::SubirPassageiros(int passageirosEntrando){
    int lotacaoAtualizada = this->lotacaoAtual + passageirosEntrando;
    
    if(lotacaoAtualizada > this->capacidadeMax){
        return false;
    }
    else{
        this->lotacaoAtual = lotacaoAtualizada;
    }

    return true;
}

bool Onibus::DescerPassageiros(int passageirosSaindo){
    int lotacaoAtualizada = this->lotacaoAtual - passageirosSaindo;
    
    if(lotacaoAtualizada < 0){
        return false;
    }
    else{
        this->lotacaoAtual = lotacaoAtualizada;
    }
        
    return true;
}

bool Onibus::TranferePassageiros(Onibus* destino, int quantidadeTrocados){
    if(destino == nullptr){
        return false;
    }
    
    int lotacaoDestinoAtualizada = destino->lotacaoAtual + quantidadeTrocados;
    int lotacaoAtualizada = this->lotacaoAtual - quantidadeTrocados;

    if(lotacaoDestinoAtualizada > destino->capacidadeMax){
        return false;
    }
    if(lotacaoAtualizada < 0){
        return false;
    }
    
    this->lotacaoAtual = lotacaoAtualizada;
    destino->lotacaoAtual = lotacaoDestinoAtualizada;

    return true;
}

void Onibus::ImprimeEstado(){
    cout << this->placa << " (" 
         << this->lotacaoAtual << "/" 
         << this->capacidadeMax << ")" 
         << endl; 
}

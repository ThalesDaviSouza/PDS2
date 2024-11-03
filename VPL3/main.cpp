#include "Empresa.hpp"
#include <iostream>

using namespace std;

void printOnibusInexistente(){
    cout << "ERRO : onibus inexistente" << endl;
}

int main(){
    Empresa empresa; 
    char comando;

    string placa;
    string placa2;
    int lotacaoMax;
    int numPessoas;
    bool confirmacao;
    Onibus* onibus;
    Onibus* onibus2;

    do{
        cin >> comando;

        switch (comando)
        {
        case 'C':
            cin >> placa >> lotacaoMax;
            onibus = empresa.AdicionarOnibus(placa, lotacaoMax);
            
            if(onibus != nullptr){
                cout << "novo onibus cadastrado" << endl;  
            }
            else{
                cout << "ERRO : onibus repetido" << endl;
            }

            break;

        case 'S':
            cin >> placa >> numPessoas;
            onibus = empresa.BuscarOnibus(placa);
            
            if(onibus == nullptr){
                printOnibusInexistente();
                continue;
            }

            confirmacao = onibus->SubirPassageiros(numPessoas);
            if(confirmacao){
                cout << "passageiros subiram com sucesso" << endl;
            }
            else{
                cout << "ERRO : onibus lotado" << endl;
            }

            break;

        case 'D':
            cin >> placa >> numPessoas;
            onibus = empresa.BuscarOnibus(placa);

            if(onibus == nullptr){
                printOnibusInexistente();
                continue;
            }

            confirmacao = onibus->DescerPassageiros(numPessoas);
            if(confirmacao){
                cout << "passageiros desceram com sucesso" << endl;
            }
            else{
                cout << "ERRO : faltam passageiros" << endl;
            }

            break;

        case 'T':
            cin >> placa >> placa2 >> numPessoas;
            onibus = empresa.BuscarOnibus(placa);
            if(onibus == nullptr){
                printOnibusInexistente();
                continue;
            }
            onibus2 = empresa.BuscarOnibus(placa2);
            if(onibus == nullptr){
                printOnibusInexistente();
                continue;
            }

            confirmacao = onibus->TranferePassageiros(onibus2, numPessoas);
            if(confirmacao){
                cout << "transferencia de passageiros efetuada" << endl;
            }
            else{
                cout << "ERRO : transferencia cancelada" << endl;
            }
            break;

        case 'I':
            empresa.ImprimirEstado();
            break;

        default:
            break;
        }


    }while(comando != 'F');


}
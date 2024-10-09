#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char getDicaLetra(char letra, int posLetra, string palavra){
    int pos = (int)palavra.find(letra);  

    if(pos != -1){
        return pos == posLetra ? toupper(letra) : tolower(letra);
    }
    else{
        return '*';
    }
}

int main(){
    string palavraSelecionada;
    string input;
    string dica;
    string erros;
    int indexPalavraSelecionada;
    bool acertou = false;
    int tentativas = 0;

    ifstream file("palavras.txt", fstream::in);
    if(!file.is_open()){
        cerr << "Não foi possível abrir o arquivo" << endl;
        return -1;
    }

    cin >> indexPalavraSelecionada;

    for(int i = 0; i <= indexPalavraSelecionada; i++){
        if(i == 0){
            int quantPalavras;
            file >> quantPalavras;
            // Removendo o \n
            file >> input;
            if(quantPalavras < indexPalavraSelecionada){
                cerr << "Palavra selecionada fora do indíce" << endl;
                return -1;
            }
        }
        else if(i == indexPalavraSelecionada){
            getline(file, palavraSelecionada);
            break;
        }
        else{
            // Movendo o pointer para a próxima linha
            getline(file, input);
        }
    }

    // Limpoando o buffer
    getline(cin, input);

    while(tentativas < 5 && !acertou){
        getline(cin, input);
        if(input.length() != 5){
            cerr << "input deve ter 5 letras";
            continue;
        }
        
        if(input.compare(palavraSelecionada) == 0){
            acertou = true;
        }
        
        dica.clear();

        for(int i = 0; i < 5; i++){
            dica.push_back(getDicaLetra(input[i], i, palavraSelecionada));
            if(dica[i] == '*'){
                if((int)erros.find(input[i]) == -1)
                    erros.push_back(input[i]);
            }
        }

        cout << dica << " (" << erros << ")" << endl;

        tentativas++;
    }

    if(acertou){
        cout << "GANHOU!";
    }
    else{
        cout << "PERDEU! " << palavraSelecionada;
    }

    return 0;
}
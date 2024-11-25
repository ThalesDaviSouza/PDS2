#include "aluno.hpp"
#include <algorithm>
#include <iostream>
#include <iomanip> 

using namespace std;

Aluno::Aluno(string nome, int matricula){
    this->nome = nome;
    this->matricula = matricula;
};

bool Aluno::addNota(int nota){
    this->notas.push_back(nota);

    return true;
};


float Aluno::getMediaNotas(){
    float total = 0;
    float media = 0;

    for(const& nota : this->notas){
        total += nota;
    }

    media = total / this->notas.size();

    return media;
}

int Aluno::getNotaMax(){
    return *max_element(this->notas.begin(), this->notas.end());
}

int Aluno::getNotaMin(){
    return *min_element(this->notas.begin(), this->notas.end());
}

string Aluno::getNome(){ return this->nome; }
int Aluno::getMatricula(){ return this->matricula; }
vector<int> Aluno::getNotas(){ return this->notas; }

void Aluno::printData(){
    cout << this->getMatricula() << " " << this->getNome();
    for(int& nota : this->getNotas()){
        cout << " " << nota;
    }
    cout << endl;

    cout << fixed << setprecision(2) << this->getMediaNotas() << " ";
    cout << this->getNotaMax() << " " << this->getNotaMin() << endl;
}
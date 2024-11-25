#ifndef ALUNOS_H
#define ALUNOS_H
#include <string>
#include <vector>
using namespace std;

class Aluno{
private:
    string nome;
    int matricula;
    vector<int> notas;

public:
    Aluno(string nome, int matricula);
    bool addNota(int nota);
    
    float getMediaNotas();
    int getNotaMax();
    int getNotaMin();
    string getNome();
    int getMatricula();
    vector<int> getNotas();
    void printData();

};
#endif
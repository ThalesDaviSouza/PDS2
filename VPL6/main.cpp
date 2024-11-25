#include <iostream>
#include <vector>
#include <algorithm>
#include "aluno.hpp"

using namespace std;

bool comparator(Aluno& a1, Aluno& a2){
    return a1.getNome() < a2.getNome();
}

int main(){
    vector<Aluno> alunos;
    string nome = "";
    int matricula;
    string rawGrades;
    int endGrade;

    int alunoCount = 0;

    while(nome.compare("END") != 0){
        getline(cin, nome);
        
        if(nome.compare("END") == 0){
            break;
        }

        cin >> matricula;
        // Removendo o '\n' da linha anterior
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        getline(cin, rawGrades);
        
        alunos.push_back(Aluno(nome, matricula));
        
        endGrade = rawGrades.find(" ");
        while(endGrade != -1){
            string gradeStr = rawGrades.substr(0, endGrade);
            int grade = stoi(gradeStr);
            if(grade == -1){
                break;
            }

            alunos[alunoCount].addNota(grade);

            // Remove a nota que acabou de ser lida
            rawGrades.erase(rawGrades.begin(), rawGrades.begin() + endGrade + 1);

            endGrade = rawGrades.find(" ");
        }
        alunoCount++;
    }

    sort(alunos.begin(), alunos.end(), comparator);

    for(Aluno& aluno : alunos){
        aluno.printData();
    }

    return 0;
}
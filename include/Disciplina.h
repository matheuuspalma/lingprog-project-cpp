/*Trabalho Avaliativo 01 - Desempenho das Turmas em Disciplinas 
Arquivo: Classe Disciplinas.h
Gustavo Rocha de Barros
DRE: 119050063*/

#include "Aluno.h"
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Disciplina {
public:
    map <string, float> nomeMedias;
    string nomeDisciplina;
    vector<Aluno> alunosDisciplina;
    vector<float> mediasDisciplina;
    Disciplina(string nome, vector<Aluno> alunos) : nomeDisciplina(nome), alunosDisciplina(alunos) {}
};

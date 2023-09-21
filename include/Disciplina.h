/*Trabalho Avaliativo 01 - Desempenho das Turmas em Disciplinas 
Arquivo: Classe Disciplinas.h
Gustavo Rocha de Barros
DRE: 119050063*/

#include <iostream>
#include <map>
#include <vector>
#include "Aluno.h"

/*O include map foi feito para fazer um vector onde me possibilita escolher o indice, no caso uma string e um float*/


using namespace std;

class Disciplina {
public:
    map <string, float> nomeMedias; // Exemplo: nomeMedias["portugues"] = 7.0
    string nomeDisciplina;
    vector<Aluno> alunosDisciplina;
    vector<float> mediasDisciplina;
    Disciplina(string nome, vector<Aluno> alunos) : nomeDisciplina(nome), alunosDisciplina(alunos) {}
};

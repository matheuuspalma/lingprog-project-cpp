/*Trabalho Avaliativo 01 - Desempenho das Turmas em Disciplinas 
Arquivo: Classe Alunos.h
Gustavo Rocha de Barros
DRE: 119050063*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Aluno{

public:
    string nomeAluno;
    vector<float> notas;
    Aluno(string nome, vector<float> notasAluno) : nomeAluno(nome), notas(notasAluno) {};
};

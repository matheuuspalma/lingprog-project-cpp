/*Trabalho Avaliativo 01 - Desempenho das Turmas em Disciplinas 
Arquivo: Classe Alunos.h
Gustavo Rocha de Barros
DRE: 119050063*/

#include <iostream>
#include <string>
#include <vector>
#include "Disciplina.h"
#include <map>


using namespace std;


class Turma {

    public:
    vector<Disciplina> disciplinas;
    void preencherTurma(void);
};

class Periodo {

    public:
    float CalcularMediaDisciplina(Disciplina d, int numeroDoPeriodo);
    map <string,float> disciplinaMedia;
};
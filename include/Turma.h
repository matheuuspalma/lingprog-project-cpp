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
    Turma(void);
    ~Turma(void);
    void setQuantidadeDePeriodos(int qt);
    void obterMediaGeralDisciplina(void);
    void obterMediaMovelDisciplina(void);
    void obterDesempenhoDisciplina(int);
    void obterDesempenhoAlunos(int);
    string obterDisciplinaComMaiorEvolucao(void);
    string obterMelhorALunoDoUltimoPeriodo(void);
    map <string,float> getMediasGerais(void);
    map <string, float> getMediasMovelDisciplinas(void);
    map <string, string> getDesempenhoDisciplinas(void);
    map <string, string> getDesempenhoAlunos(void);
    int periodoMaiorMediaDisciplina;
    float maiorMediaDisciplina;
    string nomeDisciplinaMaiorMedia;

    private:
    vector<Aluno> alunos;
    vector<Disciplina> disciplinas;
    map <string,string> alunoEDesempenho; //map para buscar o desempenho relacionado a cada aluno
    map <string,float> disciplinaMediaGeral; //map para buscar a media geral
    map<string,float> disciplinaEMediaMovel; //map para buscar a media movel das disciplinas
    map<string,string> disciplinaEDesempenho; //map para buscar o desempenho das disciplinas
    vector<string> nomeDisciplinas;
    float CalcularMediaDisciplinaNoPeriodo(Disciplina d, int numeroDoPeriodo);
    int quantidadeDePeriodos;
};

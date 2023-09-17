/*Trabalho Avaliativo 01 - Desempenho das Turmas em Disciplinas
Arquivo: Programa Principal
Gustavo Rocha de Barros
DRE: 119050063*/

#include <string>
#include "Turma.h"

#define MAX_ALUNOS 10
#define NUM_PERIODO 3 //Numero de periodos escolhidos

void obterMediaMoveleDesempenho(vector <Periodo> p, map<string,float> *, map<string,string> *);


//Dividi os alunos por disciplinas com suas notas, onde cada elemento do vetor defini sua nota em cada periodo escolhido, no caso o valor maximo de 8 periodos.
void Turma::preencherTurma(void) {
    Aluno armandoMat("Armano", { 0, 5, 6, 9, 5, 7, 1, 10 });
    Aluno joaoMat("Joao", { 2, 3, 7, 5, 6, 1, 6, 7 });
    Aluno claraMat("Clara", { 7, 5, 9, 10, 5, 9, 7, 7 });
    Aluno mariaMat("Maria", { 8, 6, 6, 3, 7, 7, 8, 9 });
    Disciplina mat("Matematica", { armandoMat, joaoMat, claraMat, mariaMat });

    Aluno armandoPor("Armano", { 10, 10, 4, 7, 10, 5, 7, 8 });
    Aluno joaoPor("Joao", { 9, 8, 2, 3, 4, 7, 1, 8 });
    Aluno claraPor("Clara", { 4, 7, 6, 7, 4, 9, 9, 1 });
    Aluno mariaPor("Maria", { 9, 4, 10, 3, 6, 9, 9, 6 });
    Disciplina por("Portugues", { armandoPor, joaoPor, claraPor, mariaPor });

    Aluno armandoFis("Armano", { 5, 5, 5, 5, 6, 9, 5, 8 });
    Aluno joaoFis("Joao", { 9, 3, 9, 7, 10, 10, 10, 8 });
    Aluno claraFis("Clara", { 10, 4, 9, 9, 7, 7, 4, 3 });
    Aluno mariaFis("Maria", { 2, 3, 4, 7, 5, 6, 8, 5 });
    Disciplina fis("Fisica", { armandoFis, joaoFis, claraFis, mariaFis });

    Aluno armandoBio("Armano", { 6, 6, 6, 9, 6, 8, 8, 7 });
    Aluno joaoBio("Joao", { 2, 5, 6, 5, 6, 7, 8, 9 });
    Aluno claraBio("Clara", { 8, 10, 8, 5, 6, 8, 9, 3 });
    Aluno mariaBio("Maria", { 7, 5, 6, 3, 8, 8, 8, 9 });
    Disciplina bio("Biologia", { armandoBio, joaoBio, claraBio, mariaBio });

    Aluno armandoProg("Armano", { 2, 8, 8, 9, 4, 4, 6, 9 });
    Aluno joaoProg("Joao", { 0, 0, 10, 7, 7, 7, 6, 9 });
    Aluno claraProg("Clara", { 6, 7, 8, 2, 7, 9, 7, 4 });
    Aluno mariaProg("Maria", { 10, 4, 6, 10, 6, 8, 9, 8 });
    Disciplina prog("Programacao", { armandoProg, joaoProg, claraProg, mariaProg });

    Turma::disciplinas = { mat, por, fis, bio, prog };

}


int main() {

    Turma turma;
    float mediaMovel;
    map<string,float> disciplinaEMediaMovel;
    map<string,string> disciplinaEDesempenho;

    turma.preencherTurma();

    vector<Periodo> periodo(NUM_PERIODO);   //Numero de periodos escolhidos = 3

    for (int periodoNum = 0; periodoNum < periodo.size(); periodoNum++) {

        cout << "\n\nPeriodo: " << periodoNum + 1<< endl;

        for ( int indexDisciplinas = 0; indexDisciplinas < turma.disciplinas.size();  indexDisciplinas++) {

            string nomeDisciplina = turma.disciplinas[indexDisciplinas].nomeDisciplina;

            float mediaDisciplina = periodo[periodoNum].CalcularMediaDisciplina(turma.disciplinas[indexDisciplinas], periodoNum);

            periodo[periodoNum].disciplinaMedia[nomeDisciplina] = mediaDisciplina; //map pra salvar nome de uma disciplina e media

        }

    }

    obterMediaMoveleDesempenho(periodo, &disciplinaEMediaMovel, &disciplinaEDesempenho);

    return 0;
}

void obterMediaMoveleDesempenho(vector <Periodo> p, map<string,float> *disciplinaEMediaMovel, map<string,string> *disciplinaEDesempenho) {

    vector<string> nomeDisciplinas =  {"Matematica", "Portugues", "Fisica", "Biologia", "Programacao"};
    string nomeDisciplina;

    for (int indexDisciplinas = 0; indexDisciplinas < nomeDisciplinas.size(); indexDisciplinas++) {

        float mediaMovelDisciplina = 0.0;

        float desempenhoDisciplina = 1.0; /*medir o desempenho em percentual (ponto numero 2 da tarefa)*/

        float mediaAnterior;

        nomeDisciplina = nomeDisciplinas[indexDisciplinas];

        for (int indexVector = 0; indexVector < p.size(); indexVector++) {

            mediaMovelDisciplina += p[indexVector].disciplinaMedia[nomeDisciplina];

            if(indexVector != 0)
                desempenhoDisciplina = (p[indexVector].disciplinaMedia[nomeDisciplina] / mediaAnterior)/desempenhoDisciplina;

            mediaAnterior = p[indexVector].disciplinaMedia[nomeDisciplina];
        }

        (*disciplinaEMediaMovel)[nomeDisciplina] = mediaMovelDisciplina / p.size();

        if (desempenhoDisciplina >= 1.05) {
            (*disciplinaEDesempenho)[nomeDisciplina] = "melhora no desempenho";
        } else if (desempenhoDisciplina < 0.95) {
            (*disciplinaEDesempenho)[nomeDisciplina] = "piora no desempenho";
        } else {
            (*disciplinaEDesempenho)[nomeDisciplina] = "estabilidade";
        }


        cout << "A media movel da disciplina " << nomeDisciplina << " foi: " << mediaMovelDisciplina/p.size() << "\n\n" << endl;

        cout << "A disciplina " << nomeDisciplina << " teve: " << (*disciplinaEDesempenho)[nomeDisciplina] << " \n\n" << endl;

        /* IR EM CADA PERIODO BUSCAR A MEDIA DESSA DISCIPLINA E SALVAR NUMA VARIAVEL PRA FAZER A MEDIA MOVEL NO FINAL*/
    }
}


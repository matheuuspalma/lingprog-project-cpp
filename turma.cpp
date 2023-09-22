#include "Turma.h"



//Construindo a Turma e fazendo a divisao os alunos por disciplinas com suas notas, onde cada elemento do vetor defini sua nota em cada periodo escolhido, no caso o valor maximo de 8 periodos.
Turma::Turma(void) {
    Aluno armandoMat("Armano", { 0, 5, 6, 9, 5, 7, 1, 5 });
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

    nomeDisciplinas =  {"Matematica", "Portugues", "Fisica", "Biologia", "Programacao"};


}


/*Obter a media de uma disciplina e armazenar na variavel privada da classe*/
void Turma::obterMediaGeralDisciplina(void){

    for (int periodoNum = 0; periodoNum < quantidadeDePeriodos; periodoNum++) {

        for ( int indexDisciplinas = 0; indexDisciplinas < disciplinas.size();  indexDisciplinas++) {

            string nomeDisciplina = disciplinas[indexDisciplinas].nomeDisciplina;

            float mediaDisciplina = CalcularMediaDisciplinaNoPeriodo(disciplinas[indexDisciplinas], periodoNum);

            if(mediaDisciplina > maiorMediaDisciplina)
            {
                maiorMediaDisciplina = mediaDisciplina;
                periodoMaiorMediaDisciplina = periodoNum + 1;
                nomeDisciplinaMaiorMedia = nomeDisciplina;
            }
            disciplinaMediaGeral[nomeDisciplina] = mediaDisciplina; //map pra salvar nome de uma disciplina e media
        }
    }
}

/*Calcular a nota dos alunos e definiar a média da disciplina D em certo Periodo N*/
float Turma::CalcularMediaDisciplinaNoPeriodo(Disciplina d, int periodo){

    float mediaDisciplina = 0.0;

    for (int alunoNum = 0; alunoNum < d.alunosDisciplina.size(); alunoNum++) {

        /*1 - Para média dos alunos por período, pegar cada nota em cada matéria feita no período, somar e dps dividir pelo número de matérias*/

        mediaDisciplina += d.alunosDisciplina[alunoNum].notas[periodo];

    }
    mediaDisciplina /=  d.alunosDisciplina.size();

    return mediaDisciplina;
}

void Turma::setQuantidadeDePeriodos(int qt){
    Turma::quantidadeDePeriodos = qt;
}

map <string, float> Turma::getMediasGerais(void){
    return Turma::disciplinaMediaGeral;
}

map <string, float> Turma::getMediasMovelDisciplinas(void){
    return disciplinaEMediaMovel;
}

map <string, string> Turma::getDesempenhoDisciplinas(void){
    return disciplinaEDesempenho;
}




Turma::~Turma(void){

}


/*Funcao para avaliar a media movel dos ultimos 3 periodos*/

void Turma::obterMediaMovelDisciplina(void) {

    string nomeDisciplina;

    for (int indexDisciplinas = 0; indexDisciplinas < nomeDisciplinas.size(); indexDisciplinas++) {

        float mediaMovelDisciplina = 0.0;

        nomeDisciplina = nomeDisciplinas[indexDisciplinas];

        for (int indexVector = quantidadeDePeriodos - 1; indexVector > quantidadeDePeriodos - 3; indexVector--) {

            mediaMovelDisciplina += disciplinaMediaGeral[nomeDisciplina];

        }

        disciplinaEMediaMovel[nomeDisciplina] = mediaMovelDisciplina / 3;

    /* IR EM CADA PERIODO BUSCAR A MEDIA DESSA DISCIPLINA E SALVAR NUMA VARIAVEL PRA FAZER A MEDIA MOVEL NO FINAL*/
    }
}

/* O desempenho do periodo escolhido em relação ao periodo anterior.
   Razão da media movel atual e media movel anterior
   Razão >= 1.05 melhora
   Razão entre 0.95 e 1.05 estabilidade
   Razão <= 0.95 piora
*/
void Turma::obterDesempenhoDisciplina(int periodo) {

    string nomeDisciplina;

    periodo--;
    for ( int indexDisciplinas = 0; indexDisciplinas < disciplinas.size();  indexDisciplinas++) {
        string nomeDisciplina = disciplinas[indexDisciplinas].nomeDisciplina;
        float desempenho = 1.0;
        for (int indexPeriodo = periodo; indexPeriodo >= periodo - 1; indexPeriodo--) {

            float mediaDisciplina = CalcularMediaDisciplinaNoPeriodo(disciplinas[indexDisciplinas], indexPeriodo);

            if(indexPeriodo != periodo)
                desempenho = desempenho/mediaDisciplina;
            else
                desempenho = mediaDisciplina;
        }
        if (desempenho >= 1.05) {
            disciplinaEDesempenho[nomeDisciplina] = "houve uma melhora no desempenho";
        } else if (desempenho <= 0.95) {
            disciplinaEDesempenho[nomeDisciplina] = "houve uma piora no desempenho";
        } else {
            disciplinaEDesempenho[nomeDisciplina] = "há uma estabilidade";
        }

    /* IR EM CADA PERIODO BUSCAR A MEDIA DESSA DISCIPLINA E SALVAR NUMA VARIAVEL PRA FAZER A MEDIA MOVEL NO FINAL*/
    }
}


/* O desempenho do periodo escolhido em relação ao periodo anterior.
   Razão da media movel atual e media movel anterior
   Razão >= 1.05 melhora
   Razão entre 0.95 e 1.05 estabilidade
   Razão <= 0.95 piora
*/
void Turma::obterDesempenhoAlunos(int periodo) {

    string nomeDisciplina;
    map <string, float> nomesENotasPeriodoAtual;
    map <string, float> nomesENotasPeriodoAnterior;

    periodo--;
   for ( int indexDisciplinas = 0; indexDisciplinas < disciplinas.size();  indexDisciplinas++) {
        string nomeDisciplina = disciplinas[indexDisciplinas].nomeDisciplina;
        vector<Aluno> alunosDisciplina = disciplinas[indexDisciplinas].alunosDisciplina;
        for (int indexPeriodo = periodo; indexPeriodo >= periodo - 1; indexPeriodo--) {

            for(int indexAlunos = 0; indexAlunos < alunosDisciplina.size(); indexAlunos++){
                string nomeDoAluno = alunosDisciplina[indexAlunos].nomeAluno;
                if(indexPeriodo != periodo){
                    nomesENotasPeriodoAnterior[nomeDoAluno] = alunosDisciplina[indexAlunos].notas[indexPeriodo];
                    float desempenho = (nomesENotasPeriodoAtual[nomeDoAluno]) / (nomesENotasPeriodoAnterior[nomeDoAluno]);
                    if (desempenho >= 1.05) {
                        alunoEDesempenho[nomeDoAluno] = "houve uma melhora no desempenho";
                    } else if (desempenho <= 0.95) {
                        alunoEDesempenho[nomeDoAluno] = "houve uma piora no desempenho";
                    } else {
                        alunoEDesempenho[nomeDoAluno] = "há uma estabilidade";
                    }
                }
                else{
                    nomesENotasPeriodoAtual[nomeDoAluno] = alunosDisciplina[indexAlunos].notas[indexPeriodo];
                }
            }
        }

    }
}

map<string,string> Turma::getDesempenhoAlunos(void){
    return alunoEDesempenho;
}

string Turma::obterDisciplinaComMaiorEvolucao(void){
    float evolucao = 0.0;
    string disciplinaComMaiorEvolucao ;

    for ( int indexDisciplinas = 0; indexDisciplinas < disciplinas.size();  indexDisciplinas++) {
        string nomeDisciplina = disciplinas[indexDisciplinas].nomeDisciplina;
        float media = CalcularMediaDisciplinaNoPeriodo(disciplinas[indexDisciplinas], quantidadeDePeriodos - 1);
        if (media > evolucao){
            disciplinaComMaiorEvolucao = nomeDisciplina;
            evolucao = media;
        }
    }
    return disciplinaComMaiorEvolucao;
}

string Turma::obterMelhorALunoDoUltimoPeriodo(void){
    float maiorNota = 0.0;
    float media;
    string aluno;

    for ( int indexDisciplinas = 0; indexDisciplinas < disciplinas.size();  indexDisciplinas++) {
        vector<Aluno> alunosDisciplina = disciplinas[indexDisciplinas].alunosDisciplina;
        for(int indexAlunos = 0; indexAlunos < alunosDisciplina.size(); indexAlunos++){
            media = alunosDisciplina[indexAlunos].notas[quantidadeDePeriodos - 1];
            if(media > maiorNota){
                maiorNota = media;
                aluno = alunosDisciplina[indexAlunos].nomeAluno;
            }
        }
    }
    return aluno;
}



/*Trabalho Avaliativo 01 - Desempenho das Turmas em Disciplinas
Arquivo: Programa Principal
Gustavo Rocha de Barros
DRE: 119050063*/

#include <string>
#include "Turma.h"

void Turma::preencherTurma(void) {
    Aluno armandoMat("Armano", { 0, 5, 6, 9 });
    Aluno joaoMat("Joao", { 2, 3, 7, 5 });
    Aluno claraMat("Clara", { 7, 5, 9, 10 });
    Aluno mariaMat("Maria", { 8, 6, 6, 3 });
    Disciplina mat("Matematica", { armandoMat, joaoMat, claraMat, mariaMat });

    Aluno armandoPor("Armano", { 10, 10, 4, 7 });
    Aluno joaoPor("Joao", { 9, 8, 2, 3 });
    Aluno claraPor("Clara", { 4, 7, 6, 7 });
    Aluno mariaPor("Maria", { 9, 4, 10, 3 });
    Disciplina por("Portugues", { armandoPor, joaoPor, claraPor, mariaPor });

    Aluno armandoFis("Armano", { 5, 5, 5, 5 });
    Aluno joaoFis("Joao", { 9, 3, 9, 7 });
    Aluno claraFis("Clara", { 10, 4, 9, 9 });
    Aluno mariaFis("Maria", { 2, 3, 4, 7 });
    Disciplina fis("Fisica", { armandoFis, joaoFis, claraFis, mariaFis });

    Aluno armandoBio("Armano", { 6, 6, 6, 9 });
    Aluno joaoBio("Joao", { 2, 5, 6, 5 });
    Aluno claraBio("Clara", { 8, 10, 8, 5 });
    Aluno mariaBio("Maria", { 7, 5, 6, 3 });
    Disciplina bio("Biologia", { armandoBio, joaoBio, claraBio, mariaBio });

    Aluno armandoProg("Armano", { 2, 8, 8, 9 });
    Aluno joaoProg("Joao", { 0, 0, 10, 7 });
    Aluno claraProg("Clara", { 6, 7, 8, 2 });
    Aluno mariaProg("Maria", { 10, 4, 6, 10 });
    Disciplina prog("Programação", { armandoProg, joaoProg, claraProg, mariaProg });

    Turma::disciplinas = { mat, por, fis, bio, prog };

}


int main() {

    Turma turma;
    turma.preencherTurma();

    int totalPeriodo = 3;

    vector<vector<float>> mediasAlunos;

    for (int periodoNum = 0; periodoNum < totalPeriodo; periodoNum++) {
        cout << "\n\nPeriodo: " << periodoNum << endl;

        for ( int indexDisciplinas = 0; indexDisciplinas < turma.disciplinas.size();  indexDisciplinas++) {

            for (int alunoNum = 0; alunoNum < turma.disciplinas[indexDisciplinas].alunosDisciplina.size(); alunoNum++) {
                /*1 - Para média dos alunos por período, pegar cada nota em cada matéria feita no período, somar e dps dividir pelo número de matérias*/
                string nomeDoAluno = turma.disciplinas[indexDisciplinas].alunosDisciplina[alunoNum].nomeAluno;

                float mediaDoAlunoNaDisciplina = 0;

                    for (int disciNum = 0; disciNum < turma.disciplinas.size(); disciNum++) {
                        mediaDoAlunoNaDisciplina += turma.disciplinas[disciNum].alunosDisciplina[alunoNum].notas[periodoNum];
                    }

                    mediaDoAlunoNaDisciplina /= turma.disciplinas[indexDisciplinas].alunosDisciplina.size();

                    cout << "A media do Aluno " << nomeDoAluno << " foi: " << mediaDoAlunoNaDisciplina << "\n";



                    /*4 - Fazer a mesma ideia do item 3 porém com as médias dos alunos por período*/

        /*              if (disciNum > 0) {
                        //caso x >= 1.05, exibir que houve uma melhora de tantos % em relação a média anterior exibir de maneira ordenada (maior evolução para pior), caso x <= 0.95, exibir que houve uma piora de tantos % em relação
                        //a média anterior exibir de maneira ordenada (desemepenho mais próximo de 0.95 ao mais distante), caso nenhum dos dois ocorra, exibir que as disciplinas estáveis
                        if (mediaDisciplina > mediasDisciplina[disciNum - 1] * 1,05) {
                            cout << "Houve melhora na Disciplina " << nomeDisciplina << " de: " << (mediasDisciplina[disciNum - 1] / mediaDisciplina) << "\n";
                        }
                        if (mediaDisciplina < mediasDisciplina[disciNum - 1] / 1,05) {
                            cout << "Houve piora na Disciplina " << nomeDisciplina << " de: " << (mediasDisciplina[disciNum - 1] / mediaDisciplina) << "\n";
                        }
                    } */

            }
        }
            cout << "Média das Disciplinas:";
        Disciplina maiorDisciplina("teste", {});

        for (int disciNum = 0; disciNum < turma.disciplinas.size(); disciNum++) {
            /*2 - Para média das disciplinas de cada período, pegar as notas de cada aluno por período somar e dividir pelo número de alunos, armazenar essas informações para dps*/
            string nomeDisciplina = turma.disciplinas[disciNum].nomeDisciplina;
            float mediaDisciplina = 0;

            vector<Aluno> alunosNaDisciplina = turma.disciplinas[disciNum].alunosDisciplina;
            for (int alunoNum = 0; alunoNum < alunosNaDisciplina.size(); alunoNum++) {
                mediaDisciplina += alunosNaDisciplina[alunoNum].notas[periodoNum];
            }
            mediaDisciplina /= alunosNaDisciplina.size();

            cout << "A media da Disciplina " << nomeDisciplina << " foi: " << mediaDisciplina << "\n";

            /*3 - Fazer um comparativo entre as médias das disciplinas do período atual com o período anterior, ou seja sendo X evolução, calcular x = média atual/ média do período anterior, com o valor de X comparar*/
            if (periodoNum > 0) {
                 /*caso x >= 1.05, exibir que houve uma melhora de tantos % em relação a média anterior exibir de maneira ordenada (maior evolução para pior), caso x <= 0.95, exibir que houve uma piora de tantos % em relação
                 a média anterior exibir de maneira ordenada (desemepenho mais próximo de 0.95 ao mais distante), caso nenhum dos dois ocorra, exibir que as disciplinas estáveis*/

                float notaAnterior = turma.disciplinas[disciNum].mediasDisciplina[periodoNum - 1];
                if (mediaDisciplina > notaAnterior * 1,05) {
                    cout << "Houve melhora na Disciplina " << nomeDisciplina << " de: " << (notaAnterior / mediaDisciplina) << "\n";
                }
                if (mediaDisciplina < notaAnterior / 1,05) {
                    cout << "Houve piora na Disciplina " << nomeDisciplina << " de: " << (notaAnterior - mediaDisciplina / notaAnterior) << "\n";
                }
            }
            
            if (maiorDisciplina.mediasDisciplina[periodoNum] >= mediaDisciplina) {
                maiorDisciplina = turma.disciplinas[disciNum];
            }
        }
        
        /*5 - Exibir a disciplina com a maior média de todas no período escolhido*/

        cout << "Disciplina com maior media " << maiorDisciplina.mediasDisciplina[periodoNum] << " sendo: " << maiorDisciplina.mediasDisciplina[periodoNum] << "\n";

        /*6 - Mostrar qual disciplina teve maior média em todos os períodos, ou seja melhorDisiciplina = todasAsNotas / númeroDePeríodos*/

        if (totalPeriodo == periodoNum + 1) {
        /*7 - Exibir o aluno que possuiu a maior média de notas no último período*/

        }
    } 

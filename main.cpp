/*Trabalho Avaliativo 01 - Desempenho das Turmas em Disciplinas
Arquivo: Programa Principal
Gustavo Rocha de Barros
DRE: 119050063*/

#include <string>
#include "Turma.h"
#include <unistd.h>

#define MAX_ALUNOS 10
#define NUM_PERIODO 8 //Numero de periodos escolhidos


void printMapStringFloat(map <string, float> p){

    for (const auto &content : p){
        cout << "A média da matéria " <<content.first << " é " << content.second << "\n" << endl;
    }
}

void printMediaMovelDisciplina(map <string, float> p){
    for (const auto &content : p){
        cout << "A media movel da disciplina " << content.first << " foi: " << content.second << endl;
    }
}

void printDesempenhoDisciplina(map <string, string> p){

    for (const auto &content : p){
        cout << "Na disciplina "  << content.first << " teve seu desempenho "  << content.second << "\n" << endl;
    }
}

void printDesempenhoAluno(map <string, string> p){

    for (const auto &content : p){
        cout << "O aluno "  << content.first << " teve seu desempenho "  << content.second << "\n" << endl;
    }
}





int main() {

    Turma turma;
    int escolhaMenu;
    int escolhaPeriodo;

    turma.setQuantidadeDePeriodos(NUM_PERIODO);
    turma.obterMediaGeralDisciplina();
    while (escolhaMenu =! 0) {
        cout << "1 - Media das Notas Finais de todas as Disciplinas de Todos os Periodos." << endl << "2 - Media Movel dos Ultimos 3 Periodos." << endl << "3 - Desempenho das Disciplinas." << endl;
        cout << "4 - Desempenho dos Alunos." << endl << "5 - Disciplina com Maior media.\n" << "6 - Disciplina com Maior Evolucao no Ultimo Periodo." << endl << "7 - Melhor Aluno." << endl;
        cout << "0 - Sair do Programa.\nEntre com uma Opção : ";
        cin >> escolhaMenu;
        cout << "\n";


        if(escolhaMenu == 0){
            cout << "Saindo do Programa !!!\n\n" << endl;
            break;

        }
        else if (escolhaMenu == 1) {

            printMapStringFloat(turma.getMediasGerais());

        }

        else if (escolhaMenu == 2) {
            turma.obterMediaMovelDisciplina();
            printMediaMovelDisciplina(turma.getMediasMovelDisciplinas());
        }

        else if (escolhaMenu == 3){

            while (1){
                cout << "Entre com o Periodo entre 1 e 8 ou 0 para Voltar ao Menu Principal: ";
                cin >> escolhaPeriodo;
                cout << "\n";

                if(escolhaPeriodo == 0){
                    cout << "Retornando ao Menu Principal." << endl;
                    break;
                }

                if (escolhaPeriodo == 1){
                    cout << "Error: Nao e possivel calcular desempenho da disciplina no primeiro periodo" << endl;
                }

                else if (escolhaPeriodo >= 2 && escolhaPeriodo <= 8 ){
                    turma.obterDesempenhoDisciplina(escolhaPeriodo);
                    printDesempenhoDisciplina(turma.getDesempenhoDisciplinas());
                }

                else {
                    cout << "Error: Entre com uma opcao valida." << endl;
                }

            sleep (4);
            }



        }

        else if (escolhaMenu == 4){
            
            while (1){
                cout << "Entre com o Periodo entre 1 e 8 ou 0 para Voltar ao Menu Principal: ";
                cin >> escolhaPeriodo;
                cout << "\n";

                if(escolhaPeriodo == 0){
                    cout << "Retornando ao Menu Principal." << endl;
                    break;
                }

                if (escolhaPeriodo == 1){
                    cout << "Error: Nao e possivel calcular desempenho do aluno no primeiro periodo" << endl;
                }

                else if (escolhaPeriodo >= 2 && escolhaPeriodo <= 8 ){
                    turma.obterDesempenhoAlunos(escolhaPeriodo);
                    printDesempenhoAluno(turma.getDesempenhoAlunos());
                }

                else {
                    cout << "Error: Entre com uma opcao valida." << endl;
                }

            cout << "Retornando ao Menu Principal." << endl;
            sleep (4);
            }
        }

        else if (escolhaMenu == 5){
            cout << "Maior media foi " << turma.maiorMediaDisciplina << " da disciplina " << turma.nomeDisciplinaMaiorMedia << " do periodo " << turma.periodoMaiorMediaDisciplina << endl;

        }
        
        else if (escolhaMenu == 6){
            cout << "A Disciplina que teve maior evolucao no desempenho foi: " << turma.obterDisciplinaComMaiorEvolucao() << endl;
        }
        
        else if (escolhaMenu == 7){
            cout << "O melhor aluno foi " << turma.obterMelhorALunoDoUltimoPeriodo() << endl;
        }

        else {
            cout << "Error: Entre com uma opcao valida." << endl;
        }
    }
    return 0;
}



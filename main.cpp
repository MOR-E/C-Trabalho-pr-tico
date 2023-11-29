#include <iostream>
#include "Professor.h"
#include "Aluno.h"
#include "SalaDeDefesa.h"
#include "AgendamentoDefesa.h"

int main() {
    Professor professor;
    Aluno aluno;
    SalaDeDefesa salaDeDefesa;
    AgendamentoDefesa agendamentoDefesa;

    int opcao;
    do {
        std::cout << "Escolha uma opcao:\n"
                  << "1. Gerenciar Professores\n"
                  << "2. Gerenciar Alunos\n"
                  << "3. Gerenciar Salas de Defesa\n"
                  << "4. Gerenciar Agendamentos de Defesa\n"
                  << "0. Sair\n";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                int opProfessores;
                do {
                    std::cout << "\nGerenciamento de Professores:\n"
                              << "1. Cadastrar Professor\n"
                              << "2. Listar Professores\n"
                              << "3. Atualizar Professor\n"
                              << "4. Deletar Professor\n"
                              << "0. Voltar\n";
                    std::cin >> opProfessores;

                    switch (opProfessores) {
                        case 1:
                            professor.cadastrarProfessores();
                            break;
                        case 2:
                            professor.listarProfessores();
                            break;
                        case 3:
                            professor.atualizarProfessores();
                            break;
                        case 4:
                            professor.deletarProfessores();
                            break;
                        case 0:
                            break;
                        default:
                            std::cout << "opcao inválida!\n";
                            break;
                    }
                } while (opProfessores != 0);
                break;

            case 2:
                // Opções para gerenciar Alunos
                int opAlunos;
                do {
                    std::cout << "\nGerenciamento de Alunos:\n"
                              << "1. Cadastrar Alunos\n"
                              << "2. Listar Alunos\n"
                              << "3. Atualizar Alunos\n"
                              << "4. Deletar Alunos\n"
                              << "0. Voltar\n";
                    std::cin >> opAlunos;

                    switch (opAlunos) {
                        case 1:
                            aluno.cadastrarAlunos();
                            break;
                        case 2:
                            aluno.listarAlunos();
                            break;
                        case 3:
                            aluno.atualizarAlunos();
                            break;
                        case 4:
                            aluno.deletarAlunos();
                            break;
                        case 0:
                            break;
                        default:
                            std::cout << "opcao invalida!\n";
                            break;
                    }
                } while (opAlunos != 0);
                break;

            case 3:
                // Opções para gerenciar Salas de Defesa
                int opSalaDeDefesas;
                do {
                    std::cout << "\nGerenciamento de Sala de defesa:\n"
                              << "1. Cadastrar Sala de defesa\n"
                              << "2. Listar Sala de defesa\n"
                              << "3. Atualizar Sala de defesa\n"
                              << "4. Deletar Sala de defesa\n"
                              << "0. Voltar\n";
                    std::cin >> opSalaDeDefesas;

                    switch (opSalaDeDefesas) {
                        case 1:
                            salaDeDefesa.cadastrarSalasDeDefesa();
                            break;
                        case 2:
                            salaDeDefesa.listarSalasDeDefesa();
                            break;
                        case 3:
                            salaDeDefesa.atualizarSalaDeDefesa();
                            break;
                        case 4:
                            salaDeDefesa.deletarSalaDeDefesa();
                            break;
                        case 0:
                            break;
                        default:
                            std::cout << "opcao invalida!\n";
                            break;
                    }
                } while (opSalaDeDefesas != 0);
                break;

            case 4:
                // Opções para gerenciar Agendamentos de Defesa
                int opAgendamentoDefesas;
                do {
                    std::cout << "\nGerenciamento de Agendamento de defesa:\n"
                              << "1. Cadastrar Agendamento de defesa\n"
                              << "2. Listar Agendamento de defesa\n"
                              << "3. Atualizar Agendamento de defesa\n"
                              << "4. Deletar Agendamento de defesa\n"
                              << "0. Voltar\n";
                    std::cin >> opAgendamentoDefesas;

                    switch (opAgendamentoDefesas) {
                        case 1:
                            agendamentoDefesa.cadastrarAgendamentoDefesa();
                            break;
                        case 2:
                            agendamentoDefesa.listarAgendamentosDefesa();
                            break;
                        case 3:
                            agendamentoDefesa.atualizarAgendamentoDefesa();
                            break;
                        case 4:
                            agendamentoDefesa.deletarAgendamentoDefesa();
                            break;
                        case 0:
                            break;
                        default:
                            std::cout << "opcao invalida!\n";
                            break;
                    }
                } while (opAgendamentoDefesas != 0);
                break;

            case 0:
                std::cout << "Saindo...\n";
                break;

            default:
                std::cout << "opcao invalida!\n";
                break;
        }
    } while (opcao != 0);

    return 0;
}
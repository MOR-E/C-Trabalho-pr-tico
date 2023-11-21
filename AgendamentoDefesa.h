// AgendamentoDefesa.h

#ifndef AGENDAMENTODEFESA_H
#define AGENDAMENTODEFESA_H

#include <string>
#include <iostream>

class AgendamentoDefesa {
private:
    struct InfoAgendamentoDefesa {
        std::string codigoAgendamento;
        std::string codigoSala;
        std::string matriculaAluno;
        std::string CPFOrientador;
        std::string CPFMembroBanca1;
        std::string CPFMembroBanca2;
        std::string CPFMembroBanca3;
        std::string CPFMembroBanca4;
    };

    static const int MAX_AGENDAMENTOS = 100; // Número máximo de agendamentos de defesa
    InfoAgendamentoDefesa agendamentos[MAX_AGENDAMENTOS]; // Array de agendamentos de defesa
    int totalAgendamentos = 0; // Contador de agendamentos cadastrados

public:
    // Método para cadastrar agendamentos de defesa
    void cadastrarAgendamentoDefesa() {
        int quantidade;
        std::cout << "Quantos agendamentos de defesa deseja cadastrar? ";
        std::cin >> quantidade;

        for (int i = 0; i < quantidade; ++i) {
            if (totalAgendamentos >= MAX_AGENDAMENTOS) {
                std::cout << "Limite máximo de agendamentos de defesa atingido!" << std::endl;
                break;
            }

            InfoAgendamentoDefesa novoAgendamento;
            std::cout << "Código do agendamento " << i + 1 << ": ";
            std::cin >> novoAgendamento.codigoAgendamento;
            std::cout << "Código da sala " << i + 1 << ": ";
            std::cin >> novoAgendamento.codigoSala;
            std::cout << "Matrícula do aluno " << i + 1 << ": ";
            std::cin >> novoAgendamento.matriculaAluno;
            std::cout << "CPF do orientador " << i + 1 << ": ";
            std::cin >> novoAgendamento.CPFOrientador;
            std::cout << "CPF do membro da banca 1 " << i + 1 << ": ";
            std::cin >> novoAgendamento.CPFMembroBanca1;
            std::cout << "CPF do membro da banca 2 " << i + 1 << ": ";
            std::cin >> novoAgendamento.CPFMembroBanca2;
            std::cout << "CPF do membro da banca 3 " << i + 1 << ": ";
            std::cin >> novoAgendamento.CPFMembroBanca3;
            std::cout << "CPF do membro da banca 4 " << i + 1 << ": ";
            std::cin >> novoAgendamento.CPFMembroBanca4;

            agendamentos[totalAgendamentos++] = novoAgendamento;
        }
    }

    // Método para listar todos os agendamentos de defesa
    void listarAgendamentosDefesa() {
        std::cout << "Lista de agendamentos de defesa cadastrados:" << std::endl;
        for (int i = 0; i < totalAgendamentos; ++i) {
            std::cout << "Código do agendamento: " << agendamentos[i].codigoAgendamento << std::endl;
            std::cout << "Código da sala: " << agendamentos[i].codigoSala << std::endl;
            std::cout << "Matrícula do aluno: " << agendamentos[i].matriculaAluno << std::endl;
            std::cout << "CPF do orientador: " << agendamentos[i].CPFOrientador << std::endl;
            std::cout << "CPF do membro da banca 1: " << agendamentos[i].CPFMembroBanca1 << std::endl;
            std::cout << "CPF do membro da banca 2: " << agendamentos[i].CPFMembroBanca2 << std::endl;
            std::cout << "CPF do membro da banca 3: " << agendamentos[i].CPFMembroBanca3 << std::endl;
            std::cout << "CPF do membro da banca 4: " << agendamentos[i].CPFMembroBanca4 << std::endl;
            std::cout << std::endl;
        }
    }

    // Método para atualizar informações de agendamentos de defesa
    void atualizarAgendamentoDefesa() {
        listarAgendamentosDefesa(); // Mostra a lista antes da atualização

        int indice;
        std::cout << "\nQual agendamento de defesa deseja atualizar (digite o número correspondente)? ";
        std::cin >> indice;
        --indice; // Ajusta para o índice no array (começando de zero)

        if (indice >= 0 && indice < totalAgendamentos) {
            InfoAgendamentoDefesa novoAgendamento;
            std::cout << "Novo código do agendamento: ";
            std::cin >> novoAgendamento.codigoAgendamento;
            std::cout << "Novo código da sala: ";
            std::cin >> novoAgendamento.codigoSala;
            std::cout << "Nova matrícula do aluno: ";
            std::cin >> novoAgendamento.matriculaAluno;
            std::cout << "Novo CPF do orientador: ";
            std::cin >> novoAgendamento.CPFOrientador;
            std::cout << "Novo CPF do membro da banca 1: ";
            std::cin >> novoAgendamento.CPFMembroBanca1;
            std::cout << "Novo CPF do membro da banca 2: ";
            std::cin >> novoAgendamento.CPFMembroBanca2;
            std::cout << "Novo CPF do membro da banca 3: ";
            std::cin >> novoAgendamento.CPFMembroBanca3;
            std::cout << "Novo CPF do membro da banca 4: ";
            std::cin >> novoAgendamento.CPFMembroBanca4;

            agendamentos[indice] = novoAgendamento;
            std::cout << "Agendamento de defesa atualizado com sucesso!" << std::endl;
        } else {
            std::cout << "Índice inválido!" << std::endl;
        }
    }

    // Método para deletar agendamentos de defesa
    void deletarAgendamentoDefesa() {
        listarAgendamentosDefesa(); // Mostra a lista antes da deleção

        int quantidade;
        std::cout << "\nQuantos agendamentos de defesa deseja deletar? ";
        std::cin >> quantidade;

        for (int i = 0; i < quantidade; ++i) {
            int indice;
            std::cout << "Digite o número correspondente ao agendamento de defesa a ser deletado: ";
            std::cin >> indice;
            --indice; // Ajusta para o índice no array (começando de zero)

            if (indice >= 0 && indice < totalAgendamentos) {
                for (int j = indice; j < totalAgendamentos - 1; ++j) {
                    agendamentos[j] = agendamentos[j + 1];
                }
                --totalAgendamentos;
                std::cout << "Agendamento de defesa deletado com sucesso!" << std::endl;
            } else {
                std::cout << "Índice inválido!" << std::endl;
            }
        }
    }
};

#endif

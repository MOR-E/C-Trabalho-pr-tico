// Professor.h

#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
#include <iostream>

class Professor {
private:
    struct InfoProfessor {
        std::string CPF;
        std::string nome;
        std::string instituicao;
        bool externo;
    };

    static const int MAX_PROFESSORES = 100; // Número máximo de professores
    InfoProfessor professores[MAX_PROFESSORES]; // Array de professores
    int totalProfessores = 0; // Contador de professores cadastrados

public:
    // Método para cadastrar professores
    void cadastrarProfessores() {
        int quantidade;
        std::cout << "Quantos professores deseja cadastrar? ";
        std::cin >> quantidade;

        for (int i = 0; i < quantidade; ++i) {
            if (totalProfessores >= MAX_PROFESSORES) {
                std::cout << "Limite máximo de professores atingido!" << std::endl;
                break;
            }

            InfoProfessor novoProfessor;
            std::cout << "CPF do professor " << i + 1 << ": ";
            std::cin >> novoProfessor.CPF;
            std::cout << "Nome do professor " << i + 1 << ": ";
            std::cin.ignore(); // Limpa o buffer do teclado
            std::getline(std::cin, novoProfessor.nome);
            std::cout << "Instituicao do professor " << i + 1 << ": ";
            std::getline(std::cin, novoProfessor.instituicao);
            std::cout << "É externo (1 - Sim / 0 - Não) do professor " << i + 1 << ": ";
            std::cin >> novoProfessor.externo;

            professores[totalProfessores++] = novoProfessor;
        }
    }

    // Método para listar todos os professores
    void listarProfessores() {
        std::cout << "Lista de professores cadastrados:" << std::endl;
        for (int i = 0; i < totalProfessores; ++i) {
            std::cout << "CPF: " << professores[i].CPF << " | Nome: " << professores[i].nome
                      << " | Instituicao: " << professores[i].instituicao << " | Externo: "
                      << (professores[i].externo ? "Sim" : "Não") << std::endl;
        }
    }

    // Método para atualizar informações de professores
    void atualizarProfessores() {
        listarProfessores(); // Mostra a lista antes da atualização

        int opcao, indice;
        std::cout << "\nQual professor deseja atualizar (digite o número correspondente)? ";
        std::cin >> indice;
        --indice; // Ajusta para o índice no array (começando de zero)

        if (indice >= 0 && indice < totalProfessores) {
            InfoProfessor novoProfessor;
            std::cout << "Novo CPF: ";
            std::cin >> novoProfessor.CPF;
            std::cout << "Novo nome: ";
            std::cin.ignore(); // Limpa o buffer do teclado
            std::getline(std::cin, novoProfessor.nome);
            std::cout << "Nova instituicao: ";
            std::getline(std::cin, novoProfessor.instituicao);
            std::cout << "É externo (1 - Sim / 0 - Não)? ";
            std::cin >> novoProfessor.externo;

            professores[indice] = novoProfessor;
            std::cout << "Professor atualizado com sucesso!" << std::endl;
        } else {
            std::cout << "Índice inválido!" << std::endl;
        }
    }

    // Método para deletar professores
    void deletarProfessores() {
        listarProfessores(); // Mostra a lista antes da deleção

        int quantidade;
        std::cout << "\nQuantos professores deseja deletar? ";
        std::cin >> quantidade;

        for (int i = 0; i < quantidade; ++i) {
            int indice;
            std::cout << "Digite o número correspondente ao professor a ser deletado: ";
            std::cin >> indice;
            --indice; // Ajusta para o índice no array (começando de zero)

            if (indice >= 0 && indice < totalProfessores) {
                for (int j = indice; j < totalProfessores - 1; ++j) {
                    professores[j] = professores[j + 1];
                }
                --totalProfessores;
                std::cout << "Professor deletado com sucesso!" << std::endl;
            } else {
                std::cout << "Índice inválido!" << std::endl;
            }
        }
    }
};

#endif

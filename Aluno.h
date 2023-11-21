// Aluno.h

#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <iostream>

class Aluno {
private:
    struct InfoAluno {
        std::string matricula;
        std::string nome;
    };

    static const int MAX_ALUNOS = 100; // Número máximo de alunos
    InfoAluno alunos[MAX_ALUNOS]; // Array de alunos
    int totalAlunos = 0; // Contador de alunos cadastrados

public:
    // Método para cadastrar alunos
    void cadastrarAlunos() {
        int quantidade;
        std::cout << "Quantos alunos deseja cadastrar? ";
        std::cin >> quantidade;

        for (int i = 0; i < quantidade; ++i) {
            if (totalAlunos >= MAX_ALUNOS) {
                std::cout << "Limite máximo de alunos atingido!" << std::endl;
                break;
            }

            InfoAluno novoAluno;
            std::cout << "Matrícula do aluno " << i + 1 << ": ";
            std::cin >> novoAluno.matricula;
            std::cout << "Nome do aluno " << i + 1 << ": ";
            std::cin.ignore(); // Limpa o buffer do teclado
            std::getline(std::cin, novoAluno.nome);

            alunos[totalAlunos++] = novoAluno;
        }
    }

    // Método para listar todos os alunos
    void listarAlunos() {
        std::cout << "Lista de alunos cadastrados:" << std::endl;
        for (int i = 0; i < totalAlunos; ++i) {
            std::cout << "Matrícula: " << alunos[i].matricula << " | Nome: " << alunos[i].nome << std::endl;
        }
    }

    // Método para atualizar informações de alunos
    void atualizarAlunos() {
        listarAlunos(); // Mostra a lista antes da atualização

        int opcao, indice;
        std::cout << "\nQual aluno deseja atualizar (digite o número correspondente)? ";
        std::cin >> indice;
        --indice; // Ajusta para o índice no array (começando de zero)

        if (indice >= 0 && indice < totalAlunos) {
            InfoAluno novoAluno;
            std::cout << "Nova matrícula: ";
            std::cin >> novoAluno.matricula;
            std::cout << "Novo nome: ";
            std::cin.ignore(); // Limpa o buffer do teclado
            std::getline(std::cin, novoAluno.nome);

            alunos[indice] = novoAluno;
            std::cout << "Aluno atualizado com sucesso!" << std::endl;
        } else {
            std::cout << "Índice inválido!" << std::endl;
        }
    }

    // Método para deletar alunos
    void deletarAlunos() {
        listarAlunos(); // Mostra a lista antes da deleção

        int quantidade;
        std::cout << "\nQuantos alunos deseja deletar? ";
        std::cin >> quantidade;

        for (int i = 0; i < quantidade; ++i) {
            int indice;
            std::cout << "Digite o número correspondente ao aluno a ser deletado: ";
            std::cin >> indice;
            --indice; // Ajusta para o índice no array (começando de zero)

            if (indice >= 0 && indice < totalAlunos) {
                for (int j = indice; j < totalAlunos - 1; ++j) {
                    alunos[j] = alunos[j + 1];
                }
                --totalAlunos;
                std::cout << "Aluno deletado com sucesso!" << std::endl;
            } else {
                std::cout << "Índice inválido!" << std::endl;
            }
        }
    }
};

#endif

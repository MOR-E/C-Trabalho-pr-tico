// SalaDeDefesa.h

#ifndef SALADEDEFESA_H
#define SALADEDEFESA_H

#include <string>
#include <iostream>

class SalaDeDefesa {
private:
    struct InfoSalaDeDefesa {
        std::string codigoSala;
        std::string nomeSala;
        std::string local;
        std::string horarioInicioReserva;
        std::string horarioTerminoReserva;
        bool reservado;
    };

    static const int MAX_SALAS = 100; // Número máximo de salas de defesa
    InfoSalaDeDefesa salas[MAX_SALAS]; // Array de salas de defesa
    int totalSalas = 0; // Contador de salas cadastradas

public:
    // Método para cadastrar salas de defesa
    void cadastrarSalasDeDefesa() {
        int quantidade;
        std::cout << "Quantas salas de defesa deseja cadastrar? ";
        std::cin >> quantidade;

        for (int i = 0; i < quantidade; ++i) {
            if (totalSalas >= MAX_SALAS) {
                std::cout << "Limite máximo de salas de defesa atingido!" << std::endl;
                break;
            }

            InfoSalaDeDefesa novaSala;
            std::cout << "Código da sala de defesa " << i + 1 << ": ";
            std::cin >> novaSala.codigoSala;
            std::cout << "Nome da sala de defesa " << i + 1 << ": ";
            std::cin.ignore(); // Limpa o buffer do teclado
            std::getline(std::cin, novaSala.nomeSala);
            std::cout << "Local da sala de defesa " << i + 1 << ": ";
            std::getline(std::cin, novaSala.local);
            std::cout << "Horário de início da reserva: ";
            std::getline(std::cin, novaSala.horarioInicioReserva);
            std::cout << "Horário de término da reserva: ";
            std::getline(std::cin, novaSala.horarioTerminoReserva);
            std::cout << "Está reservada (1 - Sim / 0 - Não)? ";
            std::cin >> novaSala.reservado;

            salas[totalSalas++] = novaSala;
        }
    }

    // Método para listar todas as salas de defesa
    void listarSalasDeDefesa() {
        std::cout << "Lista de salas de defesa cadastradas:" << std::endl;
        for (int i = 0; i < totalSalas; ++i) {
            std::cout << "Código da sala: " << salas[i].codigoSala << std::endl;
            std::cout << "Nome da sala: " << salas[i].nomeSala << std::endl;
            std::cout << "Local: " << salas[i].local << std::endl;
            std::cout << "Horário de início da reserva: " << salas[i].horarioInicioReserva << std::endl;
            std::cout << "Horário de término da reserva: " << salas[i].horarioTerminoReserva << std::endl;
            std::cout << "Reservada: " << (salas[i].reservado ? "Sim" : "Não") << std::endl;
            std::cout << std::endl;
        }
    }

    // Método para atualizar informações de salas de defesa
    void atualizarSalaDeDefesa() {
        listarSalasDeDefesa(); // Mostra a lista antes da atualização

        int opcao, indice;
        std::cout << "\nQual sala de defesa deseja atualizar (digite o número correspondente)? ";
        std::cin >> indice;
        --indice; // Ajusta para o índice no array (começando de zero)

        if (indice >= 0 && indice < totalSalas) {
            InfoSalaDeDefesa novaSala;
            std::cout << "Novo código da sala: ";
            std::cin >> novaSala.codigoSala;
            std::cout << "Novo nome da sala: ";
            std::cin.ignore(); // Limpa o buffer do teclado
            std::getline(std::cin, novaSala.nomeSala);
            std::cout << "Novo local da sala: ";
            std::getline(std::cin, novaSala.local);
            std::cout << "Novo horário de início da reserva: ";
            std::getline(std::cin, novaSala.horarioInicioReserva);
            std::cout << "Novo horário de término da reserva: ";
            std::getline(std::cin, novaSala.horarioTerminoReserva);
            std::cout << "Está reservada (1 - Sim / 0 - Não)? ";
            std::cin >> novaSala.reservado;

            salas[indice] = novaSala;
            std::cout << "Sala de defesa atualizada com sucesso!" << std::endl;
        } else {
            std::cout << "Índice inválido!" << std::endl;
        }
    }

    // Método para deletar salas de defesa
    void deletarSalaDeDefesa() {
        listarSalasDeDefesa(); // Mostra a lista antes da deleção

        int quantidade;
        std::cout << "\nQuantas salas de defesa deseja deletar? ";
        std::cin >> quantidade;

        for (int i = 0; i < quantidade; ++i) {
            int indice;
            std::cout << "Digite o número correspondente à sala de defesa a ser deletada: ";
            std::cin >> indice;
            --indice; // Ajusta para o índice no array (começando de zero)

            if (indice >= 0 && indice < totalSalas) {
                for (int j = indice; j < totalSalas - 1; ++j) {
                    salas[j] = salas[j + 1];
                }
                --totalSalas;
                std::cout << "Sala de defesa deletada com sucesso!" << std::endl;
            } else {
                std::cout << "Índice inválido!" << std::endl;
            }
        }
    }
};

#endif

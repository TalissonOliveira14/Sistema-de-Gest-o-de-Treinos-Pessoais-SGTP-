#include "Utils.h"
#include <iostream>
#include <limits>

void Utils::limparTela() {
    std::cout << "\033[2J\033[1;1H";
}

void Utils::pausar() {
    std::cout << "\nPressione Enter para continuar...";
    std::cin.ignore();
    std::cin.get();
}

std::string Utils::getDataAtual() {
    time_t agora = time(0);
    tm* dataHora = localtime(&agora);
    char buffer[80];
    strftime(buffer, 80, "%d/%m/%Y %H:%M:%S", dataHora);
    return std::string(buffer);
}

double Utils::lerDouble(const std::string& mensagem) {
    double valor;
    while (true) {
        std::cout << mensagem;
        if (std::cin >> valor) {
            std::cin.ignore();
            return valor;
        }
        std::cout << "Valor invalido. Tente novamente.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int Utils::lerInt(const std::string& mensagem) {
    int valor;
    while (true) {
        std::cout << mensagem;
        if (std::cin >> valor) {
            std::cin.ignore();
            return valor;
        }
        std::cout << "Valor invalido. Tente novamente.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::string Utils::lerString(const std::string& mensagem) {
    std::string valor;
    std::cout << mensagem;
    std::getline(std::cin, valor);
    return valor;
}

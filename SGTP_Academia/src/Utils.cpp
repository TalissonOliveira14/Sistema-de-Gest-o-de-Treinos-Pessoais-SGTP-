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

std::string Utils::formatarTempo(double minutos) {
    int horas = minutos / 60;
    int mins = (int)minutos % 60;
    int segs = (int)((minutos - (int)minutos) * 60);
    
    if (horas > 0) {
        return std::to_string(horas) + "h " + std::to_string(mins) + "min";
    }
    return std::to_string(mins) + "min " + std::to_string(segs) + "s";
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
        std::cout << "Valor invalido. Trente novamente.\n";
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

bool Utils::confirmar(const std::string& mensagem) {
    std::cout << mensagem << " (S/N): ";
    std::string resposta;
    std::getline(std::cin, resposta);
    return !resposta.empty() && (resposta[0] == 'S' || resposta[0] == 's');
}

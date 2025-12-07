#include "Cardio.h"
#include <iostream>
#include <sstream>
#include <iomanip>

Cardio::Cardio() : Exercicio(), duracao(0), caloriasPorMinuto(0.0) {}

Cardio::Cardio(std::string nome, int duracao, double caloriasPorMinuto) : 
    Exercicio(nome), duracao(duracao), caloriasPorMinuto(caloriasPorMinuto) {}

Cardio::Cardio(int idExistente, std::string nome, bool status, int duracao, double caloriasPorMinuto) : 
    Exercicio(idExistente, nome, status), duracao(duracao), caloriasPorMinuto(caloriasPorMinuto) {}

double Cardio::calcularTempo() const {
    return duracao;
}

double Cardio::calcularCalorias() const {
    return duracao * caloriasPorMinuto;
}

void Cardio::exibirDetalhes() const {
    std::cout << "ID: " << id << " | ";
    std::cout << "Tipo: Cardio | ";
    std::cout << "Nome: " << nome << " | ";
    std::cout << "Status: " << (ativo ? "Ativo" : "Inativo") << " | ";
    std::cout << "Duracao: " << duracao << " min | ";
    std::cout << "Calorias/min: " << caloriasPorMinuto;
}

std::string Cardio::toFileString() const {
    std::ostringstream oss;
    oss << 1 << ";" << id << ";" << nome << ";" << duracao << ";" 
        << std::fixed << std::setprecision(2) << caloriasPorMinuto << ";" 
        << (ativo ? 1 : 0);
    return oss.str();
}

int Cardio::getDuracao() const {
    return duracao;
}

double Cardio::getCaloriasPorMinuto() const {
    return caloriasPorMinuto;
}

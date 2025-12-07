#include "Forca.h"
#include <iostream>
#include <iomanip>

Forca::Forca() : Exercicio(), carga(0.0), series(0), repeticoes(0), descanso(0) {}

Forca::Forca(std::string nome, double carga, int series, int repeticoes, int descanso) : 
    Exercicio(nome), carga(carga), series(series), repeticoes(repeticoes), descanso(descanso) {}

Forca::Forca(int idExistente, std::string nome, bool status, double carga, int series, int repeticoes, int descanso) : 
    Exercicio(idExistente, nome, status), carga(carga), series(series), repeticoes(repeticoes), descanso(descanso) {}

double Forca::calcularTempo() const {
    double segundos = (series * repeticoes * 3) + (series * descanso);
    return segundos / 60.0;
}

double Forca::calcularCalorias() const {
    return series * repeticoes * carga * 0.15;
}

void Forca::exibirDetalhes() const {
    std::cout << "ID: " << id << " | ";
    std::cout << "Tipo: Forca | ";
    std::cout << "Nome: " << nome << " | ";
    std::cout << "Status: " << (ativo ? "Ativo" : "Inativo") << " | ";
    std::cout << "Carga: " << std::fixed << std::setprecision(2) << carga << " kg | ";
    std::cout << "Series: " << series << " | ";
    std::cout << "Repeticoes: " << repeticoes << " | ";
    std::cout << "Descanso: " << descanso << " s";
}

double Forca::getCarga() const {
    return carga;
}

int Forca::getSeries() const {
    return series;
}

int Forca::getRepeticoes() const {
    return repeticoes;
}

int Forca::getDescanso() const {
    return descanso;
}

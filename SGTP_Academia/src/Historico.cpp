#include "Historico.h"
#include <iostream>
#include <iomanip>

Historico::Historico() : data(""), idFicha(0), nomeFicha(""), tempoTotal(0.0), caloriasTotais(0.0) {}

Historico::Historico(std::string data, int idFicha, std::string nomeFicha, double tempoTotal, double caloriasTotais) : 
    data(data), idFicha(idFicha), nomeFicha(nomeFicha), tempoTotal(tempoTotal), caloriasTotais(caloriasTotais) {}

std::string Historico::getData() const {
    return data;
}

int Historico::getIdFicha() const {
    return idFicha;
}

std::string Historico::getNomeFicha() const {
    return nomeFicha;
}

double Historico::getTempoTotal() const {
    return tempoTotal;
}

double Historico::getCaloriasTotais() const {
    return caloriasTotais;
}

void Historico::exibir() const {
    std::cout << "Data: " << data << " | ";
    std::cout << "Ficha: " << nomeFicha << " (ID: " << idFicha << ") | ";
    std::cout << "Tempo: " << std::fixed << std::setprecision(2) << tempoTotal << " min | ";
    std::cout << "Calorias: " << caloriasTotais << " cal" << std::endl;
}

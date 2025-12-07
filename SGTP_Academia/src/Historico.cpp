#include "Historico.h"
#include <iostream>
#include <sstream>
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

std::string Historico::toFileString() const {
    std::ostringstream oss;
    oss << data << ";" << idFicha << ";" << nomeFicha << ";" 
        << std::fixed << std::setprecision(2) << tempoTotal << ";" 
        << caloriasTotais;
    return oss.str();
}

Historico Historico::fromFileString(std::string linha) {
    std::istringstream iss(linha);
    std::string token;
    std::vector<std::string> tokens;
    
    while (std::getline(iss, token, ';')) {
        tokens.push_back(token);
    }
    
    if (tokens.size() != 5) {
        return Historico();
    }
    
    std::string data = tokens[0];
    int idFicha = std::stoi(tokens[1]);
    std::string nomeFicha = tokens[2];
    double tempoTotal = std::stod(tokens[3]);
    double caloriasTotais = std::stod(tokens[4]);
    
    return Historico(data, idFicha, nomeFicha, tempoTotal, caloriasTotais);
}

void Historico::exibir() const {
    std::cout << "Data: " << data << " | ";
    std::cout << "Ficha: " << nomeFicha << " (ID: " << idFicha << ") | ";
    std::cout << "Tempo: " << std::fixed << std::setprecision(2) << tempoTotal << " min | ";
    std::cout << "Calorias: " << caloriasTotais << " cal" << std::endl;
}

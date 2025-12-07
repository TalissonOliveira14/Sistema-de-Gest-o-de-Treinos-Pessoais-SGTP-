#include "Ficha.h"
#include <iostream>
#include <sstream>
#include <iomanip>

Ficha::Ficha() : id(0), nome("") {}

Ficha::Ficha(int id, std::string nome) : id(id), nome(nome) {}

Ficha::~Ficha() {}

int Ficha::getId() const {
    return id;
}

std::string Ficha::getNome() const {
    return nome;
}

void Ficha::setNome(std::string nome) {
    this->nome = nome;
}

void Ficha::adicionarExercicio(Exercicio* exercicio) {
    exercicios.push_back(exercicio);
}

void Ficha::removerExercicio(int index) {
    if (index >= 0 && index < exercicios.size()) {
        exercicios.erase(exercicios.begin() + index);
    }
}

void Ficha::limparExercicios() {
    exercicios.clear();
}

double Ficha::calcularTempoTotal() const {
    double total = 0.0;
    for (Exercicio* e : exercicios) {
        total += e->calcularTempo();
    }
    return total;
}

double Ficha::calcularCaloriasTotais() const {
    double total = 0.0;
    for (Exercicio* e : exercicios) {
        total += e->calcularCalorias();
    }
    return total;
}

void Ficha::exibirDetalhes() const {
    std::cout << "=== Ficha ID: " << id << " - " << nome << " ===" << std::endl;
    for (Exercicio* e : exercicios) {
        std::cout << "  ";
        e->exibirDetalhes();
        std::cout << std::endl;
    }
    std::cout << "Tempo total: " << std::fixed << std::setprecision(2) 
              << calcularTempoTotal() << " minutos" << std::endl;
    std::cout << "Calorias totais: " << calcularCaloriasTotais() << std::endl;
}

std::string Ficha::toFileString() const {
    std::ostringstream oss;
    oss << id << ";" << nome << ";" << exercicios.size();
    for (Exercicio* e : exercicios) {
        oss << ";" << e->getId();
    }
    return oss.str();
}

Ficha Ficha::fromFileString(std::string linha, std::vector<Exercicio*> listaExercicios) {
    std::istringstream iss(linha);
    std::string token;
    std::vector<std::string> tokens;
    
    while (std::getline(iss, token, ';')) {
        tokens.push_back(token);
    }
    
    if (tokens.size() < 3) {
        return Ficha();
    }
    
    int id = std::stoi(tokens[0]);
    std::string nome = tokens[1];
    int totalExercicios = std::stoi(tokens[2]);
    
    Ficha ficha(id, nome);
    
    for (int i = 0; i < totalExercicios; i++) {
        int idExercicio = std::stoi(tokens[3 + i]);
        for (Exercicio* e : listaExercicios) {
            if (e->getId() == idExercicio) {
                ficha.adicionarExercicio(e);
                break;
            }
        }
    }
    
    return ficha;
}

std::vector<Exercicio*> Ficha::getExercicios() const {
    return exercicios;
}

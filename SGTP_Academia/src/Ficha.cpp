#include "Ficha.h"
#include <iostream>
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
    if (index >= 0 && static_cast<size_t>(index) < exercicios.size()) {
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

std::vector<Exercicio*> Ficha::getExercicios() const {
    return exercicios;
}

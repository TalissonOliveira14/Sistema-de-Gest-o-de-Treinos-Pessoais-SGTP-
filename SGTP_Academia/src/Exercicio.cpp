#include "Exercicio.h"

int Exercicio::proximoId = 1;

Exercicio::Exercicio() : id(0), nome(""), ativo(false) {}

Exercicio::Exercicio(std::string nome) : nome(nome), ativo(true) {
    id = proximoId++;
}

Exercicio::Exercicio(int idExistente, std::string nome, bool status) : 
    id(idExistente), nome(nome), ativo(status) {
    if (idExistente >= proximoId) {
        proximoId = idExistente + 1;
    }
}

Exercicio::~Exercicio() {}

int Exercicio::getId() const {
    return id;
}

std::string Exercicio::getNome() const {
    return nome;
}

bool Exercicio::isAtivo() const {
    return ativo;
}

void Exercicio::setAtivo(bool status) {
    ativo = status;
}

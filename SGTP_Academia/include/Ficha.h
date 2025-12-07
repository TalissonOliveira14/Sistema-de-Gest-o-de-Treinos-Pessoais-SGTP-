#ifndef FICHA_H
#define FICHA_H

#include <vector>
#include <string>
#include "Exercicio.h"

class Ficha {
private:
    int id;
    std::string nome;
    std::vector<Exercicio*> exercicios;

public:
    Ficha();
    Ficha(int id, std::string nome);
    ~Ficha();
    
    int getId() const;
    std::string getNome() const;
    void setNome(std::string nome);
    
    void adicionarExercicio(Exercicio* exercicio);
    void removerExercicio(int index);
    void limparExercicios();
    
    double calcularTempoTotal() const;
    double calcularCaloriasTotais() const;
    void exibirDetalhes() const;
    
    std::vector<Exercicio*> getExercicios() const;
};

#endif

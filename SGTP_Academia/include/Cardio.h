#ifndef CARDIO_H
#define CARDIO_H

#include "Exercicio.h"

class Cardio : public Exercicio {
private:
    int duracao;
    double caloriasPorMinuto;

public:
    Cardio();
    Cardio(std::string nome, int duracao, double caloriasPorMinuto);
    Cardio(int idExistente, std::string nome, bool status, int duracao, double caloriasPorMinuto);
    
    double calcularTempo() const override;
    double calcularCalorias() const override;
    void exibirDetalhes() const override;
    
    int getDuracao() const;
    double getCaloriasPorMinuto() const;
};

#endif

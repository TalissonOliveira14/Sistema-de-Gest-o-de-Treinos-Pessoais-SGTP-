#ifndef FORCA_H
#define FORCA_H

#include "Exercicio.h"

class Forca : public Exercicio {
private:
    double carga;
    int series;
    int repeticoes;
    int descanso;

public:
    Forca();
    Forca(std::string nome, double carga, int series, int repeticoes, int descanso);
    Forca(int idExistente, std::string nome, bool status, double carga, int series, int repeticoes, int descanso);
    
    double calcularTempo() const override;
    double calcularCalorias() const override;
    void exibirDetalhes() const override;
    std::string toFileString() const override;
    
    double getCarga() const;
    int getSeries() const;
    int getRepeticoes() const;
    int getDescanso() const;
};

#endif

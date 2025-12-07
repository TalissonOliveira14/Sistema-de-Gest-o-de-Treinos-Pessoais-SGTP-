#ifndef HISTORICO_H
#define HISTORICO_H

#include <string>

class Historico {
private:
    std::string data;
    int idFicha;
    std::string nomeFicha;
    double tempoTotal;
    double caloriasTotais;

public:
    Historico();
    Historico(std::string data, int idFicha, std::string nomeFicha, double tempoTotal, double caloriasTotais);
    
    std::string getData() const;
    int getIdFicha() const;
    std::string getNomeFicha() const;
    double getTempoTotal() const;
    double getCaloriasTotais() const;
    
    void exibir() const;
};

#endif

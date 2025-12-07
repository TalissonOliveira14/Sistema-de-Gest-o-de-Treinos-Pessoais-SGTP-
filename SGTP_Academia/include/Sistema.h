#ifndef GERENCIADOR_H
#define GERENCIADOR_H

#include <vector>
#include <string>
#include "Exercicio.h"
#include "Ficha.h"
#include "Historico.h"

class Gerenciador {
private:
    std::string caminhoExercicios;
    std::string caminhoFichas;
    std::string caminhoHistorico;

public:
    Gerenciador();
    Gerenciador(std::string caminhoExercicios, std::string caminhoFichas, std::string caminhoHistorico);
    
    void salvarExercicios(const std::vector<Exercicio*>& exercicios);
    std::vector<Exercicio*> carregarExercicios();
    
    void salvarFichas(const std::vector<Ficha>& fichas);
    std::vector<Ficha> carregarFichas(const std::vector<Exercicio*>& exercicios);
    
    void salvarHistorico(const std::vector<Historico>& historico);
    std::vector<Historico> carregarHistorico();
};

#endif

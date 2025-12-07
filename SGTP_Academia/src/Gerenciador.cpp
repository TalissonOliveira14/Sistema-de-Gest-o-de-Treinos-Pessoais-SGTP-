#include "Gerenciador.h"
#include <fstream>
#include <iostream>
#include <sstream>

Gerenciador::Gerenciador() {
    caminhoExercicios = "data/exercicios.txt";
    caminhoFichas = "data/fichas.txt";
    caminhoHistorico = "data/historico.txt";
}

Gerenciador::Gerenciador(std::string caminhoExercicios, std::string caminhoFichas, std::string caminhoHistorico) : 
    caminhoExercicios(caminhoExercicios), caminhoFichas(caminhoFichas), caminhoHistorico(caminhoHistorico) {}

void Gerenciador::salvarExercicios(const std::vector<Exercicio*>& exercicios) {
    std::ofstream arquivo(caminhoExercicios);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao salvar exercicios." << std::endl;
        return;
    }
    
    for (Exercicio* e : exercicios) {
        arquivo << e->toFileString() << std::endl;
    }
    
    arquivo.close();
}

std::vector<Exercicio*> Gerenciador::carregarExercicios() {
    std::vector<Exercicio*> exercicios;
    std::ifstream arquivo(caminhoExercicios);
    
    if (!arquivo.is_open()) {
        return exercicios;
    }
    
    std::string linha;
    while (std::getline(arquivo, linha)) {
        if (linha.empty()) continue;
        
        std::istringstream iss(linha);
        std::string token;
        std::vector<std::string> tokens;
        
        while (std::getline(iss, token, ';')) {
            tokens.push_back(token);
        }
        
        if (tokens.size() < 6) continue;
        
        int tipo = std::stoi(tokens[0]);
        int id = std::stoi(tokens[1]);
        std::string nome = tokens[2];
        bool status = std::stoi(tokens[tokens.size() - 1]) == 1;
        
        if (tipo == 1 && tokens.size() == 6) {
            int duracao = std::stoi(tokens[3]);
            double caloriasPorMinuto = std::stod(tokens[4]);
            exercicios.push_back(new Cardio(id, nome, status, duracao, caloriasPorMinuto));
        }
        else if (tipo == 2 && tokens.size() == 8) {
            double carga = std::stod(tokens[3]);
            int series = std::stoi(tokens[4]);
            int repeticoes = std::stoi(tokens[5]);
            int descanso = std::stoi(tokens[6]);
            exercicios.push_back(new Forca(id, nome, status, carga, series, repeticoes, descanso));
        }
    }
    
    arquivo.close();
    return exercicios;
}

void Gerenciador::salvarFichas(const std::vector<Ficha>& fichas) {
    std::ofstream arquivo(caminhoFichas);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao salvar fichas." << std::endl;
        return;
    }
    
    for (const Ficha& f : fichas) {
        arquivo << f.toFileString() << std::endl;
    }
    
    arquivo.close();
}

std::vector<Ficha> Gerenciador::carregarFichas(const std::vector<Exercicio*>& exercicios) {
    std::vector<Ficha> fichas;
    std::ifstream arquivo(caminhoFichas);
    
    if (!arquivo.is_open()) {
        return fichas;
    }
    
    std::string linha;
    while (std::getline(arquivo, linha)) {
        if (linha.empty()) continue;
        fichas.push_back(Ficha::fromFileString(linha, exercicios));
    }
    
    arquivo.close();
    return fichas;
}

void Gerenciador::salvarHistorico(const std::vector<Historico>& historico) {
    std::ofstream arquivo(caminhoHistorico);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao salvar historico." << std::endl;
        return;
    }
    
    for (const Historico& h : historico) {
        arquivo << h.toFileString() << std::endl;
    }
    
    arquivo.close();
}

std::vector<Historico> Gerenciador::carregarHistorico() {
    std::vector<Historico> historico;
    std::ifstream arquivo(caminhoHistorico);
    
    if (!arquivo.is_open()) {
        return historico;
    }
    
    std::string linha;
    while (std::getline(arquivo, linha)) {
        if (linha.empty()) continue;
        historico.push_back(Historico::fromFileString(linha));
    }
    
    arquivo.close();
    return historico;
}

#include "Sistema.h"
#include "Utils.h"
#include "Cardio.h"
#include "Forca.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

Sistema::Sistema() {
    caminhoExercicios = "data/exercicios.txt";
    caminhoFichas = "data/fichas.txt";
    caminhoHistorico = "data/historico.txt";
    carregarDados();
}

Sistema::~Sistema() {
    for (Exercicio* e : exercicios) {
        delete e;
    }
}

void Sistema::cadastrarExercicio() {
    Utils::limparTela();
    std::cout << "=== CADASTRAR EXERCICIO ===\n";
    
    int tipo = Utils::lerInt("1. Cardio\n2. Forca\nTipo: ");
    if (tipo != 1 && tipo != 2) {
        std::cout << "Tipo invalido!\n";
        Utils::pausar();
        return;
    }
    
    std::string nome = Utils::lerString("Nome: ");
    
    if (tipo == 1) {
        int duracao = Utils::lerInt("Duracao (minutos): ");
        double caloriasPorMinuto = Utils::lerDouble("Calorias por minuto: ");
        exercicios.push_back(new Cardio(nome, duracao, caloriasPorMinuto));
        std::cout << "Exercicio de Cardio cadastrado com ID " << exercicios.back()->getId() << std::endl;
    } else {
        double carga = Utils::lerDouble("Carga (kg): ");
        int series = Utils::lerInt("Series: ");
        int repeticoes = Utils::lerInt("Repeticoes: ");
        int descanso = Utils::lerInt("Descanso (segundos): ");
        exercicios.push_back(new Forca(nome, carga, series, repeticoes, descanso));
        std::cout << "Exercicio de Forca cadastrado com ID " << exercicios.back()->getId() << std::endl;
    }
    
    Utils::pausar();
}

void Sistema::listarExerciciosAtivos() const {
    Utils::limparTela();
    std::cout << "=== EXERCICIOS ATIVOS ===\n";
    
    bool encontrou = false;
    for (Exercicio* e : exercicios) {
        if (e->isAtivo()) {
            e->exibirDetalhes();
            std::cout << std::endl;
            encontrou = true;
        }
    }
    
    if (!encontrou) {
        std::cout << "Nenhum exercicio ativo.\n";
    }
    Utils::pausar();
}

void Sistema::excluirExercicioLogico(int id) {
    Exercicio* exercicio = buscarExercicioPorId(id);
    if (exercicio && exercicio->isAtivo()) {
        exercicio->setAtivo(false);
        std::cout << "Exercicio marcado como inativo.\n";
    } else {
        std::cout << "Exercicio nao encontrado ou ja inativo.\n";
    }
}

Exercicio* Sistema::buscarExercicioPorId(int id) const {
    for (Exercicio* e : exercicios) {
        if (e->getId() == id) {
            return e;
        }
    }
    return nullptr;
}

void Sistema::criarFicha(const std::string& nome) {
    int novoId = getProximoIdFicha();
    fichas.push_back(Ficha(novoId, nome));
    std::cout << "Ficha criada com ID " << novoId << std::endl;
}

void Sistema::adicionarExercicioAFicha(int idFicha, int idExercicio) {
    Ficha* ficha = buscarFichaPorId(idFicha);
    Exercicio* exercicio = buscarExercicioPorId(idExercicio);
    
    if (!ficha) {
        std::cout << "Ficha nao encontrada.\n";
        return;
    }
    
    if (!exercicio) {
        std::cout << "Exercicio nao encontrado.\n";
        return;
    }
    
    if (!exercicio->isAtivo()) {
        std::cout << "Exercicio esta inativo.\n";
        return;
    }
    
    ficha->adicionarExercicio(exercicio);
    std::cout << "Exercicio adicionado a ficha.\n";
}

void Sistema::listarFichas() const {
    Utils::limparTela();
    std::cout << "=== FICHAS CADASTRADAS ===\n";
    
    if (fichas.empty()) {
        std::cout << "Nenhuma ficha cadastrada.\n";
    } else {
        for (const Ficha& f : fichas) {
            f.exibirDetalhes();
            std::cout << std::endl;
        }
    }
    Utils::pausar();
}

Ficha* Sistema::buscarFichaPorId(int id) {
    for (Ficha& f : fichas) {
        if (f.getId() == id) {
            return &f;
        }
    }
    return nullptr;
}

void Sistema::registrarTreino(int idFicha) {
    Ficha* ficha = buscarFichaPorId(idFicha);
    if (!ficha) {
        std::cout << "Ficha nao encontrada.\n";
        return;
    }
    
    double tempoTotal = ficha->calcularTempoTotal();
    double caloriasTotais = ficha->calcularCaloriasTotais();
    std::string dataAtual = Utils::getDataAtual();
    
    historico.push_back(Historico(dataAtual, idFicha, ficha->getNome(), tempoTotal, caloriasTotais));
    
    std::cout << "Treino registrado!\n";
    std::cout << "Tempo total: " << std::fixed << std::setprecision(2) << tempoTotal << " min\n";
    std::cout << "Calorias: " << caloriasTotais << " cal\n";
    Utils::pausar();
}

void Sistema::listarHistorico() const {
    Utils::limparTela();
    std::cout << "=== HISTORICO DE TREINOS ===\n";
    
    if (historico.empty()) {
        std::cout << "Nenhum treino registrado.\n";
    } else {
        for (const Historico& h : historico) {
            h.exibir();
        }
    }
    Utils::pausar();
}

void Sistema::carregarDados() {
    std::ifstream arqExercicios(caminhoExercicios);
    if (arqExercicios.is_open()) {
        std::string linha;
        while (std::getline(arqExercicios, linha)) {
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
            } else if (tipo == 2 && tokens.size() == 8) {
                double carga = std::stod(tokens[3]);
                int series = std::stoi(tokens[4]);
                int repeticoes = std::stoi(tokens[5]);
                int descanso = std::stoi(tokens[6]);
                exercicios.push_back(new Forca(id, nome, status, carga, series, repeticoes, descanso));
            }
        }
        arqExercicios.close();
    }
    
    std::ifstream arqFichas(caminhoFichas);
    if (arqFichas.is_open()) {
        std::string linha;
        while (std::getline(arqFichas, linha)) {
            if (linha.empty()) continue;
            fichas.push_back(Ficha::fromFileString(linha, exercicios));
        }
        arqFichas.close();
    }
    
    std::ifstream arqHistorico(caminhoHistorico);
    if (arqHistorico.is_open()) {
        std::string linha;
        while (std::getline(arqHistorico, linha)) {
            if (linha.empty()) continue;
            historico.push_back(Historico::fromFileString(linha));
        }
        arqHistorico.close();
    }
}

void Sistema::salvarDados() {
    std::ofstream arqExercicios(caminhoExercicios);
    if (arqExercicios.is_open()) {
        for (Exercicio* e : exercicios) {
            arqExercicios << e->toFileString() << std::endl;
        }
        arqExercicios.close();
    }
    
    std::ofstream arqFichas(caminhoFichas);
    if (arqFichas.is_open()) {
        for (const Ficha& f : fichas) {
            arqFichas << f.toFileString() << std::endl;
        }
        arqFichas.close();
    }
    
    std::ofstream arqHistorico(caminhoHistorico);
    if (arqHistorico.is_open()) {
        for (const Historico& h : historico) {
            arqHistorico << h.toFileString() << std::endl;
        }
        arqHistorico.close();
    }
}

int Sistema::getProximoIdFicha() const {
    return fichas.empty() ? 1 : fichas.back().getId() + 1;
}

bool Sistema::exercicioExiste(int id) const {
    return buscarExercicioPorId(id) != nullptr;
}

bool Sistema::fichaExiste(int id) const {
    for (const Ficha& f : fichas) {
        if (f.getId() == id) {
            return true;
        }
    }
    return false;
}

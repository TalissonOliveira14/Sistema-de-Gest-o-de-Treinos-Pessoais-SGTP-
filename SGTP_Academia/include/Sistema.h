#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
#include <string>
#include "Exercicio.h"
#include "Ficha.h"
#include "Historico.h"

class Sistema {
private:
    std::string caminhoExercicios;
    std::string caminhoFichas;
    std::string caminhoHistorico;
    
    std::vector<Exercicio*> exercicios;
    std::vector<Ficha> fichas;
    std::vector<Historico> historico;
    
public:
    Sistema();
    ~Sistema();
    
    // Gerenciamento de exercícios
    void cadastrarExercicio();
    void listarExerciciosAtivos() const;
    void excluirExercicioLogico(int id);
    Exercicio* buscarExercicioPorId(int id) const;
    
    // Gerenciamento de fichas
    void criarFicha(const std::string& nome);
    void adicionarExercicioAFicha(int idFicha, int idExercicio);
    void listarFichas() const;
    Ficha* buscarFichaPorId(int id);
    
    // Histórico
    void registrarTreino(int idFicha);
    void listarHistorico() const;
    
    // Persistência
    void carregarDados();
    void salvarDados();
    
    // Utilitários
    int getProximoIdFicha() const;
    bool exercicioExiste(int id) const;
    bool fichaExiste(int id) const;
};

#endif

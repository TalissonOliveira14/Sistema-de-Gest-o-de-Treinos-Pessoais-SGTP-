#ifndef EXERCICIO_H
#define EXERCICIO_H

#include <string>

class Exercicio {
protected:
    int id;
    std::string nome;
    bool ativo;
    static int proximoId;

public:
    Exercicio();
    Exercicio(std::string nome);
    Exercicio(int idExistente, std::string nome, bool status);
    virtual ~Exercicio();

    int getId() const;
    std::string getNome() const;
    bool isAtivo() const;
    void setAtivo(bool status);

    virtual double calcularTempo() const = 0;
    virtual double calcularCalorias() const = 0;
    virtual void exibirDetalhes() const = 0;
    virtual std::string toFileString() const = 0;
};

#endif

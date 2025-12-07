#include "Sistema.h"
#include "Utils.h"
#include <iostream>

void menuGerenciarExercicios(Sistema& sistema) {
    int opcao;
    do {
        Utils::limparTela();
        std::cout << "=== GERENCIAR EXERCICIOS ===\n";
        std::cout << "1. Cadastrar Exercicio\n";
        std::cout << "2. Listar Exercicios Ativos\n";
        std::cout << "3. Excluir Exercicio (Logico)\n";
        std::cout << "0. Voltar\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;
        std::cin.ignore();
        
        switch (opcao) {
            case 1:
                sistema.cadastrarExercicio();
                break;
            case 2:
                sistema.listarExerciciosAtivos();
                break;
            case 3: {
                int id = Utils::lerInt("ID do exercicio a excluir: ");
                sistema.excluirExercicioLogico(id);
                Utils::pausar();
                break;
            }
            case 0:
                break;
            default:
                std::cout << "Opcao invalida!\n";
                Utils::pausar();
        }
    } while (opcao != 0);
}

void menuGerenciarFichas(Sistema& sistema) {
    int opcao;
    do {
        Utils::limparTela();
        std::cout << "=== GERENCIAR FICHAS ===\n";
        std::cout << "1. Criar Ficha\n";
        std::cout << "2. Adicionar Exercicio a Ficha\n";
        std::cout << "3. Visualizar Fichas\n";
        std::cout << "0. Voltar\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;
        std::cin.ignore();
        
        switch (opcao) {
            case 1: {
                std::string nome = Utils::lerString("Nome da ficha: ");
                sistema.criarFicha(nome);
                Utils::pausar();
                break;
            }
            case 2: {
                int idFicha = Utils::lerInt("ID da ficha: ");
                int idExercicio = Utils::lerInt("ID do exercicio: ");
                sistema.adicionarExercicioAFicha(idFicha, idExercicio);
                Utils::pausar();
                break;
            }
            case 3:
                sistema.listarFichas();
                break;
            case 0:
                break;
            default:
                std::cout << "Opcao invalida!\n";
                Utils::pausar();
        }
    } while (opcao != 0);
}

int main() {
    Sistema sistema;
    int opcao;
    
    do {
        Utils::limparTela();
        std::cout << "=== SISTEMA DE GESTAO DE TREINOS PESSOAIS ===\n";
        std::cout << "1. Gerenciar Banco de Exercicios\n";
        std::cout << "2. Gerenciar Fichas de Treino\n";
        std::cout << "3. Registrar Execucao (Treinar)\n";
        std::cout << "4. Consultar Historico\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;
        std::cin.ignore();
        
        switch (opcao) {
            case 1:
                menuGerenciarExercicios(sistema);
                break;
            case 2:
                menuGerenciarFichas(sistema);
                break;
            case 3: {
                int idFicha = Utils::lerInt("ID da ficha realizada: ");
                sistema.registrarTreino(idFicha);
                break;
            }
            case 4:
                sistema.listarHistorico();
                break;
            case 0:
                Utils::limparTela();
                std::cout << "Salvando dados...\n";
                sistema.salvarDados();
                std::cout << "Dados salvos. Adeus!\n";
                break;
            default:
                std::cout << "Opcao invalida!\n";
                Utils::pausar();
        }
    } while (opcao != 0);
    
    return 0;
}

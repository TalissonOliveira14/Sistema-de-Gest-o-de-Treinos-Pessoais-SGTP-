#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>
#include <limits>
#include "Exercicio.h"
#include "Cardio.h"
#include "Forca.h"
#include "Ficha.h"
#include "Historico.h"
#include "Gerenciador.h"

using namespace std;

void limparTela() {
    cout << "\033[2J\033[1;1H";
}

void pausar() {
    cout << "\nPressione Enter para continuar...";
    cin.ignore();
    cin.get();
}

string getDataAtual() {
    time_t agora = time(0);
    tm* dataHora = localtime(&agora);
    char buffer[80];
    strftime(buffer, 80, "%d/%m/%Y %H:%M:%S", dataHora);
    return string(buffer);
}

void menuPrincipal() {
    Gerenciador gerenciador;
    vector<Exercicio*> exercicios = gerenciador.carregarExercicios();
    vector<Ficha> fichas = gerenciador.carregarFichas(exercicios);
    vector<Historico> historico = gerenciador.carregarHistorico();
    
    int opcao;
    do {
        limparTela();
        cout << "=== SISTEMA DE GESTAO DE TREINOS PESSOAIS ===\n";
        cout << "1. Gerenciar Banco de Exercicios\n";
        cout << "2. Gerenciar Fichas de Treino\n";
        cout << "3. Registrar Execucao (Treinar)\n";
        cout << "4. Consultar Historico\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cin.ignore();
        
        switch (opcao) {
            case 1: {
                int subOpcao;
                do {
                    limparTela();
                    cout << "=== GERENCIAR EXERCICIOS ===\n";
                    cout << "1. Cadastrar Exercicio\n";
                    cout << "2. Listar Exercicios Ativos\n";
                    cout << "3. Excluir Exercicio (Logico)\n";
                    cout << "0. Voltar\n";
                    cout << "Escolha: ";
                    cin >> subOpcao;
                    cin.ignore();
                    
                    switch (subOpcao) {
                        case 1: {
                            limparTela();
                            cout << "=== CADASTRAR EXERCICIO ===\n";
                            cout << "1. Cardio\n2. Forca\nTipo: ";
                            int tipo;
                            cin >> tipo;
                            cin.ignore();
                            
                            cout << "Nome: ";
                            string nome;
                            getline(cin, nome);
                            
                            if (tipo == 1) {
                                int duracao;
                                double calMin;
                                cout << "Duracao (min): ";
                                cin >> duracao;
                                cout << "Calorias/min: ";
                                cin >> calMin;
                                cin.ignore();
                                
                                exercicios.push_back(new Cardio(nome, duracao, calMin));
                                cout << "Exercicio cadastrado com ID " << exercicios.back()->getId() << endl;
                            }
                            else if (tipo == 2) {
                                double carga;
                                int series, reps, descanso;
                                cout << "Carga (kg): ";
                                cin >> carga;
                                cout << "Series: ";
                                cin >> series;
                                cout << "Repeticoes: ";
                                cin >> reps;
                                cout << "Descanso (s): ";
                                cin >> descanso;
                                cin.ignore();
                                
                                exercicios.push_back(new Forca(nome, carga, series, reps, descanso));
                                cout << "Exercicio cadastrado com ID " << exercicios.back()->getId() << endl;
                            }
                            pausar();
                            break;
                        }
                        case 2: {
                            limparTela();
                            cout << "=== EXERCICIOS ATIVOS ===\n";
                            bool encontrou = false;
                            for (Exercicio* e : exercicios) {
                                if (e->isAtivo()) {
                                    e->exibirDetalhes();
                                    cout << endl;
                                    encontrou = true;
                                }
                            }
                            if (!encontrou) cout << "Nenhum exercicio ativo.\n";
                            pausar();
                            break;
                        }
                        case 3: {
                            limparTela();
                            cout << "=== EXCLUIR EXERCICIO ===\n";
                            cout << "ID do exercicio: ";
                            int id;
                            cin >> id;
                            cin.ignore();
                            
                            bool encontrou = false;
                            for (Exercicio* e : exercicios) {
                                if (e->getId() == id && e->isAtivo()) {
                                    e->setAtivo(false);
                                    cout << "Exercicio marcado como inativo.\n";
                                    encontrou = true;
                                    break;
                                }
                            }
                            if (!encontrou) cout << "Exercicio nao encontrado.\n";
                            pausar();
                            break;
                        }
                    }
                } while (subOpcao != 0);
                break;
            }
            case 2: {
                int subOpcao;
                do {
                    limparTela();
                    cout << "=== GERENCIAR FICHAS ===\n";
                    cout << "1. Criar Ficha\n";
                    cout << "2. Adicionar Exercicio a Ficha\n";
                    cout << "3. Visualizar Fichas\n";
                    cout << "0. Voltar\n";
                    cout << "Escolha: ";
                    cin >> subOpcao;
                    cin.ignore();
                    
                    switch (subOpcao) {
                        case 1: {
                            limparTela();
                            cout << "=== CRIAR FICHA ===\n";
                            cout << "Nome da ficha: ";
                            string nome;
                            getline(cin, nome);
                            
                            int novoId = fichas.empty() ? 1 : fichas.back().getId() + 1;
                            fichas.push_back(Ficha(novoId, nome));
                            cout << "Ficha criada com ID " << novoId << endl;
                            pausar();
                            break;
                        }
                        case 2: {
                            limparTela();
                            cout << "=== ADICIONAR EXERCICIO ===\n";
                            
                            if (fichas.empty()) {
                                cout << "Nenhuma ficha cadastrada.\n";
                                pausar();
                                break;
                            }
                            
                            cout << "ID da ficha: ";
                            int idFicha;
                            cin >> idFicha;
                            cin.ignore();
                            
                            Ficha* fichaSelecionada = nullptr;
                            for (Ficha& f : fichas) {
                                if (f.getId() == idFicha) {
                                    fichaSelecionada = &f;
                                    break;
                                }
                            }
                            
                            if (!fichaSelecionada) {
                                cout << "Ficha nao encontrada.\n";
                                pausar();
                                break;
                            }
                            
                            cout << "ID do exercicio: ";
                            int idExercicio;
                            cin >> idExercicio;
                            cin.ignore();
                            
                            Exercicio* exercicioSelecionado = nullptr;
                            for (Exercicio* e : exercicios) {
                                if (e->getId() == idExercicio && e->isAtivo()) {
                                    exercicioSelecionado = e;
                                    break;
                                }
                            }
                            
                            if (!exercicioSelecionado) {
                                cout << "Exercicio nao encontrado ou inativo.\n";
                                pausar();
                                break;
                            }
                            
                            fichaSelecionada->adicionarExercicio(exercicioSelecionado);
                            cout << "Exercicio adicionado.\n";
                            pausar();
                            break;
                        }
                        case 3: {
                            limparTela();
                            cout << "=== FICHAS CADASTRADAS ===\n";
                            if (fichas.empty()) {
                                cout << "Nenhuma ficha cadastrada.\n";
                            }
                            else {
                                for (Ficha& f : fichas) {
                                    f.exibirDetalhes();
                                    cout << endl;
                                }
                            }
                            pausar();
                            break;
                        }
                    }
                } while (subOpcao != 0);
                break;
            }
            case 3: {
                limparTela();
                cout << "=== REGISTRAR TREINO ===\n";
                
                if (fichas.empty()) {
                    cout << "Nenhuma ficha cadastrada.\n";
                    pausar();
                    break;
                }
                
                cout << "ID da ficha realizada: ";
                int idFicha;
                cin >> idFicha;
                cin.ignore();
                
                Ficha* fichaSelecionada = nullptr;
                for (Ficha& f : fichas) {
                    if (f.getId() == idFicha) {
                        fichaSelecionada = &f;
                        break;
                    }
                }
                
                if (!fichaSelecionada) {
                    cout << "Ficha nao encontrada.\n";
                    pausar();
                    break;
                }
                
                double tempoTotal = fichaSelecionada->calcularTempoTotal();
                double caloriasTotais = fichaSelecionada->calcularCaloriasTotais();
                string dataAtual = getDataAtual();
                
                historico.push_back(Historico(dataAtual, idFicha, fichaSelecionada->getNome(), tempoTotal, caloriasTotais));
                cout << "Treino registrado!\n";
                cout << "Tempo: " << tempoTotal << " min | ";
                cout << "Calorias: " << caloriasTotais << " cal\n";
                pausar();
                break;
            }
            case 4: {
                limparTela();
                cout << "=== HISTORICO ===\n";
                if (historico.empty()) {
                    cout << "Nenhum registro.\n";
                }
                else {
                    for (Historico& h : historico) {
                        h.exibir();
                    }
                }
                pausar();
                break;
            }
            case 0: {
                limparTela();
                cout << "Salvando dados...\n";
                gerenciador.salvarExercicios(exercicios);
                gerenciador.salvarFichas(fichas);
                gerenciador.salvarHistorico(historico);
                cout << "Dados salvos. Adeus!\n";
                
                for (Exercicio* e : exercicios) {
                    delete e;
                }
                break;
            }
            default:
                cout << "Opcao invalida.\n";
                pausar();
                break;
        }
    } while (opcao != 0);
}

int main() {
    menuPrincipal();
    return 0;
}

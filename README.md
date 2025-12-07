# Sistema de Gestão de Treinos Pessoais (SGTP)

## Disciplina: Linguagem de Programação 1
## Aluno: Talisson Pereira de Oliveira e Pedro Henrique Mendes Fernandes
## Matrícula: 20230066172, 20240061527
## Turno:Vespertino

## Descrição
Sistema desenvolvido em C++ para gerenciamento de treinos pessoais, permitindo cadastrar exercícios, criar fichas de treino, calcular tempo e calorias, e registrar histórico de execução.

## Funcionalidades Implementadas

### 1. Gerenciamento de Exercícios
- Cadastro de exercícios de Cardio e Força
- Listagem de exercícios ativos
- Exclusão lógica (marca como inativo)
- IDs automáticos persistentes

### 2. Gerenciamento de Fichas de Treino
- Criação de fichas com nomes personalizados
- Adição de exercícios às fichas
- Cálculo automático de tempo total
- Cálculo automático de calorias totais
- Visualização completa das fichas

### 3. Histórico de Execução
- Registro de treinos realizados
- Armazenamento de data/hora, tempo e calorias
- Consulta do histórico cronológico

### 4. Persistência de Dados
- Salvamento automático em arquivos texto
- Carregamento automático ao iniciar
- Três arquivos de dados: exercicios.txt, fichas.txt, historico.txt

## Características Técnicas

### Classes Implementadas
- **Exercicio** (classe base abstrata)
- **Cardio** (herda de Exercicio)
- **Forca** (herda de Exercicio)
- **Ficha** (agrega exercícios)
- **Historico** (registra execuções)
- **Sistema** (gerencia a aplicação)
- **Utils** (funções auxiliares)

### Conceitos de POO Utilizados
- Herança (Exercicio → Cardio/Forca)
- Polimorfismo (cálculos diferentes para cada tipo)
- Encapsulamento (atributos privados com getters/setters)
- Classes abstratas (Exercicio)
- Composição (Ficha contém Exercicio)

### Persistência
- Arquivos texto com formato CSV (separado por ;)
- IDs automáticos persistentes entre execuções
- Tratamento de arquivos inexistentes

## Compilação e Execução

### Pré-requisitos
- Compilador C++11 (g++ recomendado)
- Sistema Linux/Windows/Mac

### Compilar
```bash
make

# Estruturas de Dados em C

Repositório dedicado ao desenvolvimento de exercícios práticos de **Estruturas de Dados utilizando a linguagem C**, realizados durante meus estudos de Ciência da Computação.

O objetivo é aplicar conceitos fundamentais de programação, estruturas de dados, ponteiros e gerenciamento de memória, consolidando os conhecimentos adquiridos ao longo da graduação.

---

## Tecnologias Utilizadas

- **Linguagem:** C
- **Compilador:** GCC
- **Editor:** Visual Studio Code
- **Sistema Operacional:** Windows

## Estrutura do Repositório

```text
estruturas-de-dados-em-c/
|
|-- fila/
|   |-- fila.c
|
|-- pilha/
|   |-- pilha.c
|
|-- README.md
```

## Projetos Desenvolvidos

### 01. Fila Dinâmica (FIFO)

Implementação de uma fila dinâmica utilizando listas encadeadas, seguindo o princípio **FIFO (First In, First Out)**, no qual o primeiro elemento inserido é o primeiro a ser removido.

#### Funcionalidades

- Inicialização de uma fila vazia.
- Inserção de cinco números inteiros.
- Exibição dos elementos armazenados.
- Remoção dos elementos seguindo a ordem FIFO.
- Verificação de fila vazia.
- Liberação da memória alocada dinamicamente.

#### Conceitos Aplicados

- Estruturas (`struct`).
- Ponteiros e listas encadeadas.
- Alocação dinâmica de memória (`malloc`).
- Liberação de memória (`free`).
- Manipulação de nós.
- Funções e estruturas de repetição.

### 02. Pilha Dinâmica (LIFO)

Implementação de uma pilha dinâmica utilizando listas encadeadas, seguindo o princípio **LIFO (Last In, First Out)**, no qual o último elemento inserido é o primeiro a ser removido.

#### Funcionalidades

- Inicialização de uma pilha vazia.
- Inserção de cinco números inteiros (Push).
- Exibição dos elementos do topo até a base.
- Remoção dos elementos seguindo a ordem LIFO (Pop).
- Verificação de pilha vazia.
- Liberação da memória alocada dinamicamente.

#### Conceitos Aplicados

- Estruturas (`struct`).
- Ponteiros e listas encadeadas.
- Alocação dinâmica de memória (`malloc`).
- Liberação de memória (`free`).
- Manipulação de nós e ponteiro para o topo.
- Funções e estruturas de repetição.

## Como Executar

### Pré-requisitos

É necessário possuir o compilador **GCC** instalado e configurado no sistema.

### Compilação

Clone o repositório:

```bash
git clone https://github.com/thurtavares/estruturas-de-dados-em-c.git
```

Acesse o diretório:

```bash
cd estruturas-de-dados-em-c
```

#### Fila Dinâmica (FIFO)

Compile o programa:

```bash
gcc fila/fila.c -o fila.exe
```

Execute no Windows:

```powershell
.\fila.exe
```

#### Pilha Dinâmica (LIFO)

Compile o programa:

```bash
gcc pilha/pilha.c -o pilha.exe
```

Execute no Windows:

```powershell
.\pilha.exe
```

## Exemplo de Execução

### Fila Dinâmica (FIFO)

```text
Digite 5 números inteiros:
Número 1: 10
Número 2: 20
Número 3: 30
Número 4: 40
Número 5: 50

Fila: 10 20 30 40 50

Removendo elementos da fila:
Elemento removido: 10
Elemento removido: 20
Elemento removido: 30
Elemento removido: 40
Elemento removido: 50
```

### Pilha Dinâmica (LIFO)

```text
Digite 5 números inteiros:
Número 1: 10
Elemento 10 empilhado na pilha.
Número 2: 20
Elemento 20 empilhado na pilha.
Número 3: 30
Elemento 30 empilhado na pilha.
Número 4: 40
Elemento 40 empilhado na pilha.
Número 5: 50
Elemento 50 empilhado na pilha.

Pilha (topo -> base): 50 40 30 20 10

Removendo elementos da pilha:
Elemento removido: 50
Elemento removido: 40
Elemento removido: 30
Elemento removido: 20
Elemento removido: 10

A pilha está vazia.
```

## Objetivo do Repositório

Este repositório tem como finalidade registrar minha evolução no aprendizado de estruturas de dados, por meio da implementação de exercícios práticos em linguagem C.

Novas implementações serão adicionadas conforme o avanço dos estudos, explorando diferentes estruturas e suas aplicações no desenvolvimento de software.

---

**Projeto desenvolvido para fins acadêmicos e de aprendizado.**

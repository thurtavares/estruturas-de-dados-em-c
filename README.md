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

Compile o programa:

```bash
gcc fila/fila.c -o fila.exe
```

Execute no Windows:

```powershell
.\fila.exe
```

## Exemplo de Execução

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

## Objetivo do Repositório

Este repositório tem como finalidade registrar minha evolução no aprendizado de estruturas de dados, por meio da implementação de exercícios práticos em linguagem C.

Novas implementações serão adicionadas conforme o avanço dos estudos, explorando diferentes estruturas e suas aplicações no desenvolvimento de software.

---

**Projeto desenvolvido para fins acadêmicos e de aprendizado.**

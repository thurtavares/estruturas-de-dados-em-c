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
|-- arvore-binaria-de-busca/
|   |-- arvore_binaria.c
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

### 03. Árvore Binária de Busca (BST)

Implementação de uma **Árvore Binária de Busca (Binary Search Tree — BST)** utilizando a linguagem C. A estrutura organiza os elementos de forma que os valores menores que um nó sejam armazenados à esquerda e os valores maiores, à direita.

O projeto explora operações fundamentais de manipulação de árvores, incluindo inserção, busca, remoção e diferentes formas de percorrer os nós.

#### Funcionalidades

- Inserção recursiva e iterativa de elementos.
- Busca de valores na árvore.
- Remoção de nós, considerando os diferentes casos de exclusão.
- Tratamento de chaves duplicadas por meio de um contador de ocorrências.
- Percursos em pré-ordem (Preorder), em ordem (Inorder) e pós-ordem (Postorder).
- Percurso por nível (Level Order), utilizando uma fila encadeada.
- Cálculo da altura da árvore.
- Validação das propriedades de uma Árvore Binária de Busca.
- Liberação da memória alocada dinamicamente.

#### Conceitos Aplicados

- Estruturas (`struct`) e tipos definidos com `typedef`.
- Ponteiros e estruturas de dados dinâmicas.
- Alocação e liberação de memória (`malloc` e `free`).
- Recursividade e funções iterativas.
- Árvores binárias e propriedades de uma BST.
- Filas encadeadas como apoio ao percurso por nível.
- Manipulação e remoção de nós.
- Validação de estruturas por meio de limites de valores.
- Análise da altura e organização dos elementos na árvore.

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

Execute no Windows, utilizando o terminal do VS Code:

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

#### Árvore Binária de Busca (BST)

Compile o programa:

```bash
gcc arvore-binaria-de-busca/arvore_binaria.c -o arvore_binaria.exe -Wall -Wextra
```

Execute no Windows:

```powershell
.\arvore_binaria.exe
```

## Exemplos de Execução

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

### Árvore Binária de Busca (BST)

Considerando a inserção dos valores `10`, `20`, `30`, `40` e `50`, nessa ordem, a árvore resultante fica inclinada à direita, pois cada novo valor é maior que o anterior.

```text
10
  \
   20
     \
      30
        \
         40
           \
            50
```

Exemplo dos percursos dessa árvore:

```text
Preorder:  10 20 30 40 50
Inorder:   10 20 30 40 50
Postorder: 50 40 30 20 10

Level Order: 10 20 30 40 50

Altura da árvore: 4
```

**Observação:** a altura é medida em arestas, considerando uma árvore com um único nó como altura `0` e uma árvore vazia como altura `-1`. A inserção dos valores em ordem crescente demonstra que uma BST comum pode se tornar desbalanceada.

## Objetivo do Repositório

Este repositório tem como finalidade registrar minha evolução no aprendizado de estruturas de dados, por meio da implementação de exercícios práticos em linguagem C.

Cada projeto representa uma oportunidade de aprofundar conhecimentos em lógica de programação, gerenciamento de memória, ponteiros e organização de dados, desenvolvendo gradualmente uma base sólida para a construção de software.

Novas implementações serão adicionadas conforme o avanço dos estudos, explorando diferentes estruturas de dados e suas aplicações.

---

**Projeto desenvolvido para fins acadêmicos e de aprendizado.**

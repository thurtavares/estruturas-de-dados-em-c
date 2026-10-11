#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct No {     // Estrutura de um nó
    int dado;
    struct No* proximo;
} No;

typedef struct Fila {     // Estrutura da fila
    No* frente;     // Ponteiro para o primeiro elemento da fila
    No* tras;     // Ponteiro para o ultimo elemento da fila
} Fila;

void inicializarFila(Fila* fila) {     // Função para inicializar a fila
    fila->frente = NULL;     // A função começa vazia, então frente e tras são NULL
    fila->tras = NULL;
}

int estaVazia(Fila* fila) {     // Função para verificar se a fila está vazia
    return (fila->frente == NULL);     // Se a frente da fila é NULL então a fila está vazia
}

void enfileirar(Fila* fila, int valor) {     // Função para inserir um novo elemento na fila (enqueue)
    No* novo = (No*)malloc(sizeof(No));     // Cria e aloca memória para um novo nó
    if (novo == NULL) {
        printf("Erro de alocação de memória. \n");
        exit(1); // Encerra o programa em caso de erro
    }

    novo->dado = valor;     // Define o valor do novo nó
    novo->proximo = NULL;     // Define que o próximo nó da fila sera NULL, pois o novo nó será o ultimo

    if (estaVazia(fila)) {     // Define que se a fila está vazia, o novo nó será a frente e o ultimo da fila
        fila->frente = novo;
        fila->tras = novo; 
    } else {     // Se a fila não estiver vazia adiciona o novo nó no final
        fila->tras->proximo = novo;
        fila->tras = novo;     // Atualiza o ponteiro 'tras'
    }

    printf("Elemento %d inserido na fila. \n", valor);     // Imprime o novo valor inserido na fila
}

int desenfileirar(Fila* fila) {     // Função para remover um elemento da fila, como é uma FILA, usamos o FIFO, ou seja, o primeiro elemento adicionado deve ser o primeiro removido
        if (estaVazia(fila)) {
            printf("Fila vazia, nada a remover. \n");
            return -1;     // Retorna um valor inválido, indicando erro
        } 

        No* temp = fila->frente;     // Nó temporário armazenando a frente
        int valor = temp->dado;     // Guarda o valor a ser retornado

        fila->frente = fila->frente->proximo;     // Move o ponteiro para o próximo nó

        if (fila->frente == NULL) {
            fila->tras = NULL;     // Se a fila ficar vazia, atualiza o 'tras' também
        }

        free(temp);     // Libera a memória do nó removido
        return valor;
    }

void exibirFila(Fila* fila) {     // Função para exibir a fila
        if (estaVazia(fila)) {
            printf("A fila está vazia. \n");
            return;
        }

    No* atual = fila->frente;     // Começa pela frente da fila

    printf("Fila: ");
    while (atual != NULL) {
        printf("%d ", atual->dado);     // Imprime o valor do nó atual
        atual = atual->proximo;     // Avança para o próximo nó
    }
    printf("\n");
}

void liberarFila(Fila* fila) {     // Função para liberar a memória da fila
    while (!estaVazia(fila)) {
        desenfileirar(fila);     // Remove todos os elementos da fila
    }
}

int main() {     // Função principal
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int numero;     // Declaração de uma variável do tipo inteiro
    Fila fila;     // Declaração de uma variável do tipo Fila
    inicializarFila(&fila);     // Inicializa a fila

    printf("Digite 5 numeros inteiros: \n");     // Solicita ao usuário os elementos que serão inseridos na fila
    printf("\n");

    for (int i = 0; i < 5; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numero);
        enfileirar(&fila, numero);
    }
    printf("\n");
    
    exibirFila(&fila);     // Exibe a fila com os novos elemento inseridos
    printf("\n");

    printf("Removendo elementos da fila: \n");     // Remove os elementos da fila seguindo a regra FIFO
        for (int i = 0; i < 5; i++) {
            int removido = desenfileirar(&fila);
            printf("Elemento removido: %d \n", removido);
        }
    printf("\n");

    liberarFila(&fila);     // Libera a memória alocada
    exibirFila(&fila);     // Informa se ainda existe algum elemento na fila
    return 0;
}

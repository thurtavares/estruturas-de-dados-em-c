#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct No {     // Estrutura de um nó
    int dado;
    struct No* proximo;
} No;

typedef struct Pilha {     // Estrutura da pilha
    No* topo;     // Ponteiro para o primeiro elemento do topo da pilha
} Pilha;

void inicializarPilha(Pilha* pilha) {     // Função para inicializar a pilha
    pilha->topo = NULL;     // A função começa vazia, então o topo é NULL
}

int estaVazia(Pilha* pilha) {     // Função para verificar se a pilha está vazia
    return (pilha->topo == NULL);     // Se o topo da pilha é NULL então a pilha está vazia
}

void empilhar(Pilha* pilha, int valor) {     // Função para empilhar um novo elemento na pilha (push)
    No* novo = (No*)malloc(sizeof(No));     // Cria e aloca memória para um novo nó
    if (novo == NULL) {
        printf("Erro de alocação de memória. \n");
        exit(1); // Encerra o programa em caso de erro
    }

    novo->dado = valor;     // Define o valor do novo nó
    novo->proximo = pilha->topo;     // Define que o novo nó da pilha aponta para o topo da pilha
    pilha->topo = novo; // Atualiza o topo da pilha para o novo nó

    printf("Elemento %d empilhado na pilha. \n", valor);     // Imprime o novo valor inserido na pilha
}

int desempilhar(Pilha* pilha) {     // Função para remover um elemento da pilha, como é uma PILHA, usamos o LIFO, ou seja, o último elemento adicionado deve ser o primeiro removido
        if (estaVazia(pilha)) {     // Verifica se a pilha está vazia
            printf("Pilha vazia, nada a remover. \n");
            return -1;     // Retorna um valor inválido, indicando erro
        } 

        No* temp = pilha->topo;     // Nó temporário armazenando o topo
        int valor = temp->dado;     // Guarda o valor a ser retornado

        pilha->topo = temp->proximo;     // Atualiza o topo para o próximo nó da pilha

        free(temp);     // Libera a memória do nó removido
        return valor;     // Retorna o valor removido
    }

void exibirPilha(Pilha* pilha) {     // Função para exibir a pilha
        if (estaVazia(pilha)) {    
            printf("A pilha está vazia. \n");
            return;
        }

    No* atual = pilha->topo;     // Começa pelo topo da pilha

    printf("Pilha (topo -> base): ");
    while (atual != NULL) {
        printf("%d ", atual->dado);     // Imprime o valor do nó atual
        atual = atual->proximo;     // Avança para o próximo nó
    }
    printf("\n");
}

void liberarPilha(Pilha* pilha) {     // Função para liberar a memória da pilha
    while (!estaVazia(pilha)) {
        desempilhar(pilha);     // Remove todos os elementos da pilha
    }
}

int main() {     // Função principal
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    int numero;     // Declaração de uma variável do tipo inteiro
    Pilha pilha;     // Declaração de uma variável do tipo Pilha
    inicializarPilha(&pilha);     // Inicializa a pilha

    printf("Digite 5 números inteiros: \n");     // Solicita ao usuário os elementos que serão inseridos na pilha
    printf("\n");

    for (int i = 0; i < 5; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numero);
        empilhar(&pilha, numero);
    }
    printf("\n");
    
    exibirPilha(&pilha);     // Exibe a pilha com os novos elemento inseridos
    printf("\n");

    printf("Removendo elementos da pilha: \n");     // Remove os elementos da pilha seguindo a regra LIFO
        for (int i = 0; i < 5; i++) {
            int removido = desempilhar(&pilha);
            printf("Elemento removido: %d \n", removido);
        }
    printf("\n");

    liberarPilha(&pilha);     // Libera a memória alocada
    exibirPilha(&pilha);     // Informa se ainda existe algum elemento na pilha
    return 0;
}

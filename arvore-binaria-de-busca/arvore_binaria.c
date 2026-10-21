#include <stdio.h>    // Inclui funções de entrada/saída
#include <stdlib.h>     // Inclui malloc, free e EXIT_SUCCESS
#include <stdbool.h>     // Inclui tipo bool, true e false
#include <limits.h> // Inclui os limites dos tipos inteiros
#include <windows.h>

typedef struct No {     // Definição da estrutura do nó de árvore binária
    int chave;     // Campo chave do nó
    int contador;     // Adiciona um contador aos nós
    struct No* esq;     // Ponteiro para filho esquerdo
    struct No* dir;     // Ponteiro para filho direito
} No;

No* criar_no(int chave) {     // Função para criar um novo nó com uma chave
    No* n = (No*)malloc(sizeof(No));     // Alocação de memória para um nó
    if (n == NULL) {     // Verifica se malloc falhou
        fprintf(stderr, "Memória insuficiente\n");     // Imprime erro
        exit(EXIT_FAILURE);     // Encerra o programa em erro
    }

    n->chave = chave;     // Define a chave do nó
    n->contador = 1;     // Inicia o contador do nó em 1
    n->esq = NULL;     // Inicializa ponteiro esquerdo
    n->dir = NULL;     // Inicializa ponteiro direito
    return n;     // Retorna ponteiro para o novo nó
}

No* inserir_bst(No* raiz, int chave) {     // Inserção em uma árvore binária de busca (recursiva)                                        
    if (raiz == NULL) {     // Caso base: árvore vazia
        return criar_no(chave);     // Cria e retorna novo nó como raiz
    }
    if (chave < raiz->chave) {     // Se a chave for menor, vai para a subárvore esquerda
        raiz->esq = inserir_bst(raiz->esq, chave);     // Recursivamente insere à esquerda
    } else if (chave > raiz->chave) {     // Se a chave for maior, vai para a subárvore direita
        raiz->dir = inserir_bst(raiz->dir, chave);     // Insere à direita
    } else {
        raiz->contador++;
    }
    return raiz;     // Retorna a raiz (inalterada)
}

No* inserir_bst_iterativo(No* raiz, int chave) {     // Função para inserção iterativa para BST (sem recursão)
    No* novo = criar_no(chave);     // Cria um novo nó
    if (raiz == NULL) {     // Se a árvore estiver vazia
        return novo;     // Retorna o novo nó como raiz
    }

    No* atual = raiz;     // Percorre a árvore procurando a posição de inserção
    No* pai = NULL;     // Guarda o pai do nó atual

    while (atual != NULL) {     // Percorre a árvore até encontrar uma posição vazia
        pai = atual;     // Guarda o nó atual como pai
        if (chave < atual->chave) {     // Se menor
            atual = atual->esq;     // Avança para a subarvore da esquerda
        } else if (chave > atual->chave) {     // Se maior
            atual = atual->dir;     // Avança para a subarcore da direita
        } else {     // Se ja existir
            atual->contador++;     // Aumenta o contador
            free(novo);      // Libera o nó
            return raiz;     // Retorna a raiz
        }
    }
    if (chave < pai->chave) {     // Se chave menor que a do pai
        pai->esq = novo;     // Insere novo como filho à esquerda
    } else {     // Se chave maior que a do pai
        pai->dir = novo;     // Insere novo como filho à direita
    }

    return raiz;     // Retorna raiz
}

bool validar_bst_aux(No* raiz, long long min, long long max) {     // Se a árvore ou subárvore estiver vazia, ela é válida
    if (raiz == NULL) {
        return true;
    }
    if (raiz->chave <= min || raiz->chave >= max) {     // Verifica se a chave está fora dos limites permitidos
        return false;
    }
    if (!validar_bst_aux(raiz->esq, min, raiz->chave)) {     // Valida a subárvore esquerda com limite máximo igual à chave atual
        return false;
    }
    if (!validar_bst_aux(raiz->dir, raiz->chave, max)) {     // Valida a subárvore direita com limite mínimo igual à chave atual
        return false;
    }
    return true;     // Todos os nós respeitam as regras da BST
}

bool validar_bst(No* raiz) {     // Utiliza limites amplos para aceitar qualquer valor do tipo int
    return validar_bst_aux(raiz, LLONG_MIN, LLONG_MAX);
}


No* buscar_bst(No* raiz, int chave) {     // Busca em BST (recursiva)
    if (raiz == NULL) {     // Se árvore vazia ou chegamos ao final
        return NULL;     // Retorna NULL (não encontrado)
    }

    if (chave == raiz->chave) {     // Se encontramos a chave
        return raiz;     // Retorna nó encontrado
    } else if (chave < raiz->chave) {     // Se menor, busca na subárvore esquerda
        return buscar_bst(raiz->esq, chave);     // Recursão esquerda
    } else {     // Se maior
        return buscar_bst(raiz->dir, chave);     // Recursão direita
    }
}

// Percursos recursivos: preorder, inorder, postorder
void preorder(No* raiz) {     // preorder: Visita nó, depois esquerda, depois direita // Imprime em preorder 
    if (raiz == NULL) return;     // Caso base: nada a fazer
    printf("%d ", raiz->chave);     // Visita o nó atual
    preorder(raiz->esq);     // Percorre subárvore esquerda
    preorder(raiz->dir);     // Percorre subárvore direita
}

void inorder(No* raiz) {     // inorder: Esquerda, nó, direita (em BST produz ordenação crescente) // Imprime em inorder
    if (raiz == NULL) return;     // Caso base
    inorder(raiz->esq);     // Esquerda
    printf("%d (x%d) ", raiz->chave, raiz->contador);     // Nó
    inorder(raiz->dir);     // Direita
}

void postorder(No* raiz) {     // postorder: Esquerda, direita, nó // Imprime em postorder
    if (raiz == NULL) return;     // Caso base
    postorder(raiz->esq);     // Esquerda
    postorder(raiz->dir);     // Direita
    printf("%d ", raiz->chave);     // Nó
}

typedef struct NoFila {     // Implementação de level-order (BFS) usando fila simples
    No* no_arvore;     // Ponteiro para nó da árvore
    struct NoFila* prox;     // Próximo elemento na fila
} NoFila;

typedef struct Fila {     // Fila encadeada
    NoFila* frente;   // Frente da fila
    NoFila* fim;    // Fim da fila
} Fila;

Fila* criar_fila() {     // Função para criar a fila vazia
    Fila* f = (Fila*)malloc(sizeof(Fila));     // Alocação de memória para a fila
    if (f == NULL) {     // Se fila vazia
        fprintf(stderr, "Memória Insuficiente\n");     // Imprime erro
        exit(EXIT_FAILURE);     // Encerra o programa com erro
    }
    f->frente = f->fim = NULL;     // Inicializa os ponteiros
    return f;     // Retorna a fila
}

void enfileirar(Fila* f, No* noa) {     // Função para enfileirar um nó da arvore
    NoFila* nf = (NoFila*)malloc(sizeof(NoFila));     // Alocação de memória
    if (nf == NULL) {     // Verifica alocação
        fprintf(stderr, "Memória Insuficiente\n");     // Imprime erro
        exit(EXIT_FAILURE);     // Encerra o programa com erro
    }
    nf->no_arvore = noa;     // Armazena ponteiro para nó da arvore
    nf->prox = NULL;     // Próximo é NULL
    if (f->fim == NULL) {     // Se fila vazia
        f->frente = f->fim = nf;     // Frente e fim apontam para novo
        return;
    }
    f->fim->prox = nf;     // Liga o último ao novo
    f->fim = nf;     // Atualiza o fim da fila
}

No* desenfileirar(Fila* f) {     // Função para desenfileirar e retornar ponteiro para nó da arvore
    if (f->frente == NULL) return NULL;     // Se vazia retorna NULL
    NoFila* temp = f->frente;     // Guarda a frente
    No* noa = temp->no_arvore;     // Obtém o nó da arvore
    f->frente = f->frente->prox;     // Avança para o próximo elemento
    if (f->frente == NULL) {     // Se a frente ficar vazia
        f->fim = NULL;     // O fim da fila também fica NULL
    }
    free(temp);     // Libera nó da fila
    return noa;     // Retorna no_arvore
}

bool fila_esta_vazia(Fila* f) {     // Verifica se a fila está vazia
    return (f->frente == NULL);     // Condição de fila vazia
}

void level_order(No* raiz) {     // Imprime por nível (level-order)
    if (raiz == NULL) return;     // Caso base
    Fila* f = criar_fila();     // Cria fila
    enfileirar(f, raiz);      // Enfileira raiz
    while (!fila_esta_vazia(f)) {     // Enquanto não estiver vazia
        No* atual = desenfileirar(f);     // Obtém nó atual
        printf("%d ", atual->chave);    // Imprime chave
        if (atual->esq != NULL) {     // Se filho esquerdo existe 
            enfileirar(f, atual->esq);     // Enfileira esquerda
        }
        if (atual->dir != NULL) {     // Se filho direito existe
            enfileirar(f, atual->dir);     // Enfleira direita
        }
    }

    free(f);     // Libera a estrutura fila
}

No* encontrar_min(No* raiz) {     // Função para encontrar o menor nó da subarvore (uso em remoção)
    No* atual = raiz;     // Começa pela raiz da subarvore
    while (atual != NULL && atual->esq != NULL) {     // Enquanto houver filho à esquerda 
        atual = atual->esq;     // Avança para o menor (sempre esquerda)
    }
    return atual;     // Retorna o menor nó encontrado
}

int altura_bst(No* raiz) { // Calcula a altura da árvore binária de busca
    if (raiz == NULL) { // Se a árvore ou subárvore estiver vazia
        return -1; // Retorna -1 para considerar a altura em arestas
    }

    int altura_esq = altura_bst(raiz->esq); // Calcula a altura da subárvore esquerda
    int altura_dir = altura_bst(raiz->dir); // Calcula a altura da subárvore direita

    if (altura_esq > altura_dir) { // Se a subárvore esquerda for mais alta
        return altura_esq + 1; // Retorna a altura esquerda mais a aresta atual
    } else { // Se a subárvore direita for maior ou igual
        return altura_dir + 1; // Retorna a altura direita mais a aresta atual
    }
}

// Remoção de nó em BST (casos: 0, 1 ou 2 filhos) - método recursivo
No* deletar_bst(No* raiz, int chave) {
    if (raiz == NULL) return NULL;     // Caso base: arvore vazia
    if (chave < raiz->chave) {     // Se menor deleta na subarvore da esquerda
        raiz->esq = deletar_bst(raiz->esq, chave);     // Recursão esquerda
    } else if (chave > raiz->chave) {     // Se maior deleta na subarvore da direita
        raiz->dir = deletar_bst(raiz->dir, chave);     // Recursão direita
    } else {     // Encontramos o nó a ser removido
        // Caso 1: Nó sem filhos, ou Caso 2: Um filho
        if (raiz->esq == NULL) {     // Se não tiver filho à esquerda
            No* temp = raiz->dir;     // Substitui pelo filho da direita (pode ser NULL)
            free(raiz);     // Libera o nó
            return temp;     // Retorna o substituto
        } else if (raiz->dir == NULL) {     // Se não tiver filho à direita
            No* temp = raiz->esq;     // Substitui pelo filho à esquerda
            free(raiz);     // Libera o nó
            return temp;     // Retorna o substituto
        }
        // Caso 3: Nó tem dois filhos
        No* temp = encontrar_min(raiz->dir);     // Encontrar sucessor inorder (menor da direita)
        raiz->chave = temp->chave;     // Copia a chave do sucessor para o nó atual
        raiz->dir = deletar_bst(raiz->dir, temp->chave);     // Deleta o sucessor na direita
    }
    return raiz;     // Retorna a raiz (possívelmente modificada)
}

void liberar_arvore(No* raiz) {     // Função para liberar toda a arvore (postorder)
    if (raiz == NULL) return;     // Caso base
    liberar_arvore(raiz->esq);     // Libera subarvore à esquerda
    liberar_arvore(raiz->dir);     // Libera subarvore à direita
    free(raiz);     // Libera o nó atual
}

int main(void) {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    No* raiz = NULL;
    int chaves[] = {10, 20, 30, 40, 50};
    int n = sizeof(chaves) / sizeof(chaves[0]);
    for (int i = 0; i < n; i++) {
        raiz = inserir_bst_iterativo(raiz, chaves[i]);
    }
    printf("Inorder (deve estar ordenado): ");
    inorder(raiz);
    printf("\n");
    printf("Preorder: ");
    preorder(raiz);
    printf("\n");
    printf("Postorder: ");
    postorder(raiz);
    printf("\n");
    printf("Level-order: ");
    level_order(raiz);
    printf("\n");
    printf("Altura da árvore: %d\n", altura_bst(raiz));
    if (validar_bst(raiz)) {
    printf("A árvore é uma BST válida.\n");
} else {
    printf("A árvore não é uma BST válida.\n");
}

    int alvo = 70;
    No* encontrado = buscar_bst(raiz, alvo);
    if (encontrado != NULL) {
        printf("Chave %d encontrada na árvore.\n", alvo);
    } else {
        printf("Chave %d não encontrada.\n", alvo);
    }

    raiz = deletar_bst(raiz, 50);
    printf("Inorder após remover 50: ");
    inorder(raiz);
    printf("\n");

    liberar_arvore(raiz);
    return 0;
}

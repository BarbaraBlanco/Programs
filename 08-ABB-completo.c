#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
    int valor;
    struct arvore* esq;
    struct arvore* dir;
} Arvore;

Arvore* cria_no(int valor) {
    Arvore* novo = (Arvore*)malloc(sizeof(Arvore));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

Arvore* inserir(Arvore* raiz, int valor) {
    if (raiz == NULL) {
        return cria_no(valor);
    }
    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
}

// Função para encontrar o menor valor em uma árvore binária de busca
Arvore* minimo(Arvore* raiz) {
    if (raiz == NULL || raiz->esq == NULL)
        return raiz;
    return minimo(raiz->esq);
}

Arvore* busca(Arvore* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor) {
        return raiz;
    }
    if (valor < raiz->valor) {
        return busca(raiz->esq, valor);
    } else {
        return busca(raiz->dir, valor);
    }
}

// Função para remover um valor na árvore de busca binária
Arvore* remover(Arvore* raiz, int valor) {
    if (raiz == NULL) {
        return NULL;
    }

    // Navega pela árvore para encontrar o nó a ser removido
    if (valor < raiz->valor) {
        raiz->esq = remover(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = remover(raiz->dir, valor);
    } else {
        // Encontrou o nó a ser removido

        // Caso 1: Nó sem filhos
        if (raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz);
            return NULL;
        }

        // Caso 2: Nó com apenas um filho
        if (raiz->esq == NULL) {
            Arvore* temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (raiz->dir == NULL) {
            Arvore* temp = raiz->esq;
            free(raiz);
            return temp;
        }

        // Caso 3: Nó com dois filhos
        // Encontra o menor valor na subárvore direita
        Arvore* temp = minimo(raiz->dir);

        // Substitui o valor do nó pelo valor do sucessor
        raiz->valor = temp->valor;

        // Remove o sucessor
        raiz->dir = remover(raiz->dir, temp->valor);
    }

    return raiz;
}

// Função para liberar a memória alocada pela árvore
void libera_arvore(Arvore* raiz) {
    if (raiz != NULL) {
        libera_arvore(raiz->esq);
        libera_arvore(raiz->dir);
        free(raiz);
    }
}

// Função para imprimir a árvore em ordem (in-order traversal)
void imprimir_em_ordem(Arvore* raiz) {
    if (raiz != NULL) {
        imprimir_em_ordem(raiz->esq);
        printf("%d ", raiz->valor);
        imprimir_em_ordem(raiz->dir);
    }
}

// Função principal (main) para testar o código
int main(void) {
    Arvore* raiz = NULL;

    // Inserindo valores na árvore
    int valores[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++) {
        raiz = inserir(raiz, valores[i]);
    }

    // Imprimindo a árvore em ordem
    printf("Árvore em ordem: ");
    imprimir_em_ordem(raiz);
    printf("\n");

    // Removendo alguns valores da árvore
    printf("Removendo o valor 50 (raiz com dois filhos):\n");
    raiz = remover(raiz, 50);
    printf("Árvore em ordem após remoção: ");
    imprimir_em_ordem(raiz);
    printf("\n");

    printf("Removendo o valor 20 (folha):\n");
    raiz = remover(raiz, 20);
    printf("Árvore em ordem após remoção: ");
    imprimir_em_ordem(raiz);
    printf("\n");

    printf("Removendo o valor 30 (nó com um filho):\n");
    raiz = remover(raiz, 30);
    printf("Árvore em ordem após remoção: ");
    imprimir_em_ordem(raiz);
    printf("\n");
    
    // Busca
    int busca_valores[] = {30, 60, 80};
    for (int i = 0; i < 3; i++) {
        int valor = busca_valores[i];
        Arvore* resultado = busca(raiz, valor);
        if (resultado != NULL)
            printf("Valor %d encontrado.\n", valor);
        else
            printf("Valor %d não encontrado.\n", valor);
    }

    libera_arvore(raiz);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>

typedef struct arv {
    char info;
    struct arv* esq;
    struct arv* dir;
} Arv;

Arv* cria_no(char c) {
    Arv* novo = (Arv*)malloc(sizeof(Arv));
    novo->info = c;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

int vazia(Arv* a) {
    return (a == NULL);
}

Arv* busca(Arv* a, char c) {
    if (vazia(a) || c == a->info)
        return a;

    Arv* esq = busca(a->esq, c);
    if (esq != NULL)
        return esq;
    else
        return busca(a->dir, c);
}

void libera_arvore(Arv* a) {
    if (a != NULL) {
        libera_arvore(a->esq);
        libera_arvore(a->dir);
        free(a);
    }
}

int main(void) {
    // Construção manual da árvore:
    //      A
    //     / \
    //    B   C
    //   / \   \
    //  D   E   F

    Arv* raiz = cria_no('A');
    raiz->esq = cria_no('B');
    raiz->dir = cria_no('C');
    raiz->esq->esq = cria_no('D');
    raiz->esq->dir = cria_no('E');
    raiz->dir->dir = cria_no('F');

    // Teste
    char c = 'E';
    Arv* resultado = busca(raiz, c);

    if (resultado != NULL)
        printf("Encontrado: %c\n", resultado->info);
    else
        printf("Caractere '%c' não encontrado\n", c);

    libera_arvore(raiz);

    return 0;
}


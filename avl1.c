#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *esq, *dir;
    short altura;
}No;

No* novoNo(int x)
{
    No *novo = malloc(sizeof(No));

    if(novo)
    {
        novo->valor = x;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->altura = 0;
    }
    else
        printf("Erro ao alocar no em novoNo...\n");
    return novo;
}

short maior(short a, short b)
{   // a, b -> altura de dois nós da arvore
    return (a > b)? a: b;
}

short alturaNo(No *no)
{   // Retorna a altura de um nó ou -1 caso ele seja null
    if(no == NULL)
        return -1;
    else
        return no->altura;
}

short balanceamento(No *no)
{   // calcula e retorna seu fator de balanceamento (negativo - pendendo para direita, positivo - pendendo para a esquerda)
    if(no)
        return (alturaNo(no->esq) - alturaNo(no->dir));
    else
        return 0;
}

// Rotação para a esquerda
No* rotacaoEsq(No *r)
{
    No *y, *f;

    y = r->dir;
    f = y->esq;

    y->esq = r;
    r->dir = f;

    r->altura = maior(alturaNo(r->esq), alturaNo(r->dir)) + 1;
    y->altura = maior(alturaNo(y->esq), alturaNo(y->dir)) + 1;

    return y;
}

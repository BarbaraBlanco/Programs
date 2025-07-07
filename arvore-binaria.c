#include <stdio.h>
#include <stdlib.h>

typedef struct arv
{
    int info;
    struct arv* esq;
    struct arv* dir;
} arv;

arv* inicializa(void);
arv* criaNo(int valor, arv* sae, arv* sad); // Função para criar um novo nó
arv* insere(arv* raiz, int valor); // Inserir novo nó na árvore
void emOrdem(arv* raiz); // Percorre na árvore em ordem
arv* busca(arv* raiz, int valor); // Função de busca

arv* inicializa(void)
{
    return NULL;
}

arv* criaNo(int valor, arv* sae, arv* sad)
{
    arv* p = (arv*)malloc(sizeof(arv));
    if (p != NULL)
    {
        p->info = valor;
        p->esq = sae;
        p->dir = sad;
    }
    return p;
}

arv* insere(arv* raiz, int valor)
{
    if (raiz == NULL)
    {
        return criaNo(valor, NULL, NULL);  // Passa NULL para as subárvores
    }

    if (valor < raiz->info)
    {
        // Insere na subárvore esquerda
        raiz->esq = insere(raiz->esq, valor);
    }
    else
    {
        // Insere na subárvore direita
        raiz->dir = insere(raiz->dir, valor);
    }
    return raiz;
}

void emOrdem(arv* raiz)
{
    if (raiz != NULL)
    {
        emOrdem(raiz->esq);
        printf("%d ", raiz->info);
        emOrdem(raiz->dir);
    }
}

// Função para buscar um valor na árvore binária
arv* busca(arv* raiz, int valor)
{
    if (raiz == NULL || raiz->info == valor)
    {
        return raiz;
    }
    if (valor < raiz->info)
    {
        return busca(raiz->esq, valor);
    }
    else
    {
        return busca(raiz->dir, valor);
    }
}

int main()
{
    arv* raiz = inicializa();

    // Inserir valores na árvore
    raiz = insere(raiz, 10);
    raiz = insere(raiz, 5);
    raiz = insere(raiz, 15);
    raiz = insere(raiz, 3);
    raiz = insere(raiz, 7);

     // Exibir a árvore em ordem
    printf("Percurso em-ordem: ");
    emOrdem(raiz);  // Corrigido o nome da função
    printf("\n");

    // Buscar um valor na árvore
    int valor = 7;
    arv* resultado = busca(raiz, valor);
    if (resultado != NULL)
    {
        printf("Valor %d encontrado na arvore.\n", valor);
    }
    else
    {
        printf("Valor %d nao encontrado na arvore.\n", valor);
    }

    return 0;
}
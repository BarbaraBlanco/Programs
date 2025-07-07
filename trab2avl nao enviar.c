#include <stdio.h>
#include <stdlib.h>

// Arvores AVL, implementaçao de Controle de Estoque 

typedef struct arv
{
    int codigoProduto;
    int qtdProduto;
    struct arv* esq;
    struct arv* dir;
}arv;

arv* raiz = NULL; // Apontar para o inicio (raiz) da arvore

// Funçoes
arv* criaNo(int codigoProduto, int qtdProduto);
arv* rotacaoDir(arv* y);
arv* rotacaoEsq(arv* x);
arv* insere(arv* no, int codigoProduto, int qtdProduto);
arv* remove(arv* raiz, int codigoProduto);
int buscaProduto(arv* raiz, int codigoProduto);
int altura(arv* no);
int balanceamento(arv* no);
void ordenado(arv* raiz);
void menu();


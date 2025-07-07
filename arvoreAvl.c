#include <stdio.h>
#include <stdlib.h>

typedef struct arv
{
    struct arv* esq;
    struct arv* dir;
}Arv;

Arv* inicializa(void);
Arv* cria(char valor, Arv* sae, Arv* sad);
int vazia(Arv* a);
void imprimir(Arv* a);

Arv* libera(Arv* a)
{
    if(!vazia(a)){
        libera(a->esq); // libera sae / esq
        libera(a->dir); // libera sad / dir
        free(a);        // libera raiz
    }
    return NULL;
}

/* 
Arv* cria(char valor, Arv* sae, Arv* sad)
{
    Arv * p=(Arv*)malloc(sizeof(Arv));
    p->info = valor;
    p->esq = sae;
    p->dir = sad;
    return p;
}
*/
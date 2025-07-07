#include <stdio.h>
#include <stdlib.h>


typedef struct arv {
    char info;
    struct arv* esq;
    struct arv* dir;
} Arv;

Arv* inicializa(void);
Arv* cria(char valor, Arv* sae, Arv* sad);
int vazia(Arv* a);
void imprime(Arv* a);
Arv* libera(Arv* a);

void pre_ordem(Arv* a);
void inordem(Arv* a);
void pos_ordem(Arv* a);

int main() {

    Arv* a1= cria('d',inicializa(),inicializa());
    Arv* a2= cria('b',inicializa(),a1);
    Arv* a3= cria('e',inicializa(),inicializa());
    Arv* a4= cria('f',inicializa(),inicializa());
    Arv* a5= cria('c',a3,a4);
    Arv* a = cria('a',a2,a5 );

    imprime(a);

    printf("\nPre-ordem: ");
    pre_ordem(a);

    printf("\nInordem: ");
    inordem(a);

    printf("\nPos-ordem: ");
    pos_ordem(a);

    a = libera(a);

    return 0;
}

Arv* inicializa(void) {
    return NULL;
}

Arv* cria(char valor, Arv* sae, Arv* sad) {
    Arv* p=(Arv*)malloc(sizeof(Arv));
    p->info = valor;
    p->esq = sae;
    p->dir = sad;
    return p;
}

int vazia(Arv* a) {
    return a==NULL;
}

void imprime (Arv* a) {
    if (!vazia(a)) {
        printf("%c ", a->info);
        imprime(a->esq);
        imprime(a->dir);
    }
}

Arv* libera (Arv* a){
    if (!vazia(a)){
        libera(a->esq); /* libera sae */
        libera(a->dir); /* libera sad */
        free(a);        /* libera raiz */
    }
    return NULL;
}

void pre_ordem (Arv* a) {
    if (!vazia(a)) {
        printf("%c ", a->info);
        pre_ordem(a->esq);
        pre_ordem(a->dir);
    }
}

void inordem (Arv* a) {
    if (!vazia(a)) {
        inordem(a->esq);
        printf("%c ", a->info);
        inordem(a->dir);
    }
}


void pos_ordem (Arv* a) {
    if (!vazia(a)) {
        pos_ordem(a->esq);
        pos_ordem(a->dir);
        printf("%c ", a->info);
    }
}

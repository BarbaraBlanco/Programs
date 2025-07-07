#include <stdlib.h>
#include <stdio.h>

typedef struct Tno_pilha
{
    int dado;
    struct no_pilha *prox;
}Tno_pilha;

int Inicializar_pilha      (Tno_pilha **p);
int Inicializar2_pilha     (Tno_pilha **p);
int Inserir_topo           (Tno_pilha **p, int info);
int Remover_topo           (Tno_pilha **p);
int Obter_topo             (Tno_pilha *p, int *dado);
int Verifica_vazio         (Tno_pilha *p, int *resp);

int crescente(Tno_pilha *p, int *resp)
{
    if(p==NULL){
        return 1; //pilha vazia
    };
    int dado_topo1, dado_topo2;
    Tno_pilha *p1, *p2;
    Inicializar_pilha(&p2);
    p1 = p;
    Obter_topo(p1, &dado_topo1);
    Obter_topo(p1, &dado_topo2);
    Remover_topo(&p1);

    while(p1 != NULL){
        Obter_topo(p1, &dado_topo1);
        Inserir_topo(&p2, dado_topo1);
        Obter_topo(p1, &dado_topo1);
        if(dado_topo1 >= dado_topo2){
            return 1; // pilha não é decrescente
        }
        else{
            dado_topo2 = dado_topo1;
        }
        Remover_topo(&p1);
    }

     while(p2 != NULL){
        Obter_topo(p2, &dado_topo1);
        Inserir_topo(&p1, dado_topo1);
        Remover_topo(&p2);
    }
    *resp = 1;
return 0;
}

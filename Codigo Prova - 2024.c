/*---------------------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
/*---------------------------------------------------------------------------*/

/* -----------------------------------------------------------------------------
Estrutura LISTA ENCADEADA SIMPLES- prova
------------------------------------------------------------------------------*/

struct no_ls {
	int dado;
	struct no_ls *prox;
};

typedef struct no_ls Tno_ls;

//===================================
typedef struct vetor
{
     int dado[5];
} T_vetor;

// ==================================
/* Tabela de codigo de erros
// 0 - sem erro
// 1 - ...
// 2 - ...
*/

/* -----------------------------------------------------------------------------
Prototipos das funcoes
------------------------------------------------------------------------------*/
int Inicializar_LS     (Tno_ls **inicio);
int Inicializar2_LS    (Tno_ls **inicio);
int Inserir_inicio_LS  (Tno_ls **inicio, int info);
int Inserir_fim_LS     (Tno_ls **inicio, int info);
int Inserir_meio_LS    (Tno_ls **inicio, int info, int pos);
int Remover_inicio_LS  (Tno_ls **inicio);
int Listar_LS          (Tno_ls *inicio);
int Obter_pos_LS       (Tno_ls *inicio, int dado, int *pos);
int Obter_Tamanho_LS   (Tno_ls *inicio, int *tam);

// ===================================== Compara
int Compara (Tno_ls *Ini_L, T_vetor v[], int *resp)
{
    int tam,i,j, achados;
    Tno_ls *percorre, *aux;
    if (Ini_L == NULL)
    {
        return 1;  // erro - lista vazia
    }
    // IMPORTANTE- CONSIDERANDO QUE NAO HA VALORES REPETIDOS
    Obter_Tamanho_LS (Ini_L, &tam);
    percorre = Ini_L;
    achados =0;
    for (i=1; i<=tam; i++)  // loop para a lista
    {
       for (j=0; j<=4; j++) // loop para o vetor
       {
           if (percorre->dado == v->dado[j])
              achados++;   // achado sim
       }
       //printf("achados = %d",achados);
       //system("pause");
       percorre = percorre->prox;
    }
    if (achados==tam)
        *resp = 1; // sim
    else
        *resp = 2; // nao
    return 0;
}

// ================================================= remove metade
int Remove_metade (Tno_ls **Ini_L)
{
    int tam,i;
    Tno_ls *percorre, *aux;

    if (*Ini_L == NULL)
    {
        return 1;  // erro - lista vazia
    }
    Obter_Tamanho_LS   (*Ini_L, &tam);
    if (tam%2 != 0)
    {   return 2;  // erro - lista de tamanho impar
    }

    percorre = *Ini_L;
    for (i=1; i<=(tam/2); i++)
    {
        aux = percorre;
        percorre = percorre->prox;
        free(aux);
    }
    *Ini_L = percorre;
    return 0;
}

// ========================================== Total de dados
int Total_entre (Tno_ls *Ini_L, int x, int y, int *total)
{
    Tno_ls *percorre;
    *total = 0;
    if (Ini_L==NULL)
    {
        *total = 0;
        return 0;
    }
    else
    {
        if (x==y)
            return 1; // erro - n�o forma um intervalo
        if (x>y)      // x tem que ser menor que y
            return 2; // erro - defini��o de intervalo
    }
    percorre = Ini_L;
    while (percorre != NULL)
    {
        if ((percorre->dado >=x)&&(percorre->dado<=y))
            (*total)++;
        percorre = percorre->prox;
    }
    return 0;
}



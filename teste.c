#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ESTRUTURA LISTA ENCADEADA SIMPLES

struct no_ls
{
    int dado;
    struct no_ls *prox;
};

typedef struct no_ls Tno_ls;

// Tabela de código de erros
// 0 = nenhum erro
// 1 = ...
// 2 = ...
// 3 = ...


// Protótipo das Funções 

int Inicializar_LS (Tno_ls **p_inicio);
int Inicializar2_LS (Tno_ls **p_inicio);
int Inserir_inicio_LS (Tno_ls **p_inicio, int info);
int Inserir_fim_LS (Tno_ls **p_inicio, int info);
int Inserir_meio_LS (Tno_ls **p_inicio, int info, int pos);
int Remover_inicio_LS (Tno_ls **p_inicio);
int Listar_LS (Tno_ls *c_inicio);
int Obter_pos_LS (Tno_ls *c_inicio, int dado, int *pos);
int Obter_tamanho_LS (Tno_ls *c_inicio, int *tam);
int Inverte_LS (Tno_ls **p_inicio);
int Inverte2_LS (Tno_ls **p_inicio);

int Repete_dado_LS (Tno_ls *c_inicio, int info, int *resp)
{
// Função Repete_dado_LS ----------------------------------------

    Tno_ls *percorre;
    int cont_repete = 0;

    if(c_inicio == NULL)
        return 10;
    else
    {
        percorre = c_inicio;
        while(percorre != NULL)
        {
            if(percorre -> dado == info)
                cont_repete++;
            percorre = percorre -> prox;
        }
    if(cont_repete>=2)
        *resp=1;
    else
        *resp=0;
    }
    return 0;
}

// Função Remover_meio_LS ----------------------------------------

int Remover_meio_LS(Tno_ls **p_inicio, int pos)
{
    Tno_ls *percorre, *anterior; //percorre pela lista
    int atual;
    if(*p_inicio != NULL)
    {
        atual = 0; 
        percorre = *p_inicio; //recebendo o endereço do primeiro nó da lista
        while(percorre != NULL)
        {
            anterior = percorre; //salvando o node atual
            percorre = percorre -> prox;
            // caso o indice seja igual ao pedido
            if(atual == pos)
            {
                free(anterior); //liberar ou excluir node escolhido
                return 0;
            }
            atual++; //incrementando o contador de indice
        }
    }
    else //caso for vazia
    {
        return 1;
    }
}

// Função Remover_fim_LS ----------------------------------------

int Remover_fim_LS(Tno_ls **p_inicio)
{
    Tno_ls *percorre, *anterior;

    if(*p_inicio != NULL)
    {
        percorre = *p_inicio;

        while(percorre != NULL)
        {
            anterior = percorre; //salvando o node atual
            percorre = percorre -> prox; //partindo para o proximo node
        }
        free(anterior); //liberar ou excluir o node escolhido
        return 0;
    }
    else //caso for vazia
    {
        return 1;
    }
}

/* FAZER int Obter_dado_LS      (Tno_ls *c_inicio, int pos, int *dado); */

int Maiorque_Dado_LS (Tno_ls *c_inicio, int info, int *quant);
/* obtem a quantidade de dados maior que info */

int Inverter2_LS (Tno_ls **p_inicio);
/* inverter a lista encadeada usando as rotinas prontas */


/* Variaveis globais:NENHUMA */


int main(void)
{
    int info, resp, pos;
    int erro; //valor de erro retornado pelas funções
    Tno_ls *ini;
    int q; //receber opção do usuário
    erro=Inicializar_LS(&ini);
    system("pause");
    do
    {
        system("cls");
        printf("LISTA ENCADEADA SIMPLES - LES");
        printf("\n\nOpcoes: \n\n");

        printf("1 -> Inserir no incio\n");
        printf("2 -> Inserir no final\n");
        printf("3 -> Remover no inicio\n");
        printf("4 -> Mostrar toda a lista\n");
        printf("5 -> Inicializar a lista (versao 2)\n");
        printf("6 -> Inverter a lista\n");
        printf("7 -> Verifica a repeticao de um dado\n");
        printf("9 -> Sair\n");
        scanf("%d", &q);
    switch(q)
    {
        case 1: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    erro=Inserir_inicio_LS (&ini, info);
                    if (erro == 0) printf("Insercao realizada com sucesso\n");
                    system("pause");
					break;
        case 10: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    printf("Posicao de insercao: ");
                    scanf("%d",&pos);
                    erro= Repete_dado_LS (&ini, info, &resp);
                    if (erro == 0)
                            printf("Insercao realizada com sucesso\n");
                    if (erro == 1)
                        printf("Dado%d repete\n", info);
                    system("pause");
					break;
		case 2: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    Inserir_fim_LS (&ini, info);
			        break;
        case 3: erro = Remover_inicio_LS (&ini);
                    if (erro==1)
                    {
                        printf("\nLista vazia. Impossivel remover");
                    }
                    system("pause");
                    break;
		case 4: erro=Listar_LS (ini);
                    if (erro==1)
                    {
                        printf("\nLista vazia. Impossivel listar");
                    }
                    system("pause");
					break;
		case 5: erro=Inicializar2_LS (&ini);
                    printf("\nInicializacao realizada com sucesso !\n");
                    printf("\nLISTA VAZIA !\n");
                    system("pause");
					break;
		case 6: erro=Inverte2_LS (&ini);
                    if (erro == 1)
                        printf("\nLista vazia. Inversao nao realizada !\n");
                    else
                        printf("\nInversao realizada !\n");
                    system("pause");
					break;
		case 7:
			        // FAZER
                    system("pause");
					break;
        case 8:
			        // FAZER
                    system("pause");
					break;
		case 9: break;
			default: printf("\n\n Opcao nao valida");
		}
		getchar();    /* Limpa o buffer de entrada */
    }while((q!=9));
}

// Função Listar todos elementos presentes na lista encadeada----------------------------------------

int Listar_LS(Tno_ls *c_inicio)
{
    int i;
    if(c_inicio == NULL)
    {
        return 1;
    }
    printf("Lista: ");
    while(c_inicio != NULL)
    {
        printf("%d ", c_inicio->dado);
        c_inicio = c_inicio->prox;
    }
    printf("\n");
    return 0;
}

// Função Inicializar ----------------------------------------

int Inicializar2_LS(Tno_ls **p_inicio)
{
    Tno_ls *percorre, *aux;
    if(*p_inicio != NULL)
    {
        percorre = *p_inicio;
        while(percorre != NULL)
        {
            aux = percorre;
            percorre = percorre -> prox;
            free(aux);
        }
        *p_inicio = NULL;
        return 1;
    }
    else
    {
        Inicializar_LS(p_inicio);
        return 0;
    }
}

// Função Obter Tamanho ----------------------------------------

int Obter_tamanho(Tno_ls *c_inicio, int *tam)
{
    Tno_ls *percorre;
    *tam = 0;
    if(c_inicio != NULL)
    {
        percorre = c_inicio;
        while(percorre != NULL)
        {
            (*tam)++;
            percorre = percorre -> prox;
        }
    }
    else
    {
        *tam = 0;
    }
}

// Função Inserir no Inicio ----------------------------------------

int Inserir_inicio_LS(Tno_ls **p_inicio, int info)
{
    Tno_ls *no_novo;
    no_novo = (Tno_ls *) malloc(sizeof(Tno_ls));
    no_novo -> dado = info;

    if(*p_inicio == NULL)
    {   //inserção na lista vazia
        no_novo -> prox = NULL;
        *p_inicio = no_novo;
    }
    else
    {   //inserção na lisa não vazia
        no_novo -> prox = *p_inicio;
        *p_inicio = no_novo;
    }
    return 0;
}

// Função Inserir no meio ----------------------------------------

int Inserir_meio_LS(Tno_ls **p_inicio, int info, int pos)
{
    int tam;
    Tno_ls *no_novo, *percorre;

    if(pos<=0)
        return 1;

    Obter_tamanho_LS(*p_inicio, &tam);
    if(pos > tam+1)
        return 2; //acima do tamanho da lista
    
    //Alocação do novo nó
    no_novo = (Tno_ls *) malloc(sizeof(Tno_ls));
    no_novo -> dado = info;

    //Procura pela posição de inserção
    if(pos==1)
    {   //inserção no inicio
        Inserir_inicio_LS(p_inicio, info);
    }
    else
    {
        int pos_aux=1;
        percorre = *p_inicio;
        while(pos_aux!=pos-1) //parar uma posição antes
        {
            percorre = percorre -> prox;
            pos_aux++;
        }
        no_novo -> prox = percorre -> prox;
        percorre -> prox = no_novo;
    }
    return 0;
}

// Função Inserir no Fim ----------------------------------------

int Inserir_fim_LS(Tno_ls **p_inicio, int info)
{
    Tno_ls *no_novo, *percorre;

    no_novo = (Tno_ls *)malloc(sizeof(Tno_ls));
    no_novo -> dado = info;
    no_novo -> prox = NULL;

    if(*p_inicio == NULL)
    {   // Lista vazia
        *p_inicio = no_novo;
    }
    else
    {   // Lista não vazia
        percorre = *p_inicio;
        while(percorre->prox != NULL)
        {
            percorre = percorre -> prox;
        }
        percorre -> prox =  no_novo;
    }
    return 0;
}

// Função Obter Pós ----------------------------------------

int Obter_pos_LS(Tno_ls *c_inicio, int valor, int *pos)
{
    *pos = 0;
    while(c_inicio != NULL)
    {
        (*pos)++;
        if(valor == c_inicio -> dado)
            return 0;
            c_inicio = c_inicio -> prox;
    }
    if(c_inicio != NULL)
        *pos=0;
    return 1;
}

// Função Remover Inicio ----------------------------------------

int Remover_inicio_LS(Tno_ls **p_inicio)
{
    Tno_ls *aux;
    if(*p_inicio == NULL)
    {
        printf("Lista Vazia, impossivel remover.\n");
        return 1;
    }
    else
    {
        aux = *p_inicio;
        *p_inicio = (*p_inicio) -> prox;
        free(aux);
        return 0;
    }
}

// Função Inverter Lista ----------------------------------------

int Inverte_LS(Tno_ls **p_inicio)
{
    Tno_ls *percorre, *aux1, *aux2, *aux3;
    percorre = *p_inicio;
    if(percorre == NULL)
    {
        return 1; //Lista vazia
    }
    else if(percorre -> prox == NULL)
    {
        return 0; //Lista possui apenas um nó
    }
    else
    {
        aux1 = *p_inicio;   /*O ponteiro aux1 aponta para o primeiro nó, uma vez que o ponteiro "ini" passa a apontar para o último. */
        aux2 = aux1->prox;  /*O ponteiro aux2 passa a apontar para o segundo nó da lista.*/
        aux3 = aux2->prox;  /*O ponteiro aux3 passa a apontar para o terceiro nó da lista.*/
        aux1->prox = NULL;  /*O primeiro nó da lista passa a ser o último, apontando para NULL.*/
        aux2->prox = aux1;  /*O segundo nó da lista passa a apontar para o primeiro, começando a inversão da lista.*/
                            /*Início - Processo de inversão.*/
        while(aux3!=NULL)
        {
            aux1 = aux2;             /*O ponteiro aux1 pega o valor do nó a sua frente na lista.*/
            aux2 = aux3;             /*O ponteiro aux2 pega o valor do nó a sua frente na lista.*/
            aux3 = aux3->prox;       /*O ponteiro aux3 pega o valor do nó a sua frente na lista.*/
            aux2->prox=aux1;         /*O nó para o qual aux3 está apontado passa a apontar para o nó anterior a ele na lista.*/
        }
                                    /*Fim - Processo de inversão. */
        *p_inicio = aux2;           /* atualização do ponteiro de início */
    }
    return 0;
}

// Função Inverter Lista (versão 2) ----------------------------------------

int Inverte2_LS(Tno_ls **p_inicio)
{
    int i, erro, tam, info;
    Tno_ls *inicio_lista_aux; //lista auxiliar

    erro = Obter_tamanho_LS(*p_inicio, &tam);
    if(tam==0)
    {
        return 1; //lista vazia
    }
    else if(tam==1)
    {
        return 0; //lista com apenas um nó
    }
    else
    {
        Inicializar_LS(&inicio_lista_aux);
        for(i=1;i<=tam;i++)
        {
            info=(*p_inicio) -> dado; //obtendo o dado do primeiro nó
            Obter_Dado_LS (p_inicio, 1, &info);
            Remover_inicio_LS (p_inicio);
            Inserir_inicio_LS (&inicio_lista_aux, info);
       }
       *p_inicio = inicio_lista_aux;
    }
    return 0;
}
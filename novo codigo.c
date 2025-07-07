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
            if(percorre -> dado == info);
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

// Função  ----------------------------------------

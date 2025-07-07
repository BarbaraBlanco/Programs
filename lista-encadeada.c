#include <stdio.h>
#include <stdlib.h>

// Função remove metade

typedef struct no_ls{
    int dado;
    struct no_ls *prox;
}Tno_ls;

int Remove_metade(Tno_ls **Ini_L){
    if(*Ini_L == NULL){
        return -1; //Lista vazia
    }

    // Contar o número de nós na lista
    int Total_nos = 0;
    Tno_ls *atual = *Ini_L;
    while(atual != NULL){
        Total_nos++;
        atual = atual -> prox;
    }

    if(Total_nos % 2 != 0){
        return -1; // Tamanho da lista não é par
    }

    // Calcular a metade do tamanho da lista
    int metade = Total_nos / 2;

    // Remover a primeira metade dos nós
    atual = *Ini_L;
    Tno_ls *temp;
    for(int i = 0; i < metade; i++){
        temp = atual;
        atual = atual -> prox;
        free(temp);
    }

    // Atualizar o início da lista para o novo início (a segunda metade)
    *Ini_L = atual;

return 0; // Sucesso
}

// Função total acima

int Total_acima(Tno_ls *ini_L, int x, int y, int *total){
    *total=0; //inicializa o contador

    Tno_ls *atual = ini_L; // ponteiro para percorrer a lista
    while(atual != NULL){
        if(atual->dado >= x && atual->dado <= y){
            (*total)++; // Incrementa o contador se o dado estiver no intervalo
        }
        atual = atual->prox; // Avança para o próximo nó
    }

    return *total; // Retorna o total de nós no intervalo
}

int main()
{
    Tno_ls *ini_L = NULL;
    Tno_ls *novo_no;
    int valores[] = {1, 3, 5, 4, 2, 10, 13, 11, 22, 6};
    int n = sizeof(valores) / sizeof(valores[0]);
    for(int i = 0; i < n; i++){
        novo_no = (Tno_ls *)malloc(sizeof(Tno_ls));
        novo_no->dado = valores[i];
        novo_no->prox = ini_L;
        ini_L = novo_no;
    }

    int x=5;
    int y=11;
    int total=0;

    // Chamando a função Total_acima
    Total_acima(ini_L, x, y, &total);

    printf("Total de nós com dados no intervalo [%d, %d]: %d\n", x, y, total);

    // Liberando a memória alocada para a lista encadeada
    Tno_ls *temp;
    while(ini_L != NULL){
        temp = ini_L;
        ini_L = ini_L->prox;
        free(temp);
    }

    return 0;
}
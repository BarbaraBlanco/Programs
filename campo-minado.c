#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Campo minado
typedef struct campo_minado{
    int bomba;
    int estaAberta;
    int vizinhos;

}campo_minado;

campo_minado jogo[10][10];
int linha, coluna, tam = 10;

// inicializar matriz

void inicializar()
{
    for(linha = 0; linha < tam; linha++){
        for(coluna = 0; coluna < tam; coluna++){
            jogo[linha][coluna].bomba = 0;
            jogo[linha][coluna].estaAberta = 0;
            jogo[linha][coluna].vizinhos = 0;
        }
    }
}

// sortear n bombas

void sortear_bombas(int n)
{
    srand(time(NULL));
    for(int i = 1; i <= n; i++){
        linha = rand() % tam;
        coluna = rand() % tam;
        if(jogo[linha][coluna].bomba == 0)
            jogo[linha][coluna].bomba = 1;
        else
            i--;
    }
}

int coordenada_valida(int linha, int coluna){
    if(linha >= 0 && linha < tam && coluna >= 0 && coluna < tam)
        return 1;
    else
        return 0;
}

// n = quantidade de bombas
int bombas_vizinhas(int linha, int coluna){
    int quantidade = 0;

    if(coordenada_valida(linha - 1, coluna) && jogo[linha-1][coluna].bomba)
        quantidade++;
    if(coordenada_valida(linha + 1, coluna) && jogo[linha+1][coluna].bomba)
        quantidade++;
    if(coordenada_valida(linha, coluna + 1) && jogo[linha][coluna+1].bomba)
        quantidade++;
    if(coordenada_valida(linha, coluna - 1) && jogo[linha][coluna-1].bomba)
        quantidade++;

    return quantidade;
}

//contar bombas vizinhas
void contar_bombas(){
    for(linha = 0; linha < tam; linha++){
        for(coluna = 0; coluna < tam; coluna++)
            jogo[linha][coluna].vizinhos = bombas_vizinhas(linha, coluna);
    }
}

void imprimir(){

    printf("\n\n\t   ");
    for(linha = 0; linha < tam; linha++)
        printf("%d   ", linha); // indice das colunas
    printf("\n\t  ---------------------------------------------\n");
    for(linha = 0; linha < tam; linha++){
        printf("\t%d  |", linha); // indices das linhas
        for(coluna = 0; coluna < tam; coluna++){
            if(jogo[linha][coluna].estaAberta){
                if(jogo[linha][coluna].bomba)
                printf(" * ");
            else
                printf(" %d ", jogo[linha][coluna].vizinhos);
        }
        else
            printf("   ");
        printf("|");
    }
    printf("\n\t  ---------------------------------------------\n");
    }
}

int main()
{
    inicializar();
    sortear_bombas(tam);
    contar_bombas();
    printf("\n\n\tCAMPO MINADO");
    imprimir();

return 0;
}

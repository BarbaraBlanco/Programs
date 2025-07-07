#include <stdio.h>

int main(){

    int vetor[5];

    printf("Digite os 5 elementos do vetor:\n");
    for(int i = 0; i<5; i++){
        printf("Elemento %d: ", i+1);
        scanf("%d", &vetor[i]);
    }

    int matriz[4][4];

    printf("\nDigite os elementos da matriz 4x4:\n");
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    int posicaoVetor;
    printf("\nDigite a posicao do vetor que deseja mostrar (de 0 a 4): ");
    scanf("%d", &posicaoVetor);

    if(posicaoVetor >= 0 && posicaoVetor < 5){
        printf("Elemento na posicao %d do vetor: %d\n", posicaoVetor, vetor[posicaoVetor]);
    } else{
        printf("Posicao invalida no vetor.\n");
    }

    int linhaMatriz, colunaMatriz;
    printf("\nDigite a posicao da matriz que deseja mostrar (linha e coluna): ");
    scanf("%d %d", &linhaMatriz, &colunaMatriz);

    if(linhaMatriz >= 0 && linhaMatriz < 5 && colunaMatriz >= 0 && colunaMatriz < 5){
        printf("Elemento na posicao [%d][%d] da matriz: %d\n", linhaMatriz, colunaMatriz, matriz[linhaMatriz][colunaMatriz]);
    } else {
        printf("Posicao invalida na matriz.\n");
    }





return 0; }
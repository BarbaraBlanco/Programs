#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[100];
    int menor, i;

    for(i=0; i<100; i++)
    {
        printf("Digite um valor do vetor: %d\n", i+1);
        scanf("%d", &vetor[i]);
    }

    menor = vetor[0];

    for(i=0; i<100; i++)
    {
        if(vetor[i] < menor){
            menor = vetor[i];
        }
    }

    printf("O menor valor do vetor: %d\n", menor);
    return 0;
}
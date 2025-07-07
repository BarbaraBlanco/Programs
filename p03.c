#include <stdio.h>

int main()
{
    int vet[5] = {45,34,11,87,44};
    int *pt = vet;
    int maior = *pt;

    for(int i=1;i<5;i++)
    {
        if(*(pt+i)>maior){
            maior = *(pt+i);
        }
    }
    printf("\nO maior numero do vetor eh: %d", maior);
}

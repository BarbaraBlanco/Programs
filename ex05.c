#include <stdio.h>

int main(){

int vet[2] = {40,32};
    int *pt = vet;
    int maior = *pt;
    int menor = *pt;

    for(int i=1;i<2;i++)
    {
        if(*(pt+i)>maior){
            maior = *(pt+i);
        }if(*(pt+i)<menor){
            menor = *(pt+i);
        }

    printf("\nO maior numero do vetor eh: %d", maior);

return 0;}}

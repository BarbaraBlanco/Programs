#include <stdio.h>

int main(){
    int vet[] = {1,2,3,4,5};
    int *p;
    p = vet;
    int soma = 0;
    for (int i = 0; i<5; i++)
    {
        soma+= *p;
        p++;
    }
    printf("\nSoma do vetor: %d", soma);




return 0;}

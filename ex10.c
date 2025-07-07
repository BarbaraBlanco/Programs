#include <stdio.h>

int main(){

        int num[5];

        for(int i=0; i<5; i++){
        printf("\nDigite cinco numeros inteiros: ");
        scanf("%d", &num[i]);
        }

        printf("\nO dobro dos resultados sera de: ");

        for(int j=0; j<5; j++){
        int *p = &num[j];
        *p = *p + *p;
        printf("\n%d", *p);
        }


return 0;}

#include <stdio.h>

int main(){

    int a; int b;
    printf("\nDigite um valor inteiro para A: ");
    scanf("%d",&a);
    printf("\nDigite um valor inteiro para B: ");
    scanf("%d",&b);
    int *pA = &a;
    int *pB = &b;
    *pA = a + a;
    *pB = b + b;

    printf("\nOs valores de A e de B dobrados serao de: %d e %d", *pA, *pB);

return 0;}

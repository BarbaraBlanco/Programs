#include <stdio.h>

int soma(int *p, int b)
{
    *p = *p + b;
    return *p;
}

int main(){
    int a, b;
    printf("Digite um valor inteiro para A: ");
    scanf("%d", &a);
    printf("Digite um valor inteiro para B: ");
    scanf("%d", &b);

    int resultado = soma(&a, b);

    printf("O resultado final de A sera de: %d\n",resultado);

return 0;}

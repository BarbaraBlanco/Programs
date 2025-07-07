#include <stdio.h>

void soma();

int main(){

        soma();

return 0;
void soma()
{
int a, b, soma;
printf("Digite um numero inteiro: ");
scanf("%d", &a);
printf("Digite outro numero inteiro: ");
scanf("%d", &b);
soma = a + b;
printf("Soma sera de: %d", soma);
}
}

//Programa para trocar valores de variáveis
#include <stdio.h>

int main(){
int a = 5; int b = 10;
int *pA, *pB;
pA = &a; pB = &b;
printf("\n%d",&a);
printf("\n%d",&b);
printf("\n%d",pA);
printf("\n%d",pB);
int temp = *pA;///armazenando em temp valor de a = 5
*pA = *pB;///salvando o valor de b  em a => entao a = 10
*pB = temp; ///salvando o valor de temp (a) em b => entao b = 5
printf("\n%d",a);
printf("\n%d",b);

return 0;
}

///fazer uma calculadora de quatro operações
#include <stdio.h>

void adicao(int *r, int a, int b) {*r = a + b;}
void subtracao(int *r,int a, int b) {*r = a - b;}
void multiplicacao(int *r,int a, int b) {*r = a * b;}
void divisao(int *r,int a, int b) {*r = a / b;}


int main(){

int num1, num2;
int resultado;
char op;
char operador; /// + - * /

printf("\nDigite um numero: ");
scanf("%d",&num1);
printf("\nDigite outro numero: ");
scanf("%d",&num2);
printf("\nDigite o operador (1-soma, 2-subtracao, 3-multiplicacao, 4-divisao): ");
scanf(" %c",&op);

switch(op) {
   case '1':
       adicao(&resultado,num1,num2);
       printf("Soma: %d",resultado);
       break;
   case '2':
       subtracao(&resultado,num1,num2);
       printf("Subtracao: %d",resultado);
       break;
   case '3':
       multiplicacao(&resultado,num1,num2);
       printf("Multiplicacao: %d",resultado);
       break;
   case '4':
       divisao(&resultado,num1,num2);
       printf("Divisao: %d",resultado);
       break;
   default:
       printf("Operador invalido.");
       break;
}



return 0;
}

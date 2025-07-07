#include <stdio.h>

void soma(); ///assinatura da função
int par();
float potencia();

int main()
{
    float z;
    z = potencia();
    printf("\nPotencia: %0.1f", z);
    int x;
    //soma();
    x = par();
    if (x == 0){
        printf("par");
    }
    else{
        printf("impar");
    }
    return 0;
}

float potencia(){
    float e, b, potencia;
    printf("\nDigite o valor da base: ");
    scanf("%f", &e);
    printf("\nDigite o expoente: ");
    scanf("%f", &b);
    potencia = pow(e,b);
    return potencia;}


int par(){
    int n, r;
    printf("\nDigite um numero inteiro: ");
    scanf("%d",&n);
    r = n % 2;
    return r;
}

void soma(){
  int a, b, s;
  printf("\nDigite um numero inteiro:");
  scanf("%d",&a);
  printf("\nDigite outro numero inteiro:");
  scanf("%d",&b);
  s = a + b;
  printf("\nSoma: %d",s);
}


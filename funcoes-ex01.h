#ifndef HEADER-EX01_H_INCLUDED
#define HEADER-EX01_H_INCLUDED

int soma()
{
    int a, b, s;
    printf("\nDigite um numero inteiro: ");
    scanf("%d",&a);
    printf("\nDigite outro numero inteiro: ");
    scanf("%d",&b);
    s = a + b;
    printf("\nSoma: %d",s);
}

float divisao()
{
    float a, b, d;
    printf("\nDigite um numero inteiro: ");
  scanf("%f",&a);
  printf("\nDigite outro numero inteiro: ");
  scanf("%f",&b);
   d = a / b;
  printf("\nDivisao: %0.2f",d);

}

int multiplicacao()
{
    int a, b, m;
    printf("\nDigite um numero inteiro: ");
  scanf("%d",&a);
  printf("\nDigite outro numero inteiro: ");
  scanf("%d",&b);
    m = (a * b);
  printf("\nMultiplicacao: %d", m);
}

int subtracao()
{
    int a, b, s;
    printf("\nDigite um numero inteiro: ");
    scanf("%d",&a);
    printf("\nDigite outro numero inteiro: ");
    scanf("%d",&b);
    s = a - b;
    printf("\nSubtracao: %d",s);
}

#endif // HEADER-EX01_H_INCLUDED

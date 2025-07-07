#include <stdio.h>
#include <math.h>

void main()
{
int i, j;
int num, dig[5];

printf("Digite um numero: ");
scanf("%i", &num);

for(i=0; num; i++)
 {
  dig[i] = num % 10;
  num /= 10;
 }

for(j=0; j<i; j++)
 { num += dig[j] * pow(10, (i-j-1)); }

printf("Num. invertido: %i", num);

}

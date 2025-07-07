#include <stdio.h>
#include <stdlib.h>
main ()
{
float media, nota1, nota2;
printf ("Digite a nota da prova 1: ");
scanf ("%f", &nota1);

printf("Digite a nota da prova 2: ");
scanf ("%f", &nota2);

media = (nota1+nota2)/2;
printf ("A media e: %f", media);

}

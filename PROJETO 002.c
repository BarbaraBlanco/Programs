#include <stdio.h>
#include <stdlib.h>

int main () {
    int a, b, s;

    printf ("\nDIGITE O VALOR DE A: \t");
    scanf ("%d", &a);

    printf ("\nDIGITE O VALOR DE B: \t");
    scanf ("%d", &b);

    if (a != b) {
        printf ("\nNumeros diferentes");
        s=1;
        } else {
        printf ("\nNumeros iguais");
        }

return 0;
}

#include <stdlib.h>
#include<stdio.h>

int main () {

    int num, sucessor, antecessor;
    printf (" Digite um numero inteiro: ");
    scanf ("%d", &num);
    sucessor = num + 1;
    antecessor = num - 1;
    printf (" Sucessor: %d", sucessor);
    printf (" Antecessor: %d", antecessor);
    return 0;
}

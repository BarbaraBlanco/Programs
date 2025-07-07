#include <stdio.h>
#include <stdlib.h>

int main () {

    int a, b, h;
    printf (" Digite um valor para A: ", a);
    scanf ("%d", &a);
    printf (" Digite um valor para B: ", b);
    scanf ("%d", &b);
    h = sqrt(a*a+b*b);
    printf (" O valor de hipotenusa sera: %d", h);
    return 0;
}

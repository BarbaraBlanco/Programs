#include <stdio.h>
#include <stdlib.h>
#include <math.h>

    int main () {

    float a, b, h;
    printf (" digite os valores dos catetos: ");
    scanf ("%f%f", &a, &b);
    h = pow(pow(a,2) + pow(b,2),0.5);
    printf (" a hipotenusa dos catetos %0.1f e %0.1f - %0.1f", a, b, h);

    }

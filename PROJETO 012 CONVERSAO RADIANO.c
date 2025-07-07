#include <stdio.h>
#include <stdlib.h>

float main () {

    float g, r, pi;
    pi=3.1415;
    printf (" Digite um valor para graus: ");
    scanf ("%f", &g);
    r = g*pi/180;
    printf (" Em radiano sera: %f", r);

    return 0;
}

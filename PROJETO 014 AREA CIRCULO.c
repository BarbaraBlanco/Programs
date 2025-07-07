#include <stdio.h>
#include <stdlib.h>

float main () {

    float pi, raio, area;
    pi=3.14;
    printf (" Determine o raio do circulo: ", raio);
    scanf ("%f", &raio);
    area = pi*(raio*raio);
    printf (" A area do circulo sera: %f", area);
    return 0;
}

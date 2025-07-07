#include <stdio.h>
#include <stdlib.h>

float main () {

    float k, m;
    printf (" Digite uma velocidade em km: ");
    scanf ("%f", &k);
    m = k/3.6;
    printf (" A velocidade convertida em metros por sec e: %f", m);

    return 0;
}

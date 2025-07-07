#include <stdio.h>
#include <stdlib.h>

float main () {

    float real, usd;
    printf (" Digite um valor em real: ");
    scanf ("%f", &real);
    usd = real/5;
    printf (" Em dolar o valor sera: %f", usd);

    return 0;
}

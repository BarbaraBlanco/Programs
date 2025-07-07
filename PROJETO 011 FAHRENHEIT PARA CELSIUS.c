#include <stdio.h>
#include <stdlib.h>

float main () {

    float f, c;
    printf (" Digite um valor para celsius: ");
    scanf ("%f", &c);
    f = c*(9.0/5.0) + 32.0;
    printf (" Em fahrenheit sera: %f", f);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

float main () {
    float num, quinta;
    printf (" Digite um numero real: ");
    scanf ("%f", &num);
    quinta = num / 5;
    printf (" A quinta parte do numero %0.1f e: %0.1f", num,quinta);


    return 0;
}

#include <stdio.h>
#include <stdlib.h>

float main () {

    float g1, g2, g3, p;
    p=780000.00;
    g1 = (p*0.46);
    g2 = (p*0.32);
    g3 = (p*0.22);
    printf (" O ganhador 1 recebera: %f", g1);
    printf (" O ganhador 2 recebera: %f", g2);
    printf (" O ganhador 3 recebera: %f", g3);
    return 0;
}

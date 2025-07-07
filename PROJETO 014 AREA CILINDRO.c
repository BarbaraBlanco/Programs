#include <stdio.h>
#include <stdlib.h>

float main () {

    float pi, raio, volume, altura;
    pi=3.14;
    printf (" Determine o raio do cilindro: ", raio);
    scanf ("%f", &raio);
    printf (" Determine a altura do cilindro: ", raio);
    scanf ("%f", &altura);
    volume = pi*(raio*raio)*altura;
    printf (" O volume do cilindro sera: %f", volume);
    return 0;
}

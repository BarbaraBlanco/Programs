#include <stdio.h>
#include <stdlib.h>

typedef struct coordenada
{
    double x, y;
}coordenada;

void imprime_coordenada(coordenada);
coordenada leCoordenada();
coordenada somaCoordenada(coordenada, coordenada);
coordenada multiCoordenada(coordenada, float);

int main()
{
    coordenada c1, c2, cSoma, cMulti;

    printf("Coordenada 1: \n");
    c1 = leCoordenada();
    printf("Coordenada 2: \n");
    c2 = leCoordenada();

    printf("Corrdenada 1: \n");
    imprime_coordenada(c1);
    printf("Coordenada 2: \n");
    imprime_coordenada(c2);

    cSoma = somaCoordenada(c1, c2);
    printf("Coordenada somada: ");
    imprime_coordenada(cMulti);

    return 0;
}

void imprimeCoordenada(coordenada coord)
{
    printf("(%.1f, %.1f)\n", coord.x, coord.y);
}

coordenada leCoordenada()
{
    coordenada aux;

    printf("Digite o valor de X: ");
    scanf("%f", &aux.x);
    printf("Digite o valor de Y: ");
    scanf("%f", &aux.y);

    return aux;
}

coordenada somaCoordenada(coordenada coord1, coordenada coord2)
{
    coordenada aux;

    aux.x = coord1.x + coord2.x;
    aux.y = coord1.y + coord2.y;

    return aux;
}

coordenada multiCoordenada(coordenada coord, float numero)
{
    coordenada aux;

    aux.x = coord.x + numero;
    aux.y = coord.y + numero;

    return aux;
}
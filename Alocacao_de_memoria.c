#include <stdlib.h>
#include <stdio.h>

typedef struct pessoa {
	int peso;
	float altura
} T_Pessoa;


main( )
{
    /* =====================  Aloca��o est�tica */
    T_Pessoa p1, p2;
    T_Pessoa vp [10];

    p1.peso = 89;
    p1.altura = 1.89;

    vp[0].peso = 90;
    vp[0].altura = 1.69;

    printf("peso = %d\n",vp[0].peso);

    /* ======================= Aloca��o din�mica */

    T_Pessoa *py, *px, *pz;
    int i;

    printf("Tamanho = %d\n",sizeof(float));

    px = (T_Pessoa *) malloc (sizeof(T_Pessoa));
    py = (T_Pessoa *) malloc (sizeof(T_Pessoa));

    px -> peso = 89;
    px -> altura = 1.98;
    (*px).peso = 89;

    py -> peso = 69;
    py -> altura = 1.70;

    free(px);
    printf("peso = %d\n",px->peso);

    //malloc = A fun��o malloc (o nome � uma abreviatura
    //de memory allocation) aloca espa�o para um bloco de
    //bytes consecutivos na mem�ria RAM (= random access memory)
    //do computador e devolve o endere�o desse bloco.
}












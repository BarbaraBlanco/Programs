#include <stdlib.h>
#include <stdio.h>

typedef struct pessoa {
	int peso;
	float altura
} T_Pessoa;


main( )
{
    /* =====================  Alocação estática */
    T_Pessoa p1, p2;
    T_Pessoa vp [10];

    p1.peso = 89;
    p1.altura = 1.89;

    vp[0].peso = 90;
    vp[0].altura = 1.69;

    printf("peso = %d\n",vp[0].peso);

    /* ======================= Alocação dinâmica */

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

    //malloc = A função malloc (o nome é uma abreviatura
    //de memory allocation) aloca espaço para um bloco de
    //bytes consecutivos na memória RAM (= random access memory)
    //do computador e devolve o endereço desse bloco.
}












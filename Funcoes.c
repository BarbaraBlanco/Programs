#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int funcao_A(int *b)
{
    printf("a = %d\n", *b);
    printf("b (endereco) = %d\n", b);
    printf("a (alterado) = %d\n", (*b)+1);
    *b = *b + 1;
    return 0;
}

main()
{
    int a =1;
    int c;
    c = funcao_A(&a);
    printf("a (final) = %d\n", a);
}

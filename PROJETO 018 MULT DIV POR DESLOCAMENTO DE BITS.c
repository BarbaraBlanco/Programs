#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    int mult = num << 1;
    printf("Multiplica��o por 2: %d\n", mult);

    int div = num >> 1;
    printf("Divis�o por 2: %d\n", div);

    return 0;
}

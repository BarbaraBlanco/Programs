#include <stdio.h>

int main() {
    int vetor[5];

    for (int i = 0; i < 5; i++) {
        printf("Digite um valor para a posição %d do vetor: ", i);
        scanf("%d", &vetor[i]);
    }

    int *p = vetor;
    printf("Os numeros digitados foram: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *p);
        p++;
    }

    return 0;
}

#include <stdio.h>

int main() {
    int num[5];

    for (int i = 0; i < 5; i++) {
        printf("Digite um numero inteiro: ");
        scanf("%d", &num[i]);
    }

    printf("\nEnderecos das posicoes que contem valores pares: ");

    for (int j = 0; j < 5; j++) {
        if (num[j] % 2 == 0) {
            printf("Valor: %d\n", num[j]);
        }
    }

    return 0;
}

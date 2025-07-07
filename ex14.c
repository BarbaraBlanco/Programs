#include <stdio.h>

void preencherArray(int *array, int tamanho, int valor) {
    int *ptr = array;

    while (ptr < array + tamanho) {
        *ptr = valor;
        ptr++;
    }
}

int main() {
    int meuArray[5];
    int tamanhoArray = sizeof(meuArray) / sizeof(meuArray[0]);
    int valorPreenchimento = 42;

    preencherArray(meuArray, tamanhoArray, valorPreenchimento);

    printf("Array preenchido com %d:\n", valorPreenchimento);
    for (int i = 0; i < tamanhoArray; i++) {
        printf("%d ", meuArray[i]);
    }

    return 0;
}

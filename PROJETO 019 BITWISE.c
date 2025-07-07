#include <stdio.h>
int main() {
    int num;
    printf("Digite um numero inteiro: ");
    scanf("%d", &num);
    int comp = ~num;

    printf("Complemento bit a bit: %d\n", comp);

    return 0;
}

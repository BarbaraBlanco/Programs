#include <stdio.h>
#include <math.h>
void operacao();

int main() {
    int a, b, r;
    char operacao;

    printf("Digite um numero: ");
    scanf("%d", &a);

    printf("Digite outro numero: ");
    scanf("%d", &b);

    printf("Digite a operacao (1 para soma, 2 para verificar se um numero e par, 3 para potencia, 4 para encerrar): ");
    scanf(" %c", &operacao);
    if (operacao == '1') {
        r = a + b;
        printf("O resultado da soma sera: %d\n", r);
    } else if (operacao == '2') {
        if (a % 2 == 0) {
            printf("O numero %d eh par.\n", a);
        } else {
            printf("O numero %d eh impar.\n", a);
        }
        if (b % 2 == 0) {
            printf("O numero %d eh par.\n", b);
        } else {
            printf("O numero %d eh impar.\n", b);
        }
    } else if (operacao == '3') {
        r = pow(a, b);
        printf("O resultado da potencia sera: %d\n", r);
    } else if (operacao == '4') {
        printf("Encerrar operacao!\n");
    } else {
        printf("Operacao invalida.\n");
    }

    return 0;
}

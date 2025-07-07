#include <stdio.h>

int main(){
    int num[3];

    for (int i = 0; i < 3; i++) {
        printf("Digite um número inteiro: ");
        scanf("%d", &num[i]);
    }

    for (int i = 0; i < 3 - 1; i++) {
        for (int j = 0; j < 3 - i - 1; j++) {
            if (num[j] > num[j + 1]) {
                int temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }
    int *p = num;

    printf("A sequencia dos tres numeros de menor para maior eh: %d, %d, %d\n", p[0], p[1], p[2]);

    return 0;
}

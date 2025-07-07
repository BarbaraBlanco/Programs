#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;
    int tamanho_inicial = 5, novo_tamanho;
    
    // Alocando memória inicial para 5 inteiros
    array = malloc(tamanho_inicial * sizeof(int));
    if (array == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Preenche o vetor
    for (int i = 0; i < tamanho_inicial; i++) {
        array[i] = i + 1;
    }
    
    printf("Vetor inicial:\n");
    for (int i = 0; i < tamanho_inicial; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Solicitar um novo tamanho
    printf("Digite o novo tamanho do vetor: ");
    scanf("%d", &novo_tamanho);

    // Realocando com segurança
    int *temp = realloc(array, novo_tamanho * sizeof(int));
    if (temp == NULL) {
        printf("Erro ao redimensionar a memória!\n");
        free(array); // Liberando memória original, pois realloc falhou
        return 1;
    } else {
        array = temp; // Se bem-sucedido, aponta para o novo bloco de memória
    }

    // Preenche novos elementos, se o novo tamanho for maior
    if (novo_tamanho > tamanho_inicial) {
        for (int i = tamanho_inicial; i < novo_tamanho; i++) {
            array[i] = i + 1;
        }
    }

    printf("Vetor redimensionado:\n");
    for (int i = 0; i < novo_tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Liberar memória
    free(array);

    return 0;
}

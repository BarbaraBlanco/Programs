#include <stdio.h>

// Função para realizar o Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    
    // Laço externo para percorrer o array
    for (i = 0; i < n - 1; i++) {
        // Laço interno para realizar comparações e trocas
        for (j = 0; j < n - i - 1; j++) {
            // Troca os elementos se estiverem na ordem errada
            if (arr[j] > arr[j + 1]) {
                // Troca os elementos
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);  // Determina o tamanho do array

    printf("Array original: \n");
    printArray(arr, n);

    // Chama a função de ordenação
    bubbleSort(arr, n);

    printf("Array ordenado: \n");
    printArray(arr, n);

    return 0;
}

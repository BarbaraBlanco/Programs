#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int somaPesosFaixa(Cell vet[], int n, int i, int inFaixa) {
    // Caso base: Se chegamos ao fim do vetor, retornamos 0
    if (i >= n) {
        return 0;
    }

    // Se estamos no início do vetor ou se não há faixa
    if (i == 0 || vet[i].letra != vet[i - 1].letra) {
        // Começamos uma nova faixa se as letras consecutivas forem iguais
        return somaPesosFaixa(vet, n, i + 1, 0);
    } else {
        // Se estamos em uma faixa, somamos o peso atual e continuamos
        return vet[i].peso + (inFaixa ? 0 : vet[i - 1].peso) + somaPesosFaixa(vet, n, i + 1, 1);
    }
}

// Função auxiliar para simplificar a chamada
int somaPesosFaixaWrapper(Cell vet[], int n) {
    return somaPesosFaixa(vet, n, 0, 0);
}

int main() {
    Cell vet[] = {{'y', 1}, {'y', 2}, {'z', 5}, {'z', 4}, {'z', 5}, {'y', 4}, {'a', 3}};
    int n = sizeof(vet) / sizeof(vet[0]);
    int resultado = somaPesosFaixaWrapper(vet, n);
    printf("Soma dos pesos das faixas: %d\n", resultado); // Esperado: 17
    return 0;
}
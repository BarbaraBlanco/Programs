#include <stdio.h>
#include <stdlib.h>
 
 
int menorDistancia(int a, int b) {
    return abs(a - b);  // Retorna o valor absoluto da diferença entre os dois pontos
}
 
 
int parMaisProximo(int vetor[], int esquerda, int direita) {
    // Se houver dois pontos, a menor distância é a diferença entre eles
    if (direita - esquerda == 1) {
        return menorDistancia(vetor[esquerda], vetor[direita]);
    }
 
    // Se houver três pontos, calculamos todas as distâncias possíveis e retornamos a menor
    if (direita - esquerda == 2) {
        int dist1 = menorDistancia(vetor[esquerda], vetor[esquerda + 1]);
        int dist2 = menorDistancia(vetor[esquerda + 1], vetor[direita]);
        int dist3 = menorDistancia(vetor[esquerda], vetor[direita]);
        // comparando as três distâncias e retornando a menor delas
        if (dist1 < dist2 && dist1 < dist3) {
            return dist1;  // Se dist1 for a menor, retorna dist1
        } else if (dist2 < dist3) {
            return dist2;  // Se dist2 for a menor, retorna dist2
        } else {
            return dist3;  // Caso contrário, retorna dist3
        }
    }
 
    // Divide o vetor em duas partes
    int meio = (esquerda + direita) / 2;
 
    // Recursivamente, encontra a menor distância na metade esquerda
    int d1 = parMaisProximo(vetor, esquerda, meio);
    // Recursivamente, encontra a menor distância na metade direita
    int d2 = parMaisProximo(vetor, meio + 1, direita);
 
    // Verifica a menor distância cruzando a linha de divisão
    int d3 = menorDistancia(vetor[meio], vetor[meio + 1]);
 
    // Retorna a menor distância entre d1, d2 e d3
    if (d1 < d2 && d1 < d3) {
        return d1;  // Se d1 for a menor, retorna d1
    } else if (d2 < d3) {
        return d2;  // Se d2 for a menor, retorna d2
    } else {
        return d3;  // Caso contrário, retorna d3
    }
}
 
int main() {
    int vetor[] = {3, 6, 9, 19, 25, 40, 43, 55, 58, 71, 73, 79, 82, 84, 90, 96, 100};
    int n = sizeof(vetor) / sizeof(vetor[0]);
 
    int resultado = parMaisProximo(vetor, 0, n - 1);
    printf("A menor distancia entre dois pontos e: %d\n", resultado);
 
    return 0;
}

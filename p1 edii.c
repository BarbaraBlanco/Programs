#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char letra;
    int peso;
}Cell;


int somaPesosFaixa(Cell vet[], int n, int i, int inFaixa)
{ 
// Caso base: Percorrer o vetor todo, e ai retornar 0
    if(i >= n)
        return 0;

// Caso: Inicio do vetor ou vetor nulo/vazio
    if(i == 0 || vet[i].letra != vet[i-1].letra){
        // Nova faixa caso as letras consecutivas forem iguais
        return somaPesosFaixa(vet, n, i+1, 0);
    }else{
        // Se estamos em uma faixa, se soma o peso atual e continuamos
        return vet[i].peso + (inFaixa ? 0: vet[i-1].peso) + somaPesosFaixa(vet, n, i+1, 1);
    }
}

// Funcao auxiliar
int somaPesosFaixaWrapper(Cell vet[], int n)
{
    return somaPesosFaixa(vet, n, 0, 0);
}

int main()
{
    Cell vet[] = {{'y', 1}, {'y', 2}, {'z', 5}, {'z', 4}, {'z', 5}, {'y', 4}, {'a', 3}};
    int n = sizeof(vet) / sizeof(vet[0]);
    int resultado = somaPesosFaixaWrapper(vet, n);
    printf("Soma dos pesos das faixas: %d\n", resultado);
    return 0;
}
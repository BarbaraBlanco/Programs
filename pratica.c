#include <stdio.h>
#include <stdlib.h>

int *iniVet(int *size, int *maxSize);
void printVet(int *v, int size, int maxSize);
int *addVet(int *v, int *size, int *maxSize, int e);
int find(int *v, int size, int e);
int *removeVet(int *v, int *size, int *maxSize, int e);

int *iniVet(int *size, int *maxSize)
{
    *size = 0;
    *maxSize = 4;

    int *vetor = (int *)malloc((*maxSize) * sizeof(int));

    if(vetor == NULL)
        return NULL;

    return vetor;
}

int *addVet(int *v, int *size, int *maxSize, int e)
{
    if(*size >= *maxSize)
    {
        *maxSize *= 2;

        int *novoVetor = (int *)realloc(v, (*maxSize) * sizeof(int));

        if(novoVetor == NULL)
            printf("Erro ao realocar a memoria.\n");
            return v;

        v = novoVetor;
    }
    v[*size] = e;
    (*size)++;
    return v;
}

void ordenar(int *v, int size)
{
    int i, j;
    for(i = 0; i < size - 1; i++)
    {
        for(j = 0; j < size - i - 1; j++)
        {
            if(v[j] > v[j+1])
            {
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp; 
            }
        }
    }
}

void printVet(int *v, int size, int maxSize)
{
    ordenar(v, size);

    printf("\nVetor (size: %d, maxSize: %d): \n", size, maxSize);

    
}
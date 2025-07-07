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

    if( vetor == NULL){
        return NULL;
    }

    return vetor;
}

int *addVet(int *v, int *size, int *maxSize, int e)
{
    if(*size >= *maxSize){
        *maxSize *= 2;

        int *novoVetor = (int *)realloc(v, (*maxSize) * sizeof(int));

        if(novoVetor == NULL){
            printf("Erro ao realocar a memoria.\n");
            return v;
        }

        v = novoVetor;
    }

    v[*size] = e;

    (*size)++;

    return v;
}


void ordenar(int *v, int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

void printVet(int *v, int size, int maxSize)
{
    ordenar(v, size);

    printf("\nVetor (size: %d, maxSize: %d):\n", size, maxSize);

    for(int i = 0; i<size; i++){
        printf("%d\n", v[i]);
    }

    if(size==0){
        printf("vetor vazio.\n");
    }
    printf("\n");
}


int find(int *v, int size, int e)
{
    for(int i=0; i<size; i++){
        if(v[i] == e){
            return i;
        }
    }

    return -1;
}

int *removeVet(int *v, int *size, int *maxSize, int e)
{
    int pos = find(v, *size, e);

    if(pos == -1){
        printf("Elemento %d nao encontrado.\n", e);
        return v;
    }

    for(int i = pos; i < *size -1; i++){
        v[i] = v[i + 1];
    }

    (*size)--;

    if(*size <= *maxSize / 4 && *maxSize > 4){
        *maxSize /= 2;

        int *novoVetor = (int *)realloc(v, (*maxSize) * sizeof(int));

        if(novoVetor == NULL){
            printf("Erro ao realocar a memoria.\n");
            return v;
        }

        v = novoVetor;
    }

    return v;
}

int main()
{
    int size = 0, maxSize = 4;
    int *vetor = (int *)malloc(maxSize * sizeof(int));

    if(vetor == NULL){
        printf("Falha ao alocar memoria.\n");
        return 1;
    }

    int opcao;
    do{
        printf("\n");
        printf("Escolha uma opcao.\n");
        printf("1 - Adicionar elemento.\n");
        printf("2 - Imprimir vetor.\n");
        printf("3 - Procurar elemento.\n");
        printf("4 - Remover elemento.\n");
        printf("5 - Sair.\n");
        printf("Digite a opcao: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1: {
                int elemento;
                printf("\nDigite o elemento a ser adicionado: ");
                scanf("%d", &elemento);
                vetor = addVet(vetor, &size, &maxSize, elemento);
                break;
            }
            case 2:
                printVet(vetor, size, maxSize);
                break;
            case 3: {
                int elemento;
                printf("\nDigite o elemento a ser procurado: ");
                scanf("%d", &elemento);
                int pos = find(vetor, size, elemento);
                if(pos != -1){
                    printf("Elemento %d encontrado na posicao %d.\n", elemento, pos);
                }else{
                    printf("Elemento %d nao encontrado.\n", elemento);
                }
                break;
            }
            case 4: {
                int elemento;
                printf("\nDigite o elemento a ser removido: ");
                scanf("%d", &elemento);
                vetor = removeVet(vetor, &size, &maxSize, elemento);
                break;
            }
            case 5:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                break;
        }

    } while(opcao != 5);

    printVet(vetor, size, maxSize);

    free(vetor);

    return 0;
}
/*
Barbara Leticia Blanco, RA 202310023
Cesar Lucio Maia, RA 202310010
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No *esquerda, *direita;
} No;

// Estrategia 1: Adicionar os nós da 1ª na 2ª, apagar a 1ª e balancear a 2ª
No* criarNo(int chave) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->chave = chave;
    novoNo->esquerda = novoNo->direita = NULL;
    return novoNo;
}

No* inserir(No* raiz, int chave) {
    if (raiz == NULL) return criarNo(chave);
    if (chave < raiz->chave) raiz->esquerda = inserir(raiz->esquerda, chave);
    else if (chave > raiz->chave) raiz->direita = inserir(raiz->direita, chave);
    return raiz;
}

void adicionarNos(No* arvoreOrigem, No** arvoreDestino) {
    if (arvoreOrigem == NULL) return;
    adicionarNos(arvoreOrigem->esquerda, arvoreDestino);
    *arvoreDestino = inserir(*arvoreDestino, arvoreOrigem->chave);
    adicionarNos(arvoreOrigem->direita, arvoreDestino);
}

void liberarArvore(No* raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

void imprimirInOrdem(No* raiz) {
    if (raiz == NULL) return;
    imprimirInOrdem(raiz->esquerda);
    printf("%d ", raiz->chave);
    imprimirInOrdem(raiz->direita);
}

int main() {
    No* arvore1 = NULL;
    No* arvore2 = NULL;

    // Criando a árvore 1
    arvore1 = inserir(arvore1, 10);
    arvore1 = inserir(arvore1, 5);
    arvore1 = inserir(arvore1, 15);

    // Criando a árvore 2
    arvore2 = inserir(arvore2, 20);
    arvore2 = inserir(arvore2, 25);

    printf("Arvore 1 (in-order): ");
    imprimirInOrdem(arvore1);
    printf("\nArvore 2 (in-order): ");
    imprimirInOrdem(arvore2);

    adicionarNos(arvore1, &arvore2);

    liberarArvore(arvore1);

    printf("\nArvore 2 apos juncao (in-order): ");
    imprimirInOrdem(arvore2);


    liberarArvore(arvore2);

    return 0;
}

// Estratégia 2: Inserção direta
void inserirDiretamente(No* origem, No** destino) {
    if (origem == NULL) return;
    inserirDiretamente(origem->esquerda, destino);
    *destino = inserir(*destino, origem->chave);
    inserirDiretamente(origem->direita, destino);
}

// Estratégia 3: Criar uma árvore balanceada
void armazenarInOrdem(No* raiz, int* vetor, int* indice) {
    if (raiz == NULL) return;
    armazenarInOrdem(raiz->esquerda, vetor, indice);
    vetor[(*indice)++] = raiz->chave;
    armazenarInOrdem(raiz->direita, vetor, indice);
}

No* construirArvoreBalanceada(int* vetor, int inicio, int fim) {
    if (inicio > fim) return NULL;
    int meio = (inicio + fim) / 2;
    No* raiz = criarNo(vetor[meio]);
    raiz->esquerda = construirArvoreBalanceada(vetor, inicio, meio - 1);
    raiz->direita = construirArvoreBalanceada(vetor, meio + 1, fim);
    return raiz;
}

No* unirArvores(No* arvore1, No* arvore2) {
    int vetor1[100], vetor2[100], vetorFinal[200];
    int indice1 = 0, indice2 = 0, indiceFinal = 0;

    armazenarInOrdem(arvore1, vetor1, &indice1);
    armazenarInOrdem(arvore2, vetor2, &indice2);

    int i = 0, j = 0;
    while (i < indice1 && j < indice2) {
        if (vetor1[i] < vetor2[j]) vetorFinal[indiceFinal++] = vetor1[i++];
        else vetorFinal[indiceFinal++] = vetor2[j++];
    }
    while (i < indice1) vetorFinal[indiceFinal++] = vetor1[i++];
    while (j < indice2) vetorFinal[indiceFinal++] = vetor2[j++];

    return construirArvoreBalanceada(vetorFinal, 0, indiceFinal - 1);
}

// Estratégia 4: Criar nó raiz com subárvores diretas
No* combinarSubarvores(No* arvore1, No* arvore2) {
    No* raiz = criarNo(0); // Raiz com valor neutro
    raiz->esquerda = arvore1;
    raiz->direita = arvore2;
    return raiz;
}

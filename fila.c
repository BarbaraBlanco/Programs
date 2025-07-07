#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define tamanho 10
// alterar para fila. mover fila 1 para fila 2 
// (criar fila 3 para mover f1 para f3, f3 para f1 e f2)

typedef struct fila{
        int item[tamanho];
        int inicio, fim;
} T_fila;

int inicializa(T_fila *f){
  f->inicio = -1;
  f->fim = -1;
  return 0;
}

// Função para verificar se a fila está vazia
int fila_vazia(T_fila *f){
  return f->inicio == -1;
}

int fila_cheia(T_fila *f){
  return (f->fim + 1) % tamanho == f->inicio;
}

// Função para enfileirar(inserir) um elemento
int enfileira(T_fila *f, int dado){
  if(fila_cheia(f)){
    return 1; // fila cheia
  }
  if(fila_vazia(f)){
    f->inicio=0;
  }
  f->fim = (f->fim + 1) % tamanho;
  f->item[f->fim] = dado;
  return 0; //sucesso
}

// Função para remover da fila
int desenfileira(T_fila *f, int *dado){
  if(fila_vazia(f)){
    return 1; //fila vazia
  }
  *dado = f->item[f->inicio];
  if(f->inicio == f->fim){
    // fila vazia 
    f->inicio = -1;
    f->fim = -1;
  } else {
    f->inicio = (f->inicio + 1) % tamanho;
  }
  return 0; // sucesso
}

int copia_fila(T_fila *f1, T_fila *f2){
  T_fila f3;
  inicializa(&f3);

  int dado;
  // copiar todos os elementos de f1 para f3
  while(!fila_vazia(f1)){
    desenfileira(f1, &dado);
    enfileira(&f3, dado);
  }

  //copiar todos os elementos de f3 e voltar para f1 e f2
  while(!fila_vazia(&f3)){
    desenfileira(&f3, &dado);
    enfileira(f1, dado);
    enfileira(f2, dado);
  }

  return 0;
}

int main() {
    T_fila f1, f2;
    inicializa(&f1);
    inicializa(&f2);

    // Preencher f1 com alguns valores
    for (int i = 1; i <= tamanho; i++) {
        enfileira(&f1, i);
    }

    // Copiar os elementos de f1 para f2 através de f3
    copia_fila(&f1, &f2);

    // Exibir os elementos de f1 e f2
    int dado;
    printf("Elementos da fila f1: ");
    while (!fila_vazia(&f1)) {
        desenfileira(&f1, &dado);
        printf("%d ", dado);
    }
    printf("\n");

    printf("Elementos da fila f2: ");
    while (!fila_vazia(&f2)) {
        desenfileira(&f2, &dado);
        printf("%d ", dado);
    }
    printf("\n");

    return 0;
}
// Rotacoes
#include <stdio.h>
#include <stdlib.h>

// Definicao da estrutura de um no da arvore AVL
typedef struct Produto 
{
    int codigo;          // Codigo unico do produto (identificador)
    int quantidade;      // Quantidade em estoque do produto
    int altura;          // Altura do no (importante para balanceamento)
    struct Produto *esq; // Ponteiro para o filho esquerdo
    struct Produto *dir; // Ponteiro para o filho direito
}Produto;


Produto* rotacao_direita(Produto *y);
Produto* rotacao_esquerda(Produto *x);
Produto* rotacao_esquerda_direita(Produto *z);
Produto* rotacao_direita_esquerda(Produto *z);

// Rotacao a direita: Usada para balancear a arvore quando o fator de balanceamento da subarvore esquerda e 2 (desbalanceada a esquerda)
Produto* rotacao_direita(Produto *y)
{

}
/*
      y                  x
     /                  / \
    x          ->      T2  y
   /
  T2
*/

// Rotacao a esquerda: Usada para balancear a arvore quando o fator de balanceamento da subarvore direita e -2 (desbalanceada a direita)
Produto* rotacao_esquerda(Produto *x)
{

}
/*
  x                        y
   \                      / \
    y          ->        x  T2
     \
      T2
*/

// Rotacao dupla a esquerda-direita: Caso em que a subarvore esquerda de um no esta desbalanceada a direita
Produto* rotacao_esquerda_direita(Produto *z)
{


}
/*
    z                 z             x
   /                 /             / \ 
  y         ->      x       ->    y   z
   \               /
    x             y
*/

// Rotacao dupla a direita-esquerda: Caso em que a subarvore direita de um no esta desbalanceada a esquerda
Produto* rotacao_direita_esquerda(Produto *z)
{

}
/*
  x                    x                      y
   \                    \                    / \
    z         ->         y          ->      x   z
   /                      \
  y                        z
*/
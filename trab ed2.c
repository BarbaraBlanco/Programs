#include <stdio.h>
#include <stdlib.h>

/* Nomes:
    Barbara Leticia Blanco, RA: 202310023
    Cesar Lucio Maia,       RA: 202310010
    Victor Siqueira Rodrigues, RA: 202310012
*/

// Definicao da estrutura de um no da arvore AVL
typedef struct Produto {
    int codigo;          // Codigo unico do produto (identificador)
    int quantidade;      // Quantidade em estoque do produto
    int altura;          // Altura do no (importante para balanceamento)
    struct Produto *esq; // Ponteiro para o filho esquerdo
    struct Produto *dir; // Ponteiro para o filho direito
} Produto;

// Funcoes
int altura(Produto *no);
int fator_balanceamento(Produto *no);
void atualizar_altura(Produto *no);
Produto* rotacao_direita(Produto *y);
Produto* rotacao_esquerda(Produto *x);
Produto* rotacao_esquerda_direita(Produto *z);
Produto* rotacao_direita_esquerda(Produto *z);
Produto* inserir(Produto *no, int codigo, int quantidade);
Produto* remover(Produto *no, int codigo);
Produto* buscar(Produto *no, int codigo);
void listar_em_ordem(Produto *no);
void liberar_memoria(Produto *no);
int main();

// Funcao para calcular a altura de um no
// A altura de um no e 0 quando o no e NULL, e 1 mais o maior valor entre a altura da subarvore esquerda ou direita.
int altura(Produto *no) {
    if (no == NULL)
        return 0;  // Se o no for NULL, a altura e 0
    return no->altura;  // Caso contrario, retorna a altura armazenada no no
}

// Funcao para calcular o fator de balanceamento de um no
// O fator de balanceamento e a diferenca entre a altura da subarvore esquerda e direita.
int fator_balanceamento(Produto *no) {
    if (no == NULL)
        return 0;  // Se o no for NULL, o fator de balanceamento e 0
    return altura(no->esq) - altura(no->dir);  // Retorna a diferenca entre as alturas das subarvores esquerda e direita
}

// Funcao para atualizar a altura de um no
// A altura de um no e 1 mais o maior valor entre as alturas de seus filhos esquerdo e direito.
void atualizar_altura(Produto *no) {
    if (no != NULL) {
        int altura_esq = altura(no->esq);  // Altura da subarvore esquerda
        int altura_dir = altura(no->dir);  // Altura da subarvore direita
        no->altura = (altura_esq > altura_dir ? altura_esq : altura_dir) + 1;  // Atualiza a altura do no
    }
}

// Rotacao a direita: Usada para balancear a arvore quando o fator de balanceamento da subarvore esquerda e 2 (desbalanceada a esquerda)
Produto* rotacao_direita(Produto *y) {
    Produto *x = y->esq;     // O no da esquerda se torna a nova raiz
    Produto *T2 = x->dir;    // O filho direito de x e movido para o filho esquerdo de y

    // Realiza a rotacao
    x->dir = y;              // A subarvore de y (filho direito) passa a ser a subarvore esquerda de x
    y->esq = T2;             // O filho direito de x (se houver) passa a ser o filho esquerdo de y

    // Atualiza as alturas
    atualizar_altura(y);  // A altura de y precisa ser recalculada apos a rotacao
    atualizar_altura(x);  // A altura de x tambem e recalculada apos a rotacao

    return x;  // Retorna o novo no raiz (x)
}
/*
      y                  x
     /                  / \
    x          ->      T2  y
   /
  T2
*/

// Rotacao a esquerda: Usada para balancear a arvore quando o fator de balanceamento da subarvore direita e -2 (desbalanceada a direita)
Produto* rotacao_esquerda(Produto *x) {
    Produto *y = x->dir;    // O no da direita se torna a nova raiz
    Produto *T2 = y->esq;   // O filho esquerdo de y e movido para o filho direito de x

    // Realiza a rotacao
    y->esq = x;             // A subarvore de x (filho esquerdo) passa a ser a subarvore direita de y
    x->dir = T2;            // O filho esquerdo de y (se houver) passa a ser o filho direito de x

    // Atualiza as alturas
    atualizar_altura(x);  // A altura de x precisa ser recalculada apos a rotacao
    atualizar_altura(y);  // A altura de y tambem e recalculada apos a rotacao

    return y;  // Retorna o novo no raiz (y)
}
/*
  x                        y
   \                      / \
    y          ->        x  T2
     \
      T2
*/

// Rotacao dupla a esquerda-direita: Caso em que a subarvore esquerda de um no esta desbalanceada a direita
Produto* rotacao_esquerda_direita(Produto *z) {
    z->esq = rotacao_esquerda(z->esq);  // Primeiramente, realiza uma rotacao a esquerda na subarvore esquerda
    return rotacao_direita(z);          // Depois, realiza a rotacao a direita no no z
}
/*
    z                 z             x
   /                 /             / \ 
  y         ->      x       ->    y   z
   \               /
    x             y
*/

// Rotacao dupla a direita-esquerda: Caso em que a subarvore direita de um no esta desbalanceada a esquerda
Produto* rotacao_direita_esquerda(Produto *z) {
    z->dir = rotacao_direita(z->dir);   // Primeiramente, realiza uma rotacao a direita na subarvore direita
    return rotacao_esquerda(z);         // Depois, realiza a rotacao a esquerda no no z
}
/*
  x                    x                      y
   \                    \                    / \
    z         ->         y          ->      x   z
   /                      \
  y                        z
*/

// Funcao para inserir um novo produto na arvore AVL
Produto* inserir(Produto *no, int codigo, int quantidade) {
    // Passo 1: Insercao normal em uma arvore binaria de busca
    if (no == NULL) {
        Produto *novo_produto = (Produto*)malloc(sizeof(Produto));  // Cria um novo no
        novo_produto->codigo = codigo;  // Atribui o codigo do produto
        novo_produto->quantidade = quantidade;  // Atribui a quantidade em estoque
        novo_produto->esq = novo_produto->dir = NULL;  // Inicializa as subarvores como NULL
        novo_produto->altura = 1;  // O novo no tem altura 1
        return novo_produto;  // Retorna o novo no inserido
    }

    // Passo 2: Insercao recursiva: Se o codigo for menor que o codigo do no atual, insere a esquerda, senao a direita
    if (codigo < no->codigo) {
        no->esq = inserir(no->esq, codigo, quantidade);
    } else if (codigo > no->codigo) {
        no->dir = inserir(no->dir, codigo, quantidade);
    } else {
        // Se o produto ja existir, atualiza a quantidade
        no->quantidade += quantidade;
        return no;
    }

    // Passo 3: Atualizar a altura do no apos a insercao
    atualizar_altura(no);

    // Passo 4: Verificar o fator de balanceamento e corrigir se necessario (com rotacoes)
    int fb = fator_balanceamento(no);

    // Caso 1: Desbalanceamento a esquerda
    if (fb > 1 && codigo < no->esq->codigo) {
        return rotacao_direita(no);  // Realiza rotacao a direita para balancear
    }

    // Caso 2: Desbalanceamento a direita
    if (fb < -1 && codigo > no->dir->codigo) {
        return rotacao_esquerda(no);  // Realiza rotacao a esquerda para balancear
    }

    // Caso 3: Desbalanceamento a esquerda-direita
    if (fb > 1 && codigo > no->esq->codigo) {
        return rotacao_esquerda_direita(no);  // Realiza rotacao dupla a esquerda-direita
    }

    // Caso 4: Desbalanceamento a direita-esquerda
    if (fb < -1 && codigo < no->dir->codigo) {
        return rotacao_direita_esquerda(no);  // Realiza rotacao dupla a direita-esquerda
    }

    // Retorna o no, agora balanceado
    return no;
}

// Funcao para remover um produto da arvore AVL
Produto* remover(Produto *no, int codigo) {
    if (no == NULL)  // Se o no for NULL, significa que o produto nao foi encontrado
        return no;

    // Passo 1: Realiza a remocao como em uma arvore binaria de busca
    if (codigo < no->codigo) {
        no->esq = remover(no->esq, codigo);  // Se o codigo for menor, busca a esquerda
    } else if (codigo > no->codigo) {
        no->dir = remover(no->dir, codigo);  // Se o codigo for maior, busca a direita
    } else {
        // Passo 2: Encontramos o produto a ser removido
        if (no->esq == NULL || no->dir == NULL) {
            Produto *temp = no->esq ? no->esq : no->dir;  // Se um dos filhos for NULL, o no e substituido pelo filho nao-nulo
            if (temp == NULL) {
                temp = no;  // Se o no nao tiver filhos, o no e removido
                no = NULL;
            } else {
                *no = *temp;  // Caso contrario, copia o conteudo do no nao-nulo para o no a ser removido
            }
            free(temp);  // Libera a memoria do no removido
        } else {
            // Caso 3: O no tem dois filhos, precisa encontrar o sucessor (menor valor da subarvore direita)
            Produto *temp = no->dir;
            while (temp->esq != NULL) {
                temp = temp->esq;
            }
            no->codigo = temp->codigo;  // Copia o codigo do sucessor
            no->quantidade = temp->quantidade;  // Copia a quantidade do sucessor
            no->dir = remover(no->dir, temp->codigo);  // Remove o sucessor
        }
    }

    // Passo 3: Se a arvore nao esta vazia, atualiza a altura do no atual
    if (no == NULL)
        return no;

    atualizar_altura(no);

    // Passo 4: Verifica e corrige o balanceamento apos a remocao
    int fb = fator_balanceamento(no);

    // Caso 1: Desbalanceamento a esquerda
    if (fb > 1 && fator_balanceamento(no->esq) >= 0) {
        return rotacao_direita(no);
    }

    // Caso 2: Desbalanceamento a direita
    if (fb < -1 && fator_balanceamento(no->dir) <= 0) {
        return rotacao_esquerda(no);
    }

    // Caso 3: Desbalanceamento a esquerda-direita
    if (fb > 1 && fator_balanceamento(no->esq) < 0) {
        return rotacao_esquerda_direita(no);
    }

    // Caso 4: Desbalanceamento a direita-esquerda
    if (fb < -1 && fator_balanceamento(no->dir) > 0) {
        return rotacao_direita_esquerda(no);
    }

    return no;
}

// Funcao para buscar um produto na arvore
Produto* buscar(Produto *no, int codigo) {
    if (no == NULL || no->codigo == codigo)  // Se o no for NULL ou o codigo for encontrado
        return no;
    
    if (codigo < no->codigo)  // Se o codigo for menor, busca a esquerda
        return buscar(no->esq, codigo);
    else  // Se o codigo for maior, busca a direita
        return buscar(no->dir, codigo);
}

// Funcao para listar todos os produtos da arvore em ordem crescente
void listar_em_ordem(Produto *no) {
    if (no != NULL) {
        listar_em_ordem(no->esq);  // Primeiro, lista a subarvore esquerda
        printf("Produto: %d - Quantidade: %d\n", no->codigo, no->quantidade);  // Exibe o codigo e quantidade
        listar_em_ordem(no->dir);  // Depois, lista a subarvore direita
    }
}

// Funcao para liberar toda a memoria da arvore
void liberar_memoria(Produto *no) {
    if (no != NULL) {
        liberar_memoria(no->esq);  // Libera a subarvore esquerda
        liberar_memoria(no->dir);  // Libera a subarvore direita
        free(no);  // Libera o no atual
    }
}

// Funcao principal que exibe o menu e interage com o usuario
int main() {
    Produto *estoque = NULL;  // A arvore AVL comeca vazia

    int opcao, codigo, quantidade;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Inserir produto\n");
        printf("2. Remover produto\n");
        printf("3. Buscar produto\n");
        printf("4. Listar produtos em ordem\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o codigo do produto: ");
                scanf("%d", &codigo);
                printf("Digite a quantidade em estoque: ");
                scanf("%d", &quantidade);
                estoque = inserir(estoque, codigo, quantidade);
                printf("Produto inserido com sucesso!\n");
                break;
            case 2:
                printf("Digite o codigo do produto a ser removido: ");
                scanf("%d", &codigo);
                estoque = remover(estoque, codigo);
                printf("Produto removido com sucesso!\n");
                break;
            case 3:
                printf("Digite o codigo do produto a ser buscado: ");
                scanf("%d", &codigo);
                Produto *prod = buscar(estoque, codigo);
                if (prod != NULL) {
                    printf("Produto encontrado! Quantidade: %d\n", prod->quantidade);
                } else {
                    printf("Produto nao encontrado.\n");
                }
                break;
            case 4:
                printf("Lista de Produtos em Ordem:\n");
                listar_em_ordem(estoque);
                break;
            case 5:
                // Libera toda a memoria alocada antes de sair
                liberar_memoria(estoque);
                printf("Saindo do programa.\n");
                return 0;
            default:
                printf("Opcao invalida!\n");
        }
    }

    return 0;
}

/* Explicacao das Funcoes de Gerenciamento de Memoria:

Alocacao de memoria: Durante a insercao de um novo produto, e feito o malloc para alocar um novo no.

Liberacao de memoria: Quando um produto e removido, a memoria do no removido e liberada com free(). A funcao liberar_memoria percorre a arvore recursivamente e libera a memoria de todos os nos.

Finalizacao do programa: A funcao liberar_memoria e chamada ao final do programa para garantir que toda a memoria alocada seja devidamente liberada.

Estrutura de Dados: Cada no contem o codigo do produto, a quantidade em estoque, a altura (usada para verificar balanceamento) e ponteiros para os filhos esquerdo e direito.


Balanceamento:

Rotacao a direita e a esquerda sao usadas quando a arvore esta desbalanceada em uma direcao.

Rotacoes duplas (a esquerda-direita e a direita-esquerda) sao necessarias quando o desbalanceamento ocorre de forma diagonal.

Como testar:

Insercao de Produtos: Escolha a opcao 1 para inserir novos produtos.

Remocao de Produtos: Use a opcao 2 para remover produtos.

Busca de Produtos: A opcao 3 permite buscar produtos por codigo.

Listagem em Ordem: A opcao 4 lista os produtos na ordem crescente de seus codigos.

Saida: A opcao 5 finaliza o programa e libera toda a memoria.
*/
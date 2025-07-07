/*
Uma heap é uma estrutura de árvore binária completa representada como um array.
No Heap Sort, começamos transformando o array em um Max Heap (o maior elemento no topo).
O array será tratado como uma árvore binária:
*/

#include <stdio.h>
#include <stdlib.h>

// Função para reorganizar a árvore em Max Heap
void heapify(int arr[], int n, int i)
{
    int largest = i; // Consideramos inicialmente o nó atual (raiz) como o maior elemento
    int left = 2 * i + 1; // Calcula o índice do filho à esquerda do nó atual
    int right = 2 * i + 2; // Calcula o índice do filho à direita do nó atual
    /*
    Fórmulas importantes para representação da árvore binária em array:
    Pai: parent(i) = [(i - 1) / 2]
    Filho esquerdo: left(i) = 2i + 1
    Filho direito: right(i) = 2i + 2
    */

    // Verifica se o filho à esquerda é maior que a raiz (nó atual)
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Verifica se o filho à direita é maior que o maior elemento encontrado até agora
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Se o maior não for a raiz, realiza uma troca para manter a propriedade de Max Heap
    if (largest != i)
    {
        // Troca o nó atual com o maior filho
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursivamente reorganiza a subárvore afetada para garantir a propriedade do Max Heap
        heapify(arr, n, largest);
    }
}

// Função principal do Heap Sort
void heapSort(int arr[], int n)
{
    // Passo 1: Construir a Max Heap
    // Iniciamos do último nó não-folha até a raiz
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i); // Chama a função heapify para cada nó
    }

    // Passo 2: Extrair elementos da heap e ajustar o Max Heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move a raiz atual (maior elemento) para o final do array
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Chama heapify no array reduzido para manter a propriedade de Max Heap
        heapify(arr, i, 0);
    }
}

int main()
{
    int *arr = NULL; // Ponteiro para armazenar o array dinamicamente
    int size = 0;    // Tamanho atual do array
    int input;       // Variável para armazenar o elemento digitado pelo usuário
    char cont = 'y'; // Controle para continuar a entrada de dados

    printf("Digite os elementos do array (Digite 'n' para parar): \n");

    while (cont == 'y' || cont == 'Y')
    {
        printf("Digite um elemento: ");
        scanf("%d", &input);

        // Realoca memória para o array, aumentando seu tamanho dinamicamente
        arr = realloc(arr, (size + 1) * sizeof(int));

        // Adiciona o novo elemento ao final do array
        arr[size] = input;
        size++;

        // Pergunta ao usuário se deseja continuar adicionando elementos
        printf("Deseja adicionar mais um elemento? (y/n): ");
        scanf(" %c", &cont); // O espaço antes do %c é necessconsumir o caractere de nova linha
    }

    // Exibe o array antes da ordenação
    printf("Array inicial: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Ordena o array usando Heap Sort
    heapSort(arr, size);

    // Exibe o array após a ordenação
    printf("Array ordenado: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Libera a memória alocada para o array
    free(arr);

    return 0;
}
/*
1. O que é um Max Heap?
Um Max Heap é uma estrutura onde:
- Cada elemento chamado "pai" é maior que ou igual aos seus dois "filhos".
- A estrutura segue o formato de uma árvore binária completa, mas é armazenada em um array.

Imagine que você tenha o array `[4, 10, 3, 5, 1]`. Quando organizado como Max Heap, ele ficará assim:
- O maior valor (10) estará no topo da "árvore" e será o primeiro elemento no array.  
- Os filhos de cada nó são os próximos valores no array.


2. Primeiro Passo: Transformar o array em Max Heap
O objetivo aqui é reorganizar os elementos do array para que eles sigam as regras de um Max Heap:
1. Comece ajustando os "pais" dos últimos nós no array (isto é, as posições mais ao centro).  
2. Verifique os dois "filhos" de cada pai. Se algum filho for maior que o pai, troque os dois.  
3. Após cada troca, verifique novamente os filhos do nó trocado e reorganize, caso necessário, até que a propriedade de Max Heap seja satisfeita.

No exemplo `[4, 10, 3, 5, 1]`:
- O valor `10` já está na posição correta como raiz porque é maior que seus filhos `4` e `3`.


3. Segundo Passo: Ordenar o array
Depois de construir o Max Heap, seguimos para o processo de ordenação:
1. Troque o maior elemento (que está na raiz, o primeiro valor do array) com o último elemento do array.
2. Agora, o maior elemento está no final, no lugar correto da ordenação.
3. Reduza o tamanho efetivo do Max Heap (ignorando o último elemento) e reorganize o restante para restaurar as propriedades do Max Heap.
4. Repita esse processo até que todos os elementos estejam no lugar.

No exemplo:
- Após transformar em Max Heap: `[10, 5, 3, 4, 1]`
- Troque `10` (raiz) com `1` (último): `[1, 5, 3, 4, 10]`
- Reorganize o heap (agora sem incluir o `10`): `[5, 4, 3, 1, 10]`
- Troque `5` com `1`: `[1, 4, 3, 5, 10]`
- Continue até obter o array final: `[1, 3, 4, 5, 10]`.


4. Resumo do Processo
- Construção do Max Heap: Reorganiza o array para que o maior valor esteja no topo (primeira posição).  
- Extração do maior elemento: Troca o maior valor com o último, reduzindo o tamanho do heap.  
- Repetição: Continua reorganizando o heap e movendo o maior elemento para o final, até que o array inteiro esteja ordenado.


5. Por que o Heap Sort é eficiente?
- Ele utiliza a estrutura de Max Heap para sempre identificar o maior elemento de forma eficiente.
- A complexidade é **O(n log n)**, o que é ótimo para muitos casos.  
- Não exige memória extra, já que a ordenação é feita no próprio array.
*/
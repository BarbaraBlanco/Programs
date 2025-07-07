#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;      // Ponteiro para armazenar o vetor dinâmico
    int tamanho_inicial, novo_tamanho;
    
    // Solicita o tamanho inicial do vetor ao usuário
    printf("Digite o tamanho inicial do vetor: ");
    scanf("%d", &tamanho_inicial);
    
    // Aloca memória usando malloc
    array = (int *)malloc(tamanho_inicial * sizeof(int));
    
    // Verifica se a alocação foi bem-sucedida
    if (array == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }
    
    // Preenche o vetor com valores
    for (int i = 0; i < tamanho_inicial; i++) {
        array[i] = i + 1;  // Preenche o vetor com valores 1, 2, 3, ...
    }
    
    // Exibe o vetor inicial
    printf("Vetor inicial: \n");
    for (int i = 0; i < tamanho_inicial; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    // Solicita o novo tamanho do vetor
    printf("Digite o novo tamanho do vetor: ");
    scanf("%d", &novo_tamanho);
    
    // Redimensiona o vetor usando realloc
    array = (int *)realloc(array, novo_tamanho * sizeof(int));
    
    // Verifica se o redimensionamento foi bem-sucedido
    if (array == NULL) {
        printf("Erro ao redimensionar a memória!\n");
        return 1;
    }
    
    // Se o novo tamanho for maior, preenche os novos espaços
    if (novo_tamanho > tamanho_inicial) {
        for (int i = tamanho_inicial; i < novo_tamanho; i++) {
            array[i] = i + 1;  // Preenche os novos espaços com valores
        }
    }
    
    // Exibe o vetor após o redimensionamento
    printf("Vetor redimensionado:\n");
    for (int i = 0; i < novo_tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    // Libera a memória alocada
    free(array);
    
    return 0;
}

// void *realloc(void *ptr, size_t size);

// ptr: É um ponteiro para o bloco de memória previamente alocado. Pode ser um ponteiro que foi retornado por malloc, calloc ou realloc,
// ou pode ser NULL (nesse caso, realloc se comporta como malloc e aloca um novo bloco de memória).
// size: Novo tamanho do bloco de memória (em bytes). Se esse valor for 0, o comportamento de realloc pode variar, mas geralmente ele 
// libera o bloco e retorna NULL.

// Possíveis cenários ao usar realloc:

// Tamanho maior que o atual: Se você solicita mais memória (isto é, se o novo tamanho é maior que o anterior), o realloc 
// tentará expandir o bloco. Ele pode fazer isso diretamente no mesmo local, se houver espaço disponível. Caso contrário, alocará 
// um novo bloco de memória maior, copiará os dados do bloco original para o novo bloco, e liberará o bloco antigo.

// Tamanho menor que o atual: Se você pede um tamanho menor, o bloco será ajustado para o novo tamanho, podendo permanecer no mesmo local. 
// O conteúdo além do novo tamanho será descartado.

// Importante:

// Se o realloc não conseguir realocar a memória (por exemplo, se não houver memória suficiente), ele retorna NULL, mas o bloco original 
// de memória não é alterado ou liberado. É por isso que o retorno de realloc deve sempre ser verificado.

// Segurança no uso do realloc: Uma prática comum e segura é sempre atribuir o resultado de realloc a uma variável temporária antes de 
// atualizar o ponteiro original. Isso evita que o ponteiro original seja perdido em caso de falha na realocação:

// Vantagens do realloc:

//Preservação dos dados: realloc preserva os dados existentes no bloco de memória original (até o menor entre o tamanho original e o 
// novo tamanho). Ou seja, se o bloco for realocado para um novo local, os dados serão copiados para a nova área.
// Eficiência: Se o sistema puder expandir o bloco no local original, não há necessidade de copiar os dados para um novo bloco, o que
// torna o processo mais eficiente.

// Pontos a considerar:
// Realocação pode mudar o endereço: Quando realloc redimensiona o bloco, pode alocar uma nova área de memória. O endereço do bloco pode 
// mudar, então é importante sempre atribuir o retorno de realloc ao ponteiro original (ou a um temporário).

// Perigo de perder o ponteiro original: Se você usar realloc diretamente no ponteiro original e ele falhar, você pode perder o acesso ao
// bloco de memória original. Por isso, é recomendado verificar o retorno antes de alterar o ponteiro.
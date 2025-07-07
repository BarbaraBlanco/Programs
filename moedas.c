#include <stdio.h>
#include <limits.h>

#define MAX_MOEDAS 100

// Função para encontrar o menor número de moedas com quantidade limitada e solução ótima parcial
int troco_limitado(int moedas[], int quantidade[], int num_moedas, int quantia) {
    int dp[quantia + 1];
    int usado[quantia + 1];
    for (int i = 0; i <= quantia; i++) {
        dp[i] = INT_MAX;
        usado[i] = -1;  // Nenhuma moeda foi usada para atingir esse valor
    }
    dp[0] = 0;  // Não precisamos de nenhuma moeda para a quantia 0

    // Preenche a tabela dp
    for (int i = 0; i <= quantia; i++) {
        for (int j = 0; j < num_moedas; j++) {
            if (i >= moedas[j] && dp[i - moedas[j]] != INT_MAX && quantidade[j] > 0) {
                if (dp[i] > dp[i - moedas[j]] + 1) {
                    dp[i] = dp[i - moedas[j]] + 1;
                    usado[i] = j;
                }
            }
        }
    }

    // Verifica se o troco exato é possível
    if (dp[quantia] == INT_MAX) {
        printf("Não é possível dar o troco exato. Solução ótima parcial:\n");

        // Encontrar a maior quantia que pode ser alcançada
        int melhor_quantia = 0;
        for (int i = 0; i <= quantia; i++) {
            if (dp[i] != INT_MAX) {
                melhor_quantia = i;
            }
        }

        // Exibe a solução ótima parcial
        int total_moedas = 0;
        printf("Maior quantia possível alcançada: %d\n", melhor_quantia);
        for (int i = melhor_quantia; i > 0 && usado[i] != -1; i -= moedas[usado[i]]) {
            printf("Moeda de %d usada.\n", moedas[usado[i]]);
            total_moedas++;
        }
        printf("Total de moedas usadas na solução ótima parcial: %d\n", total_moedas);
        return -1;
    } else {
        return dp[quantia];
    }
}

int main() {
    int moedas[] = {100, 25, 10, 5, 1};  // Denominações de moedas
    int quantidade[] = {1, 2, 1, 2, 10};  // Quantidade disponível de cada moeda
    int num_moedas = sizeof(moedas) / sizeof(moedas[0]);
    int quantia = 36;  // Quantia a ser dada em troco
    
    int resultado = troco_limitado(moedas, quantidade, num_moedas, quantia);
    if (resultado != -1) {
        printf("Menor número de moedas necessário: %d\n", resultado);
    }

    return 0;
}
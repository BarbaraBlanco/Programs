#include <stdio.h>
#include <limits.h>
 
int partir(int x, int p) {
    if (x < 0 || p == 0) {
        return 0;
    } else if (x == 0) {
        return 1;
    } else {
        return partir(x - p, p) + partir(x, p - 1);
    }
}
 
int main() {
    int x;
    int q_particao;
    int particao;
 
    printf("Inteiro a particionar: ");
    scanf("%d", &x);
 
    q_particao = x;
 
    particao = partir(x, q_particao);
 
    printf("\n\nResultado: %d\n", particao);
 
    return 0;
}
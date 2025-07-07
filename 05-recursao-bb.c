/*
 * Busca Binária Recursiva
 */

#include <stdio.h>

int bb_rec(int chave, int ini, int fim, int v[]) {
    int meio = (ini + fim) / 2;
    if(v[meio] == chave)  // parada: achei!
        return meio;
    else if(fim < ini) // parada: chave não existe no vetor!
        return -1;
    else {
        // se a chave for menor do que o elemento do meio
        if(chave < v[meio])
            return bb_rec(chave, ini, meio-1, v);
        else
            return bb_rec(chave, meio+1, fim, v);
    }
}

int main( )
{
    int vet[] = {3, 8, 12, 15, 23, 55, 79, 92, 99};
    // indices:  0  1   2   3   4   5   6   7   8

    int chave = 15;

    printf("Posição da chave: %d", bb_rec(chave, 0, 8, vet));
    return 0;
}

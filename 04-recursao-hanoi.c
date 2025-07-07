/*
 * Torre de Hanoi
 */

#include <stdio.h>

void hanoi(int n, char estacaIni, char estacaFim, char estacaAux);

int main(){
    hanoi(3, 'A', 'C' , 'B');
    printf("\n");
}

//Discos são numerados de 1 até n

void hanoi(int n, char estacaIni, char estacaFim, char estacaAux){
    if(n==1)
        printf("\nMova disco %d da estaca %c para %c.", n,  estacaIni, estacaFim);
    else{
        hanoi(n-1,estacaIni,estacaAux,estacaFim);
        printf("\nMova disco %d da estaca %c para %c.", n,  estacaIni, estacaFim);
        hanoi(n-1,estacaAux,estacaFim,estacaIni);
    }
}

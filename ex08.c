#include <stdio.h>

int main(){

    float vet[10] = {19.5, 10.4, 32.32, 43.3, 4.2, 0.8, 8.5, 1.11, 2.1, 57.0};
    float *p = vet;

    for(int i=0; i<10;i++){
        printf("\nElementos: %0.2f", *p);
        *p++;
    }


return 0;}

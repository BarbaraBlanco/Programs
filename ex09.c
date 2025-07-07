#include <stdio.h>

int main(){

    float matriz[3][3] = {{0,1,1},
                          {2,3,5},
                         {8,13,21}};

    float linhas = 3;
    float colunas = 3;

    float *p = &matriz[0][0];

    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            printf(" %0.0f", *p);
            *p++;
        }
    }


return 0;}

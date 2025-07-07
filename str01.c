#include <stdio.h>
#include <string.h>

int main(){
    char nome[10];
    int i;

    printf(" Digite o seu nome: ");
    fgets(nome,10,stdin);

    for(i=0; i<4; i++)
    {
        printf("%c", nome[i]);
    }


return 0; }

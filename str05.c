#include <stdio.h>
#include <string.h>

int main()
{
    char nome[20];
    int i;
    int tamanho;

    printf(" Digite se nome: ");
    fgets(nome,20,stdin);
    tamanho = strlen(nome);
    for(i=tamanho;i>=0;i--){
        printf("%c", nome[i]);
    }




return 0;}

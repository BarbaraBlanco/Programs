#include <stdio.h>
#include <string.h>

int main()
{
    char nome[20];
    int qtd = 0;

    printf(" Digite seu nome: ");
    fgets(nome,20,stdin);

    for(int i  =0 ;i<20;i++)
    {
        if(isalpha(nome[i])){
            qtd++;
        }
    }
        printf("%d", qtd);

return 0; }

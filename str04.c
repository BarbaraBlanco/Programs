#include <stdio.h>
#include <string.h>

int main()
{
    char nome[20];
    int i;

    printf(" Digite seu nome: ");
    fgets(nome,20,stdin);

        if(isupper(nome[i])){
            printf("%s", nome);
        }


    return 0;
}

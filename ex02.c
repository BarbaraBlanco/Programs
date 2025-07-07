
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nome[10][50], lista[50];
    int opcao;
    int i = 0;
    int trava;
    do
    {
        printf("Insira um nome: ");
        scanf(" %s", nome[i]);
        printf("Deseja inserir outro nome?\nDigite 1 para sim ou digite 2 para nao");
        scanf("%d", &opcao);
        if(i == 9)
        {
            printf("Lista de nomes completa!");
        }
        i++;
    } while(opcao == 1  && i < 10);
    printf("Digite o nome que deseja buscar: ");
        scanf(" %s", lista);
    for(int j = 0; j < 10; j++)
    {
        if(strcmp(nome[j], lista) == 0)
        {
            trava = 1;
        }
    }
    if (trava == 1)
    {
        printf("O nome estah na lista!!");
    }
    else
    {
        printf("O nome nao estah na lista!!");
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nome[5][50], change[50];

    for (int i = 0; i < 5; i++) {
    printf("Nome: ");
    scanf("%s", nome[i]);
    }


    for (int i = 1; i < 5; i++)
    {
    for (int j = 1; j < 5; j++) {
        if (strcmp(nome[j - 1], nome[j]) > 0) {
            strcpy(change, nome[j - 1]);
            strcpy(nome[j - 1], nome[j]);
            strcpy(nome[j], change);
        }
    }
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", nome[i]);
    }
 return 0;
}

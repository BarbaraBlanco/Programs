#include <stdio.h>
#include <string.h>

int main()
{
    char palavra[20], letra;
    int i, j;

    printf(" Digite uma palavra: ");
    fgets(palavra,20,stdin);
    printf(" Digite uma letra para substituir: ");
    scanf("%c", &letra);

    for(i=0,j = strlen(palavra); i<j ;i++){
        if(palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u' ){
            palavra[i] = letra;
        }

    }
    printf("%s", palavra);
return 0;}

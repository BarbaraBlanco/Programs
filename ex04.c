#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char frase[255];
    int vogais;
    int conssantes;
    int espacos;
    int palavra;
    vogais = 0;
    conssantes = 0;
    espacos = -1;
    palavra = 0;
    printf("Digite uma frase:");
    fgets(frase, sizeof(frase), stdin);

    for(int i = 0; i < 255; i++)
    {
        if (isalpha(frase[i]))
        {
            if (frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' ||  frase[i] == 'u' || frase[i] == 'A' || frase[i] == 'E' || frase[i] == 'I' || frase[i] == 'O' ||  frase[i] == 'U' )
            {
                vogais++;
            }
            else
            {
                conssantes++;
            }
        }
        if(isspace(frase[i]))
        {
            espacos++;
            palavra++;
        }
        if(frase[i] == ',' || frase[i] == '.' || frase[i] == '!' || frase[i] == ';' || frase[i] == '?')
        {
            palavra++;
        }
        if(frase[i] == '\0')
        {
            break;
        }
    }
    printf("Qnt vogais: %d\n", vogais);
    printf("Qnt consoantes: %d\n", conssantes);
    printf("Qnt espacos: %d\n", espacos);
    printf("Qnt palavras: %d\n", palavra);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main () {

    int ano, idade, anonasc;
    printf (" Digite o ano atual: ");
    scanf ("%d", &ano);
    printf (" Digite sua idade: ");
    scanf ("%d", &idade);
    anonasc = ano - idade;
    printf (" Seu ano de nascimento e: %d", anonasc);

    return 0;
}

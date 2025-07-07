#include <stdio.h>
#include <string.h>

int main()
{
    char senha[20], troca;
    int test;
    fgets(senha, 20, stdin);
    for (int i = 0; i < 20; i++)
    {
        troca = senha[i];
        troca = troca + 3;
        senha[i] = troca;

    }
    printf("A troca de digito sera para: %s", senha);
return 0;}

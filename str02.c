#include <stdio.h>
#include <string.h>

int main()
{
    char nome[10];
    int idade;
    char sexo;

    printf(" Digite seu nome: ");
    fgets(nome,10,stdin);
    printf(" Digite sua idade: ");
    scanf("%d", &idade);
    printf(" Digite seu sexo (f ou m): ");
    scanf(" %c", &sexo);

    if(sexo == 'f' && idade < 25){
        printf(" ACEITO ");
    } if(sexo == 'm' || idade > 25) {
        printf(" NEGADO ");
    }

    return 0;
}

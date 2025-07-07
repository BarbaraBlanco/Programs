///contar palavras em uma String
#include <stdio.h>
#define True 1
#define False 0
int main(){
char input[100];/// = "boa noite pessoal";
printf("\nDigite uma frase ate 99 caracteres:");
fgets(input,100,stdin);
int contaPalavras = 0;
char *ptr = input;
int x = False;



while (*ptr!='\0'){///igual input[i]!='\0'
        if (*ptr == ' ' || *ptr == '\t' || *ptr=='\n'){
            x = False;
        }
        else if(!x){
            x = True;
            contaPalavras++;
        }
    ptr++;
}



printf("\nQtde de palavras: %d",contaPalavras);





return 0;
}

#include <stdio.h>

#include <string.h>



int main()

{
    char maiuscula, minuscula;

printf ("digite a letra minuscula: ");
scanf ("%c", &minuscula);
maiuscula = minuscula - 32;

printf ("letra maiuscula: %c", maiuscula);
 return 0;
}



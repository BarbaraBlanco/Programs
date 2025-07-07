#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char data[15];
    int check = 0;
    printf("Digite uma data no formato dd/mm/aaaa: ");
    fgets(data, sizeof(data), stdin);

    if(!(isdigit(data[0]) && isdigit(data[1])))
    {
        check = 1;
    }
    if(!(data[2] == '/' && data[5] == '/'))
    {
        check = 1;
    }
    if(!(isdigit(data[3]) && isdigit(data[4])))
    {
        check = 1;
    }
    if(!(isdigit(data[6]) && isdigit(data[7]) && isdigit(data[8])))
    {
        check = 1;
    }
    if (!(isdigit(data[9])))
        {
           check = 1;
        }
    if (check == 1)
    {
        printf("A data nao esta no formato");
    }
    else
    {
        printf("A data esta no formato");
    }
    return 0;
}

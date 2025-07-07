#include <stdio.h>

int verificaSubstring(const char *str1, const char *str2) {
    while (*str1 != '\0') {
        const char *p1 = str1;
        const char *p2 = str2;

        while (*p1 == *p2 && *p2 != '\0') {
            p1++;
            p2++;
        }

        if (*p2 == '\0') {
            return 1;
        }

        str1++;
    }

    return 0;}

int main() {
    const char *string1 = "Isso é uma string de exemplo.";
    const char *string2 = "exemplo";

    int resultado = verificaSubstring(string1, string2);

    if (resultado) {
        printf("A segunda string ocorre dentro da primeira.\n");
    } else {
        printf("A segunda string NÃO ocorre dentro da primeira.\n");
    }

    return 0;}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Definição dos tipos de token
enum {
    INT,
    IDENTIFIER,
    NUMBER,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    EQUALS,
    SEMICOLON,
    IF,
    ELSE,
    LEFT_BRACE,
    RIGHT_BRACE,
    LEFT_PAREN,
    RIGHT_PAREN,
    END_OF_FILE,
    ERROR
};

// Função para verificar o tipo de token
int checkToken(char *token) {
    if (strcmp(token, "int") == 0) {
        return INT;
    } else if (strcmp(token, "if") == 0) {
        return IF;
    } else if (strcmp(token, "else") == 0) {
        return ELSE;
    } else if (strcmp(token, "+") == 0) {
        return PLUS;
    } else if (strcmp(token, "-") == 0) {
        return MINUS;
    } else if (strcmp(token, "*") == 0) {
        return MULTIPLY;
    } else if (strcmp(token, "/") == 0) {
        return DIVIDE;
    } else if (strcmp(token, "=") == 0) {
        return EQUALS;
    } else if (strcmp(token, ";") == 0) {
        return SEMICOLON;
    } else if (strcmp(token, "{") == 0) {
        return LEFT_BRACE;
    } else if (strcmp(token, "}") == 0) {
        return RIGHT_BRACE;
    } else if (strcmp(token, "(") == 0) {
        return LEFT_PAREN;
    } else if (strcmp(token, ")") == 0) {
        return RIGHT_PAREN;
    } else if (isdigit(token[0])) {
        return NUMBER;
    } else if (isalpha(token[0])) {
        return IDENTIFIER;
    } else {
        return ERROR;
    }
}

int main() {
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo");
        return EXIT_FAILURE;
    }

    char token[100];
    int tokenType;

    while (fscanf(fp, "%s", token) != EOF) {
        tokenType = checkToken(token);
        printf("Token: %s, Tipo: %s\n", token, tokenType == INT ? "INT" :
                                          tokenType == IDENTIFIER ? "IDENTIFIER" :
                                          tokenType == NUMBER ? "NUMBER" :
                                          tokenType == PLUS ? "PLUS" :
                                          tokenType == MINUS ? "MINUS" :
                                          tokenType == MULTIPLY ? "MULTIPLY" :
                                          tokenType == DIVIDE ? "DIVIDE" :
                                          tokenType == EQUALS ? "EQUALS" :
                                          tokenType == SEMICOLON ? "SEMICOLON" :
                                          tokenType == IF ? "IF" :
                                          tokenType == ELSE ? "ELSE" :
                                          tokenType == LEFT_BRACE ? "LEFT_BRACE" :
                                          tokenType == RIGHT_BRACE ? "RIGHT_BRACE" :
                                          tokenType == LEFT_PAREN ? "LEFT_PAREN" :
                                          tokenType == RIGHT_PAREN ? "RIGHT_PAREN" :
                                          tokenType == END_OF_FILE ? "END_OF_FILE" :
                                          "ERROR");
    }

    fclose(fp);
    return 0;
}

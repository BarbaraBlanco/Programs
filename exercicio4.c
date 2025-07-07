#include <stdio.h>
#include <stdlib.h>
#include <openssl/sha.h>
#include <string.h>

void print_hash(unsigned char *hash) {
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main() {
    char texto[1000];  
    printf("Por favor digite a  mensagem: ");
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = 0;

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA265((unsigned char*)texto, strlen(texto), hash);


    printf("O Hash SHA-256 da mensagem e:\n");
    print_hash(hash);

    return 0;
}
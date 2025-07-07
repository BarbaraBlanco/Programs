#ifndef VOGALECONSOANTE-EX05_H_INCLUDED
#define VOGALECONSOANTE-EX05_H_INCLUDED

void vogaleconsoante(char frase[255], int resultados[2]) {
    resultados[0] = 0;
    resultados[1] = 0;

    for (int i = 0; i < strlen(frase); i++) {
        if (isalpha(frase[i])) {
            if (frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' ||  frase[i] == 'u' || frase[i] == 'A' || frase[i] == 'E' || frase[i] == 'I' || frase[i] == 'O' ||  frase[i] == 'U' ) {
                resultados[0]++;
            } else {
                resultados[1]++;
            }
        }
    }
}

#endif // VOGALECONSOANTE-EX05_H_INCLUDED

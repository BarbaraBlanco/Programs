#ifndef NUMEROALEATORIO-EX04_H_INCLUDED
#define NUMEROALEATORIO-EX04_H_INCLUDED

int gerarNumeroAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}


int receberPalpite() {
    int palpite;
    printf("Digite seu palpite: ");
    scanf("%d", &palpite);
    return palpite;
}

#endif // NUMEROALEATORIO-EX04_H_INCLUDED

#include <stdio.h>
#define N 5 // Tamanho do labirinto

int maze[N][N] = {
    {1, 0, 0, 0, 0},
    {1, 1, 1, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 1, 1, 1, 1},
    {0, 0, 0, 0, 1}
};

void printMaze(int maze[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int solveMazeUtil(int x, int y) {
    // Verifica se (x, y) está dentro dos limites do labirinto
    if (x < 0 || y < 0 || x >= N || y >= N) {
        return 0; // Fora dos limites
    }
    if (maze[x][y] == 0) {
        return 0; // Caminho bloqueado
    }
    if (x == N - 1 && y == N - 1) {
        return 1; // Chegou ao destino
    }

    // Marcar a posição como parte da solução
    maze[x][y] = 0;

    // Tentar mover em todas as direções
    if (solveMazeUtil(x + 1, y) || // Abaixo
        solveMazeUtil(x, y + 1) || // Direita
        solveMazeUtil(x - 1, y) || // Acima
        solveMazeUtil(x, y - 1)) { // Esquerda
        return 1;
    }

    // Se nenhum movimento levar ao destino, desmarcar a posição
    maze[x][y] = 1;
    return 0;
}

int solveMaze() {
    if (solveMazeUtil(0, 0)) {
        printf("Solução encontrada!\n");
        printMaze(maze);
    } else {
        printf("Solução não existe.\n");
    }
    return 0;
}

int main() {
    solveMaze();
    return 0;
}

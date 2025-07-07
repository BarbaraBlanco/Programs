#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define MINES 10

typedef struct {
    int hasMine;
    int revealed;
    int adjacentMines;
} Cell;

// Função para inicializar o tabuleiro
Cell** initializeBoard(int width, int height, int mines) {
    // Alocar memória para o tabuleiro
    Cell **board = (Cell **)malloc(width * sizeof(Cell *));
    for (int i = 0; i < width; i++) {
        board[i] = (Cell *)malloc(height * sizeof(Cell));
    }

    // Inicializar células do tabuleiro
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            board[x][y].hasMine = 0;
            board[x][y].revealed = 0;
            board[x][y].adjacentMines = 0;
        }
    }

    srand(time(NULL));

    // Colocar minas aleatoriamente
    for (int i = 0; i < mines; i++) {
        int x, y;
        do {
            x = rand() % width;
            y = rand() % height;
        } while (board[x][y].hasMine);
        board[x][y].hasMine = 1;
    }

    // Calcular minas adjacentes
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            if (board[x][y].hasMine) continue;
            int count = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < width && ny >= 0 && ny < height && board[nx][ny].hasMine) {
                        count++;
                    }
                }
            }
            board[x][y].adjacentMines = count;
        }
    }

    return board;
}

// Função para liberar a memória do tabuleiro
void freeBoard(Cell **board, int width) {
    for (int i = 0; i < width; i++) {
        free(board[i]);
    }
    free(board);
}

// Função para imprimir o tabuleiro
void printBoard(Cell **board, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (board[x][y].revealed) {
                if (board[x][y].hasMine) {
                    printf("* ");
                } else {
                    printf("%d ", board[x][y].adjacentMines);
                }
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// Função para revelar uma célula
void revealCell(Cell **board, int x, int y, int width, int height) {
    if (x < 0 || x >= width || y < 0 || y >= height || board[x][y].revealed) {
        return;
    }
    board[x][y].revealed = 1;

    if (board[x][y].adjacentMines == 0 && !board[x][y].hasMine) {
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                revealCell(board, x + dx, y + dy, width, height);
            }
        }
    }
}

// Função para verificar se o jogador ganhou
int checkWin(Cell **board, int width, int height) {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            if (!board[x][y].revealed && !board[x][y].hasMine) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    Cell **board = initializeBoard(WIDTH, HEIGHT, MINES);

    while (1) {
        printBoard(board, WIDTH, HEIGHT);
        int x, y;
        printf("Enter coordinates to reveal (x y): ");
        scanf("%d %d", &x, &y);

        if (board[x][y].hasMine) {
            printf("You hit a mine! Game over.\n");
            break;
        }

        revealCell(board, x, y, WIDTH, HEIGHT);

        if (checkWin(board, WIDTH, HEIGHT)) {
            printf("You revealed all cells! You win!\n");
            break;
        }
    }

    freeBoard(board, WIDTH);

    return 0;
}

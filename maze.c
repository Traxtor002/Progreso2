#include <stdio.h>
#include "maze.h"

int maze[5][5] = {
    {0, 1, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {1, 0, 0, 1, 0}
};

void printMaze(int playerRow, int playerCol) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == playerRow && j == playerCol) {
                printf("X ");
            } else {
                printf("%d ", maze[i][j]);
            }
        }
        printf("\n");
    }
}

int isValidMove(int newRow, int newCol) {
    if (newRow < 0 || newRow >= 5 || newCol < 0 || newCol >= 5 || maze[newRow][newCol] == 1) {
        return 0; // Movimiento inválido
    }
    return 1; // Movimiento válido
}

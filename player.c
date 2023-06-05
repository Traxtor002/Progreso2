#include <stdio.h>
#include "maze.h"
#include "player.h"

int playerRow = 0;
int playerCol = 0;
int moveCount = 0;

void printPlayerPosition() {
    printf("Posición del jugador: (%d, %d)\n", playerRow, playerCol);
}

void updatePlayerPosition(int newRow, int newCol) {
    playerRow = newRow;
    playerCol = newCol;
    moveCount++;
}

int hasWon() {
    if (playerRow == 4 && playerCol == 4) {
        return 1; // Jugador ha ganado
    }
    return 0; // Jugador no ha ganado
}

void startGame() {
    printMaze(int playerRow, int playerCol);
    printf("\n");

    while (!hasWon()) {
        char direction;
        printf("Elige una dirección (WASD): ");
        scanf(" %c", &direction);

        int newRow = playerRow;
        int newCol = playerCol;

        switch (direction) {
            case 'W':
            case 'w':
                newRow--;
                break;
            case 'A':
            case 'a':
                newCol--;
                break;
            case 'S':
            case 's':
                newRow++;
                break;
            case 'D':
            case 'd':
                newCol++;
                break;
            default:
                printf("Dirección inválida\n");
                continue;
        }

        if (isValidMove(newRow, newCol)) {
            updatePlayerPosition(newRow, newCol);
            printMaze();
            printf("\n");
            printPlayerPosition();
        } else {
            printf("Movimiento inválido\n");
        }
    }

    printf("¡Ganaste!\n");
    printf("Movimientos: %d\n", moveCount);

    if (moveCount <= 8) {
        printf("Eres un Pro!\n");
    } else if (moveCount <= 15) {
        printf("Eres novato\n");
    } else {
        printf("Eres un noob!\n");
    }
}

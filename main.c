#include <ncurses.h>
#include "maze.h"
#include "player.h"

void initializeNcurses() {
    initscr(); // Inicializar la pantalla de ncurses
    cbreak();  // Deshabilitar el búfer de línea
    noecho();  // No mostrar los caracteres escritos por el usuario
    keypad(stdscr, TRUE); // Habilitar el uso de las teclas especiales

    refresh(); // Actualizar la pantalla
}

void cleanupNcurses() {
    endwin(); // Restaurar la configuración de la terminal
}

void startGame() {
    initializeNcurses();

    printw("Bienvenido al Laberinto\n\n");
    refresh();

    printMaze();
    printw("\n");
    refresh();

    while (!hasWon()) {
        int ch = getch(); // Leer la entrada del usuario

        int newRow = playerRow;
        int newCol = playerCol;

        switch (ch) {
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
                printw("Dirección inválida\n");
                continue;
        }

        if (isValidMove(newRow, newCol)) {
            updatePlayerPosition(newRow, newCol);
            clear(); // Limpiar la pantalla
            printMaze();
            printw("\n");
            refresh();
        } else {
            printw("Movimiento inválido\n");
            refresh();
        }
    }

    printw("¡Ganaste!\n");
    printw("Movimientos: %d\n", moveCount);
    refresh();

    if (moveCount <= 8) {
        printw("Eres un Pro!\n");
    } else if (moveCount <= 15) {
        printw("Eres novato\n");
    } else {
        printw("Eres un noob!\n");
    }

    refresh();

    getch(); // Esperar a que el usuario presione una tecla
    cleanupNcurses();
}

int main() {
    int option;

    do {
        printf("Bienvenido al Laberinto\n");
        printf("1. Jugar\n");
        printf("2. Créditos\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                startGame();
                break;
            case 2:
                printf("Los créditos son para David Cabrera Santamaría, A00109191\n");
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida\n");
                break;
        }

        printf("\n");
    } while (option != 3);

    return 0;
}

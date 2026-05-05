#include <stdio.h>

#define TAMANO 8

int main() {
    // Declaramos la matriz de 8x8
    char tablero[TAMANO][TAMANO];
    int i, j;

    // Llenamos la matriz con el carácter 'o'
    for (i = 0; i < TAMANO; i++) {
        for (j = 0; j < TAMANO; j++) {
            tablero[i][j] = 'o';
        }
    }

    // Imprimimos el tablero con formato
    printf("   Batalla Naval\n\n");
    


    // Imprimir filas
    for (i = 0; i < TAMANO; i++) {
        for (j = 0; j < TAMANO; j++) {
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}

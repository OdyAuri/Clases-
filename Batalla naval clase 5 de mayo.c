#include <stdio.h>

#define lim 8

// Función para imprimir el tablero
void imprimirTablero(char tablero[lim][lim]) {
    printf("\n   ");
    for (int j = 0; j < lim; j++) printf("%d ", j);
    printf("\n");

    for (int i = 0; i < lim; i++) {
        printf("%d  ", i);
        for (int j = 0; j < lim; j++) {
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char tablero[lim][lim];
    int fila, col;
    int barcosColocados = 0;
    int maxBarcos = 8;

    // Inicializar tablero
    for (int i = 0; i < lim; i++) {
        for (int j = 0; j < lim; j++) {
            tablero[i][j] = 'O';
        }
    }

    while (barcosColocados < maxBarcos) {
        imprimirTablero(tablero);
        printf("\nColocando barco %d de %d (ocupa 2 espacios horizontales)\n", barcosColocados + 1, maxBarcos);
        printf("Introduce fila (0-7): ");
        scanf("%d", &fila);
        printf("Introduce columna (0-6): "); // Restricción visual
        scanf("%d", &col);

        // --- VALIDACIONES ---
        
        // 1. Validar límites generales
        if (fila < 0 || fila >= lim || col < 0 || col >= (lim - 1)) {
            printf("\n¡Error! Coordenada inválida. Recuerda que la columna máxima es %d para que el barco quepa.\n", lim - 2);
        }
        // 2. Validar si el espacio ya está ocupado
        else if (tablero[fila][col] == 'X' || tablero[fila][col + 1] == 'X') {
            printf("\n¡Error! Espacio ya ocupado por otro barco.\n");
        } 
        // 3. Colocación exitosa
        else {
            tablero[fila][col] = 'X';     // Parte izquierda
            tablero[fila][col + 1] = 'X'; // Parte derecha (el "espacio del lado derecho")
            barcosColocados++;
            printf("\n¡Barco colocado con éxito!\n");
        }
    }

    imprimirTablero(tablero);
    printf("\nTodos los barcos han sido desplegados.\n");

    return 0;
}
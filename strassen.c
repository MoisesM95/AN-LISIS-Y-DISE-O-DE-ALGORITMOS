#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Aquí van las funciones de multiplicación de matrices y las operaciones de suma/resta
// Como ejemplo, sólo se muestra el método Strassen, pero puedes hacer lo mismo con otros métodos

void multiplicar_matrices_strassen(int A[][10], int B[][10], int C[][10], int n) {
    // Implementación de Strassen (como en el código anterior)
}

void imprimir_matriz(int matriz[][10], int n) {
    // Imprimir la matriz
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 4; // Tamaño de la matriz (puede ser cualquier potencia de 2)

    // Definición de matrices A y B
    int A[10][10] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};
    
    int B[10][10] = {{16, 15, 14, 13},
                     {12, 11, 10, 9},
                     {8, 7, 6, 5},
                     {4, 3, 2, 1}};
    
    int C[10][10];  // Matriz para almacenar el resultado de la multiplicación
    
    // Medir el tiempo de ejecución
    clock_t start_time, end_time;
    double execution_time;

    // Iniciar el cronómetro
    start_time = clock();

    // Llamar al método Strassen para multiplicar
    multiplicar_matrices_strassen(A, B, C, n);

    // Detener el cronómetro
    end_time = clock();

    // Calcular el tiempo de ejecución
    execution_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    // Imprimir el tiempo de ejecución
    printf("\nTiempo de ejecución (Strassen): %f segundos\n", execution_time);
    
    return 0;
}

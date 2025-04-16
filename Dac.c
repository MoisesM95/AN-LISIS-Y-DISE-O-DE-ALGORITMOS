#include <stdio.h>

void multiplicar_matrices_dac(int A[][10], int B[][10], int C[][10], int n) {
    // Si la matriz es de tamaño 1x1, multiplicamos directamente
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
    } else {
        int m = n / 2;
        
        // Submatrices de A
        int A11[10][10], A12[10][10], A21[10][10], A22[10][10];
        // Submatrices de B
        int B11[10][10], B12[10][10], B21[10][10], B22[10][10];
        // Submatrices de C
        int C11[10][10], C12[10][10], C21[10][10], C22[10][10];
        
        // Dividir las matrices A y B en 4 submatrices
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + m];
                A21[i][j] = A[i + m][j];
                A22[i][j] = A[i + m][j + m];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + m];
                B21[i][j] = B[i + m][j];
                B22[i][j] = B[i + m][j + m];
            }
        }

        // C11 = A11 * B11 + A12 * B21
        multiplicar_matrices_dac(A11, B11, C11, m);
        multiplicar_matrices_dac(A12, B21, C12, m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                C11[i][j] += C12[i][j];
            }
        }

        // C12 = A11 * B12 + A12 * B22
        multiplicar_matrices_dac(A11, B12, C11, m);
        multiplicar_matrices_dac(A12, B22, C12, m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                C12[i][j] += C12[i][j];
            }
        }

        // C21 = A21 * B11 + A22 * B21
        multiplicar_matrices_dac(A21, B11, C21, m);
        multiplicar_matrices_dac(A22, B21, C22, m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                C21[i][j] += C22[i][j];
            }
        }

        // C22 = A21 * B12 + A22 * B22
        multiplicar_matrices_dac(A21, B12, C21, m);
        multiplicar_matrices_dac(A22, B22, C22, m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                C22[i][j] += C22[i][j];
            }
        }

        // Unir las submatrices para formar la matriz C
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                C[i][j] = C11[i][j];
                C[i][j + m] = C12[i][j];
                C[i + m][j] = C21[i][j];
                C[i + m][j + m] = C22[i][j];
            }
        }
    }
}

void imprimir_matriz(int matriz[][10], int n) {
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
    
    // Llamar a la función de multiplicación
    multiplicar_matrices_dac(A, B, C, n);
    
    // Imprimir las matrices y el resultado
    printf("Matriz A:\n");
    imprimir_matriz(A, n);
    printf("\nMatriz B:\n");
    imprimir_matriz(B, n);
    printf("\nResultado de A * B:\n");
    imprimir_matriz(C, n);
    
    return 0;
}

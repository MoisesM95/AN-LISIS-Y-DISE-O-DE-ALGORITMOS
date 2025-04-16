#include<stdio.h>

void multiplicar_matrices(int A[][10], int B[][10], int C[][10], int n) //realizar multiplicación de matrices
    {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                C[i][j] = 0; //inicializar el valor en c[i][j]
                for(int k = 0; k < n; k++){
                    C[i][j] += A[i][k] * B[k][j] * B[k][j]; //suma de los productos
                }
            }
        }
    }



void imprimir_matriz(int matriz[][10], int n)
    //imprimir la matriz
    {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                printf("%d", matriz[i][j]);
            }
            printf("\n");
        }
    }

    int main() {

        int n = 4; //Tamaño  de la matriz (puede ser cualquier potencia de 2)

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
multiplicar_matrices(A, B, C, n);

// Imprimir las matrices y el resultado
printf("Matriz A:\n");
imprimir_matriz(A, n);
printf("\nMatriz B:\n");
imprimir_matriz(B, n);
printf("\nResultado de A * B:\n");
imprimir_matriz(C, n);

return 0;
    }
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 5

int main() {
    int i, j, k;
    int A[SIZE][SIZE], B[SIZE][SIZE];

    // Read matrix A from standard input
    printf("Enter matrix A (%d x %d):\n", SIZE, SIZE);
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Compute matrix B
    #pragma omp parallel for private(j, k)
    for (i = 0; i < SIZE; i++) {
        // Set diagonal element to 0
        B[i][i] = 0;

        // Find maximum and minimum values of row i in matrix A
        int max_val = A[i][0];
        int min_val = A[i][0];
        for (j = 0; j < SIZE; j++) {
            if (A[i][j] > max_val) {
                max_val = A[i][j];
            }
            if (A[i][j] < min_val) {
                min_val = A[i][j];
            }
        }

        // Replace elements in row i of matrix B
        for (j = 0; j < SIZE; j++) {
            if (j < i) {
                B[i][j] = min_val;
            } else if (j > i) {
                B[i][j] = max_val;
            }
        }
    }

    // Print matrix B
    printf("Matrix B (%d x %d):\n", SIZE, SIZE);
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    return 0;
}



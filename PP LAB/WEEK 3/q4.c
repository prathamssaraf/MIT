#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define M 4
#define N 4

int main() {
    int i, j;
    int A[M][N], B[M][N], D[M][N];

    // Read matrix A from standard input
    printf("Enter matrix A (%d x %d):\n", M, N);
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Compute matrix B and D
    #pragma omp parallel for private(j)
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            // Compute 1's complement for non-border elements
            if (i != 0 && j != 0 && i != M-1 && j != N-1) {
                B[i][j] = ~A[i][j] & 0x0000FFFF;
            } else {
                B[i][j] = A[i][j];
            }

            // Compute matrix D
            if (i == 0 || j == 0 || i == M-1 || j == N-1) {
                D[i][j] = 1;
            } else {
                D[i][j] = 0;
            }
        }
    }

    // Print matrix B
    printf("Matrix B (%d x %d):\n", M, N);
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    // Print matrix D
    printf("Matrix D (%d x %d):\n", M, N);
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", D[i][j]);
        }
        printf("\n");
    }

    return 0;
}


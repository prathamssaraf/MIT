#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 1000

int main() {
    int i, j;
    double start, end;
    int A[SIZE][SIZE], x[SIZE], y[SIZE];

    // Initialize matrix A and vector x
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            A[i][j] = i + j;
        }
        x[i] = i;
    }

    // Perform matrix times vector multiplication
    start = omp_get_wtime();  // Record start time
    #pragma omp parallel for private(j)
    for (i = 0; i < SIZE; i++) {
        y[i] = 0;
        for (j = 0; j < SIZE; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
    end = omp_get_wtime();  // Record end time

    // Print runtime and vector y
    printf("Runtime: %f seconds\n", end - start);
    printf("y[0] = %d, y[SIZE-1] = %d\n", y[0], y[SIZE-1]);

    return 0;
}


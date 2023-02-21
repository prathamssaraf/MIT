#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 9

int reverse(int n) {
    int rev = 0;
    while (n > 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return rev;
}

int main() {
    int i, j;
    int A[SIZE] = {18, 523, 301, 1234, 2, 14, 108, 150, 1928};
    int B[SIZE], D[SIZE];

    // Reverse the digits of each element in A
    #pragma omp parallel for
    for (i = 0; i < SIZE; i++) {
        B[i] = reverse(A[i]);
    }

    // Compute D matrix
    #pragma omp parallel for private(j)
    for (i = 0; i < SIZE; i++) {
        D[i] = 0;
        for (j = 0; j < SIZE; j++) {
            if (j != i && (i == 0 || i == SIZE-1 || j == 0 || j == SIZE-1)) {
                D[i] += B[j];
            } else {
                D[i] += A[j];
            }
        }
    }

    // Print arrays A, B, and D
    printf("Input array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    printf("Output array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");

    printf("D matrix:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", (i == j ? A[i] : D[i]));
        }
        printf("\n");
    }

    return 0;
}


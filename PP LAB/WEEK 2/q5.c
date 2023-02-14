#include <omp.h>
#include <stdio.h>

#define SIZE 4

int main()
{
    int i;
    int A[SIZE] = {1, 2, 3, 4};
    int B[SIZE] = {5, 6, 7, 8};
    int C[SIZE];

    // Perform addition
    #pragma omp parallel for
    for (i = 0; i < SIZE; i++)
    {
        C[i] = A[i] + B[i];
    }
    printf("Addition: ");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", C[i]);
    }
    printf("\n");

    // Perform subtraction
    #pragma omp parallel for
    for (i = 0; i < SIZE; i++)
    {
        C[i] = A[i] - B[i];
    }
    printf("Subtraction: ");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", C[i]);
    }
    printf("\n");

    // Perform multiplication
    #pragma omp parallel for
    for (i = 0; i < SIZE; i++)
    {
        C[i] = A[i] * B[i];
    }
    printf("Multiplication: ");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", C[i]);
    }
    printf("\n");

    // Perform division
    #pragma omp parallel for
    for (i = 0; i < SIZE; i++)
    {
        C[i] = A[i] / B[i];
    }
    printf("Division: ");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", C[i]);
    }
    printf("\n");

    return 0;
}


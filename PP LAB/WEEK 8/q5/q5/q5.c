#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"

int is_prime(int n) {
    int i;

    if (n <= 1) {
        return 0;
    }

    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main(int argc, char* argv[]) {
    int rank, size;
    int* array, * subarray;
    int n, sub_n, i;
    int* is_prime_array;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        // Read an array of N elements in the root process
        printf("Enter the number of elements in the array: ");
        scanf("%d", &n);

        array = (int*)malloc(n * sizeof(int));
        for (i = 0; i < n; i++) {
            printf("Enter element %d: ", i + 1);
            scanf("%d", &array[i]);
        }

        // Distribute the array among N processes (including the master process)
        sub_n = n / size;
        for (i = 1; i < size; i++) {
            MPI_Send(&array[i * sub_n], sub_n, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
        subarray = array;
    }
    else {
        // Receive the portion of the array from the root process
        sub_n = n / size;
        subarray = (int*)malloc(sub_n * sizeof(int));
        MPI_Recv(subarray, sub_n, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    // Check whether the portion of the array is prime or not
    is_prime_array = (int*)malloc(sub_n * sizeof(int));
    for (i = 0; i < sub_n; i++) {
        is_prime_array[i] = is_prime(subarray[i]);
    }

    // Send the result back to the root process
    if (rank == 0) {
        for (i = 1; i < size; i++) {
            MPI_Recv(&is_prime_array[i * sub_n], sub_n, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }

        // Print the result
        printf("The prime numbers in the array are:\n");
        for (i = 0; i < n; i++) {
            if (is_prime_array[i]) {
                printf("%d\n", array[i]);
            }
        }

        free(array);
    }
    else {
        MPI_Send(is_prime_array, sub_n, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}

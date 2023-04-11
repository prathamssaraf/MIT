#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

#define N 4

int main(int argc, char* argv[]) {
    int rank, size;
    int array[N];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        // Read N elements of the array in the root process
        printf("Enter %d elements of the array:\n", N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &array[i]);
        }

        // Send one value to each of the slaves
        for (int i = 1; i < size; i++) {
            MPI_Bsend(&array[i - 1], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
    }
    else {
        int value;
        MPI_Recv(&value, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        // Compute the square or cube of the received element based on rank
        int result;
        if (rank % 2 == 0) {
            result = value * value;
        }
        else {
            result = value * value * value;
        }

        printf("Process %d computed result: %d\n", rank, result);
    }

    MPI_Finalize();
    return 0;
}

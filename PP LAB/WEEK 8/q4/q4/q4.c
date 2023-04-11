#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

int main(int argc, char* argv[]) {
    int rank, size;
    int value;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        // Read an integer value in the root process
        printf("Enter an integer value: ");
        scanf_s("%d", &value);

        // Send the value to Process 1
        MPI_Send(&value, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);

        // Receive the value from the last process
        MPI_Recv(&value, 1, MPI_INT, size - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        printf("Root process received value: %d\n", value);
    }
    else if (rank == size - 1) {
        // Receive the value from the previous process
        MPI_Recv(&value, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        // Increment the value by one
        value++;

        // Send the value back to the root process
        MPI_Send(&value, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    else {
        // Receive the value from the previous process
        MPI_Recv(&value, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        // Increment the value by one
        value++;

        // Send the value to the next process
        MPI_Send(&value, 1, MPI_INT, rank + 1, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}

#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int num1, num2, result;

    if (rank == 0) {
        printf("Enter two numbers: ");
        scanf("%d%d", &num1, &num2);
    }

    MPI_Bcast(&num1, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&num2, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 1) {
        result = num1 + num2;
    }
    else if (rank == 2) {
        result = num1 - num2;
    }
    else if (rank == 3) {
        result = num1 * num2;
    }
    else if (rank == 4) {
        result = num1 / num2;
    }

    MPI_Reduce(&result, &result, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Result: %d\n", result);
    }

    MPI_Finalize();
    return 0;
}

#include <stdio.h>
#include <math.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int x = 2; // constant integer
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    double result = pow(x, rank); // calculate pow(x, rank)

    printf("Process %d of %d: pow(%d, %d) = %f\n", rank, size, x, rank, result);

    MPI_Finalize();
    return 0;
}

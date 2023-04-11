#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int rank, size;
    char str[100];
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        printf("Enter a string: ");
        scanf_s("%s", str);
    }

    MPI_Bcast(str, 100, MPI_CHAR, 0, MPI_COMM_WORLD); // broadcast the string to all processes

    int len = strlen(str);
    if (rank < len) {
        if (str[rank] >= 'a' && str[rank] <= 'z') {
            str[rank] = str[rank] - 'a' + 'A'; // toggle lower case to upper case
        }
        else if (str[rank] >= 'A' && str[rank] <= 'Z') {
            str[rank] = str[rank] - 'A' + 'a'; // toggle upper case to lower case
        }
    }

    MPI_Gather(str + rank, 1, MPI_CHAR, str, 1, MPI_CHAR, 0, MPI_COMM_WORLD); // gather the toggled string to process 0

    if (rank == 0) {
        printf("Toggled string: %s\n", str);
    }

    MPI_Finalize();
    return 0;
}

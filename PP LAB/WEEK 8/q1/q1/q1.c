#include <stdio.h>
#include <string.h>
#include "mpi.h"

int main(int argc, char* argv[]) {
    int rank, size;
    char word[50];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size != 2) {
        printf("This program requires exactly 2 processes.\n");
        MPI_Finalize();
        return 0;
    }

    if (rank == 0) {
        printf("Enter a word: ");
        scanf("%s", word);

        MPI_Ssend(word, strlen(word), MPI_CHAR, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(word, strlen(word), MPI_CHAR, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        printf("Received word: %s\n", word);
    }
    else if (rank == 1) {
        MPI_Recv(word, 50, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        for (int i = 0; i < strlen(word); i++) {
            if (word[i] >= 'a' && word[i] <= 'z') {
                word[i] = 'a' + ('z' - word[i]);
            }
            else if (word[i] >= 'A' && word[i] <= 'Z') {
                word[i] = 'A' + ('Z' - word[i]);
            }
        }

        MPI_Ssend(word, strlen(word), MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}

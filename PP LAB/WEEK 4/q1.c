#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

void selection_sort(int *arr, int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

int main() {
    int n, *arr, i, j;
    double start, end, elapsed;

    // Vary input size
    for (n = 1000; n <= 10000; n += 1000) {
        arr = (int*) malloc(n * sizeof(int));
        for (i = 0; i < n; i++) {
            arr[i] = rand() % 1000;
        }

        // Vary number of threads
        for (j = 1; j <= 8; j++) {
            omp_set_num_threads(j);

            start = omp_get_wtime();
            selection_sort(arr, n);
            end = omp_get_wtime();
            elapsed = end - start;

            printf("n = %d, threads = %d, time = %f seconds\n", n, j, elapsed);
        }

        free(arr);
    }

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int sequential_search(int *arr, int n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int parallel_search(int *arr, int n, int x, int num_threads) {
    int i, index = -1;
    #pragma omp parallel num_threads(num_threads)
    {
        int local_index = -1;
        #pragma omp for
        for (i = 0; i < n; i++) {
            if (arr[i] == x) {
                local_index = i;
            }
        }
        #pragma omp critical
        {
            if (local_index != -1 && index == -1) {
                index = local_index;
            }
        }
    }
    return index;
}

int main() {
    int n = 1000000, i, x = 54321;
    int *arr = (int*) malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        arr[i] = rand() % 1000000;
    }

    double start_time = omp_get_wtime();
    int index = sequential_search(arr, n, x);
    double end_time = omp_get_wtime();
    printf("Sequential search:\n");
    if (index != -1) {
        printf("Element %d found at index %d\n", x, index);
    }
    else {
        printf("Element %d not found\n", x);
    }
    printf("Time taken: %lf seconds\n\n", end_time - start_time);

    printf("Parallel search:\n");
    for (i = 1; i <= 16; i++) {
        start_time = omp_get_wtime();
        index = parallel_search(arr, n, x, i);
        end_time = omp_get_wtime();
        if (index != -1) {
            printf("Element %d found at index %d with %d threads\n", x, index, i);
        }
        else {
            printf("Element %d not found with %d threads\n", x, i);
        }
        printf("Time taken: %lf seconds\n", end_time - start_time);
        printf("Efficiency: %lf\n", (end_time - start_time) / i / (end_time - start_time));
        printf("Speed up: %lf\n\n", (end_time - start_time) / i / (end_time - start_time) / i);
    }

    free(arr);

    return 0;
}


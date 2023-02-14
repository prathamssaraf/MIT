#include <stdio.h>
#include <omp.h>

void fork_join_1() {
    printf("Fork-Join Example 1\n");
    #pragma omp parallel
    {
        printf("Hello from thread %d\n", omp_get_thread_num());
    }
    printf("\n");
}

void fork_join_2() {
    printf("Fork-Join Example 2\n");
    omp_set_num_threads(2);
    #pragma omp parallel
    {
        printf("Hello from thread %d\n", omp_get_thread_num());
    }
    printf("\n");

    printf("Fork-Join Example 3\n");
    #pragma omp parallel num_threads(4)
    {
        printf("Hello from thread %d\n", omp_get_thread_num());
    }
    printf("\n");
}

void spmd() {
    printf("SPMD Example\n");
    int x;
    #pragma omp parallel private(x)
    {
        x = omp_get_thread_num();
        #pragma omp single
        {
            printf("Hello from thread %d\n", x);
        }
    }
}

int main() {
    fork_join_1();
    fork_join_2();
    spmd();

    return 0;
}

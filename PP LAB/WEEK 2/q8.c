#include <stdio.h>
#include <omp.h>

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    int x, y;
    #pragma omp task shared(x)
    x = fib(n-1);
    #pragma omp task shared(y)
    y = fib(n-2);
    #pragma omp taskwait
    return x + y;
}

int main() {
    int A[] = {10, 13, 5, 6};
    int n = sizeof(A) / sizeof(A[0]);

    #pragma omp parallel
    {
        #pragma omp single
        {
        	int i;
            for ( i = 0; i < n; i++) {
                int f;
                #pragma omp task shared(f)
                f = fib(A[i]);
                #pragma omp taskwait
                printf("Fibonacci(%d) = %d\n", A[i], f);
            }
        }
    }

    return 0;
}


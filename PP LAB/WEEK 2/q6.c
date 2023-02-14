#include <stdio.h>
#include <stdbool.h>
#include <omp.h>

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int start = 2, end = 100;
    #pragma omp parallel
    {
        #pragma omp for
        for (int i = start; i <= end; i++) {
            if (is_prime(i)) {
                #pragma omp critical
                {
                    printf("%d\n", i);
                }
            }
        }
    }
    return 0;
}


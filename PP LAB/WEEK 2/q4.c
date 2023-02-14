#include <stdio.h>
#include <omp.h>

int main() {
    int a = 10, b = 5;
    int result_add, result_sub, result_mul;
    float result_div;

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            result_add = a + b;
            printf("Addition: %d\n", result_add);
        }

        #pragma omp section
        {
            result_sub = a - b;
            printf("Subtraction: %d\n", result_sub);
        }

        #pragma omp section
        {
            result_mul = a * b;
            printf("Multiplication: %d\n", result_mul);
        }

        #pragma omp section
        {
            result_div = (float) a / b;
            printf("Division: %.2f\n", result_div);
        }
    }

    return 0;
}


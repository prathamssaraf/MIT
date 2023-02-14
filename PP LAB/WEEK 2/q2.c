#include <omp.h>
#include <math.h>
#include <stdio.h>

int main() {
  int i = 2;
  int x;
  int result;
  
  #pragma omp parallel private(x, result)
  {
    x = omp_get_thread_num();
    result = pow(i, x);
    printf("Thread %d calculates %d^%d = %d\n", x, i, x, result);
  }
  return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define ARRAY_SIZE 10000000

int main() {
  int *array = (int*)malloc(sizeof(int) * ARRAY_SIZE);
  int i, even_sum = 0, odd_sum = 0, num_threads;
  double start_time, end_time;
  
  // Initialize the array with random values
  for (i = 0; i < ARRAY_SIZE; i++) {
    array[i] = rand();
  }
  
  // Vary the number of threads
  for (num_threads = 1; num_threads <= 8; num_threads++) {
    start_time = omp_get_wtime();
    #pragma omp parallel num_threads(num_threads) shared(array) private(i) reduction(+:even_sum) reduction(+:odd_sum)
    {
      #pragma omp for
      for (i = 0; i < ARRAY_SIZE; i++) {
        if (array[i] % 2 == 0) {
          even_sum += array[i];
        } else {
          odd_sum += array[i];
        }
      }
    }
    end_time = omp_get_wtime();
    double parallel_time = end_time - start_time;
    printf("Parallel time with %d threads: %f\n", num_threads, parallel_time);
    double speedup = (double)(ARRAY_SIZE) / parallel_time / (double)(ARRAY_SIZE) * 2.0 / ((double)(ARRAY_SIZE) / (double)(ARRAY_SIZE % 2 == 0 ? even_sum : odd_sum));
    printf("Speedup with %d threads: %f\n", num_threads, speedup);
    double efficiency = speedup / num_threads;
    printf("Efficiency with %d threads: %f\n", num_threads, efficiency);
  }
  
  free(array);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

void insertion_sort(int *arr, int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1, j, temp;
    for (j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i+1;
}

void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        #pragma omp task
        quick_sort(arr, low, pi-1);
        #pragma omp task
        quick_sort(arr, pi+1, high);
    }
}

void merge(int *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int*) malloc(n1 * sizeof(int));
    int *R = (int*) malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void merge_sort(int *arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        #pragma omp task
        merge_sort(arr, l, m);
        #pragma omp task
        merge_sort(arr, m+1, r);
        #pragma omp taskwait
        merge(arr, l, m, r);
    }
}

int main() {
    int m = 10, i;
    int *arr = (int*) malloc(m * sizeof(int));
	 double start, end, elapsed;
    printf("Unsorted Array: ");
    for (i = 0; i < m; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");
	
	 start = omp_get_wtime();
    #pragma omp parallel num_threads(2)
    {
            #pragma omp sections
    {
        #pragma omp section
        {
            insertion_sort(arr, m/2);
        }

        #pragma omp section
        {
            quick_sort(arr, m/2, m-1);
        }
    }

    #pragma omp taskwait
    merge_sort(arr, 0, m-1);
    end = omp_get_wtime();
    elapsed = end - start;
   
}

printf("Sorted Array: ");
for (i = 0; i < m; i++) {
    printf("%d ", arr[i]);
}
printf("\n");
printf("time:  %f seconds\n", elapsed);
free(arr);

return 0;
}


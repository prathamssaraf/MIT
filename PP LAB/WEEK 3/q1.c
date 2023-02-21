#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#include<time.h>

void initialise(int **arr, int r){
	int i,j;
    for( i = 0; i < r; i++){
        for( j = 0; j < r; j++){
            arr[i][j] = (i*j+j)%5;
        }
    }
}

void multiply(int **m1, int **m2, int r, int **ans, int NUM_THREADS){
	int i,j,k;
    #pragma omp parallel for num_threads(NUM_THREADS)
    
    for( i = 0; i < r; i++){
        for( j = 0; j < r; j++){
            ans[i][j] = 0;
            for( k = 0; k < r; k++){
                ans[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

int main(){
    int **m1, **m2, **ans;
    int r;
    scanf("%d", &r);

    m1 = (int**) malloc(r * sizeof(int*));
    m2 = (int**) malloc(r * sizeof(int*));
    ans = (int**) malloc(r * sizeof(int*));
	int i;
    for( i = 0; i < r; i++){
        m1[i] = (int*) malloc(r * sizeof(int));
        m2[i] = (int*) malloc(r * sizeof(int));
        ans[i] = (int*) malloc(r * sizeof(int));
    }

    initialise(m1, r);
    initialise(m2, r);

    clock_t start, end;
    double t_seq, t_par;

    start = clock();
    multiply(m1, m2, r, ans, 1);
    end = clock();
    t_seq = ((double) (end - start)) / CLOCKS_PER_SEC;

    start = clock();
    multiply(m1, m2, r, ans, 4);
    end = clock();
    t_par = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Size of matrices: %d\n", r);
    printf("Time taken for sequential execution: %f\n", t_seq);
    printf("Time taken for parallel execution: %f\n", t_par);

    double speed_up = t_seq / t_par;
    printf("SpeedUp: %f\n", speed_up);

    int num_threads = omp_get_max_threads();
    double efficiency = speed_up / num_threads;
    printf("Efficiency: %f\n", efficiency);
	
    for( i = 0; i < r; i++){
        free(m1[i]);
        free(m2[i]);
        free(ans[i]);
    }
    free(m1);
    free(m2);
    free(ans);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <malloc.h> 

int min(int *v, int n);
int max(int *v, int n);
int *new_0(int n);
int *distribution_sort(int *v, int n);
int *vetor (unsigned int n);


int min(int *v, int n) {
    int min_val = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] < min_val) {
            min_val = v[i];
        }
    }
    return min_val;
}

int max(int *v, int n) {
    int max_val = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > max_val) {
            max_val = v[i];
        }
    }
    return max_val;
}

int *new_0(int n) {
    int *v = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        v[i] = 0;
    }
    return v;
}

int *distribution_sort(int *v, int n) {
    int i, j;
    int l = min(v, n);
    int b = max(v, n);
    int k = b - l + 1;
    int *w = new_0(k);
    int *y = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        w[v[i] - l]++;
    }

    for (j = 1; j <= b - l; j++) {
        w[j] = w[j] + w[j - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        j = w[v[i] - l];
        y[j - 1] = v[i];
        w[v[i] - l]--;
    }

    free(w);
    return y;
}


int main(void) {
    int i, j;
    int*v;
	long int tempo;
	struct timeval a, b;
	srand(time(NULL));
	for (i = 0; i <= 10000; i += 1000){
		tempo = 0;
		
        for (j=0; j < 100; j ++){
			v = vetor(i);
			gettimeofday(&b, NULL);
			distribution_sort(v,i); 
			gettimeofday(&a, NULL);
			tempo = tempo + (((a.tv_sec * 1000000)+ a.tv_usec) - ((b.tv_sec * 1000000) + b.tv_usec));			
		}
		printf("%d  %f\n", i,tempo/100.0);

        size_t allocated_size = malloc_usable_size(v);
            printf("Tamanho de memória alocada: %zu bytes\n", allocated_size);

		free(v);
	
    }

    return 0;

}


int *vetor (unsigned int n){ 
    int *v =  (int*)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){ 
        v[i] = rand() % n;
    }
  
    return v;

}
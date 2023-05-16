#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void insertion_sort(int *v, int n);
int *vetor (unsigned int n);

void insertion_sort(int *v, int n) {
    int i, j, aux;
    for (i = 1; i < n; i++) {
        aux = v[i];

        for(j = i - 1; (j >= 0) && (aux < v[j]); j--) {
            v[j+1] = v[j];
        }
        v[j+1] = aux;
    }
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
			insertion_sort(v, i); 
			gettimeofday(&a, NULL);
			tempo = tempo + (((a.tv_sec * 1000000)+ a.tv_usec) - ((b.tv_sec * 1000000) + b.tv_usec));			
		}
		printf("%d  %f\n", i,tempo/100.0);
		free(v);
	}

    return 0;

}


int *vetor(unsigned int n) {
    int *v = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        v[i] = n - i;
    }
  
    return v;
}

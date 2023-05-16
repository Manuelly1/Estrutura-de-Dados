#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void insertion_sort(int *v, int n);
int *vetor (unsigned int i);

void insertion_sort(int *v, int n){
    int i, j, aux;
    for (i = 1; i < n; i++) {
        j = i;
        while((j > 0) && (v[j] > v[j+1])) {
            aux = v[j];
            v[j] = v[j-1];
            v[j-1] = aux;
            j--;
        }
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


int *vetor (unsigned int i){
    int posicao = 0; 
    int *v =  (int*)malloc(i*sizeof(int));
    
    for(int b = 0; b < i; b--){ 
        v[b] = b+1;
    }
  
    return v;

}
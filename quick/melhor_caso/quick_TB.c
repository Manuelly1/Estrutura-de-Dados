#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>


void quick_sort(int *v, int s, int e);
int partition(int *v, int s, int e);
int *vetor (unsigned int n);


void quick_sort(int *v, int s, int e) {
    int p;
    if(s < e) {
        p = partition(v, s, e);
        quick_sort(v, s, p-1);
        quick_sort(v, p+1, e);
    }
}    


int partition(int *v, int s, int e) {
    int l = s;
    int i, aux;
    for(i=s; i < e; i++) {
        if(v[i] < v[e]) {
            aux = v[i];
            v[i] = v[l];
            v[l] = aux;
            l = l + 1;
        }
    }
    aux = v[e];
    v[e] = v[l];
    v[l] = aux;

    return l;
}


int *vetor (unsigned int i){
    int posicao = 0; 
    int *v =  (int*)malloc(i*sizeof(int));
    
    for(int b = 0; b < i; b--){ 
        v[b] = b+1;
    }
  
    return v;

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
			quick_sort(v, 0, i-1); 
			gettimeofday(&a, NULL);
			tempo = tempo + (((a.tv_sec * 1000000)+ a.tv_usec) - ((b.tv_sec * 1000000) + b.tv_usec));			
		}
		printf("%d  %f\n", i,tempo/100.0);
		free(v);
	}

    return 0;

}





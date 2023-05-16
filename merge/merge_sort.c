#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <sys/time.h>

int *vetor (unsigned int n);
void merge_sort(int *V, int s, int e);
void merge(int *V, int s, int e, int m);

void merge_sort(int *V, int s, int e) {
    int m;
    if(s < e) {
        m = ((s+e) / 2);
        merge_sort(V, s, m);
        merge_sort(V, m+1, e);
        merge(V, s, m, e);
    }
}

void merge(int *V, int s, int e, int m) {
    int i = s;
    int j = m + 1;
    int *M = (int *) malloc((e-s+1) * sizeof(int));

    for(int k = 0; k <= (e-s); k++) {
        if((j>e) || ((i <= m) && (V[i] < V[j]))) {
            M[k] = V[i];
            i = i + 1;
        } else {
            M[k] = V[j];
            j = j + 1;
        }
    }

    for(int k = 0; k <= (e-s); k++) {
        V[s+k] = M[k];
    }
    free(M);
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
			merge_sort(v,0,i); 
			gettimeofday(&a, NULL);
			tempo = tempo + (((a.tv_sec * 1000000)+ a.tv_usec) - ((b.tv_sec * 1000000) + b.tv_usec));			
		}
		printf("%d  %f\n", i,tempo/100.0);
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
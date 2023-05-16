#include <stdio.h>
#include <stdlib.h> 
#include <sys/time.h>


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
            j = j +1;
        }
    }

    for(int k = 0; k <= (e-s); k++) {
        V[s+k] = M[k];
    }
    free(M);
}

int main(){
	int i,j;
	float tempo;
	struct timeval a, b;
	FILE *fp;
	int n = 100;
    fp = fopen ("merge_sort.txt", "w");
	
    while(n<=10000){
	    int v[n];
		tempo = 0;
		
        for(j=0; j<100; j++){
        gettimeofday(&b,NULL);
         for(i=0; i<n; i++){
		    v[i]=rand()%((100-0+1)+1);
		}
        
        merge_sort(v,0,n);
        gettimeofday(&a, NULL);
        tempo = (a.tv_sec + a.tv_usec * 1e-6) - (b.tv_sec + b.tv_usec * 1e-6) + tempo;
		}
		fprintf(fp,"%d %f\n",n,(tempo*1e6)/100);
		n=n+100;
	}	
	
    return 0;

}
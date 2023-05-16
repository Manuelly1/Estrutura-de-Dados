#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

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

int main() {
    int n = 1;
	int i,j;
	float tempo = 0;
	struct timeval a,b;
	FILE *fp;
    fp = fopen ("insertion_sort.txt", "w");
	
    while(n<=10000){
		int v[n];
		for(j=0; j<100; j++){
            gettimeofday(&b,NULL);
             for(i=0; i<n; i++){
    		    v[i]=rand()%((100-0+1)+1);
    		}
    		insertion_sort(v,n);
            gettimeofday(&a,NULL);
    	    tempo =(a.tv_sec+a.tv_usec*1e-6)-(b.tv_sec+b.tv_usec*1e-6)+tempo;
		}
		
        fprintf(fp,"%d %f\n",n,(tempo*1e6)/10);
		tempo =0;
		n = n+100;			
	}

	return 0;

}
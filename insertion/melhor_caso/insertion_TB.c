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
    int n = 1000;
	int i;
	float tempo;
	struct timeval a, b;
	float v;
	FILE *fp;
    fp = fopen ("insertion_sort_melhor.txt", "w");
	
    while(n<=10000){
		int v[n];
        gettimeofday(&b,NULL);
         for(i=0; i<n; i++){
		    v[i]=i;
		}
		
        insertion_sort(v,n);
        gettimeofday(&a,NULL);
	    tempo=(a.tv_sec+a.tv_usec*1e-6)-(b.tv_sec+b.tv_usec*1e-6);
		fprintf(fp,"%d %f\n",n,tempo*1e6);
		n = n + 100;			
	}	
	
    return 0;

}
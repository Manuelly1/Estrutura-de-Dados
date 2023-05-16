#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int partition(int *v, int s, int e);

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

int main(){
    int i;
	float tempo;
	struct timeval a,b;
	float v;
	FILE *fp;
	int n=100;
    fp = fopen ("quick_sort_melhor.txt", "w");
	
    while(n<=10000){
	    int v[n];

        gettimeofday(&b,NULL);
        for(i=0; i<n; i++){
		    v[i]=i;
		}
        quick_sort(v,0,n-1);
        gettimeofday(&a,NULL);
	    tempo =(a.tv_sec+a.tv_usec*1e-6)-(b.tv_sec+b.tv_usec*1e-6);
		fprintf(fp,"%d %f\n",n,tempo*1e6);
		n = n+100;
	}	
	
    return 0;

}

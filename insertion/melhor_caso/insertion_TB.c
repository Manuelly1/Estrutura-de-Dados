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

int main(int argc, char **argv) {
    clock_t start, end;
    unsigned int t, n;
    int i, *v;

    n = atoi(argv[1]);
    v = (int *) malloc(n * sizeof(int));
    srand(time(NULL));
    for (i = 0; i < n; i++)
        v[i] = i;

    start = clock();
    insertion_sort(v, n);
    end = clock();

    t = (unsigned int) ((end - start) / (double) CLOCKS_PER_SEC * 1e9);

    printf("%u\n", t);

    free(v);

    return 0;
    
}
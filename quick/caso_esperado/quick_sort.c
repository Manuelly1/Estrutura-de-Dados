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

int main(int argc, char **argv) {
    clock_t start, end;
    unsigned int t, n;
    int i, *v;

    n = atoi(argv[1]);
    v = (int *) malloc(n * sizeof(int));
    srand(time(NULL));
    for (i = 0; i < n; i++)
        v[i] = rand();

    start = clock();
    quick_sort(v, 0, n-1);
    end = clock();

    t = (unsigned int) ((end - start) / (double) CLOCKS_PER_SEC * 1e9);

    printf("%u\n", t);

    free(v);

    return 0;
    
}
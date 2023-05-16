#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void insertion_sort(int *v, int n);

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
    struct timespec a, b;
    unsigned int t, n;
    int i, *v;

    n = atoi(argv[1]);
    v = (int *) malloc(n * sizeof(int));
    srand(time(NULL));
    for (i = 0; i < n; i++)
        v[i] = rand();

    clock_gettime(CLOCK_MONOTONIC, &b);
    insertion_sort(v, n);
    clock_gettime(CLOCK_MONOTONIC, &a);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

    printf("%u\n", t);

    free(v);

    return 0;
}


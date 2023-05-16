#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <sys/time.h>

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
    merge_sort(v, n, n-1);
    clock_gettime(CLOCK_MONOTONIC, &a);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

    printf("%u\n", t);

    free(v);

    return 0;
}

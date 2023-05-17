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
    clock_t start, end;
    unsigned int t, n;
    int i, *v;

    n = atoi(argv[1]);
    v = (int *) malloc(n * sizeof(int));
    srand(time(NULL));
    for (i = 0; i < n; i++)
        v[i] = rand();

    start = clock();
    merge_sort(v, 0, n-1);
    end = clock();

    t = (unsigned int) ((end - start) / (double) CLOCKS_PER_SEC * 1e9);

    printf("%u\n", t);

    free(v);

    return 0;
}

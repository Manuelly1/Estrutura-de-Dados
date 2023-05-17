#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void swap(int *a, int *b) {
    int m;
    m = *a;
    *a = *b;
    *b = m;
}


void selection_sort(int *v, unsigned int n) {
    unsigned int i, j;
    int m;

    for (i = 0; i < (n - 1); i++) {
        m = i;
        for (j = (i + 1); j < n; j++) {
            if (v[m] > v[j])
                m = j;
        }
        swap(&v[m], &v[i]);
        
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
        v[i] = rand();

    start = clock();
    selection_sort(v, n);
    end = clock();

    t = (unsigned int) ((end - start) / (double) CLOCKS_PER_SEC * 1e9);

    printf("%u\n", t);

    free(v);

    return 0;
    
}


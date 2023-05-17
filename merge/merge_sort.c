#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <sys/time.h>

void merge_sort(int *A, int s, int e);
void merge(int *v, int s, int m, int e);

void merge(int *v, int s, int m, int e) {

    int a = s;
    int b = m + 1;
    int k;
    int *w = (int *)malloc((e - s + 1) * sizeof(int));

    for (k = 0; k <= (e - s); k++)
    {
        if (b > e || (a <= m && v[a] < v[b])) {
            w[k] = v[a];
            a++;
        } else {
            w[k] = v[b];
            b++;
        }
    }
    for (k = 0; k <= (e - s); k++) {
        v[s + k] = w[k];
    }
    
    free(w);
}


void merge_sort(int *A, int s, int e) {

    int m;
    if (s < e) {
        m = (s + e) / 2;
        merge_sort(A, s, m);
        merge_sort(A, m + 1, e);
        merge(A, s, m, e);
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
    merge_sort(v, 0, n);
    clock_gettime(CLOCK_MONOTONIC, &a);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

    printf("%u\n", t);

    free(v);

    return 0;
    
}

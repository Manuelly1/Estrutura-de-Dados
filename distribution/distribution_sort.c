#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int min(int *v, int n) {
    int min_val = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] < min_val) {
            min_val = v[i];
        }
    }
    return min_val;
}

int max(int *v, int n) {
    int max_val = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > max_val) {
            max_val = v[i];
        }
    }
    return max_val;
}

int *new_0(int n) {
    int *v = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        v[i] = 0;
    }
    return v;
}

int *distribution_sort(int *v, int n) {
    int i, j;
    int l = min(v, n);
    int b = max(v, n);
    int k = b - l + 1;
    int *w = new_0(k);
    int *y = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        w[v[i] - l]++;
    }

    for (j = 1; j <= b - l; j++) {
        w[j] = w[j] + w[j - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        j = w[v[i] - l];
        y[j - 1] = v[i];
        w[v[i] - l]--;
    }

    free(w);
    return y;
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
    distribution_sort(v, n);
    end = clock();

    t = (unsigned int) ((end - start) / (double) CLOCKS_PER_SEC * 1e9);

    printf("%u\n", t);

    free(v);

    return 0;
    
}

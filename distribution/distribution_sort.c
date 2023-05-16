#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

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
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }
    return arr;
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


int main() {
    int i, j;
    float tempo = 0;
    struct timeval a, b;
    FILE *fp;
    int n = 100;
    fp = fopen("distribution_sort.txt", "w");

    while (n <= 10000) {
        int *v = (int *)malloc(n * sizeof(int));
        for (j = 0; j < 100; j++) {
            gettimeofday(&b, NULL);

            for (i = 0; i < n; i++) {
                v[i] = rand() % ((100-0+1) + 1); // Gerar números entre 0 e 100
            }
            distribution_sort(v, n);
            gettimeofday(&a, NULL);
            tempo = (a.tv_sec + a.tv_usec * 1e-6) - (b.tv_sec + b.tv_usec * 1e-6);
        }

        fprintf(fp, "%d %f\n", n, (tempo * 1e6));
        n = n + 100;
        free(v);
    }

    fclose(fp);
    return 0;
}

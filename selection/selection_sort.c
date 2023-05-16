#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void swap(int *a, int *b);
void selection_sort(int *v, unsigned int n);
int *vetor(unsigned int n);

void swap(int *a, int *b) {
    int m;
    m = *a;
    *a = *b;
    *b = m;
}

void selection_sort(int *v, unsigned int n) {
    unsigned int i, j;
    int m;

    for (i = 0; i < n - 1; i++) {
        m = i;
        for (j = i + 1; j < n; j++) {
            if (v[m] > v[j])
                m = j;
        }
        swap(&v[m], &v[i]);
    }
}

int main(void) {
    int i, j;
    int *v;
    long int tempo;
    struct timeval a, b;
    srand(time(NULL));
    for (i = 0; i <= 10000; i += 1000) {
        tempo = 0;

        for (j = 0; j < 100; j++) {
            v = vetor(i);
            gettimeofday(&b, NULL);
            selection_sort(v, i);
            gettimeofday(&a, NULL);
            tempo += (((a.tv_sec * 1000000) + a.tv_usec) - ((b.tv_sec * 1000000) + b.tv_usec));

            free(v);
        }

        printf("%d  %f\n", i, tempo / 100.0);
    }

    return 0;
}

int *vetor(unsigned int n) {
    int *v = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        v[i] = rand() % n;
    }

    return v;
}

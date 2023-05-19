#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void quick_sort(int *v, int s, int e);
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
    int pivo = v[(s + e) / 2]; // escolhe o elemento do meio como pivô
    int i = s - 1;
    int j = e + 1;

    while (1) {
        do {
            i++;
        } while (v[i] < pivo);

        do {
            j--;
        } while (v[j] > pivo);

        if (i >= j)
            break;

        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }

    return j;
}


int main(int argc, char **argv) {
    struct timespec a, b;
    unsigned int t, n;
    int i, *v;

    n = atoi(argv[1]);
    v = (int *) malloc(n * sizeof(int));
    srand(time(NULL));
    for (i = 0; i < n; i++)
        v[i] = n; 

    clock_gettime(CLOCK_MONOTONIC, &b);
    quick_sort(v, 0, n-1);
    clock_gettime(CLOCK_MONOTONIC, &a);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

    printf("%u\n", t);

    free(v);

    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void selection_sort(int *v, int n) {
    int i, j, ind_Min;

    for (i = 0; i < n - 1; i++) {
        ind_Min = i;
        for (j = i + 1; j < n; j++) {
            if (v[j] < v[ind_Min]) {
                ind_Min = j;
            }
        }

        int temp = v[i];
        v[i] = v[ind_Min];
        v[ind_Min] = temp;
    }
}


int main() {
    int n = 100;
    int i, j;
    float tempo = 0;
    struct timeval a, b;
    FILE *fp;
    fp = fopen("selection.txt", "w");

    while(n <= 1000) {
        int v[n];
        for(j = 0; j < 100; j++) {
            gettimeofday(&b, NULL);

            for(i = 0; i < n; i++) {
                v[i] = rand() % ((100-0+1)+1); 
            }
            selection_sort(v, n);
            gettimeofday(&a, NULL);
            tempo = (a.tv_sec + a.tv_usec * 1e-6) - (b.tv_sec + b.tv_usec * 1e-6) + tempo;
        }

        fprintf(fp, "%d %f\n", n, (tempo * 1e6) / 100);
        n = n + 100;
    }

    fclose(fp);
    return 0;
}


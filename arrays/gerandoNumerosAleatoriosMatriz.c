#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Como gerar números aleatórios para preencher uma matriz

int main () {

    int i, j;
    int mat1[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 

    srand(time(NULL)); // explicação na parte de vetor

/*
Deseja-se sortear números, ou seja, sortear e salvar em mat1. Funciona da mesma forma que no vetor
*/
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            mat1[i][j] = rand();

        }
            
    }       

// Imprime os valores:
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) 
            printf("%5d", mat1[i][j]); // o cinco pede para que não tenha números acima de 5 dígitos

        printf("\n");

    }

    return 0;

}
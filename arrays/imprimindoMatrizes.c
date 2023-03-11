#include <stdio.h>
#include <stdlib.h>

// Como imprimir o conteúdo de uma matriz

/* 
Como percorrer essas matrizes e imprimir os seus contéudos na tela?

Como agora há 2 dimensões (linha e coluna), então necessita-se de 2 variáveis contadoras para ir de
0 até menor do que o número de linhas e colunas.

*/


int main () {

    int i, j;
    int mat1[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    char mat5[3][4] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'}; 

    // Percorrendo a matriz de números inteiros, tendo cuidado que agora serão 2 variáveis:
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) 
            printf("%d", mat1[i][j]);
        printf("\n");
        
        /*
        Aplica-se o \n neste caso, pois quando terminar de imprimir a primeira linha, o j será igual a 3.
        Logo, quebrará a repetição e pulará uma linha. Assim, o i = 1, fazendo novamente a repetição.
        Dessa forma, vai gerar uma matriz.
        */
    
    }

    return 0;

}
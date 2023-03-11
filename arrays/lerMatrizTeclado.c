#include <stdio.h>
#include <stdlib.h>

// Como ler uma matriz a partir do teclado:

/* 


*/


int main () {

    int i, j;
    int mat1[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    char mat5[3][4] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'}; 

/*
Permite que a pessoa informe um valor e preencha a matriz: (o "i" gera os índices da linha, já o "j" 
os da coluna)
*/
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) 
            printf("Digite o valor %d %d: ", i, j); // escrevendo assim, mostra o índice dos valores
            scanf("%d", &mat1[i][j]);

        // quando o "i" for 0, o "j" vai passar por 0, 1, 2. Vai lendo linha por linha
    }

// Imprime os valores:
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) 
            printf("%d", mat1[i][j]);

        printf("\n");

    }

    return 0;

}
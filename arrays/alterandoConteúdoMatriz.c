#include <stdio.h>
#include <stdlib.h>

// Como alterar o conteúdo de uma matriz: somar duas matrizes e salvar o resultado em uma terceira

int main () {

    int i, j;
    int mat1[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    char mat5[3][4] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'}; 

/*
Qualquer ação/alteração que deseja-se realizar em uma matriz, necessita-se de dois for.

Abaixo há uma situação em que almeja-se multiplicar todos os elementos de uma matriz por 2 e 
salvar na mesma posição. Para fazer essa mudança, precisa fazer uma atribuição: mat1[i][j] = mat1[i][j] * 2;

O símbolo da igualdade representa essa atribuição. Como há as posições "[i][j]", as alterações que forem 
feitas, isto é, se o elemento 7 que está na posição [3][1] for multiplicado por 2, ele será substituído 
por 14, permanecendo assim na mesma posição.
*/
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            mat1[i][j] = mat1[i][j] * 2;

        }
            
    }       

// Imprime os valores:
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) 
            printf("%2d", mat1[i][j]);

        printf("\n");

    }

    return 0;

}

/*
No exemplo a seguir deseja-se fazer a soma dos elementos das matrizes, isto é, o primeiro elemento da mat1 com 
o primeiro da mat2 e assim por diante. Salvando esses elementos na mat3, ou seja, objetiva-se percorrer as 
matrizes para fazer essa operação. Sabe-se que mat1, mat2 e mat3 possuem o mesmo tamanho, então usa-se o primei-
ro for para percorrer.
*/

int main () {

    int i, j;
    int mat1[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    int mat2[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    int mat3[3][3]; 

    // Como é mat3 que vai receber o resultado da soma, faz:
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            mat3[i][j] = mat1[i][j] + mat2[i][j]; 
            /*
            Ou seja, informa o nome das matrizes que deseja-se acessar e os índices de linha e coluna.
            O primeiro elemento da mat1 será somado com o primeiro elemento da mat2 e colocar na primeira
            posição da mat3, fazendo assim para todos.
            */

        }
            
    }       

// Imprime os valores da mat3:
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) 
            printf("%2d", mat3[i][j]);

        printf("\n");

    }

    return 0;

}



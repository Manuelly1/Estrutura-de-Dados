#include <stdio.h>
#include <stdlib.h>

// Arrays bidimensionais: matrizes

/* 
Uma matriz é um conjunto de elementos do mesmo tipo, que possui colunas e linhas, ou seja, 2 dimensões.
É uma estrutura de dado homogênea.

Cada elemento pode ser acessado por meio de dois índices, um para identificar a linha que deseja acessar e
outro para a coluna. O elemento de intercessão é justamente o ponto de encontro entre essa
linha e essa coluna.

Ex: mat[0][0]; isto é, o elemento se encontra na primeira linha e na primeira coluna.
*/

// Criando uma matriz:

int main () {

    // Primeiro diz o tipo da matriz, em seguida o identificador e o tamanho (linha e coluna)
    int mat1[3][3];
    /*
    Em um caso assim, tem-se uma matriz que possui 3 linhas e 3 colunas
    */

    int mat2[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    /* 
    Pode também ser escrita assim, em que há a determinação do conjunto que compõe esta matriz, como ela 
    tem dimensões 3x3, ela agrupa 9 elementos ao todo. O programa ao rodar, gerará esta matriz:

                c1  c2  c3
    linha 1     1   2   3
    linha 2     4   5   6       
    linha 3     7   8   9

    */

    int mat3[][3] = {1, 2, 3, 4, 5, 6};
    /*
    Quando se faz dessa forma, ou seja, não informa a quantidade de linhas, a pessoa é obrigada a fornecer
    os elementos, pois o computador precisa saber qual será a distribuição para, assim, montar a matriz.
    Neste exemplo, o total de linhas acaba sendo 2, tendo em vista que há 6 elementos e tem 3 colunas.
    */
    
    int mat3[][3] = {1, 2, 3, 4, 5, 6, 7};
    /*
    Outro caso que não foi informada a quantidade de linhas e os elementos fornecidos foram 7, logo, não se
    pode ter apenas 2 linhas, como anteriormente. Então, em uma situação assim, o programa irá preencher com 
    0 as duas últimas colunas.
    */    

    int mat4[3][3] = {0};
    /*
    Neste cenário, como em um vetor, o programa irá preencher toda a matriz com 0. Serão nove elementos 0's.
    */    

    float mat5[4][5];
    char mat5[10][10]; 
    /*
    Matriz que pode armazenar 100 caracteres
    */

    return 0;

}
#include <stdio.h>
#include <stdlib.h>

// Como criar um array/vetor:

int main () {

    int idade; // declaração normal de variáveis
    char sexo;
    float nota1;

    // declaração de vetores:

    int num1[10]; 
    /* 
    Neste caso, tem-se um vetor do tipo inteiro que guarda 10 números inteiros e cujo identificador é "num1". 
    Como não determinou o conjunto dos vetores, essas dez posições podem estar vazias ou podem conter lixo de memória.
    */

    int num2[] = {1, 5, 9, 15, 43}; 
    /*
    Nesta situação, não informa-se o número do vetor, mas o programa vai entender que ele terá o tamanho do 
    conjunto de elementos fornecidos, ou seja, 5.
    */

    int num3[5] = {4, 5, 6}; 
    /*
    Neste caso, afirma-se que o vetor tem tamanho 5, mas o conjunto possui 3 elementos fornecidos. Em casos 
    assim, o programa irá ler que o vetor possui 5 elementos, em que o 4 irá ocupar a primeira posição, o 5 a 
    segunda posição e o 6 a terceira posição, no caso das duas últimas posições, ele automaticamente vai preen-
    chê-las com 0.
    */

    int num4[5] = {1, 3, 5, 7, 9, 11}; 
    /*
    Neste outro caso, o tamanho do vetor é 5, mas foram fornecidos 6 elementos no conjunto, desta forma, o pro-
    grama só irá contar até o quinto e vai ignorar o sexto. O programa sempre olha para o tamanho informado pa-
    ra o vetor, isto é, o número dentro do colchete.
    */

    int num5[5] = {0}; 
    /*
    Em um caso como esse, tem-se que o vetor possui tamanho 5 e foi determinado que o seu conjunto possui o 0, 
    então o programa irá colocar esse 0 na primeira posição do vetor e nas demais, o programa automaticamente 
    preencherá com 0. Isso evita que se tenha lixo de memória.
    */

    char letras[100]; 
    /*
    Vetor do tipo caractere, que armazena até 100 caracteres.
    */

    char vogais[5] = {'a', 'e', 'i', 'o', 'u'};
    /*
    Essa é uma forma de fornecer um conjunto de caracteres se fizesse: char vogais[5] = {a, e, i, o, u} estaria
    errado, pois ao tentar rodar o programa, ele irá entender que "a, e, i, o, u" são variáveis, então ele irá 
    procurar por elas e não vai encontrá-las com esses nomes. Por isso, o correto é usar entre aspas simples pa-
    ra identificar que são caracteres.
    */
    
    float notas[3] = {8.5, 9.8, 10.0}; 
    /*
    Vetor do tipo float gerado para armazenar 3 notas, onde o conjunto dos elementos já foi determinado.
    */

    return 0;

}
#include <stdio.h>
#include <stdlib.h>

// Como criar um array/vetor:

int main () {

    int idade; // declaração normal de variáveis
    char sexo;
    float nota1;

    // declaração de vetores:

    int num1[10]; // neste caso, tem-se um vetor do tipo inteiro que guarda 10 números inteiros e cujo 
    // identificador é "num1". Como não determinou o conjunto dos vetores, essas dez posições podem estar va-
    // zias ou podem conter lixo de memória.

    int num2[] = {1, 5, 9, 15, 43}; // neste caso, não informa-se o número do vetor, mas o programa vai enten-
    // der que ele terá o tamanho do conjunto de elementos fornecidos, ou seja, 5.

    int num3[5] = {4, 5, 6}; // neste caso, afirma-se que o vetor tem tamanho 5, mas o conjunto possui 3 ele-
    // mentos fornecidos. Em casos assim, o programa irá ler que o vetor possui 5 elementos, em que o 4 irá
    // ocupar a primeira posição, o 5 a segunda posição e o 6 a terceira posição, no caso das duas últimas po-
    // sições, ele automaticamente vai preenchê-las com 0.

    int num4[5] = {1, 3, 5, 7, 9, 11}; // neste outro caso, o tamanho do vetor é 5, mas foram fornecidos 6 
    // elementos no conjunto, desta forma, o programa só irá contar até o quinto e vai ignorar o sexto. O pro-
    // grama sempre olha para o tamanho informado para o vetor, isto é, o número dentro do colchete.

    int num5[5] = {0}; // em um caso como esse, tem-se que o vetor possui tamanho 5 e foi determinado que
    // o seu conjunto possui o 0, então o programa irá colocar esse 0 na primeira posição do vetor e nas de-
    // mais, o programa automaticamente preencherá com 0. Isso evita que se tenha lixo de memória.


    char letras[100]; // vetor do tipo caractere, que armazena até 100 caracteres.

    char vogais[5] = {'a', 'e', 'i', 'o', 'u'}; // essa é uma forma de fornecer um conjunto de caracteres
    // se fizesse: char vogais[5] = {a, e, i, o, u} estaria errado, pois ao tentar rodar o programa, ele irá
    // entender que "a, e, i, o, u" são variáveis, então ele irá procurar por elas e não vai encontrá-las com
    // esses nomes. Por isso, o correto é usar entre aspas simples, para identificar que é um caractere.

    float notas[3] = {8.5, 9.8, 10.0}; // vetor do tipo float gerado para armazenar 3 notas, onde o conjun-
    // dos elementos já foi determinado.

    return 0;

}
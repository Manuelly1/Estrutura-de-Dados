#include <stdio.h>
#include <stdlib.h>

// Como preencher um array/vetor por meio do teclado:

// Para fazer a leitura de um vetor a partir do teclado, também é necessário fazer uma estrutura de repetição

int main () {

    int i;
    int num2[10];

    for (i = 0; i < 10; i++) {
        printf("Digite o valor do vetor: ");
        scanf("%d", &num2[i]); // o num2[] indica em que posição quer salvar esse valor, ou seja, na posição i
    }

    printf("\n\n");

    // impressão do vetor para ter certeza de que ele foi preenchido:
    for (i = 0; i < 10; i++) {
        printf("%d", num2[i]);
    }

    printf("\n\n");

    return 0;

}

// O programa pode ser otimizado desta forma: sabe-se que o usuário ao informar o valor, ele não saberá qual é o elemento
// que está sendo inserido, se é o quinto ou o oitavo... Então pode ser feito assim no primeiro for: 

/*    for (i = 0; i < 10; i++) {
        printf("Digite o elemento da posição %d: ", i);
        scanf("%d", &num2[i]); 
    }

*/

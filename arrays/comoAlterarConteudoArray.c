#include <stdio.h>
#include <stdlib.h>

// Como alterar o contéudo de um array/vetor:


int main () {

    int i;
    int num2[10];

    for (i = 0; i < 10; i++) {
        printf("Digite o elemento da posição %d: ", i);
        scanf("%d", &num2[i]); 
    }

    printf("\n\n");

    // se, por exemplo, desejar multiplicar todos os elementos por 3, precisa-se de outro for, o qual irá pegar cada
    // elemento do vetor e multiplicar por 3, então pega o elemento da posição do vetor "num2[i]". Todavia, além disso, 
    // ele deseja salvar. Por exemplo, o primeiro elemento é 7, então 7 * 3 = 21, ele deseja salvar o 21 no lugar do 7, 
    // logo precisa fazer uma atribuição, isto é, atribui o resultado da multiplicação para uma variável, sendo essa variável
    // o próprio vetor, ou seja, num2. Salvando, assim, o 21 na mesma posição do 7.
    
    for (i = 0; i < 10; i++) {
        num2[i] = num2[i] * 3; 
    }

    // impressão do vetor para ter certeza de que ele foi preenchido:
    for (i = 0; i < 10; i++) {
        printf("%d", num2[i]);
    }

    printf("\n\n");

    return 0;

}

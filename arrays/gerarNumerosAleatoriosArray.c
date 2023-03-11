#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Como gerar números aleatórios para preencher um array/vetor: usando as funções rand e srand

/* 
Partindo do entendimento de que preencher um vetor manualmente pode ser trabalhoso, principalmente quando se deseja
testar o código mais de uma vez, indica-se que gere números de forma aleatória
*/

int main () {

    int i;
    int num2[10];

/* 
Para fazer isso, começa fazendo uma atribuição, ou seja, aplica-se o nome do vetor com a posição, seguido pelo
símbolo de atribuição (=) e emprega a função que irá gerar os números, que se chama rand()
    

Para evitar que a função rand() gere sempre os mesmos números, a função srand() receberá um parâmetro/chave que sempre 
será diferente toda vez que executar o programa. Isso é um detalhe curioso, pois existe no computador uma variável que
a todo momento ela é alterada, isto é, a variável que guarda a hora do PC, então sempre que executar o PC, a hora será 
distinta. Sendo assim, pode-se passar essa variável, para isso faz-se mais uma inclusão time.h, pois é por meio dele que
acessa a hora. Para passar a hora do computador basta colocar dentro do srand "time(NULL)", ou seja, não passa nenhum pa-
râmetro para a função time, pois deseja-se que ela apenas passe a hora. Dessa forma, sempre estará gerando sequências 
aleatórias.
*/

    srand(time(NULL));

    for (i = 0; i < 10; i++) 
        num2[i] = rand(); // essa função rand() irá sortear/gerar números aleatórios que serão salvos na posição i do array

    printf("\n\n");

    // impressão do vetor para ter certeza de que ele foi preenchido:
    for (i = 0; i < 10; i++) {
        printf("%d", num2[i]);
    }

    printf("\n\n");

    return 0;

}


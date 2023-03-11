#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Como gerar números aleatórios dentro de um intervalo

/* 
Para que o programa não gere números tão "longe" uns dos outros, pode-se instituir que deseja que os números
estejam entre 0 e 100, por exemplo. Para isso usa-se a operação matemática conhecida como "resto da divisão",
que é representada pela %

Exemplo: num2[i] = rand() % 100; 
Em um caso assim, imaginando-se que gerou um número bem grande, se pegar o resto da divisão por 100, desse nú-
mero que foi gerado por 100, o resto será um número menor do que 100, logo, estará entre 0 e 99. 

Dessa forma, determina-se ou estipula-se um intervalo. 

OBS: se não quiser incluir o 0, pode fazer:
num2[i] = 1 + rand() % 100; 
*/

int main () {

    int i;
    int num2[10];

    srand(time(NULL));

    for (i = 0; i < 10; i++) 
        num2[i] = rand() % 100; 

    printf("\n\n");

    // impressão do vetor para ter certeza de que ele foi preenchido:
    for (i = 0; i < 10; i++) {
        printf("%d", num2[i]);
    }

    printf("\n\n");

    return 0;

}


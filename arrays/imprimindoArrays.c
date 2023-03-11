#include <stdio.h>
#include <stdlib.h>

// Como imprimir o contéudo de um array/vetor:

/* 
Antes de tudo, deve-se entender que cada elemento em um vetor pode ser acessado por um índice.
Se o vetor possui 5 elementos, os índices para acessar esse vetor vão de 0 a 4. Sendo assim, para percorrer um 
vetor e imprimir o seu contéudo, usa-se uma estrutura de repetição.
*/

int main () {

    int i;
    int num2[] = {1, 5, 9, 15, 43};
    char vogais[5] = {'a', 'e', 'i', 'o', 'u'}; 
    float notas[3] = {8.5, 9.8, 10.0}; 

    /*
    printf("%d", num2[0]); 
    Neste caso, irá imprimir o número que está na posição 0 do vetor "num2". Fazer dessa forma, não é nada 
    eficiente, visto que se tiver um vetor de tamanho 50, terá que fazer um por um.
    */

    /*
    Como se tem um índice iniciando em 0 e crescendo sempre de 1 em 1, pode-se criar um variável "i" e colocar
    o printf dentro de uma estrutura de repetição:

    Lembrando que tem que ser i < n - 1, ou seja, até o tamanho do vetor - 1, uma vez que começa em 0.        
    */
    
    // imprimindo o vetor num2:
    for (i = 0; i < 5; i++) {    
        printf("%d", num2[i]); //assim, "i" vai assumir valores de 0 a 4    
    }

    printf("\n\n");

    // imprimindo o vetor vogais:
    for(i = 0; i < 5; i++) {
        printf("%c", vogais[i]);
    }

    printf("\n\n");

    // imprimindo as notas:
    for(i = 0; i < 3; i++) {
        printf("%.2f", notas[i]);
    }

    return 0;

}
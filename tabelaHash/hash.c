#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// struct para caso exista colisão
typedef struct bloco {
    int valor;
    struct bloco *proximo;
} Bloco;

// struct para a tabela
typedef struct tabela {
    int quant; // n
    int tam; // m 
    struct bloco **lista;
} Tabela;

struct bloco* novoBloco(int valor);
void inserirTabela(Tabela* tabela, Bloco* bloco);
void removeTabela(Tabela* tabela);
void removeBloco(Bloco* bloco);
void exibeTabela(Tabela *tabela);
void exibeLista(Bloco *valorAdic);
int buscaTab(Tabela *tabela, int valor);
void atualizaTab(Tabela *tabela, Bloco* bloco);
void dotHash(FILE *file, Tabela *tabela);

struct bloco* novoBloco(int valor) {
    struct bloco* bloco = (struct bloco*)malloc(sizeof(struct bloco));
    bloco->valor = valor;
    bloco->proximo = NULL;

    return bloco;
}

void inserirTabela(Tabela* tabela, Bloco* bloco) {

    if(tabela->quant >= tabela->tam){
		atualizaTab(tabela, bloco);
	}

    else {
        int posicao = bloco->valor % tabela->tam;

        bloco->proximo = tabela->lista[posicao];
        tabela->lista[posicao] = bloco;

        tabela->quant = tabela->quant + 1;;
    }

}

void removeTabela(Tabela* tabela) {
	for(int i = 0; i < tabela->tam; i++){
		removeBloco(tabela->lista[i]);
		tabela->lista[i] = NULL;
	}

	tabela->quant = 0;
	
}

void removeBloco(Bloco* bloco) {
	Bloco *aux;

	while (bloco != NULL){
		aux = bloco->proximo;
		free(bloco);
		bloco = aux;
	}	

}

void exibeTabela(Tabela *tabela) {
    for (int i = 0; i < tabela->tam; i++){
        printf("Chave: %d", i);
        printf(" --> ");
        exibeLista(tabela->lista[i]);
        printf("\n");
    }
}

void exibeLista(Bloco *valorAdic) {
    while (valorAdic != NULL){
        printf("%d", valorAdic->valor);
        printf(" --> ");
        valorAdic = valorAdic->proximo;
    }
}

int buscaTab(Tabela *tabela, int valor) {
    int posicao;
    Bloco *list;
    posicao = valor % tabela->tam;

    for (list = tabela->lista[posicao]; list != NULL; list = list->proximo){    	
        if(list->valor == valor){
            return 1;
        }
    }
    return 0;
}

void atualizaTab(Tabela* tabela, Bloco* bloco) {

	Tabela novTabel;
	novTabel.tam = (tabela->tam * 2);
	novTabel.lista = malloc(sizeof(Bloco *) * novTabel.tam);
    novTabel.quant = 1;

	for (int i = 0; i < novTabel.tam; i++){
        novTabel.lista[i] = NULL;
    }

    int posicao = bloco->valor % novTabel.tam;

    novTabel.lista[posicao] = bloco;

	for (int i = 0; i < tabela->tam; i++){
    	Bloco *novBloc;
	    novBloc = tabela->lista[i];

	    while (novBloc != NULL){
	        posicao = novBloc->valor % novTabel.tam;

	        Bloco *tab = novoBloco(novBloc->valor);

			tab->proximo = novTabel.lista[posicao];
			novTabel.lista[posicao] = tab;

			novBloc = novBloc->proximo;

			novTabel.quant = novTabel.quant + 1;
	    }
    }

    removeTabela(tabela);

    (*tabela) = novTabel;

}

void dotHash(FILE *file, Tabela *tabela) {
    fprintf(file, "  main_table [shape=record, label=\"");

    for (int i = 0; i < tabela->tam; i++) {
        if (i > 0) {
            fprintf(file, "|");
        }

        if (tabela->lista[i] == NULL) {
            fprintf(file, "<slot%d> NULL", i);
        } else {
            fprintf(file, "<slot%d> %p", i, (void *)tabela->lista[i]);
        }
    }

    fprintf(file, "\"];\n");

    for (int i = 0; i < tabela->tam; i++) {
        Bloco *bloco = tabela->lista[i];

        if (bloco != NULL) {
            fprintf(file, "  \"%p\" [shape=record, label=\"{%d|%p}\"];\n", (void *)bloco, bloco->valor, (void *)bloco->proximo);
            fprintf(file, "  main_table:slot%d -> \"%p\";\n", i, (void *)bloco);

            while (bloco->proximo != NULL) {
                fprintf(file, "  \"%p\" -> \"%p\" [style=dotted];\n", (void *)bloco, (void *)bloco->proximo);
                bloco = bloco->proximo;
                fprintf(file, "  \"%p\" [shape=record, label=\"{%d|%p}\"];\n", (void *)bloco, bloco->valor, (void *)bloco->proximo);
            }
        }
    }
}

int main(int argc, char **argv) {
    struct timespec a, b;
    int t, n, i, achou;
    Tabela tabela;

	tabela.lista = malloc(sizeof(Bloco*)*(4));
	tabela.quant = 0;
	tabela.tam = 4;
    
    n = atoi(argv[1]);
    srand(time(NULL));

    for (i = 0; i < 4; i++) {
        tabela.lista[i] = NULL;
    }

	for (i = 0; i < n; i++) {
		inserirTabela(&tabela, novoBloco(rand()));
	}


    clock_gettime(CLOCK_MONOTONIC, &b);
    achou = buscaTab(&tabela, rand());
    clock_gettime(CLOCK_MONOTONIC, &a);

    // if (achou == 1) {
    //     printf("Achou.\n");
    // }

    // else {
    //     printf("Não achou.\n");
    // }

    //exibeTabela(&tabela);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

    printf("%u\n", t);

    FILE *dot_file = fopen("hash.dot", "w");
    if (dot_file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    fprintf(dot_file, "digraph G {\n node [shape=record, height=0.6, width=1.5];\n edge [arrowhead=vee, arrowsize=0.8];\n");
    dotHash(dot_file, &tabela);
    fprintf(dot_file, "}\n");

    fclose(dot_file);

    removeTabela(&tabela);

    return 0;
}

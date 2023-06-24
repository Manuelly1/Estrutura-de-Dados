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

// função para criar um bloco novo
struct bloco* novoBloco(int valor) {
    struct bloco* bloco = (struct bloco*)malloc(sizeof(struct bloco));
    bloco->valor = valor;
    bloco->proximo = NULL;
    return bloco;
}

// função para adicionar na tabela
void inserirTabela(Tabela* tabela, Bloco* bloco) {

    if(tabela->quant >= tabela->tam){
		atualizaTab(tabela, bloco);
	}
    else {
    // verificando a posição onde será inserido 
        int posicao = bloco->valor % tabela->tam;

        if(tabela->lista[posicao] == NULL){
            tabela->lista[posicao] = bloco;

        }
        else{
            bloco->proximo = tabela->lista[posicao];
            tabela->lista[posicao] = bloco;
        }

        tabela->quant++;
    }

    // printf("%d %d", tabela->quant, tabela->tam);
    // getchar();
}

// funções para liberar espaço
void removeTabela(Tabela* tabela) {
	int i;
	for(i = 0; i< tabela->tam; i++){
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

// funções para mostrar a tabela
void exibeTabela(Tabela *tabela) {
    int i;

    for (i = 0; i < tabela->tam; i++){
        printf("Chave: %d", i);
        printf(" --> ");
        exibeLista(tabela->lista[i]);
        printf("\n");
    }
}

void exibeLista(Bloco *valorAdic) {
    while (valorAdic != NULL){
        printf("%d", valorAdic->valor);
        printf(" ");
        valorAdic = valorAdic->proximo;
    }
}

// função para a busca
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

// função para atualizar
void atualizaTab(Tabela* tabela, Bloco* bloco) {
	int i;
    int tam = tabela->tam;

	// criando uma tabela estática auxiliar com o dobro do tamanho 
	Tabela new;
	new.tam = (tam * 2);
	new.lista = malloc(sizeof(Bloco *) * new.tam);
    new.quant = 1;

	// prenche os valores da tabela auxiliar como NULL 
	for (i = 0; i < new.tam; i++){
        new.lista[i] = NULL;
    }

    int posicao = bloco->valor % new.tam;

    new.lista[posicao] = bloco;

    // insere os elementos na nova tabela 
	for (i = 0; i < tam; i++){
    	Bloco *adicNewTab;
	    adicNewTab = tabela->lista[i];
	    while (adicNewTab != NULL){

	        int posicao = adicNewTab->valor % tabela->tam;

	        Bloco *tab = novoBloco(adicNewTab->valor);

	        if(new.lista[posicao] == NULL){
		        new.lista[posicao] = tab;
	        }

            else{
				tab->proximo = new.lista[posicao];
				new.lista[posicao] = tab;
		    }

			adicNewTab = adicNewTab->proximo;
			new.quant++;
	    }
    }

    // remove as posições de memória usadas pela original 
    removeTabela(tabela);

    *tabela = new;
    tabela->lista = new.lista;
    tabela->tam = new.tam;
	tabela->quant = new.quant;
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
		inserirTabela(&tabela, novoBloco(rand() % 10000));
	}

    clock_gettime(CLOCK_MONOTONIC, &b);
    achou = buscaTab(&tabela, n);
    clock_gettime(CLOCK_MONOTONIC, &a);

    // if (achou == 1) {
    //     printf("Achou.\n");
    // }

    // else {
    //     printf("Não achou.\n");
    // }

    exibeTabela(&tabela);

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


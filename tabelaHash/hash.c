#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>

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
unsigned int hash(int valor, int tam);
void inserirTabela(Tabela* tabela, Bloco* bloco);
void removeTabela(Tabela* tabela);
void removeBloco(Bloco* bloco);
void exibeTabela(Tabela *tabela);
void exibeLista(Bloco *valorAdic);
int buscaTab(Tabela *tabela, int valor);
void atualizaTab(Tabela *tabela);

// função para criar um bloco novo
struct bloco* novoBloco(int valor) {
    struct bloco* bloco = (struct bloco*)malloc(sizeof(struct bloco));
    bloco->valor = valor;
    bloco->proximo = NULL;
    return bloco;
}

// função para o hash (calcular o resto)
unsigned int hash(int valor, int tam) {
	return (valor%tam);
}

// função para adicionar na tabela
void inserirTabela(Tabela* tabela, Bloco* bloco) {

    if(tabela->quant >= tabela->tam){
		printf("\n Dobrando tamanho da tabela \n");
		atualizaTab(tabela);
	}

    // verificando a posição onde será inserido 
	unsigned int posicao = hash(bloco->valor, tabela->tam);

	if(tabela->lista[posicao] == NULL){
		tabela->lista[posicao] = bloco;

	}
    
    else{
		bloco->proximo = tabela->lista[posicao];
		tabela->lista[posicao] = bloco;
	}
	tabela->quant++;
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
    posicao = hash(valor, tabela->tam);

    for (list = tabela->lista[posicao]; list != NULL; list = list->proximo){    	
        if(list->valor == valor){
            return 1;
        }
    }
    return 0;
}

// função para atualizar
void atualizaTab(Tabela *tabela) {
	int i;
    int tam = tabela->tam;

	// criando uma tabela estática auxiliar com o dobro do tamanho 
	Tabela new;
	new.tam = (tam*2);
	new.lista = malloc(sizeof(Bloco *) * new.tam);

	// prenche os valores da tabela auxiliar como NULL 
	for (i = 0; i < new.tam; i++){
        new.lista[i] = NULL;
    }

    // insere os elementos na nova tabela 
	for (i = 0; i < tam; i++){
    	Bloco *adicNewTab;
	    adicNewTab = tabela->lista[i];
	    while (adicNewTab != NULL){

	        unsigned int posicao = hash(adicNewTab->valor, new.tam);

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

    tabela->lista = new.lista;
    tabela->tam = new.tam;
	tabela->quant = new.quant;
}

int main(int argc, char **argv) {
    struct tree_node* root = NULL;
    struct timespec a, b;
    unsigned int t, n, i;

    n = atoi(argv[1]);

    srand(time(NULL));
    
    for (i = 0; i < n; i++) {
        insert(&root, create_node(rand()), &root);
    }

    clock_gettime(CLOCK_MONOTONIC, &b);
    struct tree_node** achar = search(&root, rand());
    clock_gettime(CLOCK_MONOTONIC, &a);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

    printf("%u\n", t);
    // printf("Valores da árvore: ");
    // show(root);
    // printf("\n");

    struct tree_node* achar = search(&root, 5);

    if (achar != NULL) {
        printf("Achou.\n");
    }

    else {
        printf("Não achou.\n");
    }

    //tree_print_dot_body(root);

    // Abre o arquivo para escrita

    FILE *dot_file = fopen("tree.dot", "w");
    if (dot_file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    fprintf(dot_file, "digraph G {\n node [shape=record, height=0.6, width=1.5];\n edge [arrowhead=vee, arrowsize=0.8];\n");
    tree_print_dot_body(dot_file, root);
    fprintf(dot_file, "}\n");

    fclose(dot_file);
    
    return 0;
}
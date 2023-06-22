#include <stdio.h>
#include <stdlib.h>

// struct para caso exista colisão
typedef struct bloco {
    int valor;
    struct bloco *proximo;
} Bloco;

// struct para a tabela
typedef struct tabela {
    int quant;
    int tam;
    struct bloco **lista;
} Tabela;

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
		atualizar(tabela);
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
        exibiLista(tabela->lista[i]);
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

	        Bloco *tab = novo(adicNewTab->valor);

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


int main(void) {
    struct tabela* tabela = (struct tabela*)malloc(sizeof(struct tabela));;
    tabela->quant = 0;
    tabela->tam = 4;
    tabela->lista = NULL;

    insert(&root, create_node(3));
    insert(&root, create_node(2));
    insert(&root, create_node(1));
    // insert(&root, create_node(3));
    // insert(&root, create_node(5));
    // insert(&root, create_node(4));
    // insert(&root, create_node(13));
    // insert(&root, create_node(55));
    // insert(&root, create_node(22));

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct noArvore {
   int valor;
   struct noArvore *filEsq;
   struct noArvore *filDir;

};

struct noArvore** procurar(struct noArvore** raiz, int valor) {
    if ((*raiz) != NULL) {
        if ((*raiz)->valor == valor) {
            return raiz;
        }
        else if ((*raiz)->valor > valor) {
            return procurar(&((*raiz)->filEsq), valor);
        }

        return procurar(&((*raiz)->filDir), valor);
    }

    return NULL;
}

void verArvore(struct noArvore* raiz) {
    if (raiz != NULL) {
        verArvore(raiz->filEsq);
        printf("%d ", raiz->valor);
        verArvore(raiz->filDir);
    }
}

void inserir(struct noArvore** raiz, struct noArvore* no) {
    if (*raiz == NULL) {
        *raiz = no;
    } 
    
    else {

        if ((*raiz)->valor > no->valor) {
            inserir(&((*raiz)->filEsq), no);
        } 
        
        else {
            inserir(&((*raiz)->filDir), no);
        }     
    }
}

// Criar novo nó
struct noArvore* create_no(int valor) {
    struct noArvore* no = (struct noArvore*)malloc(sizeof(struct noArvore));
    no->valor = valor;
    no->filEsq = NULL;
    no->filDir = NULL;
    
    return no;
}

void dotTree(FILE *file, struct noArvore *r) {
    if (r != NULL) {
        dotTree(file, r->filEsq);

        fprintf(file, "  \"%p\" [shape=record, label=\"{%p|%d|{%p|%p}}\"];\n", (void *)r, (void *)r, r->valor, (void *)r->filEsq, (void *)r->filDir);

        if (r->filEsq) {
            fprintf(file, "  \"%p\" -> \"%p\";\n", (void *)r, (void *)r->filEsq);
        }

        if (r->filDir) {
            fprintf(file, "  \"%p\" -> \"%p\";\n", (void *)r, (void *)r->filDir);
        }

        dotTree(file, r->filDir);
    }
}

int main(int argc, char **argv) {
    struct noArvore* raiz = NULL;

    struct timespec a, b;
    int t, n, i;

    n = atoi(argv[1]);

    srand(time(NULL));

    int ult = 0;
    
    for (i = 0; i < n; i++) {
        ult = rand();
        inserir(&raiz, create_no(ult));

        
    }

    clock_gettime(CLOCK_MONOTONIC, &b);
    struct noArvore** achar = procurar(&raiz, ult + 1);
    clock_gettime(CLOCK_MONOTONIC, &a);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

    printf("%d\n", t);

    // printf("Valores da árvore: ");
    // verArvore(raiz);
    // printf("\n");

    /*struct noArvore** achar = procurar(&raiz, 5);

    if (achar != NULL) {
        printf("Achou.\n");
    }

    else {
        printf("Não achou.\n");
    }*/

    //dotTree(raiz);

    // Abre o arquivo para escrita

    FILE *dot_file = fopen("arvBin.dot", "w");
    if (dot_file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    fprintf(dot_file, "digraph G {\n no [shape=record, height=0.6, width=1.5];\n edge [arrowhead=vee, arrowsize=0.8];\n");
    dotTree(dot_file, raiz);
    fprintf(dot_file, "}\n");

    fclose(dot_file);
    
    return 0;
}

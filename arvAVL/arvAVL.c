#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct noArvore {
   int valor;
   struct noArvore *filEsq;
   struct noArvore *filDir;
   unsigned int altura;
   struct noArvore *pai;
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

void liberarArv(struct noArvore* raiz) {
    if (raiz != NULL) {
        liberarArv(raiz->filEsq);
        free(raiz);
        liberarArv(raiz->filDir);
    }
}

unsigned int altura(struct noArvore* no) {
    if (no == NULL) {
        return 0;
    }

    if ((no->filDir != NULL) && (no->filEsq != NULL)) {
        if ((no->filDir->altura) > (no->filEsq->altura)) {
            return (no->filDir->altura) + 1;
        }

        else {
            return (no->filEsq->altura) + 1;
        }
    }

    else if ((no->filEsq == NULL) && ((no->filDir != NULL))) {
        return no->filDir->altura + 1;
    }

    else if ((no->filEsq != NULL) && ((no->filDir == NULL))) {
        return no->filEsq->altura + 1;
    }

    return 1;
    
}

int difAlt(struct noArvore* no) {
    if ((no->filEsq != NULL) && (no->filDir != NULL)) {
        return abs(no->filEsq->altura - no->filDir->altura);
    } 

    else if ((no->filEsq == NULL) && (no->filDir != NULL)) {
        return no->filDir->altura;
    } 

    else if ((no->filEsq != NULL) && (no->filDir == NULL)) {
        return no->filEsq->altura;
    }

    return 0;
}

int qualCaso(struct noArvore* no) {
    if ((no != NULL) && (no->filEsq != NULL) && (no->filDir != NULL)) {

        if ((no->filEsq->altura) > (no->filDir->altura)) {

            if ((no->filEsq->filEsq != NULL) && (no->filEsq->filDir != NULL)) {
                
                if ((no->filEsq->filEsq->altura) > (no->filEsq->filDir->altura)) {
                    return 1;
                } 
                
                else {
                    return 3;
                }
            }
        } 
        
        else {
            if ((no->filDir->filDir != NULL) && (no->filDir->filEsq != NULL)) {
                if ((no->filDir->filDir->altura) > (no->filDir->filEsq->altura)) {
                    return 2;
                } 
                
                else {
                    return 4;
                }
            }
        }
    }

    else if ((no->filEsq != NULL) && (no->filDir == NULL)){
        if ((no->filEsq->filEsq != NULL) && (no->filEsq->filDir == NULL)) {
            return 1;
        }

        else {
            return 3;
        }
    }

    else {
        if ((no->filDir->filEsq == NULL) && (no->filDir->filDir != NULL)) {
            return 2;
        }
    }
    

    return 4;
}

void rd(struct noArvore** no) {
        struct noArvore* pai = (*no)->pai;
        struct noArvore* y = (*no)->filEsq;
        struct noArvore* x = *no;
        struct noArvore* b = y->filDir;      

        y->filDir = x;
        y->pai = pai;
        x->filEsq = b;
        x->pai = y;
        
        if (b != NULL) {
            b->pai = x;
        }

        x->altura = altura(x);
        y->altura = altura(y);

        if (y->pai != NULL) {
            if (y->pai->valor > y->valor) {
                y->pai->filEsq = y;
            }

            else {
                y->pai->filDir = y;
            }
        }

        *no = y;

}

void re(struct noArvore** no) {
        struct noArvore* pai = (*no)->pai;
        struct noArvore* y = (*no)->filDir;
        struct noArvore* x = *no;
        struct noArvore* b = y->filEsq;

        y->filEsq = x;       
        y->pai = pai;
        x->filDir = b;
        x->pai = y;

        if (b != NULL) {
            b->pai = x;
        }

        x->altura = altura(x);
        y->altura = altura(y);

        if (y->pai != NULL) {
            if (y->pai->valor > y->valor) {
                y->pai->filEsq = y;
            }

            else {
                y->pai->filDir = y;
            }
        }

        *no = y;
}

void balance(struct noArvore* no, struct noArvore** raiz) {
    no = no->pai;
        
    while (no != NULL) {
        no->altura = altura(no);
       
        if (difAlt(no) > 1) {
            int c = qualCaso(no);

            if (c == 1) {
                rd(&no);
            } 
            else if (c == 2) {
                re(&no);
            } 
            else if (c == 3) {
                re(&(no->filEsq));
                rd(&no);
            } 
            else {
                rd(&(no->filDir));
                re(&no);
            }
            if (no->pai == NULL) {
                *raiz = no;
            } 
        }
        no = no->pai;
        
    }
    
}

void inserir(struct noArvore** aux, struct noArvore* no, struct noArvore** raiz) {
    if (*aux == NULL) {
        *aux = no;
        balance(*aux, raiz);
    } 
    
    else {
        no->pai = *aux;

        if ((*aux)->valor > no->valor) {
            inserir(&((*aux)->filEsq), no, raiz);
        } 
        
        else {
            inserir(&((*aux)->filDir), no, raiz);
        }     
    }
}

struct noArvore* criarNo(int valor) {
    struct noArvore* no = (struct noArvore*)malloc(sizeof(struct noArvore));
    no->valor = valor;
    no->filEsq = NULL;
    no->filDir = NULL;
    no->altura = 1;
    no->pai = NULL;
    
    return no;
}

void dotTree(FILE *file, struct noArvore *r) {
    if (r != NULL) {
        dotTree(file, r->filEsq);

        fprintf(file, "  \"%p\" [shape=record, label=\"{%p|%p|%d|h=%u|{%p|%p}}\"];\n", (void *)r, (void *)r->pai, (void *)r, r->valor, r->altura, (void *)r->filEsq, (void *)r->filDir);

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
        inserir(&raiz, criarNo(ult), &raiz);
    }

    clock_gettime(CLOCK_MONOTONIC, &b);
    struct noArvore** achou = procurar(&raiz, ult + 1);
    clock_gettime(CLOCK_MONOTONIC, &a);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

    printf("%d\n", t);

    // printf("Valores da árvore: ");
    // verArvore(raiz);
    // printf("\n");

    /*struct noArvore** achou = procurar(&raiz, 5);

    if (achou != NULL) {
        printf("Achou.\n");
    }

    else {
        printf("Não achou.\n");
    }*/

    //dotTree(raiz);

    // Abre o arquivo para escrita

    FILE *dot_file = fopen("arvAvl.dot", "w");
    if (dot_file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    fprintf(dot_file, "digraph G {\n no [shape=record, height=0.6, width=1.5];\n edge [arrowhead=vee, arrowsize=0.8];\n");
    dotTree(dot_file, raiz);
    fprintf(dot_file, "}\n");

    fclose(dot_file);

    liberarArv(raiz);
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>

// Estrutura
struct tree_node {
   int value;
   struct tree_node *lchild;
   struct tree_node *rchild;

};

struct tree_node** search(struct tree_node** root, int value) {
    if ((*root) != NULL) {
        if ((*root)->value == value) {
            return root;
        }

        else if ((*root)->value > value) {
            return search(&((*root)->lchild), value);
        }

        return search(&((*root)->rchild), value);
    }

    return NULL;
}

// Mostrar árvore em ordem
void show(struct tree_node* root) {
    if (root != NULL) {
        show(root->lchild);
        printf("%d ", root->value);
        show(root->rchild);
    }
}

// Inserir na árvore
void insert(struct tree_node** root, struct tree_node* node, struct tree_node** roota) {
    if (*root == NULL) {
        *root = node;
    } 
    
    else {

        if ((*root)->value > node->value) {
            insert(&((*root)->lchild), node, roota);
        } 
        
        else {
            insert(&((*root)->rchild), node, roota);
        }     
    }
}

// Criar novo nó
struct tree_node* create_node(int value) {
    struct tree_node* node = (struct tree_node*)malloc(sizeof(struct tree_node));
    node->value = value;
    node->lchild = NULL;
    node->rchild = NULL;
    
    return node;
}

void tree_print_dot_body(FILE *file, struct tree_node *r) {
    if (r != NULL) {
        tree_print_dot_body(file, r->lchild);

        fprintf(file, "  \"%p\" [shape=record, label=\"{%p|%d|{%p|%p}}\"];\n", (void *)r, (void *)r, r->value, (void *)r->lchild, (void *)r->rchild);

        if (r->lchild) {
            fprintf(file, "  \"%p\" -> \"%p\";\n", (void *)r, (void *)r->lchild);
        }

        if (r->rchild) {
            fprintf(file, "  \"%p\" -> \"%p\";\n", (void *)r, (void *)r->rchild);
        }

        tree_print_dot_body(file, r->rchild);
    }
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
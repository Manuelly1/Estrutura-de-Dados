#include <stdio.h>
#include <stdlib.h>

// Estrutura
struct tree_node {
   int value;
   struct tree_node *lchild;
   struct tree_node *rchild;
   unsigned int h;
   struct tree_node *parent;
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

// Calcular a altura do nó
unsigned int altura(struct tree_node* node) {
    //presta
    if (node == NULL) {
        return 0;
    }

    if ((node->rchild != NULL) && (node->lchild != NULL)) {
        if ((node->rchild->h) > (node->lchild->h)) {
            return (node->rchild->h) + 1;
        }

        else {
            return (node->lchild->h) + 1;
        }
    }

    else if ((node->lchild == NULL) && ((node->rchild != NULL))) {
        return node->rchild->h + 1;
    }

    else if ((node->lchild != NULL) && ((node->rchild == NULL))) {
        return node->lchild->h + 1;
    }

    return 1;
    
}

// Diferença entre as alturas dos filhos
int cdiff(struct tree_node* node) {
    //presta
    if ((node->lchild != NULL) && (node->rchild != NULL)) {
        return abs(node->lchild->h - node->rchild->h);
    } 

    else if ((node->lchild == NULL) && (node->rchild != NULL)) {
        return node->rchild->h;
    } 

    else if ((node->lchild != NULL) && (node->rchild == NULL)) {
        return node->lchild->h;
    }

    return 0;
}

// Número do caso para balanceamento
int cas(struct tree_node* node) {
    //presta
    if ((node != NULL) && (node->lchild != NULL) && (node->rchild != NULL)) {

        if ((node->lchild->h) > (node->rchild->h)) {

            if ((node->lchild->lchild != NULL) && (node->lchild->rchild != NULL)) {
                
                if ((node->lchild->lchild->h) > (node->lchild->rchild->h)) {
                    return 1;
                } 
                
                else {
                    return 3;
                }
            }
        } 
        
        else {
            if ((node->rchild->rchild != NULL) && (node->rchild->lchild != NULL)) {
                if ((node->rchild->rchild->h) > (node->rchild->lchild->h)) {
                    return 2;
                } 
                
                else {
                    return 4;
                }
            }
        }
    }

    else if ((node->lchild != NULL) && (node->rchild == NULL)){
        if ((node->lchild->lchild != NULL) && (node->lchild->rchild == NULL)) {
            return 1;
        }

        else {
            return 3;
        }
    }

    else {
        if ((node->rchild->lchild == NULL) && (node->rchild->rchild != NULL)) {
            return 2;
        }
    }
    

    return 4;
}

// Rotação à direita
void rd(struct tree_node** node, struct tree_node** root) {
        struct tree_node* pai = (*node)->parent;
        struct tree_node* y = (*node)->lchild;
        struct tree_node* x = *node;
        struct tree_node* b = y->rchild;

        y->rchild = x;
        y->parent = pai;
        x->lchild = b;
        x->parent = y;
        
        if (b != NULL) {
            b->parent = x;
        }

        x->h = altura(x);
        y->h = altura(y);

        // essa parte presta
        if (y->parent == NULL) {
            *root = y;
        } 


}

// Rotação à esquerda
void re(struct tree_node** node, struct tree_node** root) {
        struct tree_node* pai = (*node)->parent;
        struct tree_node* y = (*node)->rchild;
        struct tree_node* x = *node;
        struct tree_node* b = y->lchild;

        y->lchild = x;       
        y->parent = pai;
        x->rchild = b;
        x->parent = y;

        if (b != NULL) {
            b->parent = x;
        }

        x->h = altura(x);
        y->h = altura(y);

        // essa parte presta
        if (y->parent == NULL) {
            printf("%d", y->value);
            printf("aaa");
            *root = y;
        }


}

// Balanceamento
void balance(struct tree_node** node, struct tree_node** root) {
    struct tree_node *aux = *node;
    aux = aux->parent;
        
    while (aux != NULL) {
        aux->h = altura(aux);
       
        if (cdiff(aux) > 1) {
            int c = cas(aux);
            printf("Nó %d, Caso: %d\n", aux->value, c);
            if (c == 1) {
                rd(&aux, root);
            } 
            else if (c == 2) {
                re(&aux, root);
            } 
            else if (c == 3) {
                re(&(aux->lchild), root);
                rd(&aux, root);
            } 
            else {
                rd(&(aux->rchild), root);
                re(&aux, root);
            }

        }

        printf("%p\n", aux->parent);

        aux = aux->parent;
        
    }
    
}

// Inserir na árvore
void insert(struct tree_node** root, struct tree_node* node, struct tree_node** roota) {
    if (*root == NULL) {
        *root = node;
        balance(root, roota);
    } 
    
    else {
        node->parent = *root;

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
    node->h = 1;
    node->parent = NULL;
    
    return node;
}

void tree_print_dot_body(FILE *file, struct tree_node *r) {
    if (r != NULL) {
        tree_print_dot_body(file, r->lchild);

        fprintf(file, "  \"%p\" [shape=record, label=\"{%p|%p|%d|h=%u|{%p|%p}}\"];\n", (void *)r, (void *)r->parent, (void *)r, r->value, r->h, (void *)r->lchild, (void *)r->rchild);

        if (r->lchild) {
            fprintf(file, "  \"%p\" -> \"%p\";\n", (void *)r, (void *)r->lchild);
        }

        if (r->rchild) {
            fprintf(file, "  \"%p\" -> \"%p\";\n", (void *)r, (void *)r->rchild);
        }

        tree_print_dot_body(file, r->rchild);
    }
}


int main(void) {
    struct tree_node* root = NULL;

    insert(&root, create_node(3), &root);
    insert(&root, create_node(5), &root);
    insert(&root, create_node(4), &root);
    // insert(&root, create_node(5), &root);
    // insert(&root, create_node(4), &root);
    // insert(&root, create_node(13), &root);
    // insert(&root, create_node(55), &root);
    // insert(&root, create_node(22), &root);
    printf("Valores da árvore: ");
    show(root);
    printf("\n");

    /*struct tree_node* achar = search(&root, 5);

    if (achar != NULL) {
        printf("Achou.\n");
    }

    else {
        printf("Não achou.\n");
    }*/

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
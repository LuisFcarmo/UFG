#include <stdio.h>
#include <stdlib.h>
typedef struct no {
    int valor;
    struct no *direita;
    struct no *esquerda;
} node;

typedef struct {
    node *root;
} tree;

tree *Create_Tree() {
    tree *new = (tree*) malloc(sizeof(tree)*1);
    new -> root = NULL;
    return new;
}

node *Create_Node(int valor) {
    node *new = (node*) malloc(sizeof(node)*1);
    new -> valor = valor;
    new -> direita = NULL;
    new -> esquerda = NULL;
};

void inserir(node **root, int valor) {
    if (*root == NULL) {
        *root = Create_Node(valor);
    } else {
        if(valor > (*root) -> valor) {
            inserir(&((*root) -> direita), valor);
        } else {
            inserir(&((*root) -> esquerda), valor);
        }
    }
}

/*  Percorre a subárvore esquerda.
    Visita o nó atual.
    Percorre a subárvore direita.
    Visita o nó atual.
*/

void InOrder(node *root) {
    if(root == NULL) return;
    InOrder(root -> esquerda);

    printf("%d", root->valor);

    InOrder(root -> direita);
}

/*
    Visita o nó atual.
    Percorre a subárvore esquerda.
    Percorre a subárvore direita.
*/
void Preorder(node *root) {
    if (root == NULL) return;
    printf("%d", root -> valor);
    Preorder(root -> esquerda);
    Preorder(root -> direita);
}

/*
    Percorrer a subárvore esquerda.
    Percorrer a subárvore direita.
    Visitar o nó atual.
*/

void PosOrder(node *root) {
    if (root == NULL) return;
    PosOrder(root -> esquerda);
    PosOrder(root -> direita);
    printf("%d ", root -> valor);
}

void Destruct_Arvore(node *root) {
    if (root == NULL) return;
    Destruct_Arvore(root -> esquerda);
    Destruct_Arvore(root -> direita);
    free(root);
}

int main () {
    int qtd = 0;
    int valor;
    int qtdn;
    tree *tree = Create_Tree();
    scanf("%d", &qtd);
    while (qtd--) {
        scanf("%d", &qtdn);
        while (qtdn--) {
            scanf("%d%*c", &valor);
            inserir(&tree -> root, valor);
        }
        printf("in order.:");
        InOrder(tree -> root);
        printf("\n");
        printf("Pree order:");
        Preorder(tree -> root);
        printf("\n");
        printf("Pos order:");
        PosOrder(tree -> root);
        Destruct_Arvore(tree -> root);
        tree = Create_Tree();
    }

    return 0;
}
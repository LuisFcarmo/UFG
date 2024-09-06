#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//definição da estrutura
typedef struct Node {
    int *keys;
    struct Node **childs;
    int num_keys;
    bool leaf;
} Node;

typedef struct TreeB {
    Node *root;
    int order;
} TreeB;

Node *Create_Node(int order, bool leaf) {
    Node *New = (Node*) malloc(sizeof(Node)*1);
    if (New == NULL) {
        printf("error in alocation memory");
        exit(EXIT_FAILURE);
    }

    New -> num_keys = 0;
    New -> leaf = leaf;

    New -> keys = (int*) malloc(sizeof(int)*(order-1));
    
    if(New -> keys == NULL) {
        printf("error in alocation memory");
        exit(EXIT_FAILURE);
    }

    New -> childs = (Node**) malloc(sizeof(Node*)*order);

    if (New -> childs == NULL) {
        printf("error in alocation memory");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < order; i++) {
        New -> childs[i] = NULL;
    }
    return New;    
}

TreeB * Create_Btree(int order) {
    TreeB *tree = (TreeB*) malloc(sizeof(TreeB)*1);

    if (tree == NULL) {
        printf("error in alocation memory");
        exit(EXIT_FAILURE);
    }

    tree -> root = Create_Node(order, true);
    tree -> order = order;

    return tree;
}

void InsertNoSplit(Node *node, int key, int order) {
    int i = node -> num_keys-1;

    if(node -> leaf) {
        while (i >= 0 && key < node -> keys[i]) {
            node -> keys[i+1] = node -> keys[i];
            i--;
        }
        node -> keys[i+1] = key;
        node -> num_keys++;
    } else {
        while (i >= 0 && key < node -> keys[i]) {
            i--;
        }
        i++;
        if(node -> childs[i] -> num_keys == (2 *order -1)) {
            SplitChild(node, i, node -> childs[i], order);
        }
        if (key > node -> keys[i]) {
            i++;
        }

        InsertNoSplit(node -> childs[i], key, order);
    }
}

void SplitChild(Node *parent, int index, Node *Child, int order) {
    Node *NewChild = Create_Node(order, Child -> leaf);

    int NumberToMove = order / 2;

    for (int i = 0; i < NumberToMove; i++) {
        //move to keys to the child from the new child
        NewChild -> keys[i] = Child -> keys[NumberToMove + i];
        //move the metade of childs from the child to the new child
        NewChild -> childs[i] = Child -> childs[NumberToMove + i];
        
        //erase the date of the child keys 
        Child -> keys[i + NumberToMove] = 0;
        //atribute NULL from the metade of child from the older child
        Child -> childs[i + NumberToMove] = NULL;
    }

    Child -> num_keys = order/2;
    NewChild -> num_keys = order/2;
    //deslocante one position from the atribute the new child
    for (int i = parent -> num_keys; i > index; i--) {
        parent -> childs[i+1] = parent -> childs[i];
    }
    parent -> childs[index+1] = NewChild;

    for (int i = parent -> num_keys - 1; i >= index; i--) {
        parent -> keys[i+1] = parent -> keys[i];
    }

    parent -> keys[index] = Child -> keys[order/2];

    parent -> keys++;
}

void Insert(TreeB *tree, int key) {
    Node *root = tree -> root;

    //verificando se a arvore está cheia
    if (root -> keys == (2 * tree -> order - 1)) {
        Node *NewRoot = Create_Node(tree -> order, false);
        NewRoot -> childs[0] = root;
        tree -> root = NewRoot;
        SplitChild(NewRoot, 0, root, tree -> order);
        InsertNoSplit(NewRoot, key, tree -> order);
    } else {
        InsertNoSplit(root, key, tree -> order);

    }
}

int FindKeyIndex(Node *node, int key) {
    if (node != NULL) {
        int i = 0;
        while (i < node -> num_keys && key > node -> keys[i]) {
            i++;
        }
        //verify with one empty position in atual node
        if (i < node -> num_keys && key == node -> keys[i]) {
            return i;
        }

        if (!node -> leaf) {
            return FindKeyIndex(node -> childs[i], key);
        }
    }
    //return -1 whit node nó presente in tree
    return -1;
}

Node *FindNode(Node *node, int key) {
    if (node != NULL) {
        int i = 0;
        while (i < node -> num_keys && key > node -> keys[i]) {
            i++;
        }

        if (i < node -> num_keys && key == node -> keys[i]) {
            return node;
        }

        if (!node -> leaf) {
            return FindNode(node -> childs[i], key);
        }
    } 
    return NULL;
}

void RemoveInLeef(Node *node, int index) {
    //passing the keys from one position back for remove the leef
    for (int i = index + 1; i < node -> num_keys; i++) {
        node -> keys[i-1] = node -> keys[i];
    }

    node -> num_keys--;
};

void RemoveInternalNode(Node *node, int index) {
    for (int i = index + 1; i < node -> num_keys; i++) {
        node -> keys[i-1] = node -> keys[i];
    }
    if(!node -> leaf) {
        for (int i = index + 1; i < node -> num_keys; i++) {
            node -> childs[i-1] = node -> childs[i];
        }
    }

    node -> num_keys--;
}

void Remove(TreeB *tree, int key) {
    Node *root = tree -> root;
    int index  = FindKeyIndex(root, key);
    Node *node = FindNode(root, key);


    //case one whit remove node in node leaf
    if (node != NULL && node -> leaf && index != -1) {
        RemoveInLeef(node, index);
        return;
    }
    //case two key is present in intern node
    if (node != NULL && !node -> leaf && index != -1) {
        RemoveInternalNode(node, index);
        return;
    }
    printf("node is no present in BTree index = %d\n", index);
    return;
}

void printBTree(Node *node) {
    if (node != NULL) {
        int i;
        for (i = 0; i < node->num_keys; i++) {
            // Se não for uma folha, imprime recursivamente as chaves do filho i
            if (!node->leaf) {
                printBTree(node->childs[i]);
            }
            // Imprime a chave
            printf("%d ", node->keys[i]);
        }
        // Imprime recursivamente as chaves do último filho (se não for uma folha)
        if (!node->leaf) {
            printBTree(node->childs[i]);
        }
    }
}

void printTreeB(TreeB *tree) {
    if (tree != NULL && tree->root != NULL) {
        printf("B-Tree: ");
        printBTree(tree->root);
        printf("\n");
    } else {
        printf("Empty B-Tree\n");
    }
}
//falta implementar o banlaceamento distribuição e fusão nessas arvore
//maturar a ideia da api para comercio
int main() {
    int order = 3;

    TreeB *tree = Create_Btree(order);

    Insert(tree, 10);
    Insert(tree, 20);
    Insert(tree, 5);
    Insert(tree, 15);
    Insert(tree, 25);
    Insert(tree, 3);
    Insert(tree, 8);


    printTreeB(tree);

    Remove(tree, 5);
    Remove(tree, 20);

 


    return 0;
}
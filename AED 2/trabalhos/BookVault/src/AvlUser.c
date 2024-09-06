#include "../include/defines.h"

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(AVLNode *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int getBalance(AVLNode *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

AVLNode *createNode(user data) {
    AVLNode *node = (AVLNode *)malloc(sizeof(AVLNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // Novo nó é adicionado na folha
    return node;
}

AVLNode *rightRotate(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    // Rotação
    x->right = y;
    y->left = T2;

    // Atualizar alturas
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode *leftRotate(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    // Rotação
    y->left = x;
    x->right = T2;

    // Atualizar alturas
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int caseInsensitiveCompare(const char *str1, const char *str2) {
    for (; *str1 && *str2; ++str1, ++str2) {
        if (tolower(*str1) != tolower(*str2)) {
            return tolower(*str1) - tolower(*str2);
        }
    }
    return tolower(*str1) - tolower(*str2);
}

AVLNode *insert(AVLNode *node, user data) {
    if (node == NULL)
        return createNode(data);

    int cmp = caseInsensitiveCompare(data.name, node->data.name);
    if (cmp < 0)
        node->left = insert(node->left, data);
    else if (cmp > 0)
        node->right = insert(node->right, data);
    else
        return node; // Nomes iguais não são permitidos

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && caseInsensitiveCompare(data.name, node->left->data.name) < 0)
        return rightRotate(node);

    if (balance < -1 && caseInsensitiveCompare(data.name, node->right->data.name) > 0)
        return leftRotate(node);

    if (balance > 1 && caseInsensitiveCompare(data.name, node->left->data.name) > 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && caseInsensitiveCompare(data.name, node->right->data.name) < 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

bool search(AVLNode *root, const char *name) {
    if (root == NULL)
        return false; // Não encontrado

    if (caseInsensitiveCompare(name, root->data.name) == 0)
        return true; // Encontrado

    if (caseInsensitiveCompare(name, root->data.name) < 0)
        return search(root->left, name);

    return search(root->right, name);
}

user* searchUser(AVLNode *root, char *name) {
    if (root == NULL)
        return NULL; // Não encontrado

    if (caseInsensitiveCompare(name, root->data.name) == 0)
        return &root->data; // Encontrado

    if (caseInsensitiveCompare(name, root->data.name) < 0)
        return searchUser(root->left, name);

    return searchUser(root->right, name);
}

// Função auxiliar para imprimir os dados de um usuário
void printUser(user u) {
    printf("Name: %s\n", u.name);
    printf("Password: %s\n", u.password);
    printf("ID: %d\n", u.id);
    printf("\n");
}

void printUsers(AVLNode *root) {
    if (root != NULL) {
        printUsers(root->left); 
        printUser(root->data);  
        printUsers(root->right);
    }
}


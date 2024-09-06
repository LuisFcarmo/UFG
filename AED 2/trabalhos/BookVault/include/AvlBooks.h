#ifndef AVLBOOKS
#define AVLBOOKS

#include "./defines.h"

typedef struct no {
    book value;
    struct no *direita, *esquerda;
    int altura;
} NoArv;

typedef struct {
    NoArv *root;
} Tree;

typedef struct {
    bool direita;
    bool esquerda;
    int qtd;
} Resp;

/**
 * @brief Creates a new node with the given book.
 * @param x The book to be stored in the node.
 * @return A pointer to the newly created node.
 */
NoArv * Cria_No(book x);

/**
 * @brief Returns the larger of two integers.
 * @param a First integer.
 * @param b Second integer.
 * @return The larger of the two integers.
 */
int maior(int a, int b);

/**
 * @brief Gets the height of a node.
 * @param node A pointer to the node.
 * @return The height of the node.
 */
int AlturaDoNo(NoArv *node);

/**
 * @brief Calculates the balance factor of a node.
 * @param node A pointer to the node.
 * @return The balance factor of the node.
 */
int FatorDeBalanceamento(NoArv *node);

/**
 * @brief Gets the height of a node.
 * @param node A pointer to the node.
 * @return The height of the node.
 */
int altura(NoArv *node);

/**
 * @brief Performs a right rotation on a subtree.
 * @param y A pointer to the root of the subtree.
 * @return A pointer to the new root of the subtree.
 */
NoArv * RotacaoDireita(NoArv *y);

/**
 * @brief Performs a left rotation on a subtree.
 * @param x A pointer to the root of the subtree.
 * @return A pointer to the new root of the subtree.
 */
NoArv * RotacaoEsquerda(NoArv *x);

/**
 * @brief Performs a right-left rotation on a subtree.
 * @param node A pointer to the root of the subtree.
 * @return A pointer to the new root of the subtree.
 */
NoArv * RotacaoDireitaEsquerda(NoArv *node);

/**
 * @brief Performs a left-right rotation on a subtree.
 * @param node A pointer to the root of the subtree.
 * @return A pointer to the new root of the subtree.
 */
NoArv * RotacaoEsquerdaDireita(NoArv *node);

/**
 * @brief Balances an AVL tree.
 * @param node A pointer to the root of the subtree.
 * @return A pointer to the new root of the balanced subtree.
 */
NoArv * balancear(NoArv *node); 

/**
 * @brief Inserts a book into the AVL tree.
 * @param root A pointer to the root of the tree.
 * @param x The book to be inserted.
 * @return A pointer to the root of the tree after insertion.
 */
NoArv *inserir(NoArv *root, book x);

/**
 * @brief Prints the AVL tree.
 * @param root A pointer to the root of the tree.
 * @param depth The current depth of the tree (for indentation).
 * @return None
 */
void imprimir(NoArv *root, int depth);

/**
 * @brief Counts the children of a node containing a given book.
 * @param root A pointer to the root of the tree.
 * @param x The book to search for.
 * @return A Resp struct containing the count of left and right children and the total count.
 */
Resp Qtd_Filhos(NoArv *root, book x);

/**
 * @brief Removes a book from the AVL tree.
 * @param root A pointer to the root of the tree.
 * @param x The book to be removed.
 * @return A pointer to the root of the tree after removal.
 */
NoArv * Remover(NoArv *root, book x);

/**
 * @brief Finds a book in the AVL tree by name.
 * @param root A pointer to the root of the tree.
 * @param name The name of the book to find.
 * @return The book found, or a default book if not found.
 */
book Find(NoArv *root, char* name);
void LiberarMemoria(NoArv *raiz);

#endif // AVLBOOKS

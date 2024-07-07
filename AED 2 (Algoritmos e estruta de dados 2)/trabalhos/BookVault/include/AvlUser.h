#ifndef AVLUSERS
#define AVLUSERS

#include <stdbool.h>
#include "defines.h"

typedef struct  {
    char name[MaxLenghtUserName];
    char password[MaxPasswordLenght];
    int id;
} user;

typedef struct AVLNode {
    user data;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
} AVLNode;

// Auxiliary functions

/**
 * @brief Returns the maximum of two integers.
 * @param a First integer.
 * @param b Second integer.
 * @return The maximum of a and b.
 */
int max(int a, int b);

/**
 * @brief Returns the height of a given node.
 * @param N Node to find the height of.
 * @return The height of the node.
 */
int height(AVLNode *N);

/**
 * @brief Calculates the balance factor of a node.
 * @param N Node to calculate the balance factor of.
 * @return The balance factor of the node.
 */
int getBalance(AVLNode *N);

/**
 * @brief Creates a new AVL tree node with given user data.
 * @param data User data to store in the node.
 * @return Pointer to the new AVLNode.
 */
AVLNode *createNode(user data);

/**
 * @brief Prints the users in the AVL tree in order.
 * @param root Root node of the AVL tree.
 */
void printUsers(AVLNode *root);

// Rotation functions

/**
 * @brief Performs a right rotation on the given node.
 * @param y Node to perform right rotation on.
 * @return New root after rotation.
 */
AVLNode *rightRotate(AVLNode *y);

/**
 * @brief Performs a left rotation on the given node.
 * @param x Node to perform left rotation on.
 * @return New root after rotation.
 */
AVLNode *leftRotate(AVLNode *x);

// Case insensitive comparison function

/**
 * @brief Compares two strings in a case insensitive manner.
 * @param str1 First string.
 * @param str2 Second string.
 * @return An integer less than, equal to, or greater than zero if str1 is found to be less than, to match, or be greater than str2.
 */
int caseInsensitiveCompare(const char *str1, const char *str2);

// Insertion and search functions in AVL tree

/**
 * @brief Inserts a user into the AVL tree.
 * @param node Root node of the AVL tree.
 * @param data User data to insert.
 * @return New root of the AVL tree after insertion.
 */
AVLNode *insert(AVLNode *node, user data);

/**
 * @brief Searches for a user by name in the AVL tree.
 * @param root Root node of the AVL tree.
 * @param name Name of the user to search for.
 * @return True if the user is found, false otherwise.
 */
bool search(AVLNode *root, const char *name);

/**
 * @brief Searches for a user by name and returns the user data.
 * @param root Root node of the AVL tree.
 * @param name Name of the user to search for.
 * @return Pointer to the user data if found, NULL otherwise.
 */
user* searchUser(AVLNode *root, char *name);


#endif // AVLUSERS_H
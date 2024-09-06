#ifndef LINKEDLIST
#define LINKEDLIST
#include "./defines.h"

typedef struct LINK_LIST {
    order data;
    struct LINK_LIST* next;
} LINKLIST;

/**
 * @brief Create a new node with the given data.
 * 
 * This function creates a new node for the linked list and 
 * initializes it with the provided data.
 * 
 * @param data The data to be stored in the new node.
 * @return LINKLIST* Pointer to the newly created node.
 */
LINKLIST* CREATENEWNODE(order data);

/**
 * @brief Insert a node at the beginning of the linked list.
 * 
 * This function inserts a new node with the given data at 
 * the beginning of the linked list.
 * 
 * @param head Pointer to the head of the linked list.
 * @param data The data to be stored in the new node.
 */
void insertAtBeginning(LINKLIST** head, order data);

/**
 * @brief Remove a node from the linked list by book name.
 * 
 * This function searches for a node in the linked list by the 
 * provided book name and removes it from the list.
 * 
 * @param head Pointer to the head of the linked list.
 * @param bookName The name of the book to be removed.
 */
void removeByBookName(LINKLIST** head, const char* bookName);

/**
 * @brief Print all the elements of the linked list.
 * 
 * This function iterates through the linked list and prints 
 * the data of each node.
 * 
 * @param head Pointer to the head of the linked list.
 */
void printList(LINKLIST* head);

#endif

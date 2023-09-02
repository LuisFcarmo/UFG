#include <stdbool.h>
#ifndef list_h
#define list_h

/**************interface privada*****************/

typedef struct _snode Snode;

typedef struct _linkedlist linkedlist;

linkedlist *LinkedList_create();

Snode *SNode_create(int val);

/************************************************/

/**************interface publica*****************/

bool LinkedList_is_empty (const linkedlist *list);

void LinkedList_add_first (linkedlist *list, int val);

void LinkedList_add_last_slow(linkedlist *list, int val);

void LinkedList_add_last(linkedlist *list, int val);

void LinkedList_add(linkedlist *list, int val, int index);

void LinkedList_print (const linkedlist *list);

void LinkedList_remove (linkedlist *list, int val);

void LinkedList_destroy (linkedlist *list);

int LinkedList_size (linkedlist *list);

int LinkedList_first_val (const linkedlist *list);

int LinkedList_last_val (const linkedlist *list);

int linkedList_get_val (const linkedlist *list, int index);

//void LinkedList_reverse (linkedlist *list);

//linkedlist *linkedlist_clone (linkedlist *list);

/************************************************/

#endif
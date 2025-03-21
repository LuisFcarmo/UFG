#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct _snode {
    int val;
    struct _snode *next;    // auxiliary node
};

struct _linkedlist {
    Snode *end;
    Snode *begin;
    int size;
};

/**
 * @brief create a head of a linkedlist
 * 
 * @return head list of a linkedlist
*/

linkedlist *LinkedList_create() {
    linkedlist *list = (linkedlist *) calloc(1, sizeof(linkedlist));    
    list -> begin = NULL;
    list -> end = NULL;
    list -> size = 1;

    return list;
}

/**
 * @brief create a node 
 *
 * @param value
 *
 * @return a node
 */

Snode *SNode_create(int val) {
    Snode *node = (Snode*) calloc (1, sizeof(Snode));
    node -> val = val;
    node -> next = NULL;

    return node;
}

/**
 * @brief verify if linkedlist is empty
 *
 * @param linkedelist 
 *
 * @return bolean value
 */

bool LinkedList_is_empty (const linkedlist *list) {
    return (list -> begin == NULL && list -> end == NULL);
}

/**
 * @brief add a value in begin in list
 *
 * @param list
 * @param val
 * 
 */

void LinkedList_add_first (linkedlist *list, int val) {
    Snode *p = SNode_create(val);

    p -> next = list -> begin; 

    if (LinkedList_is_empty(list)) {
        list -> end = p;
    }
    list -> size =  list -> size + 1;
    list -> begin = p; 

}

/**
 * @brief print in terminal the list specified
 *
 * @param list 
 *
 */

void LinkedList_print (const linkedlist *list) {
    Snode *ptr = list -> begin;
    //  print values ​​until ptr is null
    printf("L -> ");
    while (ptr != NULL) {
        printf("%d -> ", ptr ->val);
        ptr = ptr -> next;
    }
    printf("NULL\n");
}

/**
 * @brief add value in end of a list
 *
 * @param list 
 * @param value
 * 
 */

void LinkedList_add_last_slow(linkedlist *list, int val) {
    Snode *ptr = SNode_create(val);
    //verifica se a lista está vazia;
    if (LinkedList_is_empty(list)) {
        list -> begin = ptr;
    } 
    else {                
        //this node just points to the beginning of the list and will navigate the whole list
        Snode *ptrq = list -> begin;
        // as long as there is a next node it continues walking in memory
        while (ptrq -> next != NULL) {
            ptrq = ptrq -> next;
        }
        // at this moment we are at the last node of the linked list
        ptrq -> next = ptr;
        
    }
}

/**
 * @brief add value in end of a list in the fast way
 *
 * @param list 
 * @param value
 * 
 */

void LinkedList_add_last(linkedlist *list, int val) {
    Snode *ptr = SNode_create(val);
    if (LinkedList_is_empty(list)) {
        list -> begin = ptr;
        list -> end = ptr;
    }
    else {
        list -> end -> next = ptr;
        list -> end =  list -> end -> next;
    }
    list -> size =  list -> size + 1;

}

/**
 * @brief remove the first specified value in list
 *
 * @param list 
 * @param value
 * 
 */

void LinkedList_remove (linkedlist *list, int val) {
    if (!LinkedList_is_empty(list)) {    
        Snode *prev = NULL;
        Snode *pos = list -> begin;

        while (pos != NULL && pos -> val != val) {  
            prev = pos;
            pos = pos -> next;
        }   

        if (pos != NULL) {

            if (list -> end == pos) {
                list -> end = prev;
            }
            
            if (list -> begin == pos) {
                list -> begin = list -> begin -> next;
            }

            else {
                prev -> next = pos -> next;
            }
            free(pos);
            list -> size =  list -> size - 1;
        }
    }
}

/**
 * @brief destroy a list
 *
 * @param list 
 *
 */

void LinkedList_destroy (linkedlist *list) {
    Snode *p = list -> begin;
    Snode *aux = NULL;

    while (p != NULL) {
        aux = p;
        p = p -> next;
        free(aux);
    }
    
    free(list);

}

/**
 * @brief get a size of a list
 *
 * @param list 
 *
 * @return size of a list
 */

int LinkedList_size (linkedlist *list) {
    return list -> size;
}

/**
 * @brief get a first value of a list
 *
 * @param list 
 *
 * @return first value
 */

int LinkedList_first_val (const linkedlist *list) {
    if (LinkedList_is_empty(list)){
        fprintf(stderr, "ERROR in 'LinkedList_first_val'\n");
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }
    else {
        return list -> begin -> val;
    }
}

/**
 * @brief get a las value of a list
 *
 * @param list 
 *
 * @return last value
 */

int LinkedList_last_val (const linkedlist *list) {
    if (LinkedList_is_empty(list)){
        fprintf(stderr, "ERROR in 'LinkedList_last_val'\n");
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }
    else {
        return list -> end -> val;
    }
}

/**
 * @brief get the specified index value 
 *
 * @param list
 * @param index 
 *
 * @return value specified
 */

int linkedList_get_val (const linkedlist *list, int index) {
    if (index < 0 || index > list -> size) {
        fprintf(stderr, "ERROR in 'LinkedList_get_val'\n");
        fprintf(stderr, "Invalid Index: %d\n", index);
        fprintf(stderr, "Try an index within [0, %d]\n", list->size);
        exit(EXIT_FAILURE);
    }
    else {
        Snode *node = list -> begin;
        
        for (int i = 0; i != index; i++) {
            node = node -> next;
        }
        return node -> val;
    }
}

void LinkedList_add(linkedlist *list, int val, int index) {
    if (index < 0 || index > list -> size) {
        fprintf(stderr, "ERROR in 'LinkedList_get_val'\n");
        fprintf(stderr, "Invalid Index: %d\n", index);
        fprintf(stderr, "Try an index within [0, %d]\n", list->size);
        exit(EXIT_FAILURE);
    }
    Snode *prev = NULL;
    Snode *pos = list -> begin;
    Snode *New = SNode_create(val);

    if (index == 1) {
        LinkedList_add_first(list, val);
    }     
    else if (index == list -> size) {
        LinkedList_add_last(list, val);
    }
    else {
        for (int i = 1; i != index; i++) {
            prev = pos;
            pos = pos -> next; 
        }
        prev -> next = New;
        New -> next = pos;
    }
}

#include "Circ_list.h"
#include <stdio.h>
#include <stdlib.h>

struct _circlist {
    int size;
    node *begin;    
    node *end;

};

struct _node {
    int value;
    node *next;
    node *prev;    
};

circlist *CircList_create () {
    circlist *CList = (circlist*) calloc(1, sizeof(circlist));

    CList -> size = 0;
    CList -> begin = NULL;
    CList -> end = NULL;
    
    return CList;
}

void Circnode_destroy (node **node_ref) {
    node *Pnode = *node_ref;
    free(Pnode);
    *node_ref = NULL;
}

void CircList_destroy (circlist **list_ref) {
    circlist *List = *list_ref;
    node *Pnode = List -> begin;
    node *auxNode = NULL;

    while (Pnode != List-> end);
    {
        auxNode = Pnode;
        Pnode = Pnode -> next;
        Circnode_destroy(&auxNode);
    }

    Circnode_destroy(&Pnode);
    free(List);
    *list_ref = NULL;
}

void V2CircList_destroy(circlist **list_ref) {
     circlist *List = *list_ref;
    node *Pnode = List -> begin;
    node *auxNode = NULL;

    for (int i = 0; i < List -> size; i ++) {
        auxNode = Pnode;
        Pnode = Pnode -> next;
        Circnode_destroy(auxNode);
    }

    free(List);
    *list_ref = NULL;
} 

node *Nodecreate (int value) {
    node *NewNode = (node*) calloc(1, sizeof(node));

    NewNode -> value = value;
    NewNode -> next = NewNode;
    NewNode -> prev = NewNode;

    return NewNode;
}



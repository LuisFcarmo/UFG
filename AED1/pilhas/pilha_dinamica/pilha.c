#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

struct _stack {
    node *begin;
    node *end;
    int size;

};

struct _node {
    int value;

    node *prev;
    node *next;
};

stack *Stack_create () {
    stack *newstack = (stack*) calloc(1, sizeof(stack));
    newstack -> begin = NULL;
    newstack -> end = NULL;
    newstack -> size = 0;

    return newstack;
}

node *Node_create (int value) {
    node *newNode = (node*) calloc(1, sizeof(node));
    
    newNode -> value = value;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    
    return newNode;
}

void Stack_destroy (stack *Pstack) {
    node *Node = Pstack -> begin;
    node *auxNode = NULL;

    while (Node != NULL) {
        auxNode = Node;
        Node = Node -> next;
        free(auxNode);
    }

    free(Pstack);
}   

bool Stack_is_empty (stack *Pstack) {
    return Pstack -> size == 0;
};

void Stack_push(stack *Pstack, int value) {
    node *newNode = Node_create(value);

    if (Stack_is_empty(Pstack)) {
        Pstack -> begin = newNode;
    }  
    else {
        Pstack -> end -> next = newNode;
        newNode -> prev =  Pstack -> end;
    }

    Pstack -> end = newNode;
    Pstack -> size++;
}

void Stack_pop (stack *Pstack) {
    node *AuxNode = Pstack -> end;
    
    if (!Stack_is_empty(Pstack)) {
        if (AuxNode != NULL) {
            Pstack -> end = AuxNode -> prev;

            free(AuxNode);
            Pstack -> size--;
        }
    }
};



int Stack_peek (stack *Pstack) {
    if (!Stack_is_empty(Pstack))
    {
        return Pstack -> end -> value;
    }    
}; 

void Stack_print (stack *Pstack) {
    node *AuxNode = Pstack -> begin;
    if (Pstack -> size > 0) {
        printf("Pilha vazia -> ( ");
        while (AuxNode != NULL) {
            printf(" %d", AuxNode -> value);
            AuxNode = AuxNode -> next;
        }
        printf(" )");
    } 
    else {
        printf("Pilha vazia\n");
    }
};

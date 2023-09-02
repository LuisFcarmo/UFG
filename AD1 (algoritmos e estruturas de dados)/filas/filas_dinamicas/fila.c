#include "fila.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct _row {
    int size;
    node *begin;
    node *end;

};

struct _node {
    int value;
    node *next;
    node *prev;

};

row *Row_create () {
    row *NewRow = (row*) calloc(1, sizeof(row));
    NewRow -> size = 0;
    NewRow -> begin = NULL;
    NewRow -> end = NULL;

    return NewRow;
}

node *Node_create (int value) {
    node *NewNode = (node*) calloc(1, sizeof(node));
    NewNode -> value = value;
    NewNode -> next = NULL;
    NewNode -> prev = NULL;
    
}

void Row_destroy (row *Row) {
    node *Pnode =  Row -> begin;
    node *auxNode = NULL;
    for (int i = 0; i < Row -> size; i++) {
        auxNode = Pnode;
        Pnode = Pnode -> next;
        free(auxNode);
    }

    free(Row);
}

bool Row_is_empty (const row *Row) {
    return Row -> size == 0;
}

void Row_enqueue (row *Row, int value) {
    node *NewNode = Node_create(value);

    if (Row_is_empty(Row)) {
        Row -> begin = NewNode;
    }
    else {
        NewNode -> prev = Row -> end;
        Row -> end -> next = NewNode;
    }
    
    Row -> end = NewNode;
    Row -> size++;
}

void Row_dequeue (row *Row) {
    node *Pnode = Row -> begin;
    if (!Row_is_empty(Row)) {
        Row -> begin = Row -> begin -> next;
    }

    free(Pnode);
    Row -> size--;
}

int Row_peek (row *Row) {
    if (Row_is_empty(Row)) {
        return Row -> begin -> value;
    }
}

void Row_print (row *Row) {
    node *AuxNode = Row -> begin;
    if (Row -> size > 0) {
        printf("Fila -> ( ");
        while (AuxNode != NULL) {
            printf(" %d", AuxNode -> value);
            AuxNode = AuxNode -> next;
        }
        printf(" )");
    } 
    else {
        printf("Fila vazia\n");
    }
};

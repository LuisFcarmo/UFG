#include "Datastructs.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct _node {
    ELEMENT value;
    node *next;
};
 
struct _queue {
    node *begin;
    node *end;
    int size;
};

Queue *New_Queue() {
    Queue *N_queue = NULL;
    N_queue = (Queue*) malloc(sizeof(Queue)*1);
    if (N_queue != NULL) {
        N_queue -> begin = NULL;
        N_queue -> end = NULL;
        N_queue -> size = 0;
    } else {
        printf("error");
        exit(0);
    }
    return N_queue;
};

bool Destruct_node (node **ref) {
    node *node = *ref;
    if (node != NULL) {
        free(node);
    } else {
        printf("error\n");
    }
}

bool Destruct_Queue (Queue **ref) {
    if (*ref != NULL) {    
        Queue *ref_q = *ref;
        node *n = ref_q -> begin;
        node *aux = NULL;
        
        for (int i = 0; i < ref_q -> size; i++) {
            aux = n;
            n = n -> next;
            Destruct_node(&aux);
            aux = NULL;
        }

        free(*ref);
        ref = NULL;

        return true;
    } else {
        printf("error\n");
        return false;
    }

}

node *New_Node(ELEMENT x) {
    node *Nnode = NULL;
    Nnode = (node*) malloc(sizeof(node)*1);
    if (Nnode != NULL) {   
        Nnode -> next = NULL;

        switch (x.type)
        {
        case INTEGER:
            Nnode -> value.value.valueI = x.value.valueI;
            break;
        case FLOAT:
            Nnode -> value.value.valueF = x.value.valueF;
            break;
        case CHAR:
            Nnode -> value.value.valueC = x.value.valueC;
            break;
        case LONGLONG:
            Nnode -> value.value.ValueLL = x.value.ValueLL;
            break;
        case DOUBLE:
            Nnode -> value.value.ValeuD = x.value.ValeuD;
            break;
        default:
            printf("error type is invalid\n");
            break;
        }
    } else {
        printf("error\n");
        exit(0);
    }
    return Nnode;
};
bool Queue_is_empty(Queue *ref) {
    if (ref -> size == 0) return true;
    return false;
};

bool Enqueue(Queue *ref, ELEMENT x) {
    node *node = New_Node(x);
    if (ref != NULL) {
        if (Queue_is_empty(ref)) {
            ref -> begin = node;
        } else {
            ref -> end -> next = node;
        }
    } else {
        return false;
    }
    ref -> end = node;
    ref -> size++;
}

void Dequeue (Queue *ref) {
    node *aux = ref -> begin;
    if (!Queue_is_empty(ref)) {
        Destruct_node(&ref -> end);
        ref -> size--;
        for (int i = 0; i < ref -> size-1; i++) {
            aux = aux -> next;
        }
        if (ref -> size == 0) {
            ref -> begin = NULL;
            ref -> end = NULL;
        }
        ref -> end = aux;
        ref -> end -> next = NULL;
    } else {
        printf("error\n");
    }
};

ELEMENT Row_peek (Queue * ref){
    return ref -> begin -> value;
};

void Show(Queue *list) {
    node *ptr = list -> begin;
    //  print values ​​until ptr is null
    printf("L -> ");
    while (ptr != NULL) {
        printf("%d -> ", ptr -> value.value.valueI);
        ptr = ptr -> next;
    }
    printf("NULL\n");
}




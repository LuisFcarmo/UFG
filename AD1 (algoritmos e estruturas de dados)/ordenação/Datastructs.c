#include "Datastructs.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

ELEMENT Tscanf (ELEMENT x) {
    switch (x.type)
    {
    case INTEGER:
        scanf("%d", &x.value.valueI);
        break;
    case FLOAT:
        scanf("%f", &x.value.valueF);
        break;
    case CHAR:
        scanf("%d", &x.value.valueC);
        break;
    case LONGLONG:
        scanf("%d", &x.value.ValueLL);
        break;
    case DOUBLE:
        scanf("%d", &x.value.ValeuD);

        break;
    default:
        printf("error type is invalid\n");
        break;
     }
}

/*
    Queue functions
*/
struct _node {
    ELEMENT value;
    node *next;
};

struct _dnode {
    ELEMENT value;
    node *next;
    node *prev;
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
        printf("error1");
        exit(0);
    }
    return N_queue;
};

bool Destruct_node (node **ref) {
    node *node = *ref;
    if (node != NULL) {
        free(node);
    } else {
        printf("error2\n");
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
        printf("error3\n");
        return false;
    }

}

node *New_Node(ELEMENT x) {
    node *Nnode = NULL;
    Nnode = (node*) malloc(sizeof(node)*1);
    if (Nnode != NULL) {   
        Nnode -> next = NULL;
        Nnode -> value.type = x.type;

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
        printf("error4\n");
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
// arrumar essa função
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
        printf("error5\n");
    }
};

ELEMENT Queue_peek (Queue * ref){
    return ref -> begin -> value;
};
void Queue_Show(Queue *list) {
    node *ptr = list -> begin;

    //  print values ​​until ptr is null
    printf("L -> ");
    while (ptr != NULL) {
        switch (ptr -> value.type)
        {
            case INTEGER:
                printf("%d -> ", ptr -> value.value.valueI);
                ptr = ptr -> next;
                break;
            case FLOAT:
                printf("%lf -> ", ptr -> value.value.valueF);
                ptr = ptr -> next;
                break;
            case CHAR:
                printf("%c -> ", ptr -> value.value.valueC);
                ptr = ptr -> next;
                break;
            case LONGLONG:
                printf("%lld -> ", ptr -> value.value.ValueLL);
                ptr = ptr -> next;
                break;
            case DOUBLE:
                printf("%lf -> ", ptr -> value.value.ValeuD);
                ptr = ptr -> next;
                break;
            default:
                printf("error type is invalid\n");
                break;
        }
    }
    printf("NULL\n");
}

/*
    stack functions
*/

struct _stack {
    dnode *begin;
    dnode *end;
    int size;
};

Stack *New_stack() {
    Stack *new = NULL;
    new = (Stack*) malloc(sizeof(Stack)*1);
    if (new != NULL) {
        new -> begin = NULL;
        new -> end = NULL;
        new -> size = 0;
    } else {
        printf("error\n");
        exit(0);
    }
    return new;
}; 



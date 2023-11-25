#include "Datastructs.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * @brief normal node just a next node
 */
struct _node {
    ELEMENT value;
    node *next;
};

/**
 * @brief duple node whit a next node and prev node
 * 
 */
struct _Dnode {
    dnode *next;
    dnode *prev;
    ELEMENT value;
};

/**
 * @brief simple queue header whit begin and end node
 * 
 */
struct _queue {
    node *begin;
    node *end;
    int size;
};

/**
 * @brief show the value whit a node considering a type of element present at the node
 *
 * @param node pointer
 * 
 */
void show_node (node *pt) {
    ELEMENT ptr = pt ->value;
     switch (ptr.type)
        {
        case INTEGER:
            printf("%d -> ", ptr.value.valueI);
            break;
        case FLOAT:
            printf("%lf -> ", ptr.value.valueF);
            break;
        case CHAR:
            printf("%c -> ", ptr.value.valueC);
            break;
        case LONGLONG:
             printf("%lld -> ", ptr.value.ValueLL);
            break;
        case DOUBLE:
            printf("%lf -> ", ptr.value.ValueD);
            break;
        default:
            printf("error type is invalid\n");
            break;
        }
    return;
} 

/**
 * @brief add value in end of a list
 *
 * @param list 
 * @param value
 * 
 */

void show_dnode (dnode *pt) {
    ELEMENT ptr = pt ->value;
    switch (ptr.type)
        {
        case INTEGER:
            printf("%d -> ", ptr.value.valueI);
            break;
        case FLOAT:
            printf("%lf -> ", ptr.value.valueF);
            break;
        case CHAR:
            printf("%c -> ", ptr.value.valueC);
            break;
        case LONGLONG:
             printf("%lld -> ", ptr.value.ValueLL);
            break;
        case DOUBLE:
            printf("%lf -> ", ptr.value.ValueD);
            break;
        default:
            printf("error type is invalid\n");
            break;
        }
    return;
}

/**
 * @brief scanf function modified for work whit a generic type
 *
 * @param ELEMENT x
 * 
 * @return return a gyneric element
 */
ELEMENT Tscanf(ELEMENT x) {
    switch (x.type)
    {
    case INTEGER:
        scanf("%d", &x.value.valueI);
        break;
    case FLOAT:
        scanf("%f", &x.value.valueF);
        break;
    case CHAR:
        scanf("%c",  &x.value.valueC);
        break;
    case LONGLONG:
        scanf("%lld", &x.value.ValueLL);
        break;
    case DOUBLE:
        scanf("%lf", &x.value.ValueD);
        break;
    default:
        printf("error type is invalid\n");
        break;
    }
    return x;
};

/*
    Queue functions
*/

/**
 * @brief create a new queue and resetting the variable
 * 
 * @return return a queue of desire type
 */
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
/**
 * @brief create a new queue and resetting the variable
 * @param nod reference a adress of memory from the node use &pointer
 * @return return a boolean value ( false = failure and true = sucess )
 */
bool Destruct_node (node **ref) {
    node *node = *ref;
    if (node != NULL) {
        free(node);
    } else {
        printf("error\n");
    }
    *ref = NULL;    
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
        Nnode->value.type = x.type;

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
            Nnode -> value.value.ValueD = x.value.ValueD;
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

ELEMENT Queue_peek (Queue * ref){
    return ref -> begin -> value;
};

void Queue_show(Queue *ref) {
    node *ptr = ref -> begin;
    //  print values ​​until ptr is null
    printf("L -> ");
    while (ptr != NULL) {
        show_node(ptr);
        ptr = ptr -> next;
    }
    printf("NULL\n");
}

/*
    Stack functions
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

dnode *New_dnode(ELEMENT x) {
    dnode *new = NULL;
    new = (dnode*) malloc(sizeof(dnode)*1);
    if (new != NULL) {
        new -> prev = NULL;
        new -> next = NULL;
        new -> value.type = x.type;

        switch (x.type)
        {
        case INTEGER:
            new -> value.value.valueI = x.value.valueI;
            break;
        case FLOAT:
            new -> value.value.valueF = x.value.valueF;
            break;
        case CHAR:
            new -> value.value.valueC = x.value.valueC;
            break;
        case LONGLONG:
            new -> value.value.ValueLL = x.value.ValueLL;
            break;
        case DOUBLE:
            new -> value.value.ValueD = x.value.ValueD;
            break;
        default:
            printf("error type is invalid\n");
            break;
        }
    } else {
        printf("error\n");
        exit(0);
    }
    return new;
};

bool Destruct_dnode (dnode **ref) {
    dnode *node = *ref;
    if (ref != NULL) {
        free(node);
        *ref = NULL;
    } else {
        printf("error\n");
    }
}

bool Destruct_stack(Stack **ref) {
    Stack *st = *ref;
    if (ref != NULL) {
        if (Stack_is_empty(st)) {
            free(st);
            *ref = NULL;
        } else {
            dnode *ref = st -> begin;
            dnode *aux = NULL;
            for (int i = 0; i < st -> size-1; i++) {
                aux = ref;
                Destruct_dnode(&aux);
                ref = aux -> next;
            }
        }
    } else {
        printf("error\n");
    }
};  

bool Stack_is_empty(Stack *st) {
    if (st -> size == 0) return true;
    return false;
};

bool pop(Stack *st) {
    dnode *aux = st -> end;
    if (st != NULL) {
        if (!Stack_is_empty(st)) {
            st -> end = aux -> prev;
            Destruct_dnode(&aux);
            st -> size--;
            if (st -> size != 0)  {
                st -> end -> next = NULL;
            } else {
                st -> begin = NULL;
            }
        } else {
            printf("error stack is empty\n");
        }
        
        return true;
    } else {
        printf("error\n");
        exit(0);
    }
    return false;
};

bool push(Stack *st, ELEMENT x) {
    dnode *Dnode = New_dnode(x);
    if (st != NULL) {
        if (Stack_is_empty(st)) {
            st -> begin = Dnode;
            st -> end = Dnode;
        } else {
            st -> begin -> prev = Dnode;
            Dnode -> next = st -> begin;
        }
    } else {
        printf("error\n");
        exit(0);
    }
    st -> size++;
    st -> begin = Dnode;
};

ELEMENT Stack_peek(Stack* st) {
    return st -> begin -> value;
};

void Stack_show(Stack *st) {
    dnode *node = st -> begin;
    printf("size = %d\n", st -> size);
    printf("L = ");
    while (node != NULL) {
        show_dnode(node);
        node = node -> next;
    }
    printf("NULL");
    printf("\n");
};

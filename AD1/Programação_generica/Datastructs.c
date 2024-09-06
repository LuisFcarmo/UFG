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

void Tprintf(ELEMENT x) {
switch (x.type)
    {
    case INTEGER:
        printf("%d", x.value.valueI);
        break;
    case FLOAT:
        printf("%f", x.value.valueF);
        break;
    case CHAR:
        printf("%c",  x.value.valueC);
        break;
    case LONGLONG:
        printf("%lld", x.value.ValueLL);
        break;
    case DOUBLE:
        printf("%lf", x.value.ValueD);
        break;
    default:
        printf("error type is invalid\n");
        break;
    }
    return;
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

/**
 * @brief scanf function modified for work whit a generic type
 *
 * @param ELEMENT x
 * 
 * @return return a gyneric element
 */
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

/**
 * @brief scanf function modified for work whit a generic type
 *
 * @param ELEMENT x
 * 
 * @return return a gyneric element
 */
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

/**
 * @brief scanf function modified for work whit a generic type
 *
 * @param ELEMENT x
 * 
 * @return return a gyneric element
 */
bool Queue_is_empty(Queue *ref) {
    if (ref -> size == 0) return true;
    return false;
};

/**
 * @brief scanf function modified for work whit a generic type
 *
 * @param ELEMENT x
 * 
 * @return return a gyneric element
 */
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

/**
 * @brief scanf function modified for work whit a generic type
 *
 * @param ELEMENT x
 * 
 * @return return a gyneric element
 */
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

/**
 * @brief scanf function modified for work whit a generic type
 *
 * @param ELEMENT x
 * 
 * @return return a gyneric element
 */
ELEMENT Queue_peek (Queue * ref){
    return ref -> begin -> value;
};

/**
 * @brief scanf function modified for work whit a generic type
 *
 * @param ELEMENT x
 * 
 * @return return a gyneric element
 */
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

/**
 * @brief scanf function modified for work whit a generic type
 *
 * @param ELEMENT x
 * 
 * @return return a gyneric element
 */
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

/**
 * @brief scanf function modified for work whit a generic type
 *
 * @param ELEMENT x
 * 
 * @return return a gyneric element
 */
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

/**
 * @brief scanf function modified for work whit a generic type
 *
 * @param ELEMENT x
 * 
 * @return return a gyneric element
 */
bool Destruct_dnode (dnode **ref) {
    dnode *node = *ref;
    if (ref != NULL) {
        free(node);
        *ref = NULL;
    } else {
        printf("error\n");
    }
}

/**
 * @brief scanf function modified for work whit a generic type
 *
 * @param ELEMENT x
 * 
 * @return return a gyneric element
 */
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

/**
 * @brief scanf function modified for work whit a generic type
 *
 * @param ELEMENT x
 * 
 * @return return a gyneric element
 */
bool Stack_is_empty(Stack *st) {
    if (st -> size == 0) return true;
    return false;
};

/**
 * @brief scanf function modified for work whit a generic type
 *
 * @param ELEMENT x
 * 
 * @return return a gyneric element
 */
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

/**
 * @brief scanf function modified for work whit a generic type
 *
 * @param ELEMENT x
 * 
 * @return return a gyneric element
 */
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

/**
 * @brief scanf function modified for work whit a generic type
 *
 * @param ELEMENT x
 * 
 * @return return a gyneric element
 */
ELEMENT Stack_peek(Stack* st) {
    return st -> begin -> value;
};

/**
 * @brief scanf function modified for work whit a generic type
 *
 * @param ELEMENT x
 * 
 * @return return a gyneric element
 */
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


struct _linked_list {
    dnode *begin;
    dnode *end;
    int size;
};

/**
 * @brief scanf function modified for work whit a generic type
 *
 * @param ELEMENT x
 * 
 * @return return a gyneric element
 */
Linkedlist *New_list() {
    Linkedlist *New = NULL;
    do {
        New = (Linkedlist*) malloc(sizeof(Linkedlist)*1);
    } while (New == NULL);
    New -> begin = NULL;
    New -> end = NULL;
    New -> size = 0;

    return New;
};

/**
 * @brief scanf function modified for work whit a generic type
 *
 * @param ELEMENT x
 * 
 * @return return a gyneric element
 */

/*
falta implementar não só esse destrutor como o destrutor de todos as outras estrutura de dados 
estou encontrando um erro de segmentação ao liberar as memorias resolver isso e otimizar os codigos da pilha 
como foi a primeira estrutura que fiz no projeto não está boa se encontra bastante confusa
anotações apenas para não me perder
falta documentar 90% das funções farei isso assim que possível

*/
bool Destruct_list(Linkedlist**) {

};

/**
 * @brief scanf function modified for work whit a generic type
 *
 * @param ELEMENT x
 * 
 * @return return a gyneric element
 */
bool List_is_empty(Linkedlist* list) {
    if (list -> size == 0) return true;
    return false;
};

/**
 * @brief scanf function modified for work whit a generic type
 *
 * @param ELEMENT x
 * 
 * @return return a gyneric element
 */
bool Add_first_list(Linkedlist* list, ELEMENT x) {
    dnode *node = New_dnode(x);
    if(list != NULL) {
        if (List_is_empty(list)) {
            list -> end = node;        
        } else {
            list -> begin -> prev = node;
            node -> next = list -> begin;
        }

        list -> begin = node;
        list -> size++;
        return true;
    } else {
        printf("error");
        return false;
    }
};

/**
 * @brief scanf function modified for work whit a generic type
 *
 * @param ELEMENT x
 * 
 * @return return a gyneric element
 */
bool Add_last_list(Linkedlist* list, ELEMENT x) {
    dnode *node = New_dnode(x);
    if (list != NULL) {
        if (List_is_empty(list)) {
            list -> begin = node;
        } else { 
            list -> end -> next = node;
            node -> prev = list -> end;
        }
        
        list -> end = node;
        list -> size++;
        return true;
    } else {

        return false;
    }
};

/**
 * @brief scanf function modified for work whit a generic type
 *
 * @param ELEMENT x
 * 
 * @return return a gyneric element
 */
dnode *Searching_index (Linkedlist *list, int index) {
    dnode *ref = list -> begin;
    printf("%d--\n", index);
    for (int i = 0; i < index; i++) {
        ref = ref -> next;
    }
    printf("%lf", ref ->value.value.valueF);
    return ref;

}

/**
 * @brief scanf function modified for work whit a generic type
 *
 * @param ELEMENT x
 * 
 * @return return a gyneric element
 */
int Searching_node_index (Linkedlist *list, ELEMENT x) {
    dnode *node = list -> begin;
    int index = 0;
    bool verifiy = false;
    for (int i = 0; i < list -> size; i++) {
        if (x.type == INTEGER) {
            if (x.value.valueI == node->value.value.valueI) {
                verifiy = true;
                break;
            }
        }
        if (x.type == CHAR) {
            if (x.value.valueC == node->value.value.valueC) {
                verifiy = true;
                break;
            }
        }
        if (x.type == DOUBLE) {
            if (x.value.ValueD == node->value.value.ValueD) {
                verifiy = true;
                break;
            }
        }
        if (x.type == FLOAT) {
            if (x.value.valueF == node->value.value.valueF) {
                verifiy = true;
                break;
            }
        }
        if (x.type == LONGLONG) {
            if (x.value.ValueLL == node->value.value.ValueLL) {
                verifiy = true;
                break;
            }
        }
        node = node -> next;
        index++;
    }
    if (verifiy) {
        return index;
    } else {
        printf("error element is not in list\n");
        return -1;
    }
}

/**
 * @brief add element x in a desired index 
 *
 * @param Linkedlist list
 * @param ELEMENT x
 * @param int index
 * 
 * @return  return true = (Sucefull add) and false (failure add)
 */
bool Add_list(Linkedlist *list, ELEMENT x, int index) {
    if (list != NULL) {
        if (List_is_empty(list)) {
            Add_first_list(list, x);
        } 
        else if (index == 0) {
            Add_first_list(list, x);
        }
        else if (index == list -> size + 1) {
            Add_last_list(list, x);
        } 
        else if (index > 0 && index < list -> size){
            dnode *new_node = New_dnode(x);
            dnode *ref = Searching_index(list, index);
            // change the memory address of the pointer after the reference that will now be the inserted node
            ref -> prev -> next = new_node;
            // changes the memory address of the next node of the added node by changing to the reference
            new_node -> next = ref;
            // changes the address from the previous node to the new node
            new_node -> prev = ref -> prev;
            // chages the prev address from the new node
            ref -> prev = new_node;

            list -> size++;            
        }
        return true;
    } else {
        printf("error\n");
        return false;
    }
};

/**
 * @brief remove a element x in a desired index
 *
 * @param LinkedList *list 
 * @param int index
 * 
 * @return return true = (Sucefull removed) and false (failure remove)
 */
bool Remove(Linkedlist* list, int index) {
    if (index > list -> size) {
        printf("index exceeded list size\n");
        return false;
    }
    if (!List_is_empty(list)) {
        dnode *ref = Searching_index(list, index);
        if (index == 0) {
            list -> begin = ref -> next;
            Destruct_dnode(&ref);
            list -> begin -> prev = NULL;
        } 
        else if (index == list -> size-1) {
            list -> end = ref -> prev;
            Destruct_dnode(&ref);
            list -> end -> next = NULL;
        }
        else if (index > 0 && index < list -> size) {
            ref -> prev -> next = ref -> next;
            ref -> next -> prev = ref -> prev;
            Destruct_dnode(&ref);
        }
        list -> size--;
    } else {
        printf("erro\n");
        return false;
    }
};

/**
 * @brief remove the first element in list equal a x informed
 *
 * @param LinkedList *list  Remove();

 * @param ELEMENT x
 * 
 * @return return true = (Sucefull removed) and false (failure remove)
 */
bool Remove_first(Linkedlist* list, ELEMENT x) {
    if (!List_is_empty(list)) {
        int index = Searching_node_index(list, x);
        if (index == -1) {
            printf("element not in list\n");
            return false;   
        }   
        Remove(list, index);     
        return true;
    }  else {
        printf("error\n");
        return false;
    }

};

//tratar o bug quando removemos todos os elementos
//função funcionando de maneira básica falta tratar alguns erros
//como quando todos os elementos da lista são iguais ao que vc quer remover

bool Remove_all(Linkedlist* list, ELEMENT x) {
    if (!List_is_empty(list)) {
        while (1) {
            int index = Searching_node_index(list, x);
            if (index == -1) {
                printf("element not in list\n");
                return false;   
            }   
      
            Remove(list, index);    
        }
        return true;
    }  else {
        printf("error\n");
        return false;
    }
};
/*
essa função vai retornar um elemento na lista se baseando no seu index com o intuito de facilitar a forma de exibir
e manipular os dados na lista não ficando refem do show e outras funções falta implementar;
*/
ELEMENT Get_element(Linkedlist*, int) {

};

/**
 * @brief Show the list
 *
 * @param LinkdeList *x
 * 
 * @return void
 */
void List_show(Linkedlist* list) {
    dnode *node = list -> begin;
    printf("size = %d\n", list -> size);
    printf("L = ");

    while (node != NULL) {
        show_dnode(node);
        node = node -> next;
    }
    
    printf("NULL");
    printf("\n");
};
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct _list {
    node *begin;
    node *end;
    int size;
};

struct _node {
    int val;
    node *next;
    node *prev;
};


list *List_Create () {
    list *Newlist = (list*) calloc(1, sizeof(list));

    Newlist -> begin = NULL;
    Newlist -> end = NULL;
    Newlist -> size = 0;

    return Newlist;
}

node *Node_create (int value) {
    node *NewNode = (node*) calloc(1, sizeof(node));
    NewNode -> val = value;
    NewNode -> next = NULL;
    NewNode -> prev = NULL;
    
    return NewNode;
}

bool List_empty (list *List) {
    return List -> size == 0; 
}

void List_add_first (list *List, int value) {
    node *node = Node_create(value);
    
    if (List_empty(List)) {
        List -> end = node;
    }
    else {
        node -> next = List -> begin;
        List -> begin -> prev = node;
    }

    List -> begin = node;
    List -> size++;
}

void list_add_last (list *List, int value) {
    node *node = Node_create(value);

    if (List_empty(List)) {
        List -> begin = node;
    }
    else {
        List -> end -> next = node;
        node -> prev = List -> end;
    }

    List -> end = node;
    List -> size++;
}

void list_add (list *List, int value, int index) {
    node *snode = Node_create(value);
    node *aux = List -> begin;

    if (index == 0) {
        List_add_first(List, value);
    }
    if (index == List -> size) {
        list_add_last(List, value);
    }
    else {
        for (int i = 0; i != index; i++) {
            aux = aux -> next; 
        }
        snode -> next = aux;
        aux -> prev -> next = snode;
        snode -> prev = aux -> prev;
        aux -> prev = snode;
    }
    List -> size++;
}


void List_print (list *List) {
    node *node = List -> begin;
    
    printf("L -> ");
    while (node != NULL) {
        printf("%d -> ", node -> val);
        node = node -> next;
    }
    printf("NULL\n");
}

void List_inverted_print (list *List) {
    node *node = List -> end;
    
    printf("L -> ");
    while (node != NULL) {
        printf("%d -> ", node -> val);
        node = node -> prev;
    }
    printf("NULL\n");
}

node *List_search_element(list *List, int value) {
    node *auxNode = List -> begin;
    
    while (auxNode != NULL && auxNode -> val != value) {
        auxNode = auxNode -> next;
    }

    return auxNode;
}

void List_remove(list *List, int value) {
    node *auxNode = List -> begin;

    if (!List_empty(List)){
        if (List_search_element(List, value) != NULL) {
            if (auxNode == List -> begin) {
                if (List -> begin == List -> end) {
                    List -> begin = NULL;
                    List -> end = NULL;
                }
                else {
                    List -> begin = auxNode -> next;
                    List -> begin -> prev = NULL;
                }
            }
            else if (auxNode == List -> end) {
                List -> end -> prev -> next = NULL;
                List -> end = List -> end -> prev;
            
            }

            else {
                auxNode -> prev -> next = auxNode -> next;
                auxNode -> next -> prev = auxNode -> prev;
            }

            List -> size--;
            free(auxNode);
        }
    };
}

int List_first_value(list *List) {
    if (List_empty(List)){
        fprintf(stderr, "ERROR in 'LinkedList_first_val'\n");
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }
    else {
        return List -> begin -> val;
    }
}

int List_last_value(list *List) {
    if (List_empty(List)){
        fprintf(stderr, "ERROR in 'LinkedList_last_val'\n");
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }
    else {
        return List -> end -> val;
    }
}

int List_size(list *List) {
    return List -> size;
}

int List_get_value(list *List, int index) {
    if (index < 0 || index > List -> size) {
        fprintf(stderr, "ERROR in 'LinkedList_get_val'\n");
        fprintf(stderr, "Invalid Index: %d\n", index);
        fprintf(stderr, "Try an index within [0, %d]\n", List->size);
        exit(EXIT_FAILURE);
    }
    else {
        node *auxNode = List -> begin;
        
        for (int i = 0; i < index; i++) {
            auxNode = auxNode -> next;
        }
        
        return auxNode -> val; 
    }
}

void List_delete_all (list *List) {
    node *Pnode = NULL;

    for (int i = 0; i < List -> size; i++) {
        Pnode = List -> begin;
        List -> begin = List -> begin -> next;
        free(Pnode);
    }
}

void List_inverted (list *List) {


}

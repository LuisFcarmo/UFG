#include "list.h"
#include <stdio.h>

int main() {
    linkedlist *list;
    list = LinkedList_create();


    LinkedList_add(list, 1, 1);
   

    LinkedList_add(list, 2, 2);    
    LinkedList_add(list, 3, 3);


    LinkedList_print(list);
    LinkedList_reverse(list);
    LinkedList_print(list);

    return 0;
}
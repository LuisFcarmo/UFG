#include "list.h"
#include <stdio.h>

int main () {
    int aa;
    list *list = List_Create();
    //List_add_first(list,1);
    //List_add_first(list,2);

///    List_add_first(list,3);

    list_add_last(list,1);
    list_add_last(list, 3);
    list_add_last(list,4);
    list_add_last(list,5);
    //aa = List_first_value(list);
    //printf("%d\n", aa);

    List_print(list);
    List_delete_all(list);
    List_print(list);
    return 0;
}
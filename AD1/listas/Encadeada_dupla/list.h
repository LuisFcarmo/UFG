#include <stdbool.h>
#ifndef LIST_H
#define LIST_h

typedef struct _node node;
typedef struct _list list; 

list *List_Create ();
node *Node_create (int value);
bool List_empty (list *List);
void List_add_first (list *List, int value);
void list_add_last (list *List, int value);
void list_add (list *List, int value, int index);
void List_print (list *List);
void List_inverted_print (list *List);
void List_remove (list *List, int value);
node *List_search_element (list *List, int value);
int List_first_value (list *List);
int List_last_value (list *List);
int List_size (list *List);
int List_get_value (list *List, int index);
void List_delete_all (list *List);

#endif
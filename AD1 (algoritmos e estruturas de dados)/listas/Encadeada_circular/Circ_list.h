#ifndef CIRC_LIST_H
#define CIRC_LIST_H

typedef struct _circlist circlist;
typedef struct _node node;

circlist *CircList_create ();
void CircList_destroy(circlist **list_ref);
void V2CircList_destroy(circlist **list_ref);
node *Nodecreate (int value);
void Circnode_destroy (node **node_ref);

#endif
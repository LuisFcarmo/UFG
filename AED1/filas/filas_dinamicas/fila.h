#ifndef FILHA_H
#define FILA_H
#include <stdbool.h>

typedef struct _row row;
typedef struct _node node;

row *Row_create ();
node *Node_create (int value);
void Row_destroy (row *Row);
bool Row_is_empty (const row *Row);
void Row_enqueue (row *Row, int value);
void Row_dequeue (row *Row);
int Row_peek (row *Row);
void Row_print (row *Row);


#endif
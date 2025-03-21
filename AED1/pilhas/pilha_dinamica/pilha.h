#ifndef PILHA_H
#define PILHA_h
#include <stdbool.h>

typedef struct _stack stack;
typedef struct _node node;

stack *Stack_create ();
node *Node_create (int value);
void Stack_destroy (stack *Pstack);
bool Stack_is_empty (stack *Pstack);
void Stack_push (stack *Pstack, int value);
void Stack_pop (stack *Pstack);
int Stack_peek (stack *Pstack);
void Stack_print (stack *Pstack);

#endif
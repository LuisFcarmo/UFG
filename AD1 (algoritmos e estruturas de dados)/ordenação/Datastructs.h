#ifndef _DATASTRUCTS
#define _DATASTRUCTS
#include <stdbool.h>

typedef struct {
    enum E_Type {
        CHAR,
        INT,
        INTEGER,
        FLOAT,
        STRING,
        DOUBLE,
        LONGLONG
    } type;

    union E_Value {
        char valueC;
        float valueF;
        int valueI;
        char *ValueS;
        double ValeuD;
        long long ValueLL;
    } value;
} ELEMENT;

ELEMENT Tscanf(ELEMENT);
//queue functions 
typedef struct _node node;
typedef struct _dnode dnode;

typedef struct _queue Queue;

Queue *New_Queue();
bool Destruct_Queue(Queue **);
node *New_Node(ELEMENT);
bool Enqueue(Queue *, ELEMENT);
void Dequeue (Queue *); // falta arrumar ainda
ELEMENT Queue_peek (Queue *);
bool Queue_is_empty(Queue *);
void Queue_Show(Queue *);

//stack functions

typedef struct _stack Stack;
Stack *New_stack();
bool Destruct_stack();
bool Push(Stack *, ELEMENT);
bool Pop(Stack *, ELEMENT);
ELEMENT Stack_peek(Stack *);
bool Stack_is_empty(Stack *);



#endif
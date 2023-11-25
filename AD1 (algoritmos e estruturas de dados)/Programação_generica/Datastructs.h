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
        double ValueD;
        long long ValueLL;
    } value;
} ELEMENT;

ELEMENT Tscanf(ELEMENT);


//queue functions
typedef struct _node node;

typedef struct _queue Queue;

Queue *New_Queue();
bool Destruct_Queue(Queue **);
node *New_Node(ELEMENT);
bool Enqueue(Queue *, ELEMENT);
void Dequeue (Queue *);
ELEMENT Queue_peek (Queue *);
bool Queue_is_empty(Queue *);
void Queue_show (Queue *);
#endif

//stack functions

typedef struct _Dnode dnode;
typedef struct _stack Stack;

Stack *New_stack();
dnode *New_dnode(ELEMENT);
bool Destruct_stack(Stack **);
bool Stack_is_empty(Stack *);
bool pop(Stack *);
bool push(Stack *, ELEMENT);
void Stack_show(Stack *);
ELEMENT Stack_peek(Stack*);

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

//queue
typedef struct _node node;

typedef struct _queue Queue;

Queue *New_Queue();
bool Destruct_Queue(Queue **);
node *New_Node(ELEMENT);
bool Enqueue(Queue *, ELEMENT);
void Dequeue (Queue *);
ELEMENT Row_peek (Queue *);
bool Queue_is_empty(Queue *);
void printa(Queue *);

#endif
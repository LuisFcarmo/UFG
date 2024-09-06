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

void Tprintf(ELEMENT);
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

//linked list functions

typedef struct _linked_list Linkedlist;

Linkedlist *New_list();
bool Destruct_list(Linkedlist**);
bool List_is_empty(Linkedlist*);
bool Add_first_list(Linkedlist*, ELEMENT);
bool Add_last_list(Linkedlist*, ELEMENT);
bool Add_list(Linkedlist*, ELEMENT, int);
ELEMENT Get_element(Linkedlist*, int);
bool Remove_first(Linkedlist*, ELEMENT);
bool Remove_all(Linkedlist*, ELEMENT);
bool Remove(Linkedlist*, int);
void List_show(Linkedlist*);
#ifndef _FIFO
#define _FIFO
#include <stdlib.h>
#include <stdbool.h>
typedef struct fifo FIFO;
typedef struct node NODE;

FIFO *New_fifo (void);
bool Destroy_fifo (FIFO*);
NODE *New_node (int);
bool Destroy_node (NODE*);
bool Insert_node (FIFO*, NODE*);
bool Delete_node (FIFO*, int);
bool Fix_chaining (FIFO*);
bool Get_top (FIFO*);
bool Show_fifo (FIFO*);
FIFO *Order_fifo (FIFO*, char);




#endif
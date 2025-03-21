#include "fifo.h"
struct fifo {
    int *begin;
    int *end;
    NODE *head;
};

struct  node {
    int val;
    int *next;
};



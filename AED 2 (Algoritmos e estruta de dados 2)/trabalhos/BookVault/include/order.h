#ifndef ORDER
#define ORDER
#include "defines.h"

typedef struct {
    int MaxDays;
    book BorrowedBook;
    bool expired;
    float valueOFfine;
} order;

order CreateOrder(book);

#endif
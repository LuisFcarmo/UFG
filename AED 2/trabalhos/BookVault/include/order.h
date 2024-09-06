#ifndef ORDER
#define ORDER
#include "defines.h"

typedef struct {
    int MaxDays;
    book BorrowedBook;
    bool expired;
    float valueOFfine;
} order;

/**
 * @brief Creates an order for a borrowed book.
 * @param borrowedBook The book that is being borrowed.
 * @return An order structure with the details of the borrowed book.
 */
order CreateOrder(book borrowedBook);

#endif // ORDER

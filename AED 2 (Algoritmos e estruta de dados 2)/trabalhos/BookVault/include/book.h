#ifndef BOOK
#define BOOK
#include "./defines.h"

typedef struct {
    char Name[MaxLenghtName];
    char Author[MaxLenghtName];
    int Amount;
} book;

book CreateBook(char *, char*, int);
bool UpdateBook(book*, char*, char*, int);
book ReadBook(book*);

//getters


#endif
#ifndef STORE
#define STORE
#include "./defines.h"

typedef struct {
    Tree Bookstorage;
    int qtd;
    int id;
} store;

store CreateStorage(int*);
book FindBook(char *, store);
#endif
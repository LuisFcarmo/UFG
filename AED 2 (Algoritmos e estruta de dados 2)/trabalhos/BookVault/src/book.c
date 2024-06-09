#include "../include/defines.h"

book CreateBook(char *name, char* author, int amount) {
    if(name != NULL && author != NULL && amount != 0) {
        book NewBook;
        strcpy(NewBook.Name, name);
        strcpy(NewBook.Author, author);
        NewBook.Amount = amount;
        return NewBook;
    } else {
        node *error = CreateNode(CreateError("Valores nulos ou invalidos foram inseridos nos campos", 2));
        PushError(error, ErrorsStack);
    }
};

bool UpdateBook(book* Reference, char* name, char* author, int amount) {
    if(Reference != NULL && name != NULL && author != NULL && amount != 0) {
        Reference -> Amount = amount;
        strcpy(Reference -> Author, author);
        strcpy(Reference -> Name, name);
    } else {
        node *error = CreateNode(CreateError("Valores nulos ou invalidos foram inseridos nos campos", 2));
        PushError(error, ErrorsStack);
    }
};

book ReadBook(book* reference) {
    if(reference != NULL) {
        printf("nome: %s\n", reference->Name);
        printf("author: %s\n", reference -> Author);
        printf("quantidade: %d\n", reference -> Amount);
    } else {
        node *error = CreateNode(CreateError("Valores nulos ou invalidos foram inseridos nos campos", 2));
        PushError(error, ErrorsStack);
    }
};


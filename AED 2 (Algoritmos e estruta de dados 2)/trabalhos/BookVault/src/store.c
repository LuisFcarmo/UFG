#include "../include/defines.h"

store CreateStorage(int *id) {
    if(id != NULL) {
        store NewStorage;
        NewStorage.id = *id;
        NewStorage.qtd = 0;
        NewStorage.Bookstorage.root = NULL;
        return NewStorage;
    } else {
        node *error = CreateNode(CreateError("O campo id não foi informado", 3));
        PushError(error, ErrorsStack);
        return;
    }
};


book FindBook(char *name, store *Ref) {
    if(name != NULL && Ref != NULL) {
        return Find(Ref -> Bookstorage.root, name);
    } else {
        node *error = CreateNode(CreateError("Algum dos campos informados é nulo", 2));
        PushError(error, ErrorsStack);
        return;
    }
}

order borrowAbook(char* name, int amount, store *ref) {
    if(name != NULL && ref != NULL) {
        book bk = FindBook(name, ref);
        if (strcmp(bk.Name, "") == 0 && strcmp(bk.Author, "") == 0 && bk.Amount == 0) {
            node *error = CreateNode(CreateError("Livro não está presente no nosso acervo", 4));
            PushError(error, ErrorsStack);
            return;
        } else {
            if(bk.Amount > 0) {
                bk.Amount = amount;
                return CreateOrder(bk);
            } else {
                node *error = CreateNode(CreateError("Livro está com unidade zeradas no acervo"), 5);
                PushError(error, ErrorsStack);
            }
        }
    } else {
        node *error = CreateNode(CreateError("Algum dos campos informados é nulo", 2));
        PushError(error, ErrorsStack);
        return;
    }
};

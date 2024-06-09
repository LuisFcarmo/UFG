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
    }
};


book FindBook(char *name, store Ref) {
    return Find(Ref.Bookstorage.root, name);
}
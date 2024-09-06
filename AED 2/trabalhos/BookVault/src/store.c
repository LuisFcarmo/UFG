#include "../include/defines.h"

//object store manager functions

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
}


book FindBook(char *name, store *Ref) {
    if(name != NULL && Ref != NULL) {
        return Find(Ref -> Bookstorage.root, name);
    } else {
        node *error = CreateNode(CreateError("Algum dos campos informados é nulo", 2));
        PushError(error, ErrorsStack);
    }
}

order borrowAbook(char* name, int amount, store *ref) {
    if(name != NULL && ref != NULL) {
        book bk = FindBook(name, ref);
        if (strcmp(bk.Name, "") == 0 && strcmp(bk.Author, "") == 0 && bk.Amount == 0) {
            node *error = CreateNode(CreateError("Livro não está presente no nosso acervo", 4));
            PushError(error, ErrorsStack);
        } else {
            if(bk.Amount > 0) {
                bk.Amount = amount;
                return CreateOrder(bk);
            } else {
                node *error = CreateNode(CreateError("Livro está com unidade zeradas no acervo", 9));
                PushError(error, ErrorsStack);
            }
        }
    } else {
        node *error = CreateNode(CreateError("Algum dos campos informados é nulo", 2));
        PushError(error, ErrorsStack);
    }
};

bool AddToStock(store *ref, book *Newbook) {
    if(ref != NULL && Newbook != NULL) {
        if(MigrationToDatabe(Newbook)) {
            inserir(ref -> Bookstorage.root, *Newbook);
        } else {
            PushError(CreateNode(CreateError("Erro ao fazer a migração dos dados para o banco de dados", 12)), ErrorsStack);
        }
    } else {
        PushError(CreateNode(CreateError("Objetos nulos passados para função", 1)), ErrorsStack);
    }   
};

//Data base manager

bool MigrationToDatabe(book *data) {
    FILE *file = fopen(PATH_BOOK_DATABASE, "a");
    if(file == NULL) {
        PushError(CreateNode(CreateError("Erro a inicializar o banco de dados", 11)), ErrorsStack);
        return true;
    }
    fprintf(file, "%s,%s,%d\n", data -> Name, data -> Author, data -> Amount);
    fclose(file);
    return true;
}

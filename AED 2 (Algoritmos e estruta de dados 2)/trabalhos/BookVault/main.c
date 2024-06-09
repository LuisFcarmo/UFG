#include "../include/defines.h"
// Inicializa a pilha de erros

stack *ErrorsStack = NULL;
int main () {
    ErrorsStack = CreateStack();
    book x1 = CreateBook("luis", "cesar", 1);
    book x2 = CreateBook("gatinha", "", 1);
    book x3 = CreateBook("vadia", "", 2);
    book x4 = CreateBook("teste", "", 2);

    int id = 1;
    store militar = CreateStorage(&id);

        militar.Bookstorage.root = inserir(militar.Bookstorage.root, x1);
        militar.Bookstorage.root = inserir(militar.Bookstorage.root, x2);
        militar.Bookstorage.root = inserir(militar.Bookstorage.root, x3);
        militar.Bookstorage.root = inserir(militar.Bookstorage.root, x4);

    imprimir(militar.Bookstorage.root, 1);
    return 0;
}
#include "../include/defines.h"

order CreateOrder(book bkref) {
    if (strcmp(bkref.Name, "") != 0 && strcmp(bkref.Author, "") != 0 && bkref.Amount != 0) {
        order NewOrder;
        NewOrder.MaxDays = MaxDayBorrow;
        NewOrder.expired = false;
        NewOrder.valueOFfine = ValueOfFine;
        NewOrder.BorrowedBook = bkref;
        return NewOrder;
    } else {
        node *error = CreateNode(CreateError("Livro não está presente no nosso acervo", 4));
        PushError(error, ErrorsStack);
    }
};

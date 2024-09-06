#include "../include/defines.h"

LINKLIST* CREATENEWNODE(order data) {
    LINKLIST* newNode = (LINKLIST*)malloc(sizeof(LINKLIST));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(LINKLIST** head, order data) {
    LINKLIST* newNode = CREATENEWNODE(data);
    newNode->next = *head;
    *head = newNode;
}

void removeByBookName(LINKLIST** head, const char* bookName) {
    LINKLIST* temp = *head;
    LINKLIST* prev = NULL;

    if (temp != NULL && strcmp(temp->data.BorrowedBook.Name, bookName) == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && strcmp(temp->data.BorrowedBook.Name, bookName) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Livro não encontrado.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void printList(LINKLIST* head) {
    LINKLIST* temp = head;
    while (temp != NULL) {
        printf("Livro: %s, Autor: %s, Quantidade: %d\n", temp->data.BorrowedBook.Name, temp->data.BorrowedBook.Author, temp->data.BorrowedBook.Amount);
        printf("Dias Máximos: %d, Expirado: %s, Multa: %.2f\n", temp->data.MaxDays, temp->data.expired ? "Sim" : "Não", temp->data.valueOFfine);
        temp = temp->next;
    }
}

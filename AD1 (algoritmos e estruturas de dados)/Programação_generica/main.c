#include "Datastructs.h"
#include <stdio.h>
int main () {
    ELEMENT elemento;
    elemento.type = INTEGER;
    elemento.value.valueI = 1;
    Queue *lista = New_Queue();
    Enqueue(lista, elemento);
    elemento.value.valueI = 2;
    Enqueue(lista, elemento);
    elemento.value.valueI = 3;
    Enqueue(lista, elemento);
    elemento.value.valueI = 4;
    Enqueue(lista, elemento);
    Dequeue(lista);
    elemento.value.valueI = 5;
    Enqueue(lista, elemento);
    Dequeue(lista);
    elemento.value.valueI = 5;
    Enqueue(lista, elemento);
    Dequeue(lista);

    elemento.value.valueI = 5;
    Enqueue(lista, elemento);
    elemento.value.valueI = 5;
    Enqueue(lista, elemento);
    Dequeue(lista);
    Dequeue(lista);
    Dequeue(lista);
    Dequeue(lista);
  Dequeue(lista);
    Dequeue(lista);
    Destruct_Queue(&lista);

}
#include "Datastructs.h"
#include <stdio.h>
int main () {
    ELEMENT elemento;
    ELEMENT elemento2;
    elemento2.type = FLOAT;
    elemento.type = INTEGER;
    elemento.value.valueI = 1;
    Queue *lista = New_Queue();
    Queue *lista2 = New_Queue();
    //Enqueue(lista, elemento);
    elemento.value.valueI = 2;
    Enqueue(lista, elemento);
    elemento.value.valueI = 3;
    Enqueue(lista, elemento);
    elemento.value.valueI = 4;
    Enqueue(lista, elemento);
    elemento.value.valueI = 5;
    Enqueue(lista, elemento);
    elemento.value.valueI = 5;
    Enqueue(lista, elemento);
    elemento.value.valueI = 5;
    Enqueue(lista, elemento);
    elemento.value.valueI = 5;
    Enqueue(lista, elemento);
    Show(lista);
    elemento2.value.valueF = 1.22;
    Enqueue(lista2, elemento2);
     elemento2.value.valueF = 1.32;
    Enqueue(lista2, elemento2);
     elemento2.value.valueF = 1.42;
    Enqueue(lista2, elemento2);
    Queue_Show
    (lista2);
    Destruct_Queue(&lista);
    
}
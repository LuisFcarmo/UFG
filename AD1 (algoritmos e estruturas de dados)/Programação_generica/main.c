#include "Datastructs.h"
#include <stdio.h>
int main () {
  ELEMENT x;
  ELEMENT y;
  x.type = INTEGER;
  y.type = FLOAT;
  Queue *Queue = New_Queue();
  Stack *Stack = New_stack();

  for (int i = 0; i < 5; i++) {
    x = Tscanf(x);
    Enqueue(Queue, x);
  }
  for (int i = 0; i < 5; i++) {
    y = Tscanf(y);
    push(Stack, y);
  }
  Queue_show(Queue);
  Stack_show(Stack);
  //Stack_show(xf);
}
#include "Datastructs.h"
#include <stdio.h>
int main () {
  ELEMENT x;
  ELEMENT y;
  x.type = INTEGER;
  y.type = FLOAT;
  Linkedlist *list = New_list();
  Linkedlist *flist = New_list();

  for (int i = 0; i < 5; i++) {
    y = Tscanf(y);
    Add_last_list(flist, y);
  }

 
  y = Tscanf(y);
  Remove_all(flist, y);
  List_show(flist);
  Remove_first(flist, y);
  //Remove_first(flist, y);
  /*List_show(flist);
  Remove_first(flist, y);
  List_show(flist);
  Remove_first(flist, y);
  List_show(flist);
  Remove_first(flist, y);
  List_show(flist);
  Remove_first(flist, y);
  List_show(flist);
  */
  //Stack_show(xf);
}
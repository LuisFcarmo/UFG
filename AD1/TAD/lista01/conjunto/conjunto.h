#ifndef _data_h
#define _data_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct conjunto *Conjunto;
Conjunto Create_and_fill_conjunction ();
Conjunto New_Conjunction (int);
int Insert_Element(int, Conjunto);
bool Conjunction_is_Empty (Conjunto);
bool Element_is_Conjuction (int, Conjunto);
int Display_Conjuction (Conjunto, char);
int Delete_Element (int, Conjunto);
int Cardinality (Conjunto);
int Bigger_than_Element (Conjunto, int);
int Lower_tham_Element (Conjunto, int);
int Position_in_Conjunction (int, Conjunto);
bool Belongs_in_Conjunction (Conjunto, Conjunto);
bool Twins_Conjunction (Conjunto, Conjunto);
Conjunto Union (Conjunto, Conjunto);
Conjunto intersection (Conjunto, Conjunto);
int Equal_Elements (Conjunto, Conjunto);
Conjunto New_Complement (Conjunto, Conjunto);
Conjunto Difference (Conjunto, Conjunto);
//falta essa ainda 
Conjunto Set_Of_Parts (Conjunto);
void Grow_Order (Conjunto);
void Descending_order(Conjunto);
Conjunto Copy_Conjunction (Conjunto, Conjunto);
int Destruct_Cojunction (Conjunto);

#endif
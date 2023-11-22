#ifndef _COMPLEX
#define _COMPLEX
#include <stdlib.h>
#include <stdbool.h>

typedef struct header HEADER;
typedef struct complex COMPLEX;
HEADER *New_Complex_set (int qtd);
COMPLEX *New_Complex (int imaginary, int real);
bool Set_is_Empty (HEADER *head);
int Cardinality (HEADER *head);
bool Insert_Element (COMPLEX *x , HEADER *head);
bool Delete_Element (COMPLEX *x,  HEADER *head);
bool Element_in_set (HEADER *head, COMPLEX *x);
bool Twins_Set (HEADER *head1, HEADER *head2);
bool Subset_in_Set (HEADER *head1, HEADER *head2);
HEADER *New_Complement (HEADER *head1, HEADER *head2);
void print_set (HEADER *heade);
HEADER *Set_Union (HEADER *head1, HEADER *head2);
HEADER *Set_Intersec (HEADER *head1, HEADER *head2);
HEADER *Create_and_fill_set(int qtd);
HEADER *Set_Diference (HEADER *head1, HEADER *head2);
bool Delete_set (HEADER **head);

#endif
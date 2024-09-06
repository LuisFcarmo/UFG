#ifndef _data 
#define _data
#include "stdbool.h"
#include <stdio.h>

typedef struct texto String;
String *New_Text(char *);
String *New_Empty_text();
void Destruct_Text(String **);
int Size_text(char *);
char *Get_Text(String *);
String *Scanf_Text ();
void Show_Text (String *, int );
void Replace_Text (String *, char *);
bool Compare_Text (String *, String *);
char *Get_SubText (String *, int, int);
String * Concatenate_Text (String *, String *);
int Shearching_SubText (String *, String *);

#endif


#ifndef DEFINE
#define DEFINE
//defines used in project
#define MaxLenghtName 50
#define MaxLenghtUserName 30
#define MaxPasswordLenght 20

//include whit bible in the project
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//.h made whit me
#include "./error.h"
#include "./book.h"
#include "./AvlBooks.h"
#include "./user.h"
#include "./session.h"
#include "./store.h"

//erros 
extern stack *ErrorsStack;
extern session ActualUser;

//paths

const char CSS_PATH[] = "../view/Styles/BookVault.css";
const char PATH_BOOKVAULT_GLADE[] = "../view/BookVault.glade";

#endif
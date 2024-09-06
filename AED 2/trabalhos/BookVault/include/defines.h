#ifndef DEFINE
#define DEFINE
//defines used in project
#define MaxLenghtName 50
#define MaxLenghtUserName 30
#define MaxPasswordLenght 20
#define MaxDayBorrow 7
#define ValueOfFine 3.50
#define MaxAuthorLenghname 20
#define MaxLenghtComandLine 100

//include whit bible in the project
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

//.h made whit me
#include "./BookVault.h"
#include "./error.h"
#include "AvlUser.h"
#include "./user.h"
#include "./DataBaseManager.h"
#include "./book.h"
#include "./AvlBooks.h"
#include "./session.h"
#include "./order.h"
#include "./LinkedList.h"
#include "./store.h"


//erros 
extern stack *ErrorsStack;
extern session *cr;

//paths
const char CSS_PATH[] = "../view/Styles/BookVault.css";
const char PATH_BOOKVAULT_GLADE[] = "../view/BookVault.glade";

//paths to database
const char PATH_USER_CSV[] = "../Data/Users/user.csv";
const char PATH_BOOK_DATABASE[] = "../Data/BookDB/Books.csv";
const char PATH_TO_SESSION_DATABASE[] = "../Data/Session/session.csv";
const char PATH_TO_ORDERS_SYSTEM[] = "../Orders/";

#endif
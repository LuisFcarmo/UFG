#ifndef USER
#define USER
#include "./defines.h"

typedef struct  {
    char name[MaxLenghtUserName];
    char password[MaxPasswordLenght];
    int id;
} user;

user CreateUser(char*, char*, int*);
void RegisterUser(user);

#endif
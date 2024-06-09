#ifndef SESSION
#define SESSION
#include "defines.h"

typedef struct {
    user CurrentUser;
} session;

session CreateSession(user);
char *GetName(session);
int GetId(session);

#endif
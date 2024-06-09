#include "../include/defines.h"

session CreateSession(user ref) {
    session NewSession;
    NewSession.CurrentUser = ref;
};

char *GetName(session ref) {
    return ref.CurrentUser.name;
}; 

int GetId(session ref) {
    return ref.CurrentUser.id;
};

#include "../include/defines.h"


session *CreateSessionEmpty () {
    session *NewSession = (session*) malloc(sizeof(session)*1);
    time_t now;
    time(&now);
    NewSession -> Expired = localtime(&now);
    
    return NewSession;
}

int compare_dates(int t1, int t2) {
    if (t1 < t2) {
        return -1;
    } else if (t1 > t2) {
        return 1;
    } else {
        return 0;
    }
}

session *CreateSession(user ref) {
    session *NewSession = (session*) malloc(sizeof(session)*1);
    if(NewSession == NULL) {
        PushError(CreateNode(CreateError("Erro de alocação de memorial", 1)), ErrorsStack);
        return NULL;
    }

    time_t now;
    time(&now);

    NewSession -> Expired = localtime(&now);
    NewSession -> Expired -> tm_mday += 16;
    mktime(NewSession -> Expired);

    NewSession -> CurrentUser = ref;
    FILE *SessionFolder = AcessDataBase(PATH_TO_SESSION_DATABASE, "w");
    fprintf(SessionFolder, "%s,%s,%d,%d,%d,%d", ref.name, ref.password, ref.id, NewSession->Expired->tm_mday, NewSession->Expired->tm_mon, NewSession->Expired->tm_year);
    CloseDataBase(SessionFolder);
    return NewSession;
}

bool ExpiredSession (session x) {
    time_t now = time(NULL);
    if(compare_dates(x.Expired, now)  == 0) {
       FILE *SessionFolder = AcessDataBase(PATH_TO_SESSION_DATABASE, "w");
       CloseDataBase(SessionFolder);
       return true;
    }   
    return false;
}

char *GetName(session *ref) {
    return ref -> CurrentUser.name;
}

int GetId(session *ref) {
    return ref -> CurrentUser.id;
}

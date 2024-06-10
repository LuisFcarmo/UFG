#include "../include/defines.h"

user CreateUser(char* name, char* password, int *id) {
    if(id != NULL && name != NULL && password != NULL) {
      user NewUser;
      NewUser.id = *id;
      strcpy(NewUser.name, name);
      strcpy(NewUser.password, password);
    } else {
        node *error = CreateNode(CreateError("O campo id não foi informado", 3));
        PushError(error, ErrorsStack);
    }
};

void RegisterUser(user UserRef) {
    FILE *arq;
    arq = fopen(PATH_USER_CSV, "a");
    if(arq == NULL) {
        node *error = CreateNode(CreateError("falha ao abrir o arquivo", 6));
        PushError(error, ErrorsStack);
        return;
    }

    fclose(arq);
};

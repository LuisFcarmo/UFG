#include "../include/defines.h"

FILE *AcessDataBase(const char* path , const char *method) {
    FILE *file = fopen(path, method);
    if(file == NULL) {
        PushError(CreateNode(CreateError("Erro ao acessar os dados do banco", 13)),ErrorsStack);
        return NULL;
    } 
    return file;
}

FILE *CloseDataBase(FILE *db) {
    if (db == NULL) {
        PushError(CreateNode(CreateError("Referencia a banco nula", 14)),ErrorsStack);
        return NULL;
    } 
    fclose(db);
    return NULL;
}

#include "../include/defines.h"

AVLNode *root = NULL;

user CreateUser(char *name, char *password, int id) {
    if(id != 0) {
      user NewUser;
      NewUser.id = id;
      strcpy(NewUser.name, name);
      strcpy(NewUser.password, password);
      return NewUser;
    } else {
        node *error = CreateNode(CreateError("O campo id não foi informado", 3));
        PushError(error, ErrorsStack);
    }
};

AVLNode *LoadUsers() {
    user ref;
    FILE *arq;
    char name[MaxLenghtName];
    char password[MaxPasswordLenght];
    int id;

    arq = fopen(PATH_USER_CSV, "r");

    if (arq == NULL) {
        node *error = CreateNode(CreateError("Erro ao abrir o arquivo", 3));
        PushError(error, ErrorsStack);
        exit(1);
    }

    while (fscanf(arq, "%[^,],%[^,],%d%*c", name, password, &id) != EOF) {
        user ref = CreateUser(name, password, id); // Supondo que CreateUser é uma função que inicializa a estrutura user        
        root = insert(root, ref);
    }
    fclose(arq);
    return root;
}

bool IsPresent(user refUS) {
    return search(root, refUS.name);
}

bool Validations(user ref) {
    if(IsPresent(ref)) {
        node* error = CreateNode(CreateError("Usuario já está presente no banco de dados", 8));
        return false;
    }
    return true;
}

void initDB() {
    root = LoadUsers();
};


void RegisterUser(user UserRef) {
    initDB(); // Supondo que esta função inicializa o banco de dados ou faz outras configurações necessárias

    if (Validations(UserRef)) { // Supondo que esta função valida o usuário de alguma forma
        FILE *arq;
        arq = fopen(PATH_USER_CSV, "a"); // Abre o arquivo em modo de adição

        if (arq == NULL) {
            node *error = CreateNode(CreateError("falha ao abrir o arquivo", 6));
            PushError(error, ErrorsStack);
            return;
        }

        // Escreve os dados do usuário no arquivo CSV
        fprintf(arq, "%s,%s,%d\n", UserRef.name, UserRef.password, UserRef.id);
        fclose(arq);
    } else {
        node *error = CreateNode(CreateError("falha ao registrar o usuario", 11));
        PushError(error, ErrorsStack);
        return;
    }
}

bool LoginValidations(user UserRef) {
    if(IsPresent(UserRef)) {
        if(strcmp(searchUser(root, UserRef.name)->password, UserRef.password) == 0) {
            return true;
        } else {
            return false;
        };
    } else {
        return false;
    }
}

void LoginUser(user UserRef){
    initDB();
    if(LoginValidations(UserRef)) {
        printf("usuario logado com sucesso %s\n", UserRef.name);
        cr = CreateSession(UserRef);
    } else {
        node *error = CreateNode(CreateError("Nome ou Senha incorreta", 11));
        PushError(error, ErrorsStack);
        return;
    }
} 

#include "../include/defines.h"

error CreateError(char *msg, int code) {
    error NewError;
    NewError.code = code;
    strcpy(NewError.msg, msg);
    return NewError;
}

node *CreateNode(error erro) {
    node* NewNode = (node*) malloc(sizeof(node)*1);
    NewNode -> erro = erro;
    NewNode -> prev = NULL;
    return NewNode;
}

stack *CreateStack() {
    stack *NewStack = (stack*) malloc(sizeof(stack)*1);
    NewStack -> size = 0;
    NewStack -> top = NULL;
    return NewStack;
}

bool PushError(node *NodeError, stack* ErrorStack) {
    if(NodeError != NULL) {
        node *aux = NULL;
        if(ErrorStack->size == 0) {
            ErrorStack -> top = NodeError;
            ErrorStack -> size++;
        } else {
            NodeError -> prev = ErrorStack -> top -> prev;
            ErrorStack -> top -> prev = NodeError;
            ErrorStack -> size++;
        }
    } else {
        printf("nenhum erro foi enviado");
        return false;
    }
}

void ShowErros(stack* ErrorStack) {
    node *aux = ErrorStack -> top;
    while(aux != NULL) {
        printf("%s", aux -> erro.msg);
        aux = aux -> prev;
    }
};

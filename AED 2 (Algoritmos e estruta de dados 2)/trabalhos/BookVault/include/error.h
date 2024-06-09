#ifndef ERROR
#define ERROR

typedef struct {
    int code;
    char msg[70];
} error;

typedef struct _node {
    error erro;
    struct _node *prev; 
} node;


typedef struct {
    node *top;
    int size;
} stack;

error CreateError(char *, int); 
node *CreateNode(error);
stack *CreateStack();
bool PushError(node *, stack*);
void ShowErros(stack*);

#endif
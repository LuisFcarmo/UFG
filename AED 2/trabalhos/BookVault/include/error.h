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

/**
 * @brief Creates an error structure with the given message and code.
 * @param message The error message.
 * @param code The error code.
 * @return An error structure with the provided message and code.
 */
error CreateError(char *message, int code); 

/**
 * @brief Creates a node containing the given error.
 * @param erro The error to be contained in the node.
 * @return A pointer to the created node.
 */
node *CreateNode(error erro);

/**
 * @brief Creates an empty stack.
 * @return A pointer to the created stack.
 */
stack *CreateStack();

/**
 * @brief Pushes an error node onto the stack.
 * @param erroNode The error node to be pushed.
 * @param errorStack The stack to which the error node is to be pushed.
 * @return True if the error node was successfully pushed, false otherwise.
 */
bool PushError(node *erroNode, stack *errorStack);

/**
 * @brief Displays the errors in the stack.
 * @param errorStack The stack whose errors are to be displayed.
 */
void ShowErros(stack *errorStack);

#endif // ERROR

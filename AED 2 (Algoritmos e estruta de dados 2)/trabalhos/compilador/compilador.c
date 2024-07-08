#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define QtdReservadas 179
#define MaxComandWordLenght 200

typedef struct no {
    char data[MaxComandWordLenght];
    struct no *direita, *esquerda;
    int altura;
} NoArv;

typedef struct {
    NoArv *root;
} Tree;

typedef struct {
    bool direita;
    bool esquerda;
    int qtd;
} Resp;

NoArv * Cria_No(char *x) {
    NoArv * new = (NoArv *) malloc(sizeof(NoArv));
    strcpy(new->data, x);
    new->esquerda = NULL;
    new->direita = NULL;
    new->altura = 0;
    return new;
}

Resp Criar_Resp(int qtd, bool direta, bool esquerda) {
    Resp x;
    x.qtd = qtd;
    x.direita = direta;
    x.esquerda = esquerda;
    return x;
}

int maior(int a, int b) {
    return (a > b) ? a : b;
}

int AlturaDoNo(NoArv * no) {
    return (no == NULL) ? -1 : no->altura;
}

int FatorDeBalanceamento(NoArv * no) {
    if (no) {
        return (AlturaDoNo(no->esquerda) - AlturaDoNo(no->direita));
    } else {
        return 0;
    }
}

int altura(NoArv * root) {
    if (root == NULL)
        return -1;
    else {
        int esquerda = altura(root->esquerda);
        int direita = altura(root->direita);
        if (esquerda > direita) {
            return esquerda + 1;
        } else {
            return direita + 1;
        }
    }
}

NoArv * RotacaoDireita(NoArv * NoDesbalanceado) {
    NoArv * y, * filho;
    y = NoDesbalanceado->esquerda;
    filho = y->direita;

    y->direita = NoDesbalanceado;
    NoDesbalanceado->esquerda = filho;

    NoDesbalanceado->altura = maior(AlturaDoNo(NoDesbalanceado->esquerda), AlturaDoNo(NoDesbalanceado->direita)) + 1;
    y->altura = maior(AlturaDoNo(y->esquerda), AlturaDoNo(y->direita)) + 1;

    return y;
}

NoArv * RotacaoEsquerda(NoArv * NoDesbalanceado) {
    NoArv * y, * filho;
    y = NoDesbalanceado->direita;
    filho = y->esquerda;

    y->esquerda = NoDesbalanceado;
    NoDesbalanceado->direita = filho;

    NoDesbalanceado->altura = maior(AlturaDoNo(NoDesbalanceado->esquerda), AlturaDoNo(NoDesbalanceado->direita)) + 1;
    y->altura = maior(AlturaDoNo(y->esquerda), AlturaDoNo(y->direita)) + 1;

    return y;
}

NoArv * RotacaoDireitaEsquerda(NoArv * NoDesbalanceado) {
    NoDesbalanceado->direita = RotacaoDireita(NoDesbalanceado->direita);
    return RotacaoEsquerda(NoDesbalanceado);
}

NoArv * RotacaoEsquerdaDireita(NoArv * NoDesbalanceado) {
    NoDesbalanceado->esquerda = RotacaoEsquerda(NoDesbalanceado->esquerda);
    return RotacaoDireita(NoDesbalanceado);
}

NoArv * balancear(NoArv * raiz) {
    short fb = FatorDeBalanceamento(raiz);
    if (fb < -1 && FatorDeBalanceamento(raiz->direita) <= 0) {
        raiz = RotacaoEsquerda(raiz);
    } else if (fb > 1 && FatorDeBalanceamento(raiz->esquerda) >= 0) {
        raiz = RotacaoDireita(raiz);
    } else if (fb > 1 && FatorDeBalanceamento(raiz->esquerda) < 0) {
        raiz = RotacaoEsquerdaDireita(raiz);
    } else if (fb < -1 && FatorDeBalanceamento(raiz->direita) > 0) {
        raiz = RotacaoDireitaEsquerda(raiz);
    }
    return raiz;
}

NoArv *inserir(NoArv *raiz, char *x) {
    if (raiz == NULL) {
        return Cria_No(x);
    } else {
        // Comparação dos títulos para inserir em ordem alfabética
        int comparacao = strcmp(x, raiz -> data);
        if (comparacao < 0) {
            raiz->esquerda = inserir(raiz->esquerda, x);
        } else if (comparacao > 0) {
            raiz->direita = inserir(raiz->direita, x);
        } else {
            return raiz; // Retorna a raiz sem fazer alterações
        }
    }

    raiz->altura = maior(AlturaDoNo(raiz->esquerda), AlturaDoNo(raiz->direita)) + 1;

    // Verifica se a árvore precisa de balanceamento
    int fb = FatorDeBalanceamento(raiz);
    if (fb > 1 || fb < -1) {
        raiz = balancear(raiz);
    }

    return raiz;
}

void imprimir(NoArv * raiz, int nivel) {
    if (raiz) {
        imprimir(raiz->direita, nivel + 1);
        printf("\n\n");
        for (int i = 0; i < nivel; i++) {
            printf("\t");
        }
        printf("comando:%s\n", raiz->data);
        imprimir(raiz->esquerda, nivel + 1);
    }
}

Resp Qtd_Filhos(NoArv * root, char *chave) {
    if (root != NULL) {
        Resp x;
        if (strcmp(root->data, chave)) {
            if (root->direita != NULL && root->esquerda != NULL) {
                x = Criar_Resp(2, true, true);
            } else if (root->direita == NULL && root->esquerda != NULL) {
                x = Criar_Resp(1, false, true);
            } else if (root->direita != NULL && root->esquerda == NULL) {
                x = Criar_Resp(1, true, false);
            } else {
                x = Criar_Resp(0, false, false);
            }

            return x;
        } else {
            int comparacao = strcmp(chave, root->data);
            if (comparacao > 0) {
                return Qtd_Filhos(root->direita, chave);
            } else {
                return Qtd_Filhos(root->esquerda, chave);
            }
        }
    } else {
        printf("Nó não está presente na árvore\n");
        Resp x = Criar_Resp(0, false, false);
        return x;
    }
}

NoArv * Remover(NoArv * root, char *chave) {
    if (root != NULL) {
        if (strcmp(root->data, chave) == 0) {
            // aqui apenas removemos nós folhas
            if (root->esquerda == NULL && root->direita == NULL) {
                free(root);
                return NULL; // retorna nulo pras chamadas recursivas coloca nulo no ponteiro que apontava para este nó folha
            } else {
                Resp x = Qtd_Filhos(root, chave);
                NoArv * aux = NULL;
                if (x.qtd == 1) {
                    if (x.direita) {
                        aux = root->direita;
                    } else {
                        aux = root->esquerda;
                    }
                    free(root);
                    return aux;
                } else {
                    NoArv * aux = root->esquerda;
                    while (aux->direita != NULL)
                        aux = aux->direita;
                    strcpy(root->data, aux->data);
                    strcpy(aux->data, chave);
                    root->esquerda = Remover(root->esquerda, chave);
                    return root;
                }
            }
        } else {
            int comparacao = strcmp(chave, root->data);
            if (comparacao < 0) {
                root->esquerda = Remover(root->esquerda, chave);
            } else {
                root->direita = Remover(root->direita, chave);
            }
            root->altura = maior(AlturaDoNo(root->esquerda), AlturaDoNo(root->direita)) + 1;

            root = balancear(root);
            return root;
        }
    } else {
        printf("Nó não está na árvore\n");
        return NULL;
    }
}

bool Find(NoArv *root, char *chave) {
    if (root == NULL) {
        return false;
    }
    int comparacao = strcmp(root->data, chave);
    if (comparacao == 0) {
        return true;
    } else if (comparacao > 0) {
        return Find(root->esquerda, chave);
    } else {
        return Find(root->direita, chave);
    }
}

void LiberarMemoria(NoArv *raiz) {
    if (raiz != NULL) {
        LiberarMemoria(raiz->esquerda);  // Libera a subárvore esquerda
        LiberarMemoria(raiz->direita);   // Libera a subárvore direita
        free(raiz);                      // Libera o nó atual
    }
}
char* PalavrasReservadas[] = {
    "auto", "break", "case", "char", "const",
    "continue", "default", "do", "double", "else",
    "enum", "extern", "float", "for", "goto", "if",
    "inline", "int", "long", "register", "restrict",
    "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned",
    "void", "volatile", "while", "_Alignas", "_Alignof",
    "_Atomic", "_Bool", "_Complex", "_Generic", "_Imaginary",
    "_Noreturn", "_Static_assert", "_Thread_local",
    "#include", "#define", "#undef", "#if", "#ifdef", "#ifndef",
    "#else", "#elif", "#endif", "#error", "#pragma", "main",
    "printf", "scanf", "fprintf", "fscanf", "sprintf", "sscanf",
    "snprintf", "vprintf", "vfprintf", "vsprintf", "vsnprintf",
    "putc", "getc", "getchar", "putchar", "fgets", "fputs", "rewind",
    "fopen", "fclose", "feof", "ferror", "clearerr", "remove", "rename",
    "tmpfile", "tmpnam", "setbuf", "setvbuf", "fprintf", "fscanf", "fflush",
    "fseek", "ftell", "rewind", "fgetpos", "fsetpos", "perror", "fileno",
    "malloc", "calloc", "realloc", "free", "exit", "atexit", "system",
    "abort", "atexit", "getenv", "system", "clock", "difftime", "time",
    "asctime", "ctime", "gmtime", "localtime", "mktime", "strftime",
    "signal", "raise", "sig_atomic_t", "SIG_DFL", "SIG_ERR", "SIG_IGN",
    "rand", "srand", "rand_r", "abort", "system", "bsearch", "qsort",
    "abs", "labs", "llabs", "div", "ldiv", "lldiv", "atoi", "atol", "atof",
    "strtod", "strtof", "strtold", "strtol", "strtoul", "strtoll", "strtoull",
    "itoa", "ltoa", "lltoa", "utoa", "ultoa", "ulltoa", "getchar", "putchar",
    "gets", "puts", "fgets", "fputs", "scanf", "sscanf", "sprintf", "snprintf",
    "vsprintf", "vsnprintf", "memcpy", "memmove", "memcmp", "memset",
    "strcpy", "strncpy", "strcat", "strncat", "strcmp", "strncmp",
    "strcoll", "strxfrm", "strchr", "strrchr", "strspn", "strcspn",
    "strpbrk", "strstr", "strtok", "strtok_r", "strlen", "strerror",
    "memset", "memcpy", "memmove", "memcmp", "memchr",
    "isalnum", "isalpha", "iscntrl", "isdigit", "isgraph", "islower",
    "isprint", "ispunct", "isspace", "isupper", "isxdigit", "tolower",
    "toupper", "isblank", "isascii", "toascii",
    "log", "log10", "exp", "sqrt", "fabs", "floor", "ceil", "pow", "fmod", "round", "trunc",
    "acos", "asin", "atan", "atan2", "cos", "sin", "tan", "cosh", "sinh", "tanh", "acosh", "asinh", "atanh",
    "errno", "math_errhandling", "INFINITY", "NAN", "HUGE_VAL", "HUGE_VALF", "HUGE_VALL", "M_E", "M_LOG2E", "M_LOG10E",
    "M_LN2", "M_LN10", "M_PI", "M_PI_2", "M_PI_4", "M_1_PI", "M_2_PI", "M_2_SQRTPI", "M_SQRT2", "M_SQRT1_2"
};

char TempWord[MaxComandWordLenght];

typedef struct StackNode {
    char data;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
    int size;
} Stack;

Stack stack_parenteses_abrir;
Stack stack_parenteses_fechar;
Stack stack_chaves_abrir;
Stack stack_chaves_fechar;
Stack stack_Colchetes_abrir;
Stack stack_Colchetes_fechar;
Stack stack_aspasduplas;
Stack stack_aspas_simples;
Tree verificadora;

StackNode* createNode(char data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (!newNode) {
        fprintf(stderr, "Memória insuficiente\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void initStack(Stack* s) {
    s->top = NULL;
    s->size = 0;
}

int isStackEmpty(Stack* s) {
    return s->top == NULL;
}

void push(Stack* s, char data) {
    StackNode* newNode = createNode(data);
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
}

char pop(Stack* s) {
    if (isStackEmpty(s)) {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    StackNode* temp = s->top;
    char poppedData = temp->data;
    s->top = s->top->next;
    free(temp);
    s->size--;
    return poppedData;
}

char peek(Stack* s) {
    if (isStackEmpty(s)) {
        fprintf(stderr, "A pilha está vazia\n");
        exit(EXIT_FAILURE);
    }
    return s->top->data;
}

int verifyBlocks(const char* code) {
    Stack stack;
    initStack(&stack);
    for (int i = 0; code[i] != '\0'; ++i) {
        char ch = code[i];
        if(ch == '{') {
            push(&stack_chaves_abrir, ch);
        } 
        else if (ch == '(') {
            push(&stack_parenteses_abrir, ch);
        }
        else if (ch == '['){
            push(&stack_Colchetes_abrir, ch);
        }
        else if(ch == '}') {
            push(&stack_chaves_fechar, ch);
        } 
        else if (ch == ')') {
            push(&stack_parenteses_fechar, ch);
        }
        else if (ch == ']'){
            push(&stack_Colchetes_fechar, ch);
        }
        else if (ch == '"') {
            push(&stack_aspasduplas, ch);
        }
        else if (ch == '\'') {
            push(&stack_aspas_simples, ch);
        }
    }

  while (stack_chaves_abrir.size > 0 && stack_chaves_fechar.size > 0) {
    pop(&stack_chaves_abrir);
    pop(&stack_chaves_fechar);
  }
  while (stack_Colchetes_abrir.size > 0 && stack_Colchetes_fechar.size > 0) {
    pop(&stack_Colchetes_abrir);
    pop(&stack_Colchetes_fechar);
  }
  while (stack_parenteses_abrir.size > 0 && stack_parenteses_fechar.size > 0) {
    pop(&stack_parenteses_abrir);
    pop(&stack_parenteses_fechar);
  }
}

// Função para ler o conteúdo de um arquivo
char* readFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Não foi possível abrir o arquivo %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* content = (char*)malloc(fileSize + 1);
    if (!content) {
        fprintf(stderr, "Memória insuficiente\n");
        exit(EXIT_FAILURE);
    }

    fread(content, 1, fileSize, file);
    content[fileSize] = '\0';

    fclose(file);
    return content;
}
void print_irregular_blocks () {
    if (stack_chaves_abrir.size > 0) {
        printf("o codigo apresenta irregularidades ao fechar }\n");
    }
    else if (stack_chaves_fechar.size > 0) {
        printf("o codigo apresenta irregularidades ao abrir {\n");

    }
    if (stack_Colchetes_abrir.size > 0) {
        printf("o codigo apresenta irregularidades ao fechar ]\n");
    }
    else if (stack_Colchetes_fechar.size > 0) {
        printf("o codigo apresenta irregularidades ao abrir [\n");
    }
    if (stack_parenteses_abrir.size > 0) {
        printf("o codigo apresenta irregularidades ao fechar )\n");
    }
    else if (stack_parenteses_fechar.size > 0) {
        printf("o codigo apresenta irregularidades ao abrir (\n");
    }    
    if (stack_aspasduplas.size % 2 != 0) {
        printf("o codigo apresetna irregularidades ao fechar \" \n");
    }
    if (stack_aspas_simples.size % 2 != 0) {
        printf("o codigo apresenta irregularidades ao fechar '' \n");
    }
}

void povoar_arvore_verificadora() {
  for (int i = 0; i < QtdReservadas; i++) {
        verificadora.root = inserir(verificadora.root, PalavrasReservadas[i]);
    }
};

void LimparWord() {
    for (int i = 0; i < MaxComandWordLenght; i++) {
        TempWord[i] = '\0';
    }
}

bool SimilarWord(char *word) {
    float contador = 0;
    float porcentagem = 0;
    for (int i = 0; i < QtdReservadas; i++) {
        if (strlen(word)  <= strlen(PalavrasReservadas[i])){
            for (int k = 0; k < strlen(word); k++) {
                for (int p = 0; p < strlen(PalavrasReservadas[i]); p++) {
                    if (word[k] == PalavrasReservadas[i][p]) {
                        contador++;
                    }
                }
            }
            porcentagem = contador/strlen(PalavrasReservadas[i])*100;
            if (porcentagem >= 60) {
                return true;
            }
            contador = 0;
        }
    }
    return false;
}

bool verificar_palavras_reservadas(char *code) {
    int AuxIndex = 0;
    LimparWord();
    ///  ainda faltar buscar um algoritmo melhor para decidir se devo ou não buscar tal palavra
    for (int i = 0; code[i] != '\0'; ++i) {
        if (
            (code[i] >= 'a' && code[i] <= 'z') || (code[i] >= 'A' && code[i] <= 'Z') || code[i] == '#' || '\0'
            ||( code[i] == '<' || code[i] == '>' || code[i] == '.')
            ) {
            TempWord[AuxIndex] = code[i];
            AuxIndex++;
        } else {
            if(strlen(TempWord) > 0) {
                if(SimilarWord(TempWord)){
                    if(!Find(verificadora.root, TempWord)) {
                        printf("palavra reserva apresenta sintaxe incorreta = %s\n", TempWord);

                    } 
                }
                LimparWord();
                AuxIndex = 0;
            }
        }
    }
}


int main() {
    initStack(&stack_parenteses_abrir);
    initStack(&stack_parenteses_fechar);
    initStack(&stack_chaves_abrir);
    initStack(&stack_chaves_fechar);
    initStack(&stack_Colchetes_abrir);
    initStack(&stack_Colchetes_fechar);
    initStack(&stack_aspasduplas);
    initStack(&stack_aspas_simples);


    char *content = readFile("./codigoteste.c");
    verifyBlocks(content);
    print_irregular_blocks();
    povoar_arvore_verificadora();
    printf("%s", verificadora.root->data);
    verificar_palavras_reservadas(content);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *direita, *esquerda, *pai;
    int altura;
} NoArv;

typedef struct {
    NoArv *root;
} Tree;
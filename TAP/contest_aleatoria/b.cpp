#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <limits>
using namespace std;
typedef struct _node no;

struct _node {
    no *prox;
    char value;
};

no *criar_node(char value) {
    no *novo = (no*) malloc(sizeof(no)*1);
    novo -> prox = NULL;
    novo -> value = value;
    return novo;
};

void ir_ao_ultimo_no(no **anterior, no **ultimo) {
    if ((*ultimo) -> prox == NULL) return;
    else {
        *anterior = *ultimo;
        *ultimo = (*ultimo) -> prox;
        ir_ao_ultimo_no(anterior, ultimo);
    }
}

void push (no **Stack, char value) {
    no *new_node = criar_node(value);
    if (*Stack == NULL) {
        *Stack = new_node;
    } else {
        no *final = *Stack;
        no *anterior = NULL;
        ir_ao_ultimo_no(&anterior, &final);
        final -> prox = new_node;
    }
}


void pop (no **Stack) {
    if (*Stack == NULL) {
        printf("Empty\n");
    } else {
        no *final = *Stack;
        if (final -> prox == NULL) {
            printf("%c", final -> value);
            free(final);
            *Stack = NULL;
            return;
        } else {
            no *anterior = NULL;
            ir_ao_ultimo_no(&anterior, &final); 
            printf("%c", final -> value);
            free(final);
            anterior -> prox = NULL;
        }
    }

}

int main () {
    no *stack = NULL;
    char frase[1001];
    int qtd;
    scanf("%d%*c", &qtd);
    while (qtd--) {
        scanf("%[^\n]%*c", frase);
        for (int i = 0; i < strlen(frase); i++) {
            push(&stack, frase[i]);
        }
        for (int i = 0; i < strlen(frase); i++) {
           pop(&stack);
        }
        printf("\n");
    }
    

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits>
using namespace std;
typedef struct _node no;

struct _node {
    no *prox;
    int value;
};

no *criar_node(int value) {
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

void push (no **Stack, int value) {
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
        no *anterior = NULL;
        ir_ao_ultimo_no(&anterior, &final); 
        printf("%d", final -> value);
        printf("\n");

        if (anterior == NULL) {
            free(final);
            *Stack = NULL;
            return;
        }
        free(final);
        anterior -> prox = NULL;
    }

}

int main () {
    string comando;
    int qtd;
    int numero;
    no *Stack = NULL;
    cin >> qtd;
    while (qtd--)
    {   
        std::cin.clear();
        cin >> comando;
        if (comando.compare("pop") != 0) {
            cin >> numero;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (comando.compare("push") == 0) {
            push(&Stack, numero);
        }
        if (comando.compare("pop") == 0) {
            pop(&Stack);
        }
    }


    return 0;
}
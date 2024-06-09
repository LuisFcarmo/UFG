#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define max 1000000

typedef struct NO node;

struct NO {
    float valor;
    node *ant;
};

typedef struct {
    node *topo;
    int size;
} descritor;

node *criar_node(float valor) {
    node *new = (node *)malloc(sizeof(node) * 1);
    new->ant = NULL;
    new->valor = valor;
    return new;
}

descritor *criar_pilha() {
    descritor *new = (descritor *)malloc(sizeof(descritor) * 1);
    new->topo = NULL;
    new->size = 0;
    return new;
}

void destruir_node(node **ref) {
    if (*ref != NULL) {
        node *aux = *ref;
        free(aux);
        *ref = NULL;
    } else {
        return;
    }
}

float pop(descritor *pilha) {
    if (pilha != NULL) {
        if (pilha->size > 0) {
            float valor = pilha->topo->valor;
            node *aux = pilha->topo;
            pilha->topo = pilha->topo->ant;
            free(aux);
            pilha->size--;
            return valor;
        } else {
            printf("pilha vazia");
            exit(1); // Se a pilha estiver vazia, encerre o programa
        }
    } else {
        exit(1); // Se a pilha for nula, encerre o programa
    }
}

void push(descritor *pilha, float valor) {
    if (pilha != NULL) {
        node *novo = criar_node(valor);
        node *ref = pilha->topo;
        pilha->topo = novo;
        pilha->topo->ant = ref;
        pilha->size++;
    } else {
        return;
    }
}

void exibir(descritor *pilha) {
    node *aux = pilha->topo;
    while (aux != NULL) {
        printf("%f\n", aux->valor);
        aux = aux->ant;
    }
}

bool Operador(char string[max]) {
    if ((strcmp(string, "+") == 0) || (strcmp(string, "-") == 0) || (strcmp(string, "*") == 0) || (strcmp(string, "/") == 0) || (strcmp(string, "**") == 0) || (strcmp(string, "sqrt") == 0))
        return true;
    return false;
}

int main() {
    descritor *pilha_denumeros = criar_pilha();
    float numero1 = 0;
    float numero2 = 0;
    float resultado = 0;
    char leitura[max];
    for (int i = 0; i < 1; i++) {
        for (int i = 0; i < 7; i++) {
            scanf("%s", leitura);
            if (Operador(leitura)) {
                if (strcmp(leitura, "sqrt") == 0) {
                    numero1 = pop(pilha_denumeros);
                    resultado = sqrt(numero1);
                    push(pilha_denumeros, resultado);
                } else {
                    numero2 = pop(pilha_denumeros); // Primeiro número desempilhado é o segundo operando
                    numero1 = pop(pilha_denumeros); // Segundo número desempilhado é o primeiro operando
                    if (strcmp(leitura, "+") == 0) {
                        resultado = numero1 + numero2;
                        push(pilha_denumeros, resultado);
                    } else if (strcmp(leitura, "-") == 0) {
                        resultado = numero1 - numero2;
                        push(pilha_denumeros, resultado);
                    } else if (strcmp(leitura, "*") == 0) {
                        resultado = numero1 * numero2;
                        push(pilha_denumeros, resultado);
                    } else if (strcmp(leitura, "/") == 0) {
                        resultado = numero1 / numero2;
                        push(pilha_denumeros, resultado);
                    } else if (strcmp(leitura, "**") == 0) {
                        resultado = pow(numero1, numero2);
                        push(pilha_denumeros, resultado);
                    }
                }
            } else {
                push(pilha_denumeros, atof(leitura));
            }
        }
    }
    printf("resultado da operação = %f\n", pop(pilha_denumeros));

    return 0;
}

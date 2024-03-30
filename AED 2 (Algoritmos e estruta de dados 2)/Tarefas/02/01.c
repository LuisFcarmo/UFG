#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define max 1000000

typedef struct NO node;

struct NO
{
    float valor;
    node *ant;
};

typedef struct
{
    node *topo;
    int size;
} descritor;

node *criar_node(float valor)
{
    node *new = (node *)malloc(sizeof(node) * 1);
    new->ant = NULL;
    new->valor = valor;
    return new;
}

descritor *criar_pilha()
{
    descritor *new = (descritor *)malloc(sizeof(descritor) * 1);
    new->topo = NULL;
    new->size = 0;
    return new;
}

void destruir_node(node **ref)
{
    if (*ref != NULL)
    {
        node *aux = *ref;
        free(aux);
        *ref = NULL;
    }
    else
    {
        return;
    }
}

float pop(descritor *pilha)
{
    if (pilha != NULL)
    {
        if (pilha->size > 0)
        {
            float valor = pilha->topo->valor;
            node *aux = pilha->topo;
            pilha->topo = pilha->topo->ant;
            free(aux);
            pilha->size--;
            return valor;
        }
        else
        {
            printf("pilha vazia");
        }
    }
    else
    {
        exit(0);
    }
}

void push(descritor *pilha, float valor)
{
    if (pilha != NULL)
    {
        node *novo = criar_node(valor);
        node *ref = pilha->topo;
        pilha->topo = novo;
        pilha->topo->ant = ref;
        pilha->size++;
    }
    else
    {
        return;
    }
}

void exibir(descritor *pilha)
{
    node *aux = pilha->topo;
    while (aux != NULL)
    {
        printf("%f\n", aux->valor);
        aux = aux->ant;
    }
}

bool Operador(char string[max])
{
    if ((strcmp(string, "+") == 0) || (strcmp(string, "-") == 0) || (strcmp(string, "*") == 0) || (strcmp(string, "/") == 0) || (strcmp(string, "^") == 0) || (strcmp(string, "sqrt") == 0))
        return true;
    return false;
}

float operacao(float a, float b, char x) {
    switch (x)
    {
    case '+':
        return a + b;
        break;

    case '-':
        return a - b;
        break;

    case '/':
        return a / b;
        break;

    case '*':
        return a * b;
        break;
    case '^':
        return pow(a, b);
        break;
    default:
        break;
    }
}

float raiz (float a) {
    return sqrt(a);
}

float resolver_expressao(char x[], descritor *pilha) {
    char *vetor;
    float resultado;
    float numero1;
    float numero2;

    vetor = strtok(x, " ");
    while (vetor) {
        if (Operador(vetor)){
            if (strcmp(vetor, "sqrt") != 0) {
                numero1 = pop(pilha);
                numero2 = pop(pilha);
                resultado = operacao(numero2, numero1, vetor[0]);
                push(pilha, resultado);
            } else {
                numero1 = pop(pilha);
                resultado = sqrt(numero1);
                push(pilha, resultado);
            }
        } else {
            push(pilha, strtol(vetor, NULL, 10));
        }

        vetor = strtok(NULL, " ");
        
    }
    return pop(pilha);
}

int main()
{
    descritor *pilha_denumeros = criar_pilha();
    float numero1 = 0;
    float numero2 = 0;
    float resultado = 0;
    char leitura[max];

    for (int i = 0; i < 69; i++) {
        scanf("%[^\n]%*c", leitura);
        printf("%s\n", leitura);
        printf("resultado da expressão = %f\n", resolver_expressao(leitura, pilha_denumeros));
    };
    return 0;
}
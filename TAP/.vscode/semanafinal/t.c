#include <stdio.h>
#include <stdlib.h>
typedef struct _node node;

typedef struct _node {
    struct _node *prox;
    long long id;
    long long value;

};

node *criar_node (long long value, long long id) {
    node *novo_no = (node*) malloc(sizeof(node)*1);
    novo_no -> value = value;
    novo_no -> id = id;
    return novo_no;
}

void adicionar_ordenado (node **linked_list, long long value, long long id) {
    node *novo_no = criar_node(value, id);
    if (*linked_list == NULL) {
        *linked_list = novo_no;
    } else {
        node *prox = *linked_list;
        node *anterior = NULL;
        node *ref = NULL;
        while (value <= prox -> value) {
            anterior = prox;
            prox = prox -> prox;
            if (prox == NULL) break;
        }
        if (anterior == NULL) {
            novo_no -> prox = prox;
            *linked_list = novo_no;
        }
        else if (prox == NULL) {
            anterior -> prox = novo_no;
        }
        else {
            anterior -> prox = novo_no;
            novo_no -> prox = prox;
        }
    }
}



int main () {
    node *linked_list = NULL;
    node *aux = NULL;
    long long id = 0;
    long long acertos = 0;
    long long qtd = 0;
    scanf("%lld%*c", &qtd);
    while (qtd--) {
        scanf("%lld %lld%*c", &id, &acertos);
        adicionar_ordenado(&linked_list, acertos, id);
    }
    aux = linked_list;
    while (aux != NULL) {
        printf("%lld %lld\n", aux -> id, aux -> value);
        aux = aux -> prox;
    }
    return 0;
}
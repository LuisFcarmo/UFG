#include <stdlib.h>
#include <stdbool.h>

typedef struct rubronode RubroNode;

struct rubronode {
    RubroNode *direita;
    RubroNode *esquerda;
    RubroNode *pai;
    int cor;
    int valor;
};

RubroNode *busca(int valor, RubroNode *raiz) {
    if(!raiz || raiz -> valor == valor) {
        return raiz;
    }
    return (valor < raiz -> valor) ? (busca(valor, raiz -> esquerda)) : (busca(valor, raiz -> direita));
}

void RotacaoAesquerda(RubroNode **raiz, RubroNode *x) {
    RubroNode *y;
    y = x -> direita;
    x -> direita = y -> esquerda;
    y -> esquerda -> pai = x;
    y -> pai = x -> pai;
    if (x -> pai == NULL) {
        *raiz = y;
    }
    else if (x == x -> pai -> esquerda) {
        x -> pai -> esquerda = y;
    }
    else {
        x -> pai -> direita = y;
    }

    y -> esquerda = x;
    x -> pai = y;
}

RubroNode *insere(RubroNode *raiz, RubroNode *novo) {
    RubroNode *novaraiz = raiz;
    RubroNode *pai = NULL;
    RubroNode *atual = raiz;

    while(atual != NULL) {
        pai = atual;
        atual = (novo -> valor  < atual -> valor) ? atual -> esquerda : atual -> direita;
    }
}
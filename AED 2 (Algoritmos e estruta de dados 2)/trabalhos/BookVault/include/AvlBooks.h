#ifndef AVLBOOKS
#define AVLBOOKS
#include "./defines.h"

typedef struct no {
    book value;
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

int maior(int, int );
int AlturaDoNo(NoArv *);
int FatorDeBalanceamento(NoArv *);
int altura(NoArv *);
NoArv * RotacaoDireita(NoArv *);
NoArv * RotacaoEsquerda(NoArv *);
NoArv * RotacaoDireitaEsquerda(NoArv *);
NoArv * RotacaoEsquerdaDireita(NoArv *);
NoArv * balancear(NoArv *); 
NoArv *inserir(NoArv *, book);
void imprimir(NoArv *, int);
Resp Qtd_Filhos(NoArv *, book);
NoArv * Remover(NoArv *, book);
book Find(NoArv *, char*);

#endif
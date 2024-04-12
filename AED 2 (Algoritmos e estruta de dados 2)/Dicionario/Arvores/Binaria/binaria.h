#ifndef TREE_H 
#define TREE_H
#include <stdbool.h>

typedef struct no {
   int valor;
   struct no * direita;
   struct no * esquerda;
} NoArv;

typedef struct {
   NoArv * root;
} TreeReference;

typedef struct {
    bool direita;
    bool esquerda;
    int qtd;
} Resp;

int RandNumber(int begin, int end);

TreeReference * create_tree();

NoArv * create_node(int num);

NoArv * inserir_versao_1(NoArv * root, int num);

void inserir_versao_2(NoArv ** root, int num);

void inserir_versao_3(NoArv ** root, int num);

void imprimir_desordenada(NoArv * root);

void imprimir_ordenada(NoArv * root);

NoArv * buscar_versao_1(NoArv * root, int num);

NoArv * buscar_versao_2(NoArv * root, int num);

int altura(NoArv * root);

int Contar_no(NoArv * root);

int contar_folhas(NoArv * root);

Resp Criar_Resp(int qtd, bool direta, bool esquerda);

Resp Qtd_Filhos(NoArv *root, int chave);

NoArv * Remover(NoArv * root, int chave);

void printTree(NoArv * root, int space);

#endif
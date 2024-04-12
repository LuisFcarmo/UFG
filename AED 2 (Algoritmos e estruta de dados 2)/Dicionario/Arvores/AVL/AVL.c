#include "AVL.h"
/*implementação sem verificação da alocação de memoria feita apenas com fins didaticos*/
NoArv *Cria_No (int x) {
    NoArv *new = (NoArv*) malloc(sizeof(NoArv));
    new -> valor = x;
    new -> esquerda = NULL;
    new -> direita = NULL;
    new -> pai = NULL;
    new -> altura = 0;
    return new;
}

int maior (int a, int b) {
    return (a > b) ? a: b; 
}

int AlturaDoNo (NoArv *no) {
    return (no == NULL) ? -1 : no -> altura; 
}

int FatorDeBalanceamento (NoArv *no) {
    if (no) {
        return (AlturaDoNo(no -> esquerda) - AlturaDoNo(no -> direita));
    } else {
        return 0;
    }
}

void inserir_versao_2(NoArv **root, int num) {
   if ( * root == NULL) {
      * root = create_node(num);
   } else {
      if (num < ( * root) -> valor) {
        inserir_versao_2( & (( * root) -> esquerda), num);
      } else {
        inserir_versao_2( & (( * root) -> direita), num);
      }
   }
}


/*
    encontrar altura da nossa arvore
*/
int altura(NoArv * root) {
    if (root == NULL)
      return -1;
    else {
      int esquerda = altura(root -> esquerda);
      int direita = altura(root -> direita);
      if (esquerda > direita) {
         return esquerda + 1;
      } else {
         return direita + 1;
      }
   }
}

NoArv *RotacaoDireita(NoArv *NoDesbalanceado) {
 
} 

NoArv *RotacaoEsquerda(NoArv *NoDesbalanceado) {
    NoArv *y, *filho;
    y = NoDesbalanceado -> direita;
    filho = y -> esquerda;

    y -> esquerda = NoDesbalanceado;
    NoDesbalanceado -> direita = filho;

    NoDesbalanceado -> altura = maior(AlturaDoNo(NoDesbalanceado -> esquerda), AlturaDoNo(NoDesbalanceado -> direita) + 1);
    y -> altura = maior(AlturaDoNo(y -> esquerda), AlturaDoNo(y -> direita) + 1);
    return y;
}
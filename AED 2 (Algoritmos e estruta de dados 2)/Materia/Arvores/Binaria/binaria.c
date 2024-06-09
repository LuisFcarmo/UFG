#include <stdio.h>
#include <stdlib.h>
#include "binaria.h"
#include <time.h>

int RandNumber(int begin, int end) {
   return rand() % (end - begin + 1) + begin;
}

TreeReference * create_tree() {
   TreeReference * Tree = NULL;
   do {
      Tree = (TreeReference * ) malloc(sizeof(TreeReference) * 1);
      Tree -> root = NULL;
   } while (Tree == NULL);
}

NoArv * create_node(int num) {
   NoArv * aux = NULL;
   do {
      aux = (NoArv * ) malloc(sizeof(NoArv) * 1);
      aux -> valor = num;
      aux -> direita = NULL;
      aux -> esquerda = NULL;
   } while (aux == NULL);
   return aux;
}

NoArv * inserir_versao_1(NoArv * root, int num) {
   if (root == NULL) {
      return create_node(num);
   }
   // essa segunda parte estou caminhando na arvore ate chegar no local certo da inserção
   else {
      if (num < root -> valor) {
         root -> esquerda = inserir_versao_1(root -> esquerda, num);
      } else {
         root -> direita = inserir_versao_1(root -> direita, num);
      }
      return root;
   }
}
/*
    explicação de como funciona esta função basicamente vamos supor que vc deseja inserir o valor 5
        10 -> **ptr root
    6 -> **prt root      7
    você tem a referencia par ao endereço de memoria da raiz, basicamente oque está função ira fazer
    ela vai caminhar nas sub arvores da nossa arvore por exemplo
    10 é a raiz inicial
    6 também é uma raiz pois é uma arvore tem varias sub arvores, bem sabendo disso basta vc caminhar
    para direção correta valores menores a esquerda maiores a direita.
    caminhando recursivamente vc vai andar até uma raiz nula oque significa que vc chegou na ultima subarvore correspondente
    então basta criar o nó e enserir naquele endereço de memória
*/
void inserir_versao_2(NoArv ** root, int num) {
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

// maneira iterativa
void inserir_versao_3(NoArv ** root, int num) {
   NoArv * aux = * root;

   // mesma coisa que a versão recursiva mas, usando repetição para iterar na arvore
   while (aux != NULL) {
      if (num < aux -> valor) {
         root = & (aux -> esquerda);
      } else {
         root = & (aux -> direita);
      }
      aux = * root;
   }

   // alocando a arvore caso ela seja nula
   * root = create_node(num);
}

void imprimir_desordenada(NoArv * root) {
   if (root != NULL) {
      printf("%d-", root -> valor);
      imprimir_desordenada(root -> esquerda);
      imprimir_desordenada(root -> direita);
   } else {
      return;
   }
}

void imprimir_ordenada(NoArv * root) {
   if (root != NULL) {
      imprimir_ordenada(root -> esquerda);
      printf("%d-", root -> valor);
      imprimir_ordenada(root -> direita);
   } else {
      return;
   }
}

/*
    buscar coisas em arvore extremamente parcido que ensirir coisas na arvore basicamente caminhas pelas subarvores da
    nossa arvore
*/

// buscar em uma arvore binaria

NoArv * buscar_versao_1(NoArv * root, int num) {
   if (root != NULL) {
      if (num < root -> valor) {
         return buscar_versao_1(root -> esquerda, num);
      } else if (num > root -> valor) {
         return buscar_versao_1(root -> direita, num);
      } else if (num == root -> valor) {
         return root;
      }
   } else {
      return NULL;
      // isso aqui retorna nulo para as chamadas recursivas caso não tenha o elemento na arvore
   }
}

// forma iterativa
NoArv * buscar_versao_2(NoArv * root, int num) {
   while (root != NULL) {
      if (root -> valor == num) {
         return root;
      } else if (num > root -> valor) {
         root = root -> direita;
      } else if (num < root -> valor) {
         root = root -> esquerda;
      }
   }
   return NULL;
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

// contar a quantidade nós de uma arvore
int Contar_no(NoArv * root) {
   return (root == NULL) ? (0) : (1 + Contar_no(root -> direita) + Contar_no(root -> esquerda));
}

int contar_folhas(NoArv * root) {
   if (root != NULL) {
      if (root -> esquerda == NULL && root -> direita == NULL) {
         return 1;
      } else {
         return (contar_folhas(root -> direita) + contar_folhas(root -> esquerda));
      }
   } else {
      return 0;
   }
}

Resp Criar_Resp(int qtd, bool direta, bool esquerda) {
    Resp x;
    x.qtd = qtd;
    x.direita = direta;
    x.esquerda = esquerda;
    return x;
}

Resp Qtd_Filhos(NoArv *root, int chave) {
    if (root != NULL) {
        Resp x;
        if (root -> valor == chave) {
            if (root -> direita != NULL && root -> esquerda != NULL) {
                x = Criar_Resp(2, true, true);
            }
            else if (root -> direita == NULL && root -> esquerda != NULL) {
                x = Criar_Resp(1, false, true);
            }
            else if (root -> direita != NULL && root -> esquerda == NULL) {
                x = Criar_Resp(1, true, false);
            }
            else {
                x = Criar_Resp(0, false, false);
            }

            return x;
        } else {
            if (chave > root -> valor) {
                Qtd_Filhos(root -> direita, chave);
            } else {
                Qtd_Filhos(root -> esquerda, chave);
            }
        }
    } else {
        printf("Nó não esta presente na arvore");
    }
}

NoArv * Remover(NoArv * root, int chave) {
   if (root != NULL) {
      if (root -> valor == chave) {
         // aqui apenas removemos nós folhas
         if (root -> esquerda == NULL && root -> direita == NULL) {
            free(root);
            return NULL; // retorna nulo pras chamadas recursivas coloca nulo no ponteiro que apontava para este nó folha
         } else {
            Resp x = Qtd_Filhos(root, chave);
            NoArv *aux = NULL;
            if (x.qtd == 1) {
                if (x.direita) {
                    aux = root -> direita;
                } else {
                    aux = root -> esquerda;
                }
                free(root);
                return aux;
            } else {
               NoArv *aux = root -> esquerda;
               while(aux -> direita != NULL) aux = aux -> direita;
               root -> valor = aux -> valor;
               aux -> valor = chave;
               root -> esquerda = Remover(root -> esquerda, chave);
               return root;
            }
         }
      } else {
         if (chave < root -> valor) {
            root -> esquerda = Remover(root -> esquerda, chave);
         } else {
            root -> direita = Remover(root -> direita, chave);
         }
         return root;
      }
   } else {
      printf("Nó não está na arvore\n");
      return NULL;
   }
}

void printTree(NoArv * root, int space) {
   // Caso base
   if (root == NULL)
      return;

   // Incrementa o espaço entre os níveis
   space += 5;

   // Imprime o nó da direita
   printTree(root -> direita, space);

   // Imprime o nó atual após os espaços
   printf("\n");
   for (int i = 5; i < space; i++)
      printf(" ");
   printf("%d\n", root -> valor);

   // Imprime as setas indicando os filhos
   for (int i = 5; i < space; i++)
      printf(" ");
   printf("↙");
   for (int i = 0; i < 3; i++)
      printf(" ");
   printf("↘\n");

   // Imprime o nó da esquerda
   printTree(root -> esquerda, space);
}
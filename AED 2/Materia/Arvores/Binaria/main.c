#include "binaria.h"
#include <stdio.h>

int main() {
   srand(time(NULL));
   TreeReference * tree = create_tree();

   inserir_versao_2( & (tree -> root), 583);
   inserir_versao_2( & (tree -> root), 245);
   inserir_versao_2( & (tree -> root), 731);
   inserir_versao_2( & (tree -> root), 123);
   inserir_versao_2( & (tree -> root), 389);
   inserir_versao_2( & (tree -> root), 684);
   inserir_versao_2( & (tree -> root), 893);
   inserir_versao_2( & (tree -> root), 278);

   printTree(tree -> root, 1);
   printf("\n");
   printf("altura da arvore = %d\n", altura(tree -> root));
   printf("quantidade de nós = %d\n", Contar_no(tree -> root));
   printf("quantidade de folhas = %d\n", contar_folhas(tree -> root));

   Remover(tree -> root, 389);
   printTree(tree -> root, 10); 
   printf("altura da arvore = %d\n", altura(tree -> root));
   printf("quantidade de nós = %d\n", Contar_no(tree -> root));
   printf("quantidade de folhas = %d\n", contar_folhas(tree -> root));

   return 0;
};
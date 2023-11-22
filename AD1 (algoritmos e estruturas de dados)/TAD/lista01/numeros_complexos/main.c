#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "complex.h"

int main () {
    int resposta, tamanho = 0, qtd = 0;
    bool verifica;
    COMPLEX *elemento;
    int real, imaginaria;
    COMPLEX *x;
    HEADER *cj;
    HEADER *complemento;
    HEADER *cj_aux;
    while (1) {
        while (1)
        {        
            printf(" ------------------------------------------------\n"
                    "- 1 criar conjunto                             -\n"
                    "- 2 finalizar programa                         -\n"
                    "------------------------------------------------\n");
            scanf("%d%*c", &resposta);
            if (resposta != 1 && resposta != 2) {
                printf("Opção invalida escolha uma entre as opções\n");
            } else {
                break;
            }
        }
        if (resposta == 1){
            while (1) {
                printf("Forneça o tamanho do conjunto (0, 100000000)\n");
                scanf("%d%*c", &tamanho);
                if (tamanho > 100000000 || tamanho < 0) {
                    printf("tamanho invalido escolha um dentre os parâmetros\n");
                } else {
                    cj = New_Complex_set(tamanho);
                    break;
                }
            }
            while (1) {
                printf(" -------------------------------------------------\n"
                        "- operações disponiveis                         -\n"
                        "- 1 Verificar se o conjunto está vazio          -\n"
                        "- 2 adicionar elementos no conjuno              -\n"
                        "- 3 excluir um elemento do conjunto             -\n"
                        "- 4 cardinalidade do conjunto                   -\n"
                        "- 5 verificar se um elemento x pertence ao cj   -\n" 
                        "- 6 comparar se dois conjutos são gêmeos        -\n" 
                        "- 7 verificar se um conjunto e sub do outro     -\n"
                        "- 8 complemento de um conjunto sobre outro      -\n"
                        "- 9 União de dois conjuntos                     -\n"
                        "- 10 Intersecção de dois conjuntos              -\n"
                        "- 11 Diferença de dois conjuntos                -\n"
                        "- 12 mostrar elementos                          -\n"
                        "- 13 voltar ao menu principal                   -\n"
                        "- 14 mostrar elementos                          -\n"
                        "-------------------------------------------------\n"
                    );
                scanf("%d%*c", &resposta);
                if (resposta == 13) {
                    break;
                }
                if(resposta < 0 || resposta > 18) {
                    printf("opção invalidade escolha uma entre as disponiveis\n");
                }
                switch (resposta)
                {
                case 1:
                    if (Set_is_Empty(cj)) {
                        printf("Conjunto está vazio\n");
                    } else {
                        printf("conjunto não está vazio\n");
                    }
                    break;
                case 2:
                    printf("Quantidade de elementos\n");
                    scanf("%d%*c", &qtd);
                    while(qtd--) {
                        printf("elementos restantes %d\n", qtd+1);
                        printf("Digite parte imaginaria e real !\n");
                        scanf("%d %d%*c", &imaginaria, &real);
                        x = New_Complex(imaginaria, real);
                        Insert_Element(x, cj);
                    }
                    break;
                case 3:
                    printf("Digite um elemento a ser excluído\n");
                    scanf("%d %d%*c", &imaginaria, &real);
                    elemento = New_Complex(imaginaria, real);
                    Delete_Element(elemento, cj);
                    break;
                case 4:
                    printf("Cardinalidade do conjunto = %d\n", Cardinality(cj));
                    break;
                case 5:
                    printf("qual elemento você deseja verificar se pertencem ao conjunto\n");
                    printf("Digite parte imaginaria e real !\n");
                    scanf("%d %d%*c", &imaginaria, &real);
                    x = New_Complex(imaginaria, real);
                    if(Element_in_set(cj, x)){
                        printf("o numero está no conjunto\n");
                    } else {
                        printf("não está no conjunto\n");
                    }
                    break;
                case 6:
                    scanf("%d%*c", &tamanho);
                    cj_aux = Create_and_fill_set(tamanho);
                    printf("quais conjuntos você deseja verificar se são gemêos\n");
                    Twins_Set(cj, cj_aux);
                    Delete_set(&cj_aux);
                    break;
                case 7: 
                    printf("digite o tamanho do novo conjunto\n");
                    scanf("%d%*c", &tamanho);
                    cj_aux = Create_and_fill_set(tamanho);
                    if (Subset_in_Set(cj, cj_aux)) {
                        printf("novo conjunto é subconjunto do outro\n");
                    } else {
                        printf("não é subconjunto dele\n");
                    };
                    Delete_set(&cj_aux);
                    break;
                case 8:
                    printf("digite o tamanho do novo conjunto\n");
                    scanf("%d%*c", &tamanho);
                    cj_aux = Create_and_fill_set(tamanho);
                    complemento = New_Complement(cj, cj_aux);
                    print_set(complemento);
                    Delete_set(&complemento);
                    break;
                case 9:
                    printf("digite o tamanho do novo conjunto\n"); 
                    scanf("%d%*c", &tamanho);  
                    cj_aux = Create_and_fill_set(tamanho);
                    complemento = Set_Union(cj, cj_aux);
                    print_set(complemento);
                    Delete_set(&complemento);
                    break;
                case 10:
                    printf("digite o tamanho do novo conjunto\n");
                    scanf("%d%*c", &tamanho);
                    cj_aux = Create_and_fill_set(tamanho);
                    complemento = Set_Intersec(cj, cj_aux);
                    print_set(complemento);
                    Delete_set(&complemento);
                    break;
                case 11:
                    printf("digite o tamanho do novo conjunto\n");
                    scanf("%d%*c", &tamanho);
                    cj_aux = Create_and_fill_set(tamanho);
                    complemento = Set_Diference(cj, cj_aux);
                    print_set(complemento);
                    Delete_set(&complemento);
                break;
                case 12:
                    print_set(cj);
                break;
            
                default:
                    break;
                }
            }
        }
        if (resposta == 2) {
            break;
        }
    }
    Delete_set(&cj);
    Delete_set(&cj_aux);
    Delete_set(&complemento);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "conjunto.h"

int main () {
    int resposta, tamanho = 0, qtd = 0, elemento = 0;
    bool verifica;
    Conjunto cj;
    Conjunto complemento;
    char ordem;
    Conjunto cj_aux;
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
                    cj = New_Conjunction(tamanho);
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
                        "- 5 Quantidades de elementos maiores que x      -\n"
                        "- 6 Quantidades de elementos menores que y      -\n"
                        "- 7 verificar se um elemento x pertence ao cj   -\n" 
                        "- 8 comparar se dois conjutos são gêmeos        -\n" 
                        "- 9 verificar se um conjunto e sub do outro     -\n"
                        "- 10 complemento de um conjunto sobre outro     -\n"
                        "- 11 União de dois conjuntos                    -\n"
                        "- 12 Intersecção de dois conjuntos              -\n"
                        "- 13 Diferença de dois conjuntos                -\n"
                        "- 14 mostrar elementos                          -\n"
                        "- 15 voltar ao menu principal                   -\n"
                        "-------------------------------------------------\n"
                    );
                scanf("%d%*c", &resposta);
                if (resposta == 15) {
                    break;
                }
                if(resposta < 0 || resposta > 18) {
                    printf("opção invalidade escolha uma entre as disponiveis\n");
                }
                printf("reposta ============= %d\n", resposta);

                switch (resposta)
                {
                case 1:
                    if (Conjunction_is_Empty(cj)) {
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
                        scanf("%d%*c", &elemento);
                        Insert_Element(elemento, cj);
                    }
                    break;
                case 3:
                    printf("Digite um elemento a ser excluído\n");
                    scanf("%d", &elemento);
                    Delete_Element(elemento, cj);
                    break;
                case 4:
                    printf("Cardinalidade do conjunto = %d\n", Cardinality(cj));
                    break;
                case 5:
                    printf("qual o elemento ?\n");
                    scanf("%d%*c", &elemento);
                    printf("quantidade de elementos maiores que %d (%d)\n", elemento ,Bigger_than_Element(cj, elemento));
                    break;
                case 6:
                    printf("qual o elemento ?\n");
                    scanf("%d%*c", &elemento);
                    printf("quantidade de elementos menores que %d (%d)\n", elemento ,Lower_tham_Element(cj, elemento));
                    break;
                case 7:
                    printf("qual elemento você deseja verificar se pertencem ao conjunto\n");
                    scanf("%d%*c", &elemento);
                    if(Element_is_Conjuction(elemento, cj)){
                        printf("o elemento %d está no conjunto\n", elemento);
                    } else {
                        printf("não está no conjunto\n");
                    }
                    break;
                case 8:
                    cj_aux = Create_and_fill_conjunction();
                    printf("quais conjuntos você deseja verificar se são gemêos\n");
                    Twins_Conjunction(cj, cj_aux);
                    Destruct_Cojunction(cj_aux);
                    break;
                case 9: 
                    cj_aux = Create_and_fill_conjunction();
                    Belongs_in_Conjunction(cj, cj_aux);
                    Destruct_Cojunction(cj_aux);
                    break;
                case 10:
                    cj_aux = Create_and_fill_conjunction();
                    complemento = New_Complement(cj, cj_aux);
                    Display_Conjuction(complemento, 'C');
                    Destruct_Cojunction(complemento);
                    break;
                case 11:   
                    cj_aux = Create_and_fill_conjunction();
                    complemento = Union(cj, cj_aux);
                    Display_Conjuction(complemento, 'C');
                    Destruct_Cojunction(complemento);
                    break;
                case 12:
                    cj_aux = Create_and_fill_conjunction();
                    complemento = intersection(cj, cj_aux);
                    Display_Conjuction(complemento, 'C');
                    Destruct_Cojunction(complemento);
                break;
                case 13:
                    cj_aux = Create_and_fill_conjunction();
                    complemento = Difference(cj, cj_aux);
                    Display_Conjuction(complemento, 'C');
                    Destruct_Cojunction(complemento);
                break;
                case 14:    
                    printf("qual ordem vc deseja imprimir\n");
                    printf("crescente = C, descrescente = D\n");
                    scanf("%c", &ordem);
                    Display_Conjuction(cj, ordem);
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
    return 0;
}
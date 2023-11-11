#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "texto.h"
int main () {
    int op = 0;
    int aux = 0;
    int inicio = 0, fim  = 0;
    String *texto_aux;
    String *texto;
    char *ptr_txt;
    while (1) {
        printf(
            "-----------------------\n"
            "- 1 criar texto       -\n"
            "- 2 sair              -\n"
            "-----------------------\n\n"
        );
        scanf("%d%*c", &op);
        if (op > 2) {
            printf("Opção invalidade por favor escolher uma entre as disponiveis\n");
        } else if (op == 1) {
            texto = Scanf_Text();
            while (1)
            {
               printf(
                "------------------------------------------------\n"
                "- 1 mostrar texto                              -\n"
                "- 2 concatenar dois textos                     -\n"
                "- 3 tamanho do texto                           -\n"
                "- 4 obter o texto disponivel                   -\n"
                "- 5 copiar texto                               -\n"
                "- 6 substitutir texto                          -\n"
                "- 7 obter subtexto                             -\n"
                "- 8 comparar textos                            -\n"
                "- 9 Contar ocorrência de SubTexto              -\n"
                "------------------------------------------------\n\n"
               );
               scanf("%d%*c", &op);
               switch (op) {
                case 1:
                    printf("quantidade de palavras por coluna\n");
                    scanf("%d%*c", &aux);
                    Show_Text(texto, aux);
                break;
                case 2:
                    printf("digite o outro texto que você deseja concatenar\n");
                    texto_aux = Scanf_Text();
                    texto = Concatenate_Text(texto, texto_aux);
                    printf("digite a quantiade de palavras por coluna\n");
                    scanf("%d", &aux);
                    Show_Text(texto, aux);
                break;
                case 3:
                    ptr_txt = Get_Text(texto);
                    printf("tamanho do texto == %d\n", Size_text(ptr_txt));
                case 4:
                    ptr_txt = Get_Text(texto);
                    printf("%s", ptr_txt);
                case 5:
                break;
                case 6:
                    printf("digite o texto que vai substituir o atual!\n");
                    texto_aux = Scanf_Text();
                    ptr_txt = Get_Text(texto_aux);
                    Replace_Text(texto, ptr_txt);
                    Show_Text(texto, 90);
                break;
                case 7:
                    printf("digite o inicio e o fim do subtexto!\n");
                    scanf("%d %d%*c", &inicio, &fim);
                    ptr_txt = Get_SubText(texto, inicio, fim);
                    texto = New_Text(ptr_txt);
                    Show_Text(texto, 90);
                case 8:
                    printf("qual o outro texto que vc deseja comparar !\n");
                    texto_aux = Scanf_Text();
                    if (Compare_Text(texto, texto_aux)){
                        printf("textos iguais\n");
                    } else {
                        printf("textos diferentes\n");
                    }
                break;
                case 9:
                    printf("qual o sub texto ?\n");
                    texto_aux = Scanf_Text();
                    printf("Ocorrência = (%d)", Shearching_SubText(texto, texto_aux));
                break;
                default:
                break;
               }
                sleep(1.5);
                system("clear");
            }
        }
        sleep(1.5);
        system("clear");
    }    
}
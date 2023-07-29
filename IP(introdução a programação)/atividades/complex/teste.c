#include <stdio.h>
#include <stdlib.h>
typedef struct
{   
    double numerador;
    double denominador; 
} frac;

int main () {
    int numerador = 0, denominador = 0;
    char final;
    int contador = 1;
    //faço a primeira alocação do vetor
    frac *vetdinamico = (frac*) malloc(1*sizeof(frac));
    while (1) {
        //leio os primeiros valores 
        scanf("%d/%d%c", &numerador, &denominador, &final);
        //jogo eles no vetor 
        vetdinamico[contador].denominador = denominador;
        vetdinamico[contador].numerador = numerador;
        //aumento o espaço do vetor
        contador++;
        //realoco a memoria do vertor
        vetdinamico = realloc(vetdinamico, sizeof(frac)*contador);
        //vejo se o caractere que indica o final de entrada foi digitado 
        if ( final  == '\n' ) break;
    }
}
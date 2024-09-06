#include <stdio.h>
#include "plano.h"
int main () {
    Plano_Cartesiano *plano = pc_new(10, 0, 0, 1000, 1000);
  
    New_area(plano);
    Preenche_fundo(plano, 0);
    Print_eixo_x(plano, 7);
    Print_eixo_y(plano, 7);
    //func_afim(plano, 1, 0, 7);
    Pc_cria_imagem(plano);
    return 0;
}

//scanf => fscanf(stdin, "%d", &num);
//printf => fprintf(stdout, "%d", &num)
#ifndef _PlanoCartesiano_
#include <stdio.h>
#include <stdlib.h>
#include "plano.h"
#include <math.h>

Plano_Cartesiano *pc_new(char escala, int l_origem, int c_origem, int largura, int altura) {
    Plano_Cartesiano *plano = NULL;
    plano = (Plano_Cartesiano *) malloc(1*sizeof(Plano_Cartesiano));
    
    plano -> escala = escala;
    plano -> l_origem = l_origem;
    plano -> c_origem = c_origem;
    plano -> largura = largura;
    plano -> altura = altura;
    plano -> area = NULL;

    return plano;
}

void pc_delete (Plano_Cartesiano ** Pc_ref) {
    Plano_Cartesiano *ref = *Pc_ref;
    if (ref == NULL) {
        printf("Erro tentando deleter memoria não alocada");
    } else {
        free(ref);
        *Pc_ref = NULL;
    }
}

void New_area (Plano_Cartesiano *pc) {
    pc -> area = (int**) malloc(pc->altura*sizeof(int*));
    for (int i = 0; i < pc ->largura; i++) {
        pc -> area[i] = (int*) malloc(pc->largura*sizeof(int));
    }
}

void Delete_area (Plano_Cartesiano *pc) {
    for (int i = 0; i < pc ->largura; i++) {
       free(pc -> area[i]);
    }
    free(pc->area);
}

void Preenche_fundo (Plano_Cartesiano *pc, int color) {
    for (int i = 0; i < pc -> altura; i++) {
        for (int c = 0; c < pc -> largura; c++) {
            pc -> area[i][c] = color;
        }   
    }
}

void Print_eixo_x (Plano_Cartesiano *pc, int color) {
    for (int i = 0; i < pc -> largura; i++) {
        pc -> area[pc-> c_origem][i] = color;
    }
}

void Print_eixo_y (Plano_Cartesiano *pc, int color) {
    for (int i = 0; i < pc -> altura; i++) {
        pc -> area[i][pc->l_origem] = color;
    }
}

void Pc_pinta (Plano_Cartesiano *pc, double x, double y) {

}

void Pc_cria_imagem (Plano_Cartesiano *pc) {
    FILE *ptr;
    ptr = fopen("png.pmg", "w");
    fprintf(ptr,"P2");
    fprintf(ptr, "\n");
    fprintf(ptr, "%d", pc -> altura);
    fprintf(ptr, " %d", pc -> largura);
    fprintf(ptr ,"\n");
    fprintf(ptr, "%d\n", pc -> escala);
    

    for (int i = 0; i < pc -> altura; i++){
        for (int c = 0; c < pc -> largura; c++) {
            fprintf(ptr, "%d ", pc -> area[i][c]);
        }
        fprintf(ptr,"\n");
    } 

}

void func_afim (Plano_Cartesiano *pc, int a, int b, int cor) {
    int j = 0;
    for (int i = 0; i < pc-> altura; i++) {
        j = a * i + b;
        if (j < 0) {
            pc -> area[i][j] = cor;
        }
    }
}

/*void func_quadratica (Plano_Cartesiano *pc, int a, int b, int c, int cor) {
    int j = 0;
    for (int i = 0; i < pc-> altura; i++) {
        j = pow(a*j, 2) + b*i + c;
        pc -> area[i][j] = cor;
    }
}*/



#endif
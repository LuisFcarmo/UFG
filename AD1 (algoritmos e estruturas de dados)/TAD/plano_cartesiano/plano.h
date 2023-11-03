#define _PlanoCartesiano_
typedef struct {
    char escala;
    int l_origem, c_origem;
    int largura, altura;
    int **area;
} Plano_Cartesiano;

Plano_Cartesiano *pc_new(char escala, int l_origem, int c_origem, int largura, int altura);
void pc_delete (Plano_Cartesiano ** Pc_ref);
void New_area (Plano_Cartesiano *pc);
void Delete_area (Plano_Cartesiano *pc);
void Preenche_fundo (Plano_Cartesiano *pc, int color);
void Print_eixo_x (Plano_Cartesiano *pc, int color);
void Print_eixo_y (Plano_Cartesiano *pc, int color);
void Pc_pinta (Plano_Cartesiano *pc, double x, double y);
void Pc_cria_imagem (Plano_Cartesiano *pc);
void func_afim (Plano_Cartesiano *pc, int a, int b, int cor);
//void func_quadratica (Plano_Cartesiano *pc, int a, int b, int c, int cor);
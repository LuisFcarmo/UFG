#include <stdio.h>
char matriz[100][100];
void desenhalosan (int dim, char borda, char meio) {
    int inicio = dim/2;
    int fim = dim/2;
    int linha = 0, coluna = 0;
    for (linha = 0; linha < dim; linha++) {
        if(linha <= dim/2 && linha > 0) {
                inicio--;
                fim++;
            }
            else if(linha > dim/2 && linha > 0) {
                inicio++;
                fim--;
            }
        for (coluna = 0; coluna < dim; coluna++) {
            if(coluna > inicio && coluna < fim){
                matriz[linha][coluna] = meio;
            }
            else if (coluna == inicio || coluna == fim) {
                matriz[linha][coluna] = borda;
            }
        }
    }
    for (linha = 0; linha < dim; linha++) {
        for (coluna = 0; coluna < dim; coluna++) {
            printf("%c ", matriz[linha][coluna]);
        }
        printf("\n");
    }
}
int main () {
    int dim = 0;
    char borda, meio;
    int coluna, linha;
    scanf("%d %c %c", &dim, &borda, &meio);
    if(dim % 2 == 0) {
        printf("Dimensao invalida!");
        return 0;
    }
    for (linha = 0; linha < dim; linha++) {
        for (coluna = 0; coluna < dim; coluna++) {
            matriz[linha][coluna] = ' ';
        }
    }
    desenhalosan(dim, borda, meio);
    return 0;
} 
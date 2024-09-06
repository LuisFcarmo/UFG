#include <stdio.h>
int main () {
    int matriz[50][2];
    int qfrac = 0;
    int tamanho = 0;
    int linha = 0, coluna = 0;
    int contador = 0;
    int linhab =0;
    int boleano = 0;
    scanf("%d", &qfrac);
    while (qfrac--) {
        boleano = 0;
        contador++;
        scanf("%d", &tamanho);
        for (linha = 0;linha < tamanho; linha++) {
            for (coluna = 0; coluna < tamanho; coluna++) {
                scanf("%d/%d", &matriz[linha][coluna], &matriz[linha][coluna+1]);
                break;
            }
        }
        printf("Caso de teste %d\n", contador);
        for (linha = 0; linha < tamanho; linha++) {
            for (linhab = linha+1; linhab < tamanho; linhab++) {
                if((matriz[linha][0]/(double)matriz[linha][1])==(matriz[linhab][0]/(double)matriz[linhab][1])){
                    printf("%d/%d equivalente a %d/%d\n", 
                        matriz[linha][0], 
                        matriz[linha][1], 
                        matriz[linhab][0], 
                        matriz[linhab][1]
                    );
                    boleano = 1;
                }
            }
        }
        if(boleano == 0) {
            printf("Nao ha fracoes equivalentes na sequencia\n");
        };
    }
    
    
    return 0;
}
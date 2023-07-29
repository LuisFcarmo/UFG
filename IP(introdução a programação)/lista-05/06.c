#include <stdio.h>
int matriz[6][6];
int main () {
    int linha = 0, coluna = 0;
    int soma = 0;
    int li = 0, cl = 0;
    int maior = -63;
    for (linha = 0; linha < 6; linha++) {
        for (coluna = 0; coluna < 6; coluna++) {
            scanf("%d", &matriz[linha][coluna]);
        }
    }
    
    for (linha = 0; linha < 4; linha++) {
        for (coluna = 0; coluna < 4; coluna++) {
            for (li = 0; li < 3; li+=2) {
                for (cl = 0; cl < 3; cl++) {
                    soma += matriz[linha + li][coluna + cl];
                }    
            }
            soma += matriz[linha+1][coluna+1];
            if(soma > maior) {
                maior = soma;
            }
            soma = 0;
        }
    }
    printf("%d\n", maior);
    
    return 0;
}
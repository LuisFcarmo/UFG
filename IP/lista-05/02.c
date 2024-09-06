#include <stdio.h>
int main (){
    int matriz[1000][1000];
    int tamanho;
    int i, k;
    scanf("%d", &tamanho);
    for (i = 0; i < tamanho; i++)
    {
        for (k = 0; k < tamanho; k++){
            scanf("%d", &matriz[i][k]);
        }
    }
    k = tamanho-1;
    for (i = 0; i < tamanho; i++)
    {
        printf("%d\n", matriz[i][k]);
        k--;
    }
    
    return 0;
}
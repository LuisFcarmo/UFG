#include <stdio.h>
int main (){
    int linha = 0;
    int coluna = 0;
    int i = 0, k = 0;
    int matriz[10][10];
    while (1)
    {
        scanf("%d", &linha);
        if(linha <= 10 && linha >= 1){
            break;
        }
        if (linha > 10){
            continue;
        }
    }
    while (1)
    {
        scanf("%d", &coluna);
        if(coluna <= 10 && coluna >= 1){
            break;
        }
        if (coluna > 10){
            continue;
        }
    }
    for (i = 0; i < linha; i++)
    {
        for (k = 0; k < coluna; k++)
        {
            scanf("%d", &matriz[i][k]);
        }        
    }
        for (i = 0; i < linha; i++)
    {
        printf("linha %d: ", i+1);
        for (k = 0; k < coluna; k++)
        {
            printf("%d", matriz[i][k]);
                if(k >= 0 && k < coluna-1){
                printf(",");
            }
        }   
        printf("\n");     
    }
    
    return 0;
}
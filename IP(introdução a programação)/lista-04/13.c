#include <stdio.h>
int main () {
    int comeco;
    int fim;
    int i = 0;
    int casosteste;
    int auxiliar;
    scanf("%d", &casosteste);
    while (casosteste--){
    scanf("%d %d", &comeco, &fim);
    for (i = comeco; i <= fim; i++){
        printf("%d", i);
    
    }
    for (i = fim; i >= comeco; i--){
        auxiliar = i;
        if (auxiliar == 0) {
            printf("%d", auxiliar);
            break;
        }
        while(auxiliar) {
                printf("%d", auxiliar%10);
                auxiliar = auxiliar/10;
        }
        
    
    }
    printf("\n");
    }
    
    return 0;
}
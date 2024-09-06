#include <stdio.h>
int main () {
    int vetn[1000];
    int quantvetor, valor;
    int maior; 
    int menor;
    int aux;
    int aux2;
    int i = 0;
    scanf("%d", &quantvetor);
    for (i = 0; i < quantvetor; i++){
        scanf("%d", &valor);
        vetn[i] = valor;
    }
    maior = vetn[0];
    menor = vetn[0];
    for (i = 0; i < quantvetor; i++){
        if (i != 0 && i!=quantvetor)
        {
            printf(" ");
        }
        printf("%d", vetn[i]);
    
        if(maior <= vetn[i]) {
            maior = vetn[i];
        }
        if(menor >= vetn[i]) {
            menor = vetn[i];
        }
        if (i == quantvetor)
        {
            printf("\n");
        }
        
    }
    printf("\n");
    for (i = quantvetor-1; i >= 0; i--){
        if(i != quantvetor-1){
            printf(" ");
        }
        printf("%d", vetn[i]);
        if (i == 0)
        {
            printf("\n");
        }
    }
    printf("%d\n", maior);
    printf("%d\n", menor);   
}
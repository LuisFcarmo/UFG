#include<stdio.h>
int main () {  
    int minimo = 0;
    int quantidade = 0;
    int vetorhoras[1000000];
    int contadorpresentes = 0;
    int valor = 0;
    int i = 0;
    scanf("%d", &quantidade);
    scanf("%d", &minimo);
    for (i = 0; i < quantidade; i++)
    {
        scanf("%d", &valor);
        vetorhoras[i] = valor;
    }
    for (i = 0; i < quantidade; i++)
    {
        if (vetorhoras[i] <= 0)
        {
            contadorpresentes++;
        }
        
    }
    if (contadorpresentes >= minimo) {
        printf("NAO\n");
    } else {
        printf("SIM\n");
        return 0;
    }
    
    for (i = quantidade-1; i >= 0; i--)
    {
        if(vetorhoras[i] <= 0){
            printf("%d\n",i+1);
        }
    }
    
    
    
    
    return 0;
}
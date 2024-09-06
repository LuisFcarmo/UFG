#include <stdio.h>
int main(){   
    char numero[101];
    int tabela[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    int quantidade = 0;
    int k = 0;
    int idx = 0;
    int numerol = 0;
    scanf("%d", &quantidade);
    while (quantidade--)
    {
        scanf("%s", numero);
        while (numero[k] != '\0')
        {
            idx = numero[k] - '0';
            numerol += tabela[idx];
            k++;
        }
        printf("%d leds\n",  numerol);
        numerol = 0;
        k = 0;
    }
    
    
    
    return 0;
}
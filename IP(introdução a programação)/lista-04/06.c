#include <stdio.h>
    
int verificapalavra (char um[], char dois[], char tres[], char usu []) {
    int i = 0;
    int contador = 0, contador2 = 0, contador3 = 0;
    int parada = 5;
    while (parada--)
    {
        if (usu[i] == um[i] && usu[i] != '\0' && um[i] != '\n')
        {
            contador++;
        }
        if (usu[i] == dois[i] && usu[i] != '\0' && dois[i] != '\n')
        {
            contador2++;
        }
            if (usu[i] == tres[i] && usu[i] != '\0' && tres[i] != '\n')
        {
            contador3++;
        }
        i++;
    }   
    if (contador2 == 2 || contador2 == 3)
    {
        return 2;
    }
    if (contador == 2 || contador == 3)
    {
        return 1;
    }
    if (contador3 == 4 || contador3 == 5)
    {
        return 3;
    }
    
}
int main () {
    char um [] = "one";
    char dois [] = "two";
    char tres [] = "three";
    char stringusu [6];
    int tamanho = 0;
    int quantidade = 0;
    scanf("%d", &quantidade);
    while (quantidade--)
    {
    scanf("%s", stringusu);
    tamanho = verificapalavra(um, dois, tres, stringusu);    
    printf("%d\n", tamanho);
    }
    
    
}
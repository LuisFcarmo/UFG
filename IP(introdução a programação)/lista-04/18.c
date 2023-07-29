#include <stdio.h>
#include <string.h>
int maiouminu(char texto[]){
    int i = 0;
    int contador = 0;
    for (i = 0; i < strlen(texto); i++)
    {
        contador++;
    
    
        if (texto[i] == ' ')
        {
            contador--;
            continue;
        }
        else{
        if (contador % 2 != 0)
        {
            if (texto[i] >= 97 && texto[i] <= 122)
            {
                texto[i] = texto[i]-32;
            }
            if (texto[i] >= 65 && texto[i] <= 90)
            {
                continue;
            }
    
        }
        if(contador % 2 == 0) {
            if (texto[i] >= 97 && texto[i] <= 122)
            {
                continue;
            }
            if (texto[i] >= 65 && texto[i] <= 90)
            {
                texto[i] = texto[i]+32;
            }
    
        }
        }
    
    
    }
}
    
int main () {
    char texto[50];
    while(EOF != scanf("%[^\n]%*c", texto)){
        maiouminu(texto);
        printf("%s\n", texto);
    }
    
    
    
    return 0;
}
#include <stdio.h>
int main () {
    char texto[10000];
    int letras = 0;
    int vogais = 0;
    int i = 0;
    int consoantes = 0;
    int quantidadetextos = 0;
    scanf("%d%*c", &quantidadetextos);
    int k = 0;
    while (quantidadetextos--)
    {
        scanf("%[^\n]%*c", texto);
    
        for (i = 0; texto[i] != '\0'; i++){
            if (texto[i] >= 65 && texto[i] <= 90 || texto[i] >= 97 && texto[i] <= 122){
                letras++;
                if (texto[i] == 'a' || texto[i] == 'e' || texto[i] == 'i' || texto[i] == 'o' || texto[i] == 'u' ||
                    texto[i] == 'A' || texto[i] == 'E' || texto[i] == 'I' || texto[i] == 'O' || texto[i] == 'U')
                    {
                        vogais++;
            }
            else {
                consoantes++;
            }
        }
        
    }
    printf("Letras = %d\n", letras);
    printf("Vogais = %d\n", vogais);
    printf("Consoantes = %d\n", consoantes);
    
    letras = 0;
    vogais = 0;
    consoantes = 0;
    
    }
    return 0;
}
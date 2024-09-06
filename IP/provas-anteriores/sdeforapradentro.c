#include <stdio.h>
#include <string.h>
int main () {
    char palavra[100];
    int quantidade;
    scanf("%d%*c", &quantidade);
    while (quantidade--)
    {
    scanf("%[^\n]%*c", palavra);
    //aqui ele começa do meu da palavra e vai imprimindo até o penultimo caractere 
    for (int i = (strlen(palavra)/2)-1 /*lembre se que vetor começa no 0 strlen retorna o tamanho começando do 1 */ ; i >= 0; i--)
    {
        printf("%c", palavra[i]);
    }
    //aqui ele começa no final e vai imprimindo ate o caractere do meio 
    for (int i = strlen(palavra)-1; i >= (strlen(palavra)/2); i--)
    {
        printf("%c", palavra[i]);
    }
    printf("\n");
    }
}
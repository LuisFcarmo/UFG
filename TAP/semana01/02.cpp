#include <stdio.h>

int main () {
    int qtd = 0;
    int i = 0;
    char letra[101];
    scanf("%[^\n]", letra);

    while (1) {
        if (letra[i] == '\0') break;
        if (letra[i] == 'w') qtd += 2;
        else if (letra[i] == 'v') qtd += 1; 
        i++;
    }   
    printf("%d", qtd);
}
#include <stdio.h>
int main () {
    char palavra;
    char aux;
    int fim, inicio;
    scanf("%d", &inicio);
    scanf("%d", &fim);

    scanf("%s", palavra);
    aux = palavra[inicio];
    palavra[inicio] = fim;



    return 0;
}
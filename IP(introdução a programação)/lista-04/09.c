#include <stdio.h>
int main () {
    int vetnum[10000];
    int quantnumeros = 0;
    int valor = 0, maior = 0, indice = 0;
    int contador = 0;
    int i = 0;
    scanf("%d", &quantnumeros);
    //grava os valores no vetor
    for (i = 0; i < quantnumeros; i++)
    {
        scanf("%d", &valor);
        vetnum[i] = valor;
    }
    maior = vetnum[0];
    indice = 0;
    //pega o maior indice apenas na primeira vez que ele aparece
    for (i = 0; i < quantnumeros; i++)
    {
        if (maior < vetnum[i])
        {
            maior = vetnum[i];
            indice = i;
        }
        if (vetnum[quantnumeros-1] == vetnum[i]) {
            contador++;
        }
    }
    printf("Nota %d, %d vezes\n",vetnum[quantnumeros-1], contador);
    printf("Nota %d, indice %d\n", maior, indice);
    
    return 0;
}
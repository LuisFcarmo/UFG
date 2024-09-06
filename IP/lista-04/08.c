#include <stdio.h>
#include <string.h>
void cpt (char *palavra) {
    int i = 0;
    for (i = 0; i <= (strlen(palavra)-1); i++){
        if((palavra[i] >= 'a' && palavra[i] <= 'z') || (palavra[i] >= 'A' && palavra[i] <= 'Z') )
            {
            palavra[i] = palavra[i]+3;
            }
    }
}
void inverter(char vet[], int tamanho){
int i = 0, aux = 0, fim = 0, tam = tamanho;
    fim = tam - 1; // índice do último caracter
    for(i = 0; i < tam/2; i++){
        aux = vet[i];
        vet[i] = vet[fim];
        vet[fim] = aux;
        fim--;
    }
}
void cpt2 (char *palavra) {
    int i = 0;
    int tamanho = strlen(palavra)/2;
    for (i = tamanho; i < strlen(palavra); i++){
        palavra[i] = palavra[i]-1;
        
    }
}
int main () {
    int quantidade;
    int i = 0;
    char string[1001];
    char string2[1001];
    int k = 0;
    scanf("%d%*c", &quantidade);
    while (quantidade--){
        scanf("%[^\n]%*c", string);
        cpt(string);
        inverter(string, strlen(string));
        cpt2(string);
        printf("%s\n", string);
    
    
    }
    return 0;
}
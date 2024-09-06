#include <stdio.h>
#include <stdlib.h>
int distancia (int vetrota[][6], int *rota, int tamanho) {
    int linha, coluna, i = 0;
    tamanho = tamanho -1; // o tamanho que eu preciso rodar é equivalente tamanho total de itens tirando 1 
    // exemplo 1 2 3  1 2 / 2 3
    int acumulador = 0;
    while(tamanho--) {
        linha = rota[i];// primeiro termo do vetor rota
        coluna = rota[i+1]; // a coluna vai ser sempre o proximo
        if(vetrota[linha][coluna] == -1) {
            return -1; // retorna o verificador de rota invalida
        }
        else{
            acumulador+= vetrota[linha][coluna]; // acumulo a distância
            i++;
        }
    }
    return acumulador;
}
void gravandorota (int *vetrota, int tamanho) {
    int i = 0;
    for (i = 0; i < tamanho; i++){
        scanf("%d", &vetrota[i]);
    }
}
    
int main () {
    //tabela de distância das cidades
    int tabela[6][6] = {
        0, 63, 210, 190, -1, 190,
        63, 0, 160,  150, 95, 10,
            210, 160, 0, 10, 1, 10,
        190, 150, 10, 0, 10, 20,
        10,  95,  7, 21, 0, 80,
        190,  2, -1,  41, 80, 0,
    };
    int tamanhorota = 0, i = 0, distanciatotal =0;
    int *vetrota;
    
    scanf("%d", &tamanhorota);
    
    //aloco a matriz com espaço suficiente para rota
    vetrota = (int *)(calloc(tamanhorota, sizeof(int)));    
    //função que grava a rota de viagem
    gravandorota(vetrota, tamanhorota);
    //função que calcula a distância e verifica se  a rota digitada é valida
    distanciatotal =  distancia(tabela, vetrota, tamanhorota);
    
    // o -1 foi o caractere escolhido para verificar se a rota era valida ou não
    if (distanciatotal != -1) {
        printf("%d", distanciatotal);
    } else {
    // aqui significa que o -1 apareceu na rota loga ela é invalida
        printf("rota invalida!");
        return 0;
    }
    
    return 0;
}
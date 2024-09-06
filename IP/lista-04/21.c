#include <stdio.h>
int verificando (int *vetor, int *vetor2) {
    int i = 0;
    int k = 0;
    int contador = 0;
    for (i = 0; i < 6; i++)
    {
        for (k = 0; k < 6; k++){
        if (vetor2[i] == vetor[k])
        {
            contador++;
        }
        }         
    }
    return contador;
}
    
    
int main () {
    int quadra = 0, sena = 0, quina = 0;
    int vetorsorteado[5];
    int vetorescolhido[5];
    
    int numerossorteados;
    int numroescolhido;
    
    int numerospresentes = 0;
    
    int i;
    int quantidadeapostas;
    
    for ( i = 0; i < 6;i++)
    {
        scanf("%d", &numerossorteados);
        vetorsorteado[i] = numerossorteados;
    }
    scanf("%d", &quantidadeapostas);  
    
    while (quantidadeapostas--)
        {
        for (i = 0; i < 6; i++)
        {
            scanf("%d", &numroescolhido);
            vetorescolhido[i] = numroescolhido;
        }
        
        numerospresentes = verificando(vetorsorteado, vetorescolhido);
        if (numerospresentes == 5) {
            quina++;
        }
        if (numerospresentes == 4) {
            quadra++;
        }
        if (numerospresentes == 6) {
            sena++;
        }
    
    }
    
    if (sena == 0) {
        printf("Nao houve acertador para sena\n");
    } else {
        printf("Houve %d acertador(es) da sena\n", sena);
    }
    if (quina == 0) {
        printf("Nao houve acertador para quina\n");
    } else {
        printf("Houve %d acertador(es) da quina\n", quina);
    }
        if (quadra == 0) {
        printf("Nao houve acertador para quadra\n");
    } else {
        printf("Houve %d acertador(es) da quadra\n", quadra);
    }
    
    
    return 0;
}
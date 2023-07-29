#include <stdio.h>
#include <stdlib.h>
int mergei (int *vetor, int inicio, int meio, int fim) {
    int i = 0;
    int letf[meio];
    int right[fim-meio];
    for (i = 0; i < meio; i++)
    {
        letf[i] = vetor[i]; 
    }
    for (i = meio; i < fim; i++)
    {
        right[i] = vetor[i]; 
    }
    
}
int merge (int *vetor, int inicio , int fim) {
    int meio;
    if (fim - inicio >1)
    {
        meio = (fim + inicio)/2;
        merge(vetor, inicio, meio);
        merge(vetor, meio, fim);
        mergei(vetor, inicio, meio, fim);
    
    }
    
}
int main () {
    int tamanho01 =0;
    int tamanho02 =0;
    int aux = 0;
    int inicio = 0;
    int valor;
    int i = 0, k = 0;
    int *vet;
    int tamanhototal =0;
    scanf("%d %d", &tamanho01, &tamanho02);
    tamanhototal = tamanho01 + tamanho02;
    
    vet = (int *)(calloc(tamanhototal, sizeof(int)));
    
    for ( i = 0; i < tamanhototal; i++)
    {
        scanf("%d", &valor); 
        vet[i] = valor;
    }
    for ( i = 0; i < tamanhototal; i++)
    {
        for ( k = 0; k < tamanhototal-1; k++)
        {
            
            if (vet[k] > vet[k+1])
            {
                aux = vet[k];
                vet[k] = vet[k+1];
                vet[k+1] = aux;
            }
            
        }
        
    }
    
    for (i = 0; i < tamanhototal; i++)
    {
        if (vet[i] == vet[i+1])
        {
            continue;
        }
        else{
        printf("%d\n", vet[i]);}
    }
    
    //merger(vet, inicio, tamanhototal);
    
    return 0;
}
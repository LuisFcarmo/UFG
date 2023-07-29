#include<stdio.h>
int main () {
    int vetanao[9];
    int valoranao = 0, acumulador = 0,  axiliar = 0, indice0 =0, indice1 = 0;
    int diferenca = 0;
    int verificador = 0; 
    int i = 0, k = 0;
    int casoteste = 0;
    scanf("%d", &casoteste);
    while (casoteste--)
    {
        acumulador = 0, axiliar =0, indice0 =0, indice1 =0;
    for (i = 0; i < 9; i++)
    {
        scanf("%d", &valoranao);
        vetanao[i] = valoranao;
    }
    for (i = 0; i < 9; i++)
    {
        acumulador += vetanao[i];
    }
    for (i = 0; i < 9; i++)
    {
        for (k = 0; k < 9-1; k++)
        {
            if(vetanao[k] > vetanao[k+1]) {
                axiliar = vetanao[k];
                vetanao[k] = vetanao[k+1];
                vetanao[k+1] = axiliar;
            }
        }
        
    }
    
    diferenca = acumulador-100;
    for (i = 0; i < 9; i++)
    {
        for (k = 0; k < 9; k++)
        {
            if (vetanao[i] != vetanao[k])
            {
                verificador = vetanao[i] + vetanao[k];
                if(verificador == diferenca) {
                    indice0 = i;
                    indice1 = k;
                }
            }
    
        }
        
    }
    
    for (i = 0; i < 9; i++)
    {
        if (i == indice0 || i == indice1)
        {
            continue;
        }
        else{
        printf("%d\n", vetanao[i]);}
        
    }
    }
    
    return 0;
}
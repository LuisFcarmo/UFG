#include <stdio.h>
#include <stdlib.h>

int printvet (int *vet, int tamanho) {
    printf("(");
    for(int i = 0; i < tamanho; i++) {
        printf("%d-", vet[i]);
    }
    printf(")");
}
/*
int pot (int numero, int base) {
    if (base == 0) return 1;
    else return numero*pot(numero, base-1);
}*/

int invert (int *vet, int inicio, int fim) {
    if (inicio < fim) {
        int i = vet[inicio];
        vet[inicio] = vet[fim-1];
        vet[fim-1] = i;

        invert(vet, inicio+1, fim-1);
    } else {
        return 0;
    }
}

int bin (int numero) {
    if (numero == 0) {
        printf("%d", numero);
        return 0;
    }
    bin(numero/2);
    printf("%d", numero%2);   
}

int farejadora(int numero, int buscar) {
    int cont = 0;
    
    if (numero == 0) return cont;
    if (buscar == numero%10) cont++;
    numero = numero/10;
    
    cont += farejadora(numero, buscar);


    return cont;
};


int main () {
    int op = 0;
    while (1)
    {
        printf("\nProgramas disponíveis\n"
                "1 inverter vetor\n"
                "2 contar frequência de um numero\n"
                "3 converter binario\n");
        scanf("%d", &op);
        if(op == 1) {
            int *vetor = NULL;
            int tamanho = 0;
            int init = 0;
            scanf("%d", &tamanho);

            vetor = (int*) malloc(tamanho*sizeof(int));

            for(int i = 0; i < tamanho; i++) {
                scanf("%d", &vetor[i]);
            }

            invert(vetor, init, tamanho);
            printvet(vetor, tamanho);
        }
        if (op == 2) {
            int numero;
            int buscar;
            int vezes;
            scanf("%d", &numero);
            scanf("%d", &buscar);
            vezes = farejadora(numero, buscar);

            printf("quantidade de vezes que o %d aparece %d\n",numero , vezes);
        }
        if (op == 3) {
            int numero;
            scanf("%d", &numero);
            printf("(");
            bin(numero);
            printf(")");
        }
    }
    return 0;
}
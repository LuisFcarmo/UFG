#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *vetor, int elemento1, int elemento2) {
    int aux = vetor[elemento1];
    vetor[elemento1] = vetor[elemento2];
    vetor[elemento2] = aux;
    return;
}

void imprimir(int *vetor, int inicio, int fim) {
    for (int i = inicio; i < fim; i++) {
        printf("%d ", vetor[i]);
    }
}
/*
    melhorando o pior caso aqui vamos escolher o pivo aleatoriamente ou usando uma mediana pois isso evita o pior caso
    quando o veter está ordenado particionando em dois sub vetores de tamanhos 0 e n-1 respectivamente 
*/


/*
    Se escolhermos o pivot aleatoriamente, qual a probabilidade dele ser o primeiro e, por consequência, o pior? p=1/n certo? 
    Para cairmos no pior caso adotando essa estratégia teríamos que escolher sempre o pior pivot, 
    cuja probabilidade seria dada por p=1/n∗1/(n−1)∗1/(n−2)…. 
*/

int rand_pivot(int inicio, int fim) {
    int pivo_indice = (rand () % (fim - inicio) + 1) + inicio;
    return pivo_indice;
}

/*
    implementação do quick sort usando a lógica de partição de lomotu 
    começando o pivo sempre no começo e colocando os valores maiores na frente do pivo quebrando sempre em duas sub repartições
*/
int particiona(int *vetor, int inicio, int fim) {
    int rand_pivot_index = rand_pivot(inicio, fim);
    swap(vetor, inicio, rand_pivot_index);


    int pivo = vetor[inicio];
    int i = inicio;

    for (int k = inicio+1; k <= fim; k++) {
        if (vetor[k] <= pivo) {
            i++;
            //faz a troca dos valores que são menores que o pivo
            swap(vetor, i, k);
        }
    }     
    //troca o valor do pivo com o ultimo item menor que ele
    //exemplo 4 1 2 3 6 7 -> 3 1 2 4 6 7 o ultimo valor menor que ele foi o 3
    swap(vetor, inicio, i);
    return i;
}


void quicksort_Lomuto(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particiona(vetor, inicio, fim);
        quicksort_Lomuto(vetor, inicio, pivo-1);
        quicksort_Lomuto(vetor, pivo+1, fim);
    }
}

void merge (int *vetor, int inicio, int meio, int fim) {
    int *vetor_aux = (int*)malloc((fim - inicio + 1) * sizeof(int));   
  
    for (int i = inicio; i <= fim; i++) {
        vetor_aux[i - inicio] = vetor[i];
    }

    int i = inicio;
    int j = meio + 1;
    int k = inicio;

    while (i <= meio && j <= fim) {
        if (vetor_aux[i - inicio] <= vetor_aux[j - inicio]) {
            vetor[k] = vetor_aux[i - inicio];
            i++;
        } else {
            vetor[k] = vetor_aux[j - inicio];
            j++;
        }
        k++;
    }

    while (i <= meio) {
        vetor[k] = vetor_aux[i - inicio];
        i++;
        k++;
    }

    while (j <= fim) {
        vetor[k] = vetor_aux[j - inicio];
        j++;
        k++;
    }
    free(vetor_aux);
}


void merge_sort(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim)/2;
        merge_sort(vetor, inicio, meio);
        merge_sort(vetor, meio+1, fim);
        merge(vetor, inicio, meio, fim);    
    } 
}

int main () {
    clock_t t;
    int f;

    int qtd = 1e5;
    int total = qtd;
    int *vetor;
    vetor = (int*) malloc(qtd*sizeof(int));

    for (int i = 0; i < qtd; i++) {
        vetor[i] = total;
        total--;
    }

    
    
    printf("\n");
    printf("pior caso do quick sort comparado com o merge sort\n");
    t = clock();
    quicksort_Lomuto(vetor, 0, qtd-1);
    t = clock() - t;
    printf ("It took me %ld clicks (%f seconds) <- quicksort.\n",t,((float)t)/CLOCKS_PER_SEC);
    t = clock();
    merge_sort(vetor, 0, qtd-1);
    t = clock() - t;
    printf ("It took me %ld clicks (%f seconds) <-- mergesort.\n",t,((float)t)/CLOCKS_PER_SEC);

    printf("quick sort comparado com o merge sort\n");
    for (int i = 0; i < qtd; i++) {
        vetor[i] = total;
        total--;
    }
    t = clock();
    quicksort_Lomuto(vetor, 0, qtd-1);
    t = clock() - t;
    printf ("It took me %ld clicks (%f seconds) <- quicksort.\n",t,((float)t)/CLOCKS_PER_SEC);
    t = clock();
    merge_sort(vetor, 0, qtd-1);
    t = clock() - t;
    printf ("It took me %ld clicks (%f seconds) <-- mergesort.\n",t,((float)t)/CLOCKS_PER_SEC);

    free(vetor);
    
    return 0;
}
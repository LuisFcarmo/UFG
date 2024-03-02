#include <stdio.h>
#include <stdlib.h>

void swap(int array[], int i, int k) {
    int aux = array[i];
    array[i] = array[k];
    array[k] = aux;
}

void selection_sort(int array[], int max) {
    int menor_indice = 0;
    for (int i = 0; i < max; i++) {
        menor_indice = i;
        for (int k = i+1; k < max; k++) {
            if (array[i] >= array[k]) {
                menor_indice = k;
            }
        }
        swap(array, i, menor_indice);
    }
}
/*
    complexidade
    melhor caso O(n²)
    caso medio O(n²)
    pior caso O(n²)
*/
void insertion_sort (int array[], int max) {
    for (int i = 1; i < max; i++) {
        int parametro = i;
        while (parametro > 0 && array[parametro] <= array[parametro-1]) {
            swap(array, parametro, parametro-1);
            parametro--;
        }
    }
}
/*
    complexidade
    melhor caso O(n²)
    caso medio O(n²)
    pior caso O(n²)
*/

void booble_sort (int vetor[], int max) {
    for (int i = 0; i < max; i++) {
        for (int k = i+1; k < max; k++) {
            if (vetor[i] >= vetor[k]) {
                swap(vetor, i, k);
            }
        }
    }
}

/*
    quick sort 
    melhor caso n log (n)
    caso medio n log (n)
    pior caso O(n²)
*/
int particion (int vetor[], int left, int rigth) {
    int pivot = vetor[left];
    int indice = left;
    for (int j = left + 1; j <= rigth; j++) {
        if (vetor[j] <= pivot) {
            indice++;
            swap(vetor, indice, j);
        }
    }
    swap(vetor, left, indice);
    return indice;
}

void quicksort (int vetor[], int left, int rigth) {
    if (left < rigth) {
        int pivot = particion(vetor, left, rigth);
        quicksort(vetor, left, pivot-1);
        quicksort(vetor, pivot+1, rigth);
    }
}

void merge(int *v, int left, int meio, int right) {
    int *vet_aux = (int*)malloc(sizeof(int) * (right - left + 1));

    int i = left;
    int j = meio + 1;
    int k = 0;

    while (i <= meio && j <= right) {
        if (v[i] <= v[j]) {
            vet_aux[k++] = v[i++];
        } else {
            vet_aux[k++] = v[j++];
        }
    }

    while (i <= meio) {
        vet_aux[k++] = v[i++];
    }

    while (j <= right) {
        vet_aux[k++] = v[j++];
    }

    // Copia os elementos ordenados de volta para o vetor original
    for (int p = 0; p < k; p++) {
        v[left + p] = vet_aux[p];
    }

    free(vet_aux);
}

void merge_sort(int *v, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        merge_sort(v, left, middle);
        merge_sort(v, middle + 1, right);

        merge(v, left, middle, right);
    }
}

void exibir(int vetor[], int max) {
    for (int i = 0; i < max; i++) {
        printf("%d -", vetor[i]);
    }
}

int main () {
    //ordene esse array;
    int *vetor = (int*) malloc(sizeof(int)*10);
    int total = 10;
    for (int i = 0; i < 10; i++) {
        vetor[i] = total--;
    }
   // insertion_sort(vetor, 10);
    merge_sort(vetor, 0, 9);
    exibir(vetor, 10);



    return 0;
}
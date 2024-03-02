#include <stdio.h>
#include <stdbool.h>
//busca linear classica
//complexidade O(n²)
int twoSumBruteForce (int *v, int n, int alvo) {
    int i, j;
    for (int i = 0; i < n; i++) {
        for (j = 1 + 1; j < n; j++) {
            if (v[i] + v[j] == alvo) {
                return 1;
            }
        }
    }
    return 0;
}

//complexidade O(n²)
//busca linear pelo complemento;
int towSumLinearSearch(int *v, int n, int alvo) {
    int i, j;
    int compl;
    for (int i = 0; i < n-1; i++) {
        //aqui eu acho o resto ou seja o complemento necessario para encontrar o alvo
        compl = alvo - v[i];
        for (j = 1 + 1; j < n; j++) {
            if (v[j] == compl) {
                return 1;
            }
        }
    }
    return 0;
}

int binary_shearch(int *vetor, int comeco, int fim, int buscando) {
    if (comeco <= fim) {
        int meio = (comeco+fim)/2;
        int chute = vetor[meio];
        if (chute == buscando) return meio;
        else if (chute > buscando) {
            fim = meio-1;
            binary_shearch(vetor, comeco, fim, buscando);
        }
        else {
            comeco = meio+1;
            binary_shearch(vetor, comeco, fim, buscando);
        }
    } else {
        return -1;
    }

}
//complexidade n log (n);
int towSumBinarySearch(int *v, int n, int alvo) {
    int i, j;
    int compl;
    sort(v, n);
    for (int i = 0; i < n-1; i++) {
        //aqui eu acho o resto ou seja o complemento necessario para encontrar o alvo
        compl = alvo - v[i];
        if(binarySearch(v, n, compl)) {

        }
    }
    return 0;
}

int main () {
    int size;
    int *array;
    scanf("%d", size);
    array = (int*) malloc(sizeof(int)*size);
    
    twoSumBruteForce(array, size, 2);

    return 0;
}
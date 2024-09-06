#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

void selection_sort(std::vector <int> &arry, int max) {
    int aux = 0;
    int j = 0;

    for (int i = 0; i < max; i++) {
        aux = arry[i];
        j = i-1;

        while (j >= 0 && arry[j] >= aux) {
            arry[j + 1] = arry[j];
            j--;
        };
        arry[j+1] = aux;
    }

    return;
}

void booble_sort(std::vector <int> &arry, int max) {
    int aux;
    for (int i = 0; i < max-1; i++) {
        for (int j = i + 1; j < max; j++) {
            if (arry[i] >= arry[j]) {
                aux = arry[j];
                arry[j] = arry[i];
                arry[i] = aux;
            }
        }
    }
}

int busca_sequencia(std::vector <int> arry, int numero) {
    for (int i = 0; i < arry.size(); i++) {
        if (arry[i] == numero) {
            return i;
        }
    }
    return -1;
}   

int busca_binaria (std::vector <int> arry, int l_e, int l_d, int buscar) {
    if (l_e <= l_d) {
        int c = l_e + ((l_d-l_e)/2);
        if (arry[c] == buscar) return c;
        if (arry[c] < buscar) {
            return busca_binaria(arry, c + 1, l_d, buscar);
        }
        else {
            return busca_binaria(arry, l_e, c-1, buscar);
        }
    }
    return -1;
}

void exibir (std::vector <int> vetor) {
    for (int i = 0; i < vetor.size(); i++) {
        std::cout << vetor[i];
        std::cout << "\n";
    }
}

int rd (int max) {
    return rand()%max;
}

int main () {
    int max = 1e5;
    int aux = 0;
    clock_t t;
    srand(time(NULL));
    int i = max;
    std::vector <int> vetor(i);
    std::vector <int> vetor1(i);

    for (int k = 0; k < i; k++) {
        vetor[k] = rd(max);
    }

    std::cout << "vetor1" << "\n";
    t = clock();
    selection_sort(vetor, i);
    t = clock() - t;
    std::cout << "quantidade segundos levados pelo selection sort " <<  ((float)t)/CLOCKS_PER_SEC << "s\n" << "para ordernar um vetor de 100000 elementos";
    std::cout << "\n";

    t = clock();
    booble_sort(vetor, i);
    t = clock() - t;
    std::cout << "quantidade segundos levados pelo booble sort sorte " <<  ((float)t)/CLOCKS_PER_SEC <<"s\n" << "para ordernar um vetor de 100000 elementos";
    std::cout << "\n";
        
    std::cout << "vetor2" << "\n";

    float total = 0;
    for (int i = 0; i < 1001; i++) {
        t = clock();
        aux = vetor[rd(max)];
        busca_binaria(vetor, 0, max-1, aux);
        t = clock() - t;
        total += ((float)t)/CLOCKS_PER_SEC;
    }

    std::cout << "tempo levado para busca binaria buscando 1000 mil itens " << total << " s";
    total = 0;
    for (int i = 0; i < 1001; i++) {
        t = clock();
        aux = vetor[rd(max)];
        busca_sequencia(vetor, aux);
        t = clock() - t;
        total += ((float)t)/CLOCKS_PER_SEC;

    }
    std::cout << "tempo levado para busca sequêncial buscando 1000 mil itens " << total << " s";
    /*
        vetor1
        quantidade segundos levados pelo selection sort 10.6836s
        para ordernar um vetor de 100000 elementos
        quantidade segundos levados pelo booble sort sorte 14.6439s
        para ordernar um vetor de 100000 elementos
        
        tempo levado para busca sequêncial buscando 10000 mil itens 2.82957 s
        tempo levado para busca binaria buscando 1000 mil itens 0.163419 s

        //aqui fica claro a efiência da busca binaria conforme a entrada cresce a busca binaria vai levar bem menos tempo
        que a sequêncial

    */
}
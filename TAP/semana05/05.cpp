#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
typedef struct {
    int inicio;
    int fim;
} intervalos;

void cria_intervalos (intervalos *vet, vector <int> valores) {
    int anterior = 0;
    int atual = 0;

    for (int i = 0; i < valores.size(); i++) {
        vet[i].inicio = anterior+1;

        vet[i].fim = valores[i]+anterior;
        
        anterior = vet[i].fim;
    }
}

void buscar_pilha (intervalos *vet, int valor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (valor >= vet[i].inicio && valor <= vet[i].fim) {
            printf("%d\n", i+1);
        }
    }
}

int main () {
    int qtd;
    int qtd_buscar;
    int valor;
    cin >> qtd;

    intervalos *vet_intervalos;
    vector <int> valores(qtd);

    vet_intervalos = (intervalos*) malloc(qtd*sizeof(intervalos));

    for (int i = 0; i < qtd; i++) {
        cin >> valores[i];
    }

    cin >> qtd_buscar;

    cria_intervalos(vet_intervalos, valores);

    while(qtd_buscar){
        cin >> valor;
        buscar_pilha(vet_intervalos, valor, qtd);
        qtd_buscar--;
    }

    return 0;
}
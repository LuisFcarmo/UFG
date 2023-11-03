#include <iostream>
#include <stdlib.h>

#include <vector>

typedef struct
{
  char valor;
  bool visitados;
} setas;

using namespace std;
int validos = 0;
bool teste;

void percorre (setas ** pista, int tamanho, int ic_atual, int il_atual) {     

        if(ic_atual < 0 || ic_atual == tamanho || il_atual < 0 || il_atual == tamanho){
            return;
        }

        if (pista[il_atual][ic_atual].visitados == true) {
            teste = true;
            validos++;
            return;
        }
        pista[il_atual][ic_atual].visitados = true;


        switch (pista[il_atual][ic_atual].valor)
        {
        case 'A':
            il_atual--;
            break;
        case 'V':
            il_atual++;
            break;
        case '>':
            ic_atual++;
            break;
        case '<':
            ic_atual--;
            break;
        }

    percorre(pista, tamanho, ic_atual, il_atual);
}

void controle (setas ** pista, int tamanho, int ic_atual, int il_atual) {
    teste = false;
    if (ic_atual >= tamanho) {
        ic_atual = 0;
        il_atual += 1;
    }

    if (il_atual >= tamanho) return;

    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            pista[i][j].visitados = false;
        }
    }

    percorre(pista, tamanho, ic_atual, il_atual);


    controle(pista, tamanho, ic_atual+1, il_atual);
}

int main () {
    int tamanho;
    int ic_atual;
    int il_atual;
    int invalidos;

    setas **pista;
    cin >> tamanho;
    vector<vector<setas>> pista2(tamanho, vector<setas>(tamanho));
    
    pista = (setas**) malloc(sizeof(setas)*tamanho);

    for (int i = 0; i < tamanho; i++) {
        pista[i] = (setas*) malloc(sizeof(setas)*tamanho);
    }

    for (int i = 0; i < tamanho; i++) {
        for (int k = 0; k < tamanho; k++) {
        cin >> pista[i][k].valor;
        }
    }
    controle(pista, tamanho, 0, 0);

    for (int i = 0; i < tamanho; i++) {
        free(pista[i]);
    }
    free(pista);

    printf("%d\n", validos);

  return 0;
}
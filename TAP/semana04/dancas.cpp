#include "iostream"
#include "stdlib.h"
using namespace std;
typedef struct {
    char valor;
    bool visitei;
} pista;

int caminho (pista **pista, int tamanho, int linhaat, int colunat) {
    int contador = 0;

    while (1) {
        if(pista[linhaat][colunat].visitei ==  true)  {
            cout << "-----";
            return contador;
        }
        pista[linhaat][colunat].visitei = true;

        if (pista[linhaat][colunat].valor == 'V') {
            linhaat += 1;
            if (linhaat > tamanho-1) return 0;
        }
        if (pista[linhaat][colunat].valor == '<') {
            colunat -= 1;
            if (colunat < 0) return 0;
        }
        if (pista[linhaat][colunat].valor == '>') {
            colunat += 1;
            if (colunat > tamanho-1) return 0;
        }
        if (pista[linhaat][colunat].valor == 'A') {
            linhaat -= 1;
            if (colunat < 0) return 0;
        }
        contador++;
         for (int i = 0; i < tamanho; i++) {
        for (int k = 0; k < tamanho; k++) {
            cout << pista[i][k].visitei;
        }
        cout << endl;
    }
        cout << endl;
    }        
}

void lermatriz (pista **pista, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int k = 0; k < tamanho; k++) {
            cin >> pista[i][k].valor;
        }
    }
}

int main () {
    int tamanho = 0;
    int validos = 0;
    pista **pd;

    cin >> tamanho;
    //*pd = (**pista) malloc(tamanho*sizeof(*pista));
    pd = (pista**) malloc(tamanho*sizeof(pista*));

    for (int i = 0; i < tamanho; i++) {
        pd[i] = (pista*) malloc(tamanho*sizeof(pista));
    }

    lermatriz(pd, tamanho);

    for (int i = 0; i < tamanho; i++) {
        for (int k = 0; k < tamanho; k++) {
            if (pd[i][k].visitei == false) {
                validos += caminho(pd, tamanho, i, k);
            }
            else continue;
        }
    }   
   


    /*for (int i = 0; i < tamanho; i++) {
        for (int k = 0; k < tamanho; k++) {
            cout << pd[i][k].visitei;
        }
        cout << endl;
    }*/
    cout << validos;

    

    return 0;
}
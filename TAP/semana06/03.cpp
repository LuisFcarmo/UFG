#include <stdio.h>
#include <iostream>
using namespace std;

bool odd_number (int numero) {
    int contador = 1;
    int qtd = 0;
    while (contador <= numero) {
        if(numero % contador == 0) {
            qtd++;
        }
        contador++;
    }
    if (qtd == 8) return true;
    else return false;
}

int main () {
    int numero;
    bool resp = false;
    int contador = 0;
    cin >> numero;

    for (int i = 105; i <= numero; i++) {
        if(i % 2 != 0) {
            resp = odd_number(i);
            if (resp == true) contador++;
            resp = false;
        }
    }

    cout << contador << endl;
}
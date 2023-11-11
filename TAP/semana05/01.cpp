#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;


int main () {
    long long int numero = 0;
    long long int valor = 1, contador = 0;

    cin >> numero;

    while (valor <= numero) {
        valor *= 2;
        contador++;
    }

    cout << contador-1;
}   
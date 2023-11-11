#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

int meu_log (int numero, int base) {
    int valor = 1, contador = 0;
    while (valor <= numero) {
        valor *= base;
        contador++;
    }
    return contador;
}

int main () {
    int numero;
    int base;
    int maior;
    
    vector <double> lista(0);

    cin >> numero >> base;
    /*
    while (numero != 0) {
        lista.push_back(numero%10);
        numero = numero/10;
    }
   
    sort(lista.begin(), lista.end());
    maior = lista[lista.size()-1];
    cout << maior << endl;*/

    cout << meu_log(numero, base);

    return 0;
}
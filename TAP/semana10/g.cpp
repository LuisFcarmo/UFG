#include <iostream>
#include <string>
using namespace std;
int numbs (int numero) {
    int qtd = 0;
    while (numero != 0) {
        if (numero % 10 == 4) {
            qtd++;
        }
        if (numero % 10 == 7) {
            qtd++;
        }
        numero /= 10;
    }
    return qtd;
}


int main(){
    int valor;
    int qtd;
    int max;
    int total = 0;

    cin >> qtd >> max;
    for (int i = 0; i < qtd; i++) {
        cin >> valor;
        if (numbs(valor) <= max) {
            total++;
        }
    }
    cout << total;
    
    return 0;
}
#include <iostream>
using namespace std;
void prime (int numero) {
    int contador = 0;
    int qtd = 0;
    while (contador <= numero) {
        contador++;
        if(numero % contador == 0) {
            qtd++;
        }
        if(qtd > 2) break;
    }
    if (qtd == 2) { 
        cout << "yes" << endl;
        return;
    } else {
        cout << "no" << endl;
        return;
    }
}
int main () {
    int qtd;
    int numero;
    cin >> qtd;
    while(qtd--) {
        cin >> numero;
        prime(numero);
    }


    return 0;
}
#include <iostream>
using namespace std;
bool prime (int numero) {
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
        return true;
    } else {
        return false;
    }
}

bool divisores (int numero) {
    int divisor = 1;
    int qtd = 0;
    bool resp;
    while (divisor <= numero) {
        if (numero % divisor == 0) {
            resp = prime(divisor);
            if (resp == true) {
                qtd++;
            }
        }
        divisor++;
    }
    if (qtd == 2) {
        return true;
    } else {
        return false;
    }
}

int main () {
    int qtd = 0;
    int contador = 0;
    int numero;
    bool resp = false;

    cin >> qtd;
    
    for (int i = 0; i <= qtd; i++) {
        resp = divisores(i);
        if (resp == true) {
            contador++;
        }
        resp = false;
    }
    cout << contador << endl;

    return 0;
}
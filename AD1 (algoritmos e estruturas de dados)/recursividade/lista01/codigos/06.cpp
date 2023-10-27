#include "iostream"
using namespace std;

int fat (int numero) {
    if (numero == 1 || numero == 0) return 1;
    if (numero % 2 != 0) {
        return numero*fat(numero-1);
    } else {
        return fat(numero-1);
    }

}

int main () {
    int termo = 0;
    int valor = 0;
    cin >> termo;
    valor = fat (termo);
    cout << valor;

    return 0;
}
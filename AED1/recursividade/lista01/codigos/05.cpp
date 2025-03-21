#include "iostream"
using namespace std;
void bin (int numero) {
    if (numero == 0)  {
        printf("%d", numero);
        return;
    }
    else if (numero == 1) {
        printf("%d", numero%2); 
        return;
    }
    else if (numero > 1) {
        bin(numero/2);
        printf("%d", numero%2);
    }
}

int main () {
    int qnumeros;
    int numero;
    cin >> qnumeros;
    for (int i = 0; i < qnumeros; i++) {
        cin >> numero;
        bin(numero);
    }
    return 0;
}
#include <iostream>
using namespace std;
void bin (int numero) {
    if (numero == 0) {
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
    return;
}
int main () {
    int numero;
    int qtd;
    cin >> qtd;
    while(qtd--){
        cin >> numero;
        bin(numero);
        cout << endl;
    }

    return 0;
}
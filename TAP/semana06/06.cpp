#include <iostream>
#include <math.h>
using namespace std;
// Função para contar o número de divisores de um número
int countDivisors (int numero) {
    if(numero == 1) return 1;
    int c;
    c = 2;
    for(int i=2; i<((int)floor(sqrt(numero)))+1; i++) {
    if(numero % i == 0){
        c += (numero/i == i) ? 1 : 2;
    }
    }
    return c;
}

int main () {
    int qtd;
    int valor;
    int qtd2;
    cin >> qtd;
    while(qtd--) {
        cin >> valor;
        qtd2 = countDivisors(valor);
        cout << qtd2 << endl;
    }

    return 0;
}
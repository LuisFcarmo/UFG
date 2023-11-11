#include <iostream>
using namespace std;

long long modulo = 1e9+7;

long long medpot (int x, int y) {
    if (y == 0) return 1;

    long long u = medpot(x, y/2);
    u = (u%modulo * u%modulo)%modulo;

    if (y%2 == 1) 
        u = ((u%modulo) * (x%modulo)) %modulo;
    return u;
}

int main () {
    int qtd;
    int numero;
    int expoente;
    cin >> qtd;
    while (qtd--) {
        cin >> numero;
        cin >> expoente;
        cout << medpot(numero, expoente) << '\n';
    }



    return 0;
}

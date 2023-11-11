#include <iostream>
using namespace std;

long long medpot (long long int x, long long int y, long long int modulo) {
    if (y == 0) return 1;

    long long u = medpot(x, y/2, modulo)%modulo;
    u = (u * u)%modulo;

    if (y%2 == 1) 
        u = (u * x) %modulo;
    return u%modulo;
}

int main () {
    long long int modulo = 1000000007;
    long long int qtd;
    long long int numero;
    long long int expoente;
    long long int expoente2;
    cin >> qtd;
    while (qtd--) {
        cin >> numero;
        cin >> expoente;
        cin >> expoente2;
        cout << medpot(numero, medpot(expoente, expoente2, modulo-1), modulo) << '\n';
    }



    return 0;
}
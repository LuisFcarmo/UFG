#include <iostream>
using namespace std;
const long long mod = 10;
long long pot (int numero, int expoente) {
    long long resp1 = 0;
    if (expoente == 0) return 1;

    resp1 = pot ((numero%mod), expoente >> 1)%mod;

    if (expoente % 2 == 0) {
        return (resp1%mod * resp1%mod)%mod;
    } else {
        return ((resp1%mod*resp1%mod*numero%mod) %mod)%mod;
    }

} 

int main () {
    int expoente;
    int numerador;
    int acumulador;
    int teste;
    cin >> teste;
    while (teste) {
        cin >> numerador >> expoente;
        acumulador = pot(numerador, expoente);
        cout <<  acumulador << endl;
        teste--;
    }

    return 0;
}

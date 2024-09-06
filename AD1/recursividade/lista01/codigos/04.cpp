#include "iostream"
using namespace std;
void refat (int numero, bool verifica = false) {
    if(numero == 0) return;

    if(numero % 10 == 0 && verifica == false){
        refat(numero/10, false);
        return;
    }
    cout << numero%10;
    refat(numero/10, true);
}   

int main () {
    int numero = 0;
    cin >> numero;
    refat(numero);
}
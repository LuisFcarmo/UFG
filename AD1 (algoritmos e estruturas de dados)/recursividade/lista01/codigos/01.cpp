#include "iostream"
void print (int n) {
    //passo base para parar o algoritmo
    if (n == 0) return;
    else {
        print(n -1);
        printf("%d ", n);
    }
}
using namespace std;

int main () {
    int numero;
    cin >> numero;
    print(numero);
}
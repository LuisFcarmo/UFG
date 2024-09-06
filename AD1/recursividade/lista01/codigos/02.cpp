#include "iostream"
using namespace std;
int fibo (int numero) {

    if(numero == 0){
        cout << "Falha de segmentação." << endl;
    }
    if (numero == 1) {
        return 0;
    }
       
    else if (numero == 2) {
        return 1;
    }

    else {
        return fibo(numero-1) + fibo(numero-2);
    }
}
void chama (int termo, int atual) { 
    cout << fibo(atual) << endl;
    if(atual < termo) chama(termo, atual+1);

}
using namespace std;
int main () {
    int numero;
    cin >> numero;
    chama(numero, 1);
}
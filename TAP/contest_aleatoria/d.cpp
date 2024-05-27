#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main () {
    vector <int> array;
    map <int, int> mapa;
    int qtd;
    int valor;
    int chute;
    cin >> qtd >> chute;
    for (int i = 0; i < qtd; i++) {
        cin >> valor;
        array.push_back(valor);
        mapa.insert(make_pair(valor, i + 1));
    }
    sort(array.begin(), array.end());
    int end = array.size()-1;
    int init = 0;  
   
    int i, j;
    int compl;

    for (int i = 0; i < qtd-1; i++) {
        //aqui eu acho o resto ou seja o complemento necessario para encontrar o alvo
        compl = chute - array[i];
        for (j = 1 + 1; j < qtd; j++) {
            if (array[j] == compl) {
                return 1;
            }
        }
    }
    if (end == init) {
        cout << "IMPOSSIBLE\n";
        return 0;
    };
    if (mapa[array[init]] > mapa[array[end]]) {
        cout << mapa[array[end]] << " " << mapa[array[init]];
    }
        return 0;
}

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
int buscar (vector <int> vetor1, int numero) {
    
    for (int i = 0; i < vetor1.size(); i++) {
        if (vetor1[i] == numero) {
            return i+1;
        }
    }
    return 0;
}

int main () {   
    int q1, q2;
    int achou;
    int qcasos = 1;
   
    while (1) {
        cin >> q1 >> q2;
        if (q1 == 0 && q2 == 0) break;

        vector <int> vetor1(q1);
        vector <int> vetor2(q2);

        for (int i = 0; i < q1; i++) {
            cin >> vetor1[i];
        }
        for (int k = 0; k < q2; k++) {
            cin >> vetor2[k];
        }
                sort(vetor1.begin(),vetor1.end());

        cout << "CASE# " << qcasos << ":" << endl;
        for (int o = 0; o < q2; o++) {
            achou = buscar(vetor1, vetor2[o]);
            if (achou != 0) {
                cout << vetor2[o] << " found at " << achou << endl; 
            } else {
                cout << vetor2[o] << " not found" << endl;
            }
        }
        qcasos++;
    }
    return 0;
}
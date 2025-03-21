#include "iostream"
#include "vector"
using namespace std;
int main () {
    int numeropessoas = 0;
    int linhas = 0;
    int pai = 0;
    int filho = 0;
    int totallinhas;
    int totalfamilias = 0;
    cin >> totalfamilias;
    cin >> totallinhas;
    vector <int> vetor(totalfamilias);

    for (int i = 0; i < totallinhas; i++) {
        cin >> pai;
        cin >> filho;
        vetor[pai] = filho;
        vetor[filho] = pai;
    }
    for (int i = 0; i < vetor.size()-1; i++) {
        cout << vetor[i] << " ";
    }
    for (int i = 0; i < vetor.size()-1; i++) {
        if (vetor[i] != vetor[i+1]) totalfamilias++;
    }
    cout << totalfamilias;


    return 0;
}
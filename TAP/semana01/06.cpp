#include <iostream>
#include <vector>
using namespace std;

vector <long int> pilha (0);

void dfs (vector <vector <long int>> &tree, vector<bool> &boleano, int vertice, int fim) {
    if (boleano[vertice] == true) return; 

    boleano[vertice] = true;

    pilha.push_back(vertice);
    
    if (pilha.back() == fim) {
        for (int i = 0; i < pilha.size(); i ++) {
            if (i != 0) cout << " " << pilha[i];
            else cout << pilha[i];
        }
        return;
    }

    for (int i = 0; i < tree[vertice].size(); i++) {
        dfs(tree, boleano, tree[vertice][i], fim);
    }

    if (pilha.empty() == false) pilha.pop_back();
}

int main () {
    long int qnos = 0;
    long int no1 = 0;
    long int no2 = 0;
    long int init = 0;
    long int end = 0;

    cin >> qnos >> init >> end;
    
    vector <bool> vetorbol (qnos+1);  
    for (int i = 0; i < vetorbol.size(); i++) {
        vetorbol[i] = false;
    }  
    vector <vector<long int>> tree (qnos+1, vector<long int> (0));

    for (int i = 1; i < tree.size() - 1; i++) {
        cin >> no1;
        cin >> no2;
        tree[no1].push_back(no2);
        tree[no2].push_back(no1);
    }
    
    dfs(tree, vetorbol, init, end);

    return 0;
}
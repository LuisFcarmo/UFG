#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m;

    cin >> n;
    vector<int> vet (n);
    for(int i = 0; i < vet.size(); i++){
        int ax;
        if (i == 0) {
            cin >> vet[i];
        }
        else {
            cin >> ax;
            vet[i] = ax + vet[i-1];
        }
    }

    cin >> m;
    vector<int> vet_2 (m);
    for(int i = 0; i < vet_2.size(); i++){
        cin >> vet_2[i];
    }

    for(int i = 0; i < vet_2.size(); i++) {
        cout << (lower_bound(vet.begin(), vet.end(), vet_2[i]) - vet.begin())+1 << endl;
    }


    return 0;
}
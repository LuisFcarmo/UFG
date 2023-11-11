#include <bits/stdc++.h>
using namespace std;

int main () {
    long int t1, t2;
    cin >> t1 >> t2;
    vector <long int> vetor1(t1);
    vector <long int> vetor2(t2);
    for (int i = 0; i < t1; i++) {
        cin >> vetor1[i];
    }

    for (int i = 0; i < t2; i++) {
        cin >> vetor2[i];
    }

    sort(vetor1.begin(), vetor1.end());

    for (int i = 0; i < vetor2.size(); i++) {
        cout << upper_bound(vetor1.begin(), vetor1.end(), vetor2[i]) - vetor1.begin() << " ";
    }

    return 0;
}
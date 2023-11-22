#include <iostream>
using namespace std;
string seq (long long qtd) {
    string s1 = "1";
    
    for (int i = 2; i <= qtd; i++) {
        s1 = s1 + ' ' + to_string(i) + ' ' + s1;
    }
    return s1;
}
int main () {
    int qtd;
    string s;
    cin >> qtd;
    s = seq(qtd);
    cout << s;
}
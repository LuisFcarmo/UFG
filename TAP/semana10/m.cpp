#include <iostream>
#include <string>
using namespace std;


int main(){
    int qtd;
    cin >> qtd;
    string s1;
    while (qtd--) {
        cin >> s1;
        if (s1.length() > 10) {
            cout << s1[0];
            cout << s1.length()-2;
            cout << s1[s1.length()-1];
            cout << "\n";
        }
        else cout << s1 << "\n";
    }
    return 0;
}
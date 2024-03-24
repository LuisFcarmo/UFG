#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1;
    int total;
    cin >> total;
    cin >> s1;

    int SF = 0;
    int FS = 0;

    for (int i = 0; i < s1.length()-1; i++) {
        if (s1[i] == 'S' && s1[i + 1] == 'F') {
            SF++;
        }
        else if (s1[i] == 'F' && s1[i + 1] ==  'S') {
            FS++;
        }
    }
    if (SF > FS) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main() {
   int n, m;
   bool x = false;
   bool verify = true;
   cin >> n >> m;
   for (int i = 0; i < n; i++) {
    for (int k = 0; k < m; k++) {
        if (i % 2 == 0) {
            cout << "#";
        } else {
                if (k == m - 1 && x == false && verify) {
                    cout << "#";
                    x = true;
                    verify = false;
                    continue;
                } 
                else if (k == 0 && x == true && verify) {
                    cout << "#";
                    x = false;
                    verify = false;
                    continue; 
                }
                else {
                    cout << ".";
                }
        }
    }
    verify = true;
    printf("\n");
   }

    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int main () {
    string st;
    int inicio = 0;
    int fim = 0;
    cin >> inicio >> fim;
    cin >> st;

    reverse(st.begin() + inicio-1, st.begin() + fim);

    cout << st;

    return 0;
}
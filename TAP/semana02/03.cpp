#include <stdio.h>
#include <iostream>
using namespace std;
int main () {
    string st;
    int qtd;
    cin >> qtd;

    for (int i = 0; i < qtd; i++) {
        cin >> st;
        if (st == "and" || st == "not" || st == "that" || st == "the" || st == "you") {
            printf("Yes\n");
            return 0;
        }
    }

    printf("No\n");


    return 0;
}
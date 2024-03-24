#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
    string word;
    getline(std::cin, word);
    int qtd1 = 0;
    int qtd2 = 0;
    int qtd3 = 0;
    int total = 0;
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] == '1')
        {
            qtd1++;
        }
        else if (word[i] == '2')
        {
            qtd2++;
        }
        else if (word[i] == '3')
        {
            qtd3++;
        }
    }
    total = qtd1 + qtd2 + qtd3;
    for (int i = 0; i < qtd1; i++){
        total--;
        cout << "1";
        if (total > 0) cout << "+";
    }
    for (int i = 0; i < qtd2; i++) {
        total--;
        cout << "2";
        if (total > 0) cout << "+";
    }
    for (int i = 0; i < qtd3; i++) {
        total--;
        cout << "3";
        if (total > 0) cout << "+";
    }

    return 0;
}
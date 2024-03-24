#include <iostream>
#include <string>
#include <set>
using namespace std;


int main(){
    string word;
    getline(std::cin, word);
    set <char> unicas;
    for (int i = 0; i < word.length(); i++) {
        if ((word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 'a' && word[i] <= 'z')) {
            unicas.insert(word[i]);
        }
    }
    cout << unicas.size();
    return 0;
}
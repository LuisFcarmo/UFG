#include <iostream>
#include <vector>

using namespace std;

int main(){
    long long size_pal, num_key, correto = 0;
    long long sub = 0;
    vector<bool> aval(26 ,false);
    string pal;
    cin >> size_pal >> num_key;
    cin >> pal;
    for(long long c = 0; c < num_key; c++){
        char key;
        cin >> key;
        aval[key - 'a'] = true;
    }

    for(long long c = 0; c < pal.size(); c++){
        if(aval[pal[c] - 'a'] == true){
            correto++;
            if(c == pal.size() - 1){
                sub += (correto * (correto + 1))/2;
            }
        }else{
            sub += (correto * (correto + 1)) / 2;
            correto = 0;
        }   
    }

    cout << sub << "\n";
    return 0;
}
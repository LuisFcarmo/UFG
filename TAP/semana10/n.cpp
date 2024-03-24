#include <iostream>
#include <string>
using namespace std;

std::string toLowerCase(std::string str)
{
    for (char &c : str)
    {
        c = std::tolower(c);
    }
    return str;
}

int main()
{
    int verificador = 0;
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    s1 = toLowerCase(s1);
    s2 = toLowerCase(s2);
    for (int i = 0; i < s1.length(); i++)
    {
         if (s1[i] != s2[i]) {
        
            if (s1[i] > s2[i])
            {
                cout << "1\n";  
                return 0;
            }
            else
            {
                cout << "-1\n";
                return 0;
            }
        }
    }
    
    cout << "0\n";
    

    return 0;
}
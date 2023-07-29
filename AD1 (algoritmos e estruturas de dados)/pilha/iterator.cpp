#include <iostream>
#include <vector>
int main(){
    int tamanho;
    std::cin >> tamanho;
    std::vector<int>vetor(tamanho);
    std::vector<int>::iterator j;

    for(j = vetor.begin(); j != vetor.end(); j++){
        std::cin >> *j;
    }
    for(j = vetor.begin(); j != vetor.end(); j++){
        std::cout << *j << std::endl;
    }

    for (int &i: vetor);

    return 0;
}

#include <stdio.h> 
int main () {
    int A,B,C;
    char x, y,z;
    int maior, menor, meio;
    scanf("%i %i %i\n", &A, &B,&C);
    scanf("%c %c %c", &x, &y, &z);
    
    if (A >= B && B >= C) {
        menor = C;
        maior = A;
        meio = B;
    }
    if (A >= B && C >= B) {
        menor = B;
        maior = A;
        meio = C;
    }
    if (B >= A && A >= C) {
        menor = C;
        maior = B;
        meio = A;
    }
    if (B >= C && C >= A) {
        menor = A;
        maior = B;
        meio = C;
    }
    if (C >= A && A >= B) {
        menor = B;
        maior = C;
        meio = A;
    }
    if (C >= B && B >= A) {
        menor = A;
        maior = C;
        meio = B;
    }
    if (x == 'A' && y=='B' && z=='C') {
        printf("%i %i %i", menor, meio, maior);
    
    }
    if (x == 'A' && y=='C' && z=='B') {
        printf("%i %i %i", menor, maior, menor);
    
    }
    if (x == 'B' && y=='A' && z=='C') {
        printf("%i %i %i", meio, menor, maior);
    
    }
    if (x == 'b' && y=='C' && z=='A') {
        printf("%i %i %i", meio, maior, menor);
    
    }
        if (x == 'C' && y=='A' && z=='B') {
        printf("%i %i %i", maior, menor, meio);
    }
    if (x == 'C' && y=='B' && z=='A') {
        printf("%i %i %i", maior, meio, menor);
    
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
    
void print_bits(void *ptr){
    unsigned char *p = (unsigned char *) ptr;
    unsigned char v = *p;
    int peso = 128;
    
    while(peso){
        printf("%d", v/peso);
        v%=peso;
        peso/=2;
    }
}
    
void print_bytes(const void *p, int n){
    int i;
    char *pc = (char *) p;
    for(i = 0; i < n; i++){
        print_bits(pc+i);
        printf(" ");
    }
}
    
int main(){
    char * ptr;
    double d;
    float f;
    unsigned int ui;
    unsigned short us;
    unsigned char uc;
    
    scanf("%lf", &d);
    
    uc = us = ui = f = d;
    
    print_bytes(&uc, sizeof(char));
    printf("\n");
    print_bytes(&us, sizeof(short));
    printf("\n");
    print_bytes(&ui, sizeof(int));
    printf("\n");
    print_bytes(&f, sizeof(float));
    printf("\n");
    print_bytes(&d, sizeof(double));
    printf("\n");
    
    return 0;
}
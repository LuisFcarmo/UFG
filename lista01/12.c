#include <stdio.h>
int main () {
    float rendabrutafamiliar;
    int nfamilia; 
    int escola;
    int etnia;
    
    scanf("%f", &rendabrutafamiliar);
    scanf("%i", &nfamilia);
    scanf("%i", &escola);
    scanf("%i", &etnia);
    
    float rendapercapita;
    float salariomx;
    
    salariomx = 937*1.5;
    rendapercapita = (1.5*(rendabrutafamiliar))/nfamilia;
    
    if(escola == 2 && rendapercapita <= salariomx && etnia == 4) {
        printf("ALUNO COTISTA (L1)");
    }
    else if(escola == 2 && rendapercapita <= salariomx && etnia != 4) {
        printf("ALUNO COTISTA (L2)");
    }
    
    else if(escola == 2 && rendapercapita > salariomx && etnia == 4) {
        printf("ALUNO COTISTA (L3)");
    }
    else if(escola == 2 && rendapercapita > salariomx && etnia != 4) {
        printf("ALUNO COTISTA (L4)");
    }
    else {
        printf("ALUNO NAO COTISTA");
    }
    
    
    return 0;
};
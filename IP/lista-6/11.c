    #include <stdio.h>
    #include <stdlib.h>
    typedef struct {
        int pessoas;
        int consumo;
        double consumomedio;
    } casa;
    void ordernarconsumo (casa *ptrcasa, int qcasas) {
        int i = 0, k = 0;
        casa auxilar;
        for (i = 0; i < qcasas; i++) {
            for (k = 0; k < qcasas-1; k++) {
                if (ptrcasa[i].consumomedio < ptrcasa[k].consumomedio) {
                    auxilar = ptrcasa[k];
                    ptrcasa[k] = ptrcasa[i];
                    ptrcasa[i] = auxilar; 
                }
            }
        }
    }
    void verificaiguais (casa *ptrcasa, int qcasas) {
        int i = 0, k = 0;
        for (i = 0; i < qcasas; i++) {
            for (k = i + 1; k < qcasas; k++) {
                if (ptrcasa[i].consumomedio == ptrcasa[k].consumomedio) {
                    ptrcasa[i].pessoas += ptrcasa[k].pessoas;
                    ptrcasa[k].pessoas = 0;
                    ptrcasa[k].consumo = 0;
                    ptrcasa[k].consumomedio = 0;
                }
            }
        }
    }
     
    int main () {
        int qcidades = 0, qcasas = 0;
        int i = 0, k = 0;
        double aconsumo = 0;
        int apessoas = 0;
        casa *casas = 0;
        while (1) {
            qcidades++;
            scanf("%d", &qcasas);
            if (qcasas == 0) break;
            aconsumo = 0, apessoas = 0;
         
            casas = (casa*) malloc(qcasas*sizeof(casa));
            
            for (k = 0; k < qcasas; k++) {
                scanf("%d %d", &casas[k].pessoas, &casas[k].consumo);
                casas[k].consumomedio = casas[k].consumo/casas[k].pessoas; 
                aconsumo += casas[k].consumo;
                apessoas += casas[k].pessoas;
            }
            ordernarconsumo(casas, qcasas);
            verificaiguais(casas, qcasas);
                    if (qcidades % 2 != 0 )printf("\n");
     
            printf("Cidade# %d:\n", qcidades);
            
            for (k = 0; k < qcasas; k++) {
                if (casas[k].pessoas != 0) {
                    printf("%d-%.0lf", casas[k].pessoas, casas[k].consumomedio);
                    if (k < qcasas-1) printf(" ");
     
                }
            }
            printf("\n");
            printf("Consumo medio: %.2lf m3.\n", aconsumo/apessoas);
            if (qcidades % 2 != 0 )printf("\n");
        }
        return 0;
    }
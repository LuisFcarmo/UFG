#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int co;
    float ce;
    char nome[100];
} t1;
typedef struct {
    char nome[500];
    int co;
    int ce;
} t2;
    
int main () {
    t1 *ta1;
    t2 *ta2;
    int i = 0, k = 0;
    int qcursos;
    int qpessoas;
    scanf("%d%*c", &qcursos);
    
    ta1 = (t1*) malloc(qcursos*sizeof(t1));
    
    for (i = 0; i < qcursos; i++) {
        scanf("%d%*c", &ta1[i].co);
        scanf("%f%*c", &ta1[i].ce);
        scanf("%[^\n]%*c", ta1[i].nome);
    }
    
    scanf("%d%*c", &qpessoas);
    
    ta2 = (t2*) malloc(qpessoas*sizeof(t2));
    
    for (i = 0; i < qpessoas; i++) {
        scanf("%[^\n]%*c", ta2[i].nome);
        scanf("%d%*c", &ta2[i].co);
        scanf("%d%*c", &ta2[i].ce);
    }
    
    for (i = 0; i < qpessoas; i++) {
        for (k = 0; k < qcursos; k++) {
            if (ta1[k].co == ta2[i].co) {
                printf("Aluno(a): %s Curso: %s Num. Creditos: %d Valor Credito: %.2f Mensalidade: %.2f\n",
                ta2[i].nome, ta1[k].nome, ta2[i].ce, ta1[k].ce, ta1[k].ce*ta2[i].ce    
                );
                break;
            }
        }
    }
    
    
    return 0;
}
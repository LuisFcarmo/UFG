#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    int mat;
    int dia;
    int mes;
    int ano;
    char nome[200];
} pessoa;
int main () {
    int qpessoas = 0;
    int i = 0;
    int k = 0;
    pessoa *v;
    scanf("%d", &qpessoas);
    v = (pessoa*) malloc(qpessoas*sizeof(pessoa));
    for (i = 0; i < qpessoas; i++) {
        scanf("%d %d %d %d", &v[i].mat, &v[i].dia, &v[i].mes, &v[i].ano);
        fgets(v[i].nome, 200, stdin);
        v[i].nome[strlen(v[i].nome)-1] = '\0';
    }
    for (i = 0; i < qpessoas; i++) {
        for (k = 0; k < qpessoas-1; k++) {
            if (v[k].ano == v[k+1].ano ) {
                if (v[k].mes == v[k+1].mes ) {
                    if(v[k].dia < v[k+1].dia){
                    int tdia, tmes, tano, tmat;
                    char tnome[200];
                    tdia = v[k+1].dia;
                    tmes = v[k+1].mes;
                    tano = v[k+1].ano;
                    tmat = v[k+1].mat;
                    strcpy(tnome, v[k+1].nome);
                    v[k+1].dia = v[k].dia;
                    v[k+1].mes = v[k].mes;
                    v[k+1].ano = v[k].ano;
                    v[k+1].mat = v[k].mat;
                    strcpy(v[k+1].nome, v[k].nome);
                    v[k].dia = tdia;
                    v[k].mes = tmes;
                    v[k].ano = tano;
                    v[k].mat = tmat;
                    strcpy(v[k].nome, tnome);
                    }
                }
            }
            if (v[k].ano == v[k+1].ano ) {
                if (v[k].mes < v[k+1].mes ) {
                int tdia, tmes, tano, tmat;
                char tnome[200];
                tdia = v[k+1].dia;
                tmes = v[k+1].mes;
                tano = v[k+1].ano;
                tmat = v[k+1].mat;
                strcpy(tnome, v[k+1].nome);
                v[k+1].dia = v[k].dia;
                v[k+1].mes = v[k].mes;
                v[k+1].ano = v[k].ano;
                v[k+1].mat = v[k].mat;
                strcpy(v[k+1].nome, v[k].nome);
                v[k].dia = tdia;
                v[k].mes = tmes;
                v[k].ano = tano;
                v[k].mat = tmat;
                strcpy(v[k].nome, tnome);
                }
            }
            if (v[k].ano < v[k+1].ano ) {
                int tdia, tmes, tano, tmat;
                char tnome[200];
                tdia = v[k+1].dia;
                tmes = v[k+1].mes;
                tano = v[k+1].ano;
                tmat = v[k+1].mat;
                strcpy(tnome, v[k+1].nome);
                v[k+1].dia = v[k].dia;
                v[k+1].mes = v[k].mes;
                v[k+1].ano = v[k].ano;
                v[k+1].mat = v[k].mat;
                strcpy(v[k+1].nome, v[k].nome);
                v[k].dia = tdia;
                v[k].mes = tmes;
                v[k].ano = tano;
                v[k].mat = tmat;
                strcpy(v[k].nome, tnome);
            }
        }
    }
    
    for (i = 0; i < qpessoas; i++) {
        printf("Matric.: %d Nome: %s Data Nasc: %d/%d/%d\n", v[i].mat, v[i].nome , v[i].dia, v[i].mes, v[i].ano);
    }
    
    return 0;
}
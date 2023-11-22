#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifndef _data_h
#define _data_h

typedef struct data *Data;
Data criaData (unsigned int, unsigned int, unsigned int);
int Converte_dias (Data d);
void corigir_data (Data);

bool bi (Data);

Data copiaData (Data);

void liberaData (Data);
void print_data (Data);

Data somaDiasData (Data, unsigned int);

Data subtrairDiasData (Data, unsigned int);

void atribuirData (Data, unsigned int,
unsigned int, unsigned int);

unsigned int obtemDiaData (Data);

unsigned int obtemMesData (Data);

unsigned int obtemAnoData (Data);


int comparaData (Data, Data);

int numeroDiasDatas (Data, Data);

int numeroMesesDatas (Data, Data);
int numeroAnosDatas (Data, Data);

unsigned int obtemDiaSemanaData (Data);

char* imprimeData (Data, char *);

#endif
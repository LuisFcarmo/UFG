#include <stdio.h>
#include <stdbool.h>
#include "data.h"

struct data {
    int dia;
    int mes;
    int ano;
};
bool bi (Data d) {
    int ano = d -> ano;
    if (ano % 4 == 0 && ano % 100 != 0) return true;
    else if (ano % 4 == 0 && ano % 100 == 0 && ano % 400 == 0) return true;
    else {
        return false;
    }
};

int Converte_dias (Data d) {
    bool b = bi(d);
    int acumulador;
    for (int i = 1900; i <= d -> ano-1; i++) {
        if (bi(d)) {
            acumulador += 366;  
        } else if (!bi(d)) {
            acumulador += 365;
        }
    }
    for (int i = 1; i < d -> mes; i++) {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
            acumulador += 31;
        } else if (i == 4 || i == 6 || i == 9 || i == 11) {
            acumulador += 30;
        } else if (i == 2) {
             if (b == false) {
               acumulador += 28;
            } else if (b == true) {
                acumulador += 29;
            }
        }
    }
    return acumulador;
}

void AjustaData (Data d) {
    bool b = bi(d);
    int mes = d -> mes;
    if (d -> dia > 0) {
        if (d -> mes == 13) {
            d -> mes = 1;
            d -> ano += 1;
            AjustaData(d);
        }
        if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
            if (d -> dia <= 31) return;
            d -> dia -= 31;
            d -> mes += 1;
            AjustaData(d);
        } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
            if (d -> dia <= 30) return;
            d -> dia -= 30;
            d -> mes += 1;
            AjustaData(d);
        } else if (mes == 2) {
            if (b == false) {
                if (d -> dia <= 29) return;
                d -> dia -= 28;
                d -> mes += 1;
                AjustaData(d);
            } else if (b == true) {
                if (d -> dia <= 28) return;
                d -> dia -= 28;
                d -> mes += 1;
                AjustaData(d);
            }
        }
    } else if (d -> dia <= 0) {
        if (d -> mes == 0) {
            d -> mes = 12;
            d -> ano -= 1;
            AjustaData(d);
        }
        if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
          d -> dia += 31;
          d -> mes -= 1;
          AjustaData(d);

        } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
           d -> dia += 30;
           d -> mes -= 1;
           AjustaData(d);
        } else if (mes == 2) {
            if (b == false) {
                d -> dia += 28;
                d -> mes -= 1;
                AjustaData(d);
            } else if (b == true) {
               d -> dia += 29;
               d -> mes -= 1;
               AjustaData(d);
            }
        }
    }
}

Data criaData (unsigned int dia, unsigned int mes, unsigned int ano) {
    Data nova_data = NULL;

    if (ano < 1900 || ano > 2200) {
        printf("data invalida !\n");
        return nova_data;
    } else {
        nova_data = (Data) malloc(sizeof(Data)*1);

        nova_data -> dia = dia;
        nova_data -> mes = mes;
        nova_data -> ano = ano;
        AjustaData(nova_data);
        return nova_data;
    }
};

Data copiaData (Data d) {
    Data copia_data = criaData(d->dia, d->mes, d->ano);
    return copia_data;
};

void liberaData (Data d) {
    if (d == NULL) {
        printf("tentando liberar memoria indevida!\n");
    } else {
        free(d);
    }
};

Data somaDiasData (Data d, unsigned int dias) {
    Data nova_data = criaData(d -> dia+dias, d -> mes, d -> ano);
    AjustaData(nova_data);
    return nova_data;
};

Data subtrairDiasData (Data d, unsigned int dias) {
    Data nova_data = criaData(d-> dia-dias, d -> mes, d -> ano);
    AjustaData(nova_data);
    return nova_data;
};

void print_data (Data d) {
    printf("%d / %d / %d\n", d -> dia, d -> mes, d -> ano);
};

void atribuirData (Data d, unsigned int dia,
unsigned int mes, unsigned int ano) {
    d -> dia = dia;
    d -> mes = mes;
    d -> ano = ano;
};  

unsigned int obtemDiaData (Data d) {
    return d -> dia;
};

unsigned int obtemMesData (Data d) {
    return d -> mes;
};

unsigned int obtemAnoData (Data d) {
    return d -> mes;
};

int comparaData (Data d1, Data d2) {
    if (d1-> ano < d2 -> ano) {
        return -1;
    } else if (d1 -> ano == d2 -> ano) {
        if (d1 -> mes == d2 -> mes) {
                if (d1 -> dia == d2 -> dia) {
                    return 0;
                } else if (d1 -> dia < d2 -> dia) {
                    return -1;
                }
        }
        else if (d1 -> mes < d2 -> mes) {
            return -1;
        }
    }
    if (d1 -> ano > d2 -> ano) {
        return 1;
    } else if (d1 -> ano == d2 -> ano) {
        if (d1 -> mes == d2 -> mes) {
                if (d1 -> dia == d2 -> dia) {
                    return 0;
                } else if (d1 -> dia > d2 -> dia) {
                    return 1;
                }
        }
        else if (d1 -> mes > d2 -> mes) {
            return 1;
        }
    }
};

int numeroDiasDatas (Data d1, Data d2) {
  int dia = Converte_dias(d1) - Converte_dias(d2);
  if (dia < 0) {
    dia *= -1;
  }
  return dia;
};

int numeroMesesDatas (Data d1, Data d2) {   
    int meses = ((d1 -> ano - 1900)*12) - ((d2 -> ano - 1900)*12);
    if (meses < 0) {
        meses *= -1;
    }
    return meses;
};
int numeroAnosDatas (Data d1, Data d2) {
    int ano = d1-> ano - d2-> ano;
    if (ano < 0) {
        return ano *= -1;
    }
    return ano;
};

unsigned int obtemDiaSemanaData (Data d) {
    unsigned int dia = d -> dia % 7;
    if (dia == 0) {
        return 7;
    }
    return dia;
};

char * imprimeData (Data d, char * formato) {
    bool ano = false, dia = false, mes = false;
    for (int i = 0; formato[i] != '\0'; i++) {
        if (formato[i] == 'a' && ano == false) {
            printf("(%d)", d -> ano);
            ano = true;
        }
        if (formato[i] == 'd' && dia == false) {
            printf("(%d)", d -> dia);
            dia = true;
        }
        if (formato[i] == 'm' && mes == false) {
            printf("(%d)", d -> mes);
            mes = true;
        }
    }

};
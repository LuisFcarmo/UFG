#include "texto.h"
#include <stdio.h>
#include <stdlib.h>
int MaxSize = 10000000;

struct  texto {
    char *txt;
};

int Size_text(char *t) {
    int i = 0;
    for (i = 0; t[i] != '\0'; i++);
    return i;
};

String *New_Empty_text() {
    String *Empty = NULL;
    Empty = (String*) malloc(sizeof(String)*1);
    return Empty;
}

String *Scanf_Text () {
    String *Text = (String*) malloc(sizeof(String)*1);
    char *st = (char*) malloc(sizeof(char)*MaxSize);
    int size = 0;
    scanf("%[^\n]", st);

    for (int i = 0; st[i] != '\0'; i++) {
        size++;
    }
    Text -> txt = (char*) malloc(sizeof(char)*size);

    for (size = 0; st[size] != '\0'; size++) {
        Text -> txt[size] = st[size];
    }

    Text -> txt[size+1] = '\0';
    free(st);
    return Text;
}


String *New_Text(char *s) {
    String *New_T = NULL;
    int size = Size_text(s)+1;
    New_T = (String*) malloc(sizeof(String));

    New_T -> txt = (char*) malloc(sizeof(char)*size);
    for (int i = 0; s[i] != '\0'; i++) {
        New_T -> txt[i] = s[i];
    }
    New_T -> txt[size-1] = '\0';
  
    return New_T;
};

void Destruct_Text(String **txt) {
    String *ref = *txt;
    free(ref->txt);
    free(ref);
    *txt = NULL;        
};

char *Get_Text(String *t) {
    return t -> txt;
};

void Show_Text (String *t, int colunas) {
    for (int i = 0; t -> txt[i] != '\0'; i++) {
        if (i % colunas == 0) {
            printf("\n");
        }
        printf("%c", t -> txt[i]);
    }
};

void Replace_Text (String * t, char * alteracao) {
    if (t != NULL) {
        int i = 0;
        free(t->txt);
        t -> txt = (char*) malloc(sizeof(char)*(Size_text(alteracao)+1));
        for (i = 0; alteracao[i] != '\0'; i++) {
            t -> txt[i] = alteracao[i];
        }
        t -> txt[i+1] = '\0';
    } else {
        printf("tentando acessar memoria indevida\n");
    }
};

bool Compare_Text (String * t, String * t2) {
    if (Size_text(t -> txt) != Size_text(t2 -> txt)) return false;
    else {
        for (int i = 0; i < Size_text(t -> txt)+1; i++) {
            if (t -> txt[i] == t2 -> txt[i]) continue;
            else return false;
        }
    }
    return true;
};

char *Get_SubText (String * t, int begin, int end) {
    char *Sub_Text = (char*) malloc(sizeof(char)*((end-begin)+2));
    int index = 0;
    if (end > Size_text(t -> txt)) {
        printf("tamanho ultrapassou o da string\n");
    }
    for (int i = begin; i <= end; i++) {
        Sub_Text[index] = t -> txt[i];
        index++;
    }
    Sub_Text[index] = '\0';
    return Sub_Text;
};

String * Concatenate_Text (String * t1, String * t2) {
    int index = 0;
    String *N_text = New_Empty_text();
    int size = Size_text(t1->txt) + Size_text(t2->txt);
    N_text -> txt = malloc(sizeof(char)*size);
    for (int i = 0 ;t1 -> txt[i] != '\0'; i++) {
        N_text -> txt[index] = t1 -> txt[i];
        index++;
    }
    for (int i = 0 ;t2 -> txt[i] != '\0'; i++) {
        N_text -> txt[index] = t2 -> txt[i];
        index++;
    }
    N_text -> txt[index+1] = '\0';
    return N_text;
};

int Shearching_SubText (String *t1, String *t2) {
    int iguais = 0;
    int index = 0;
    int acumulador = 0;
    for (int i = 0; i < Size_text(t1 -> txt); i++) {
        if (t1 -> txt[i] == t2 -> txt[index]) {
            iguais++;
            index++;
        } else {
            iguais = 0;
            index = 0;
        } 
        if (iguais == Size_text(t2 -> txt)-1) {
            acumulador++;
            iguais = 0;
            index = 0;
        }
    }
    return acumulador;
};

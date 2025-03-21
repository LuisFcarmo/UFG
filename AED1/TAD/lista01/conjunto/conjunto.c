#include "conjunto.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


struct conjunto {
    int *conjun;
    int tamanho;
};
int pot (int base, int expoente) {
    int acumulador = 2;
    if (expoente == 0) return 1;
    else {
        for (int i = 1; i < expoente; i++) {
            acumulador *= acumulador;
        }
    }
    return acumulador;
}

Conjunto New_Conjunction (int t) {
    Conjunto cj = NULL;
    cj = (Conjunto) calloc(1, sizeof(Conjunto));

    cj -> tamanho = 0;
    cj -> conjun = (int*) malloc(sizeof(int)*t);
    
    return cj;
};

bool Conjunction_is_Empty (Conjunto ptr_conjunto) {
    if (ptr_conjunto-> tamanho == 0) return true;
    else return false;
};

bool Element_is_Conjuction (int elemento,Conjunto ptr_conjunto){
    for (int i = 0; i < ptr_conjunto->tamanho; i++) {
        if (ptr_conjunto->conjun[i] == elemento) {
            return true;
        }
    }
    return false;
};

Conjunto Create_and_fill_conjunction () {
    Conjunto cj_aux = NULL;
    int elemento = 0;
    int qtd = 0;
    while (1)
        {            
            printf("quantos elementos tem esse novo conjunto\n");
            scanf("%d%*c", &qtd);
            if (qtd >= 0 && qtd <= 100000000) {
                cj_aux = New_Conjunction(qtd);
            while (qtd--)
            {
                printf("elementos restantes %d\n", qtd+1);
                scanf("%d%*c", &elemento);
                Insert_Element(elemento ,cj_aux);           
            }
            } else {
                printf("tamanho invalido insira um valor entre 0 e 100000000\n");
            }
        break;
    }
    return cj_aux;
};

int Position_in_Conjunction (int numero, Conjunto ptr_conjunto) {
    if (Conjunction_is_Empty(ptr_conjunto)){
        printf("impossivel achar este elemento conjunto está vazio\n");
    } else {
        for (int i = 0; i < ptr_conjunto->tamanho; i++) {
            if (ptr_conjunto-> conjun[i] == numero) {
                return i;
            }
        }
    }
};

int Insert_Element(int numero, Conjunto y) {
    if (!Element_is_Conjuction(numero, y)){
        y->conjun[y->tamanho] = numero;
        y->tamanho++;
        return 1;
    }
    else {
        return 0;
    }
};

int Delete_Element (int numero, Conjunto y) {
    if (!Element_is_Conjuction(numero, y)) {
        printf("impossivel excluir este elemento ele não está presente no conjunto\n");
        return 0;
    } else if (Element_is_Conjuction(numero, y)) { 
        int posicao = Position_in_Conjunction(numero, y);
        y -> conjun[posicao] = 0;
        y ->tamanho--;
    }
};

int Cardinality (Conjunto v) {
    return v -> tamanho;
};

int Bigger_than_Element (Conjunto v, int numero) {
    int maiores = 0;
    for (int i = 0; i < v -> tamanho ; i++) {
        if (v-> conjun[i] > numero) {
            maiores++;
        }
    }
    return maiores;
};

int Lower_tham_Element (Conjunto v, int numero) {
    int maiores = 0;
    for (int i = 0; i < v -> tamanho ; i++) {
        if (v-> conjun[i] < numero) {
            maiores++;
        }
    }
    return maiores;
};

bool Belongs_in_Conjunction (Conjunto a, Conjunto b) {
    bool pertence = false;
    int contador = 0;
    for (int i = 0; i < a -> tamanho; i++) {
        for (int k = 0; k < b -> tamanho; k++) {
            if (a->conjun[i] == b -> conjun[k]) {
                contador++;
            }
        }
    }
    if (contador == b -> tamanho) {
        pertence = true;
    } else if (contador != b -> tamanho) {
        pertence = false;
    }
};

bool Twins_Conjunction (Conjunto a, Conjunto b) {
    int contador = 0;
    for (int i = 0; i < a ->tamanho; i++) {
        for (int k = 0; k < b -> tamanho; k++) {
            if (a -> conjun[i] == b -> conjun[k]) {
                contador++;
            }
        }
    }
    if (contador == b ->tamanho && contador == a -> tamanho) {
        return true;
    } else {
        return false;
    }
};


Conjunto New_Complement (Conjunto a, Conjunto b) {
    int tamanho = 0;
    int indice = 0;
    for (int i = 0; i < a -> tamanho; i++) {
        if (!Element_is_Conjuction(a->conjun[i], b)){
            tamanho++;
        }
    }

    Conjunto complemento = New_Conjunction(tamanho);
    for (int i = 0; i < a -> tamanho; i++) {
        if (!Element_is_Conjuction(a->conjun[i], b)){
            Insert_Element(a->conjun[i], complemento);
        }
    }
    return complemento;
};

int Unique_Elements (Conjunto a, Conjunto b) {
    bool answer = false;
    int qtd = 0;
    for (int c = 0; c < a -> tamanho; c++) {
        for (int q = 0; q < b -> tamanho; q++) {
            if (a->conjun[c] == b->conjun[q]) {
                answer = true;
            }
        }
        if (answer == false) {
            qtd++;
        }
        answer = false;
    }
    return qtd;
};

int Equal_Elements (Conjunto a, Conjunto b) {
    bool answer = false;
    int qtd = 0;
    for (int c = 0; c < a -> tamanho; c++) {
        for (int q = 0; q < b -> tamanho; q++) {
            if (a->conjun[c] == b->conjun[q]) {
                answer = true;
            }
        }
        if (answer == true) {
            qtd++;
        }
        answer = false;
    }

    return qtd;
}

Conjunto Union (Conjunto a, Conjunto b) {
    int size = (b -> tamanho + (Unique_Elements(a, b)));
    int indice = 0;
    Conjunto Un = New_Conjunction(size);
    
    for(indice = 0; indice < b -> tamanho; indice++) {
        Insert_Element(b -> conjun[indice], Un);
    }
    
    for (;indice < size; indice++){
        for (int i = 0; i < a -> tamanho; i ++) {
            if (!Element_is_Conjuction(a->conjun[i], b)) {
                indice++;
                Insert_Element(a->conjun[i], Un);
            }
        }
    }
    return Un;
};

Conjunto intersection (Conjunto a , Conjunto b) {
    int size = Equal_Elements(a, b);
 
    Conjunto intersec = New_Conjunction(size);
    for (int i = 0; i < a -> tamanho; i++) {
        if (Element_is_Conjuction( a->conjun[i], b)) {
            Insert_Element( a->conjun[i], intersec);
        }
    }
    return intersec;
};

Conjunto Difference (Conjunto a, Conjunto b) {
    int size = Unique_Elements(a, b);
    Conjunto Dif = New_Conjunction(size);
    for (int i = 0; i < a -> tamanho; i++) {
        if (!Element_is_Conjuction(a->conjun[i], b)) {
            Insert_Element(a->conjun[i], Dif);
        }
    }  

    return Dif;
}

/*Conjunto Set_Of_Parts (Conjunto x) {
    Conjunto parts = pot(2, x->tamanho);

}*/

void Grow_Order (Conjunto x) {
    int aux;
    for (int i = 0; i < x -> tamanho; i++) {
        for (int c = i; c < x-> tamanho; c++) {
            if (x->conjun[i] > x -> conjun[c]) {
                aux = x -> conjun[c];
                x -> conjun[c] = x-> conjun[i];
                x -> conjun[i] = aux; 
            }
        }
    }
};  

void Descending_order(Conjunto x) {
    int aux;
    for (int i = 0; i < x -> tamanho; i++) {
        for (int c = i; c < x-> tamanho; c++) {
            if (x->conjun[i] < x -> conjun[c]) {
                aux = x -> conjun[c];
                x -> conjun[c] = x-> conjun[i];
                x -> conjun[i] = aux; 
            }
        }
    }
};

int Display_Conjuction (Conjunto y, char order) {
    if (order == 'D') {
        Descending_order(y);
        for (int i = 0; i < y->tamanho; i++) {
            printf("%d\n", y->conjun[i]);
        }
    } else if (order == 'C') {
        Grow_Order(y);
         for (int i = 0; i < y->tamanho; i++) {
            printf("%d\n", y->conjun[i]);
        }
    }
};

Conjunto Copy_Conjunction (Conjunto x, Conjunto y) {
    if (x-> tamanho < y ->tamanho) {

        } 
};

int Destruct_Cojunction (Conjunto x) {
    if(x != NULL) {
        free(x->conjun);
        free(x);
        return 1;
    } else {
        printf("Error tentando liberar memoria indevida\n");
        return 0;
    }
};

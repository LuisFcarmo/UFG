#include "complex.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct complex {
    int real;
    int imaginary;
};

struct header {
    int size; 
    COMPLEX *set;
};

COMPLEX *New_Complex (int imaginary, int real) {
    COMPLEX *x = (COMPLEX*) malloc(sizeof(COMPLEX)*1);
    x -> imaginary = imaginary;
    x -> real = real;
    return x;
}

HEADER *New_Complex_set (int qtd) {
    HEADER *head = NULL;
    head = (HEADER*) malloc(sizeof(HEADER)*1);
    head -> size = 0;

    if (head != NULL){ 
        head -> set = (COMPLEX*) malloc(sizeof(COMPLEX)*qtd);
    } else {
        printf("ERROR\n");
    }
    return head;
};

bool Set_is_Empty (HEADER *head) {
    if (head -> size == 0) {
        return true;
    } else {
        return false;
    }
}

int Cardinality (HEADER *head) {
    return head->size;
}

bool Insert_Element (COMPLEX *x , HEADER *head) {
    bool verify = false;
    for (int i = 0; i < Cardinality(head); i++) {
        if (head->set[i].imaginary == x -> imaginary && head-> set[i].real == x -> real) {
            printf("i%d  r%d\n", x->imaginary, x->real);
            verify = true;
        }
    }
    if (verify == false) {
        head->set[Cardinality(head)].real = x -> real;
        head->set[Cardinality(head)].imaginary = x -> imaginary;
        head->size++;
    } else {
        printf("element in conjunct\n");
    }
}


bool Delete_Element (COMPLEX *x,  HEADER *head) {
    bool verify = false;
    for (int i = 0; i < Cardinality(head); i++) {
        if (head->set[i].imaginary == x -> imaginary && head -> set[i].real == x -> real) {
            head -> set[i].imaginary = 0;
            head -> set[i].real = 0;
            verify = true;
            head->size--;
        }
    }
    if (verify == false) {
        printf("element not in conjunct\n");
    } 
}

bool Element_in_set (HEADER *head, COMPLEX *x) {
   bool verify = false;
    for (int i = 0; i < Cardinality(head); i++) {
        if (head->set[i].imaginary == x -> imaginary && head->set[i].real == x -> real) {
            verify = true;
        }
    }
    if (verify == true) {
        return true;
    } else {
        return false;
    }
}

bool Twins_Set (HEADER *head1, HEADER *head2) {
    int cont = 0;
    for (int i = 0; i < head1 -> size; i++) {
        for (int k = 0; k < head2 -> size; k++) {
            if ( 
                head1 -> set[i].imaginary == head2 -> set[k].imaginary &&
                head1 -> set[i].real == head2 -> set[k].real ) {
                cont++;
            }
        }
    }
    if (cont == head1->size) {
        return true;
    } else {
        return false;
    }
};

bool Subset_in_Set (HEADER *head1, HEADER *head2) {
    bool belongs = false;
    int cont = 0;
    for (int i = 0; i < head2 -> size; i++) {
        for (int k = 0; k < head1 -> size; k++) {
            if (
                head2 -> set[i].imaginary == head1 -> set[k].imaginary &&
                head2 -> set[i].real == head1 -> set[k].imaginary
                ) {
                cont++;
            }
        }
    }
    if (cont == head2->size) {
        return true;
    } else {
        return false;
    }
};

HEADER *New_Complement (HEADER *head1, HEADER *head2) {
    int size = 0;
    int index = 0;
    for (int i = 0; i < head2 -> size; i++) {
        if (!Element_in_set(head1, (&head2 -> set[i]))){
            size++;
        }
    }

    HEADER *complement = New_Complex_set(size);
    for (int i = 0; i < head1 -> size; i++) {
        if (!Element_in_set(head1, &head2 -> set[i])){
            Insert_Element(&head2 -> set[i], complement);
        }
    }
    return complement;
};

int Unique_Element (HEADER *head1, HEADER *head2) {
    int cont = 0;
    bool verify = false;
    for (int i = 0; i < head1 -> size; i++) {
        for (int b = 0; b < head2 -> size; b++) {
            if ( 
                head1 -> set[i].imaginary == head2 -> set[b].imaginary &&
                head1 -> set[i].real == head2 -> set[b].real ) {
                verify = true;
            } 
        }
        if (verify == false) {
            cont++;
        }
        verify = false;
    }
    return cont;
}

HEADER *Set_Union (HEADER *head1, HEADER *head2) {
    int size = head2 -> size + Unique_Element(head1, head2);
    HEADER *set = New_Complex_set(size);
    
    for (int i = 0; i < head1 -> size; i++) {
        Insert_Element(&head1 -> set[i], set);
    }
    for (int i = 0; i < head2 -> size; i++) {
        if (!Element_in_set(head1, &head2 -> set[i])) {
            Insert_Element(&head2 -> set[i], set);
        }
    }
    return set;
}

HEADER *Set_Intersec (HEADER *head1, HEADER *head2) {
    int size = head1 -> size - Unique_Element(head1, head2);
    HEADER *set = New_Complex_set(size);
    for (int i = 0; i < head1 -> size; i++) {
        if (Element_in_set(head2, &head1 -> set[i])) {
            Insert_Element(&head1 -> set[i], set);
        }
    }

    return set;
}

HEADER *Set_Diference (HEADER *head1, HEADER *head2) {
    int size = Unique_Element(head1, head2);
    HEADER *set = New_Complex_set(size);
    for (int i = 0; i < head1 -> size; i++) {
        if (!Element_in_set(head2, &head1 -> set[i])) {
            Insert_Element(&head1 -> set[i], set);
        }
    } 
    return set;
};

HEADER *Copy_Set (HEADER *head1) {
    HEADER *set = NULL;    
    if (set == NULL) {
        set = New_Complex_set(head1->size);
        for (int i = 0; i < head1->size; i++) {
            Insert_Element(&head1->set[i], set);
        }
        return set;
    } else {
        printf("Impossivel fazer a copia pois ouve uma falha\n");
    }
}

void Destruct_Set (HEADER **ptr) {
    HEADER *ref = *ptr;
    free(ref->set);
    free(ref);
    *ptr = NULL;
}

HEADER *Create_and_fill_set(int qtd) {
    HEADER *head = New_Complex_set(qtd); 
    COMPLEX *aux;
    int cont = qtd;
    int imaginary = 0, real = 0;
    for (int i = 0; i < qtd; i++) {
        printf("elementos restantes %d", cont);
        cont--;
        printf("digite imaginaria e real\n"); 
        scanf("%d %d%*c", &imaginary, &real);
        aux = New_Complex(imaginary, real);
        Insert_Element(aux, head);
    }
    return head;
};
bool Delete_set (HEADER **head) {
    HEADER *ref = *head;
    if (head != NULL) {
        free(ref -> set);
    }
    free(ref);
    *head = NULL;
};


void print_set (HEADER *head) {
    for (int i = 0; i < head->size; i++) {
        printf("i (imaginaria) = %d d (real) = %d\n", head -> set[i].imaginary, head -> set[i].real);
    }
}
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
    for (int i = 0; i <= Cardinality(head); i++) {
        if (head->set[i].imaginary == x -> imaginary && head-> set[i].real == x -> real) {
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
            verify == true;
        }
    }
    if (verify == true) {

    } else {
        printf("element not in conjunct\n");
    }
}

bool Element_in_set (HEADER *head, COMPLEX *x) {
   bool verify = false;
    for (int i = 0; i < Cardinality(head); i++) {
        if (head->set[i].imaginary == x -> imaginary && head->set[i].real == x -> real) {
            verify == true;
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
        if (!Element_in_set(head1, (&head2 -> set[i]))){
            Insert_Element(&(head2 -> set[i]), complement);
        }
    }
    return complement;
};

void print_set (HEADER *heade) {
    for (int i = 0; i <= heade->size; i++) {
        printf("i = %d d = %d\n", heade -> set[i].imaginary, heade -> set[i].real);
    }
}
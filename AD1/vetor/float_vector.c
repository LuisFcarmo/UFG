#include "float_vector.h"
#include <stdio.h>
#include <stdlib.h>
/**************interface privada*****************/

struct Float_vector{
    int capacity;
    int size;
    float *data;
};

int _vectorisfull (floatvector *vec) {
    if (vec -> size == vec -> capacity) return 1;
    else return 0;
};

int _verifyindex (int size, int index) {
    if ((index < 0 ) || (index > size)) return 1;
    else return 0;
};

/************************************************/

/**************interface publica*****************/

floatvector* create (int capacity)  {
    floatvector *vec = (floatvector*) calloc (1, sizeof(floatvector));
    vec -> size = 0;
    vec -> capacity = capacity;
    vec -> data = (float*) calloc(capacity, sizeof(float));
    
    return vec;
}

void destroy (floatvector **vector) {
    floatvector *vec  = *vector;

    free(vec -> data);
    free(vec);

    *vector = NULL;
}

int size (const floatvector *vec) {
   return vec -> size;
};

int capacity (const floatvector *vec) {
    return vec -> capacity;
};

float at(const floatvector *vec, int index) {
    if (_verifyindex(vec -> size, index)) {
        fprintf(stderr, "ERROR in 'at'\n");
        fprintf(stderr, "index [%d] is out of bounds [0, %d]", index, vec -> size);
        exit(EXIT_FAILURE);
    } else { 
    return vec -> data[index];
    }
};

float get(const floatvector *vec, int index) {
    return vec -> data[index];
};

void append(floatvector *vec, float val) {
    if (_vectorisfull(vec)) {
        printf("error\n");
        printf("vector is full\n");
    } else {
        vec -> data[vec->size] = val;
        vec -> size = (vec -> size + 1);
    }
};
void set(floatvector *vec, int index, float val) {
    if (_verifyindex(vec -> size, index)) {
        printf("error\n");
        printf("invalid index");
    } else {
        vec -> data[index] = val;
    }
};
void print(const floatvector *vec) {
    for (int i = 0; i < vec -> size; i++) {
        if (i == 1) printf("(");
        printf("%lf", vec -> data[i]);
        if (i == vec -> size-1) printf(")");
    }
};

/************************************************/

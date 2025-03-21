#ifndef float_vector_h 
#define floa_tvector_h 

/**************interface publica*****************/

typedef struct Float_vector floatvector;

floatvector* create (int capacity);
void destroy (floatvector **vecref);
int size (const floatvector *vec);
int capacity (const floatvector *vec);
float at(const floatvector *vec, int index);
float get(const floatvector *vec, int index);
void append(floatvector *vec, float val);
void set(floatvector *vec, int index, float val);
void print(const floatvector *vec);

/************************************************/

#endif 
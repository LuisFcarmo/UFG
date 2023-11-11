#include "complex.h"
#include <stdio.h>
int main () {   
    HEADER *ptr = New_Complex_set(4);
    HEADER *ptr2 = NULL;
    COMPLEX *x = New_Complex(1, 2);

    if (Set_is_Empty(ptr)) {
        printf("s");
    } else printf("n");
    
    printf("%d", Cardinality(ptr));
    for (int i = 0; i < 4; i++) {
        Insert_Element(x, ptr);
    }
    print_set(ptr);



    return 0;
}
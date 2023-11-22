#include <stdio.h>
#include <stdlib.h>
int main () {
    char* ptr = NULL;
    char atual;
    int size = 0;

    while(1){
        scanf("%c", &atual);
        size++;
        ptr = (char*) realloc(ptr, (size+1) * sizeof(char));
        if(atual == '\n') break;
        ptr[size-1] = atual;        
    }

    ptr[size-1] = '\0';

    printf("str = %s\n", ptr);

    return 0;
}
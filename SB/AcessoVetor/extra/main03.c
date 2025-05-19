#include <stdio.h>


extern long nums[];

extern int  size;


void ex03();


int main()

{

  int i;


  for (i = 0; i < size; i++)

    printf("nums[%d] = %ld\n", i, nums[i]);


  ex03();


  printf("---\n");

  for (i = 0; i < size; i++)

    printf("nums[%d] = %ld\n", i, nums[i]);


  return 0;

}
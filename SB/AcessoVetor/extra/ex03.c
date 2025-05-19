int size = 5;


short a[5] = {5,1,7,2,9};

int   b[5] = {6,3,8,4,2};

long nums[5] = {0};       // Zera todas as posições


short factor = 100;


void ex03()

{

  int i = 0;

  short *ptr = a;


  while (i < size) {

    if (a[i] > 6)

      nums[i] = b[0] + factor;

    else

      nums[i] = *ptr * b[i];

    i++;

    ptr++;

   }

}
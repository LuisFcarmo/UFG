#include <stdio.h>
#include <assert.h>

int match(unsigned long x, unsigned short y){
    for (int i = 0; i <= 48; i++) {
        if (((x >> i) & 0xFFFF) == y) {
            return 1;
        }
    }
    return 0;
}


int odd_ones(unsigned int x) {
    unsigned int mask = 1U << 31; 
    int contador = 0;

    for (int i = 0; i < 32; i++) {
        if (x & mask) {  
            contador++;   
        }
        mask = mask >> 1; 
    }
    mask = 1U; 

    if (contador & mask) {
        printf("impar\n");
    } else {
        printf("par\n");
    }
    return contador;
}

int leading_zeros(unsigned short n) {
    int contador = 0;
    unsigned int mask = 1U << 15; 
    for (int i = 0; i < 16; i++) {
        if (n & mask) {  
            break;   
        }
        mask = mask >> 1; 

        contador++;
    }
    return contador;
};
void testar_leading_zeros() {
    assert(leading_zeros(0) == 16);
    assert(leading_zeros(0x0083) == 8);
    assert(leading_zeros(0x0607) == 5);
    assert(leading_zeros(0xC2A4) == 0);
    assert(leading_zeros(24432) == 1);
}   

unsigned char rotate_left(unsigned char x, int n) {
    return (x << n) | (x >> (8 - n));
};

unsigned char rotate_right(unsigned char x, int n) {
    return (x >> n) | (x << (8 - n));
};


void flip(int *value, int bit) {
    unsigned int mask = 1U << bit; 
    if (*value & mask) {
        *value = *value & (~mask);
    } else {
        *value = *value | mask;
    }
};

unsigned int convertB2L(unsigned int x) {
  unsigned int byte1 = (x & 0x00000FF) << 24;
  unsigned int byte2 = (x & 0x0000FF00) << 8;
  unsigned int byte3 = (x & 0x00FF0000) >> 8;
  unsigned int byte4 = (x & 0xFF000000) >> 24;
  return (byte1 | byte2 | byte3 | byte4);
}

int testar_match(){
  unsigned long x;
  unsigned short y;

  x = 28736452;
  y = 21;
  printf("X: 0x%.16lX\n", x);
  printf("Y: 0x%.4X\n", y);


  if (match(x, y))
    printf("Y está contido em X\n");
  else
    printf("Y não está contido em X\n");

  x = 28736452;
  y = 438;

  printf("X: 0x%.16lX\n", x);
  printf("Y: 0x%.4X\n", y);


  if (match(x, y))
    printf("Y está contido em X\n");
  else
    printf("Y não está contido em X\n");



  return 0;
}

void bin(unsigned int pot, int size) {
    unsigned int mask = 1U << (size*8)-1; 
    for (int i = 1; i <= (size*8); i++) {
        if(pot&mask){
            printf("1");
        } else {
            printf("0");
        }
        if (i%4==0) printf(" ");
        mask = mask >> 1;
    }
    printf("\n");
}

void dif(unsigned int x,  unsigned int y) {
    unsigned int mask = 1U; 
    for (int i = 0; i < 4*8; i++) {
        if((x&mask) != (y&mask)) {
            printf("bit no indice é diferente %d\n", i);
        }
        mask = mask << 1;
    }
}

int main(void) {
    dif(263, 3);

    //unsigned int x = 0x87654321;

    //unsigned int a, b;

    //odd_ones(0x01010101);
    //odd_ones(0x01030101);

    // Manter o byte menos significativo de x e os outros bits em '0'

    //a =  x & 0x000000FF;

    //    b =  x | 0xFF000000;

    //printf("a = 0x%08X\n", a);

    //printf("b = 0x%08X\n", b);
    //unsigned int b = 0x12AB34CD;

    ///unsigned int l = convertB2L(b);


    //printf("b = 0x%08X\n", b);

    //printf("l = 0x%08X\n", l);
    //testar_leading_zeros();
    //printf("0x%x\n", rotate_left(0x61, 1));
    //printf("0x%x\n", rotate_left(0x61, 2));
    //printf("0x%x\n", rotate_left(0x61, 7));
    ///int value;
  
    ///value = 0x00000000;

    ///flip(&value, 0);

    //printf("0x00000001 == 0x%08X\n", value);


    //value = 0xF0000000;

    //flip(&value, 31);

    //printf("0x70000000 == 0x%08X\n", value);


    //value = 0xF002000F;

    //flip(&value, 16);

    //printf("0xF003000F == 0x%08X\n", value);
    //testar_match();



    return 0;
}
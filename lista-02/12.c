#include <stdio.h>
#include <math.h>
int main () {
    int inteirodesejado;
    int hipotenusa;
    int c1;
    int c2;
    /* 
    como essa matriz vai rodar
    111    5 3 4 (esse é um cateto valido)
    112 
    113 
    114 
    115 ...............................  
    
    */
    scanf("%i", &inteirodesejado);
    for (hipotenusa = 1; hipotenusa <= inteirodesejado; hipotenusa++){
        for (c1 = 1; c1 <= hipotenusa; c1++)
        {
            for (c2 = c1; c2 <= hipotenusa; c2++)
            {

                if(hipotenusa == sqrt(c1*c1 + c2*c2)){
                    printf("hipotenusa = %i, catetos %i e %i\n", hipotenusa, c1, c2);
                }
            }
            
        }
        
    }


    return 0;
}
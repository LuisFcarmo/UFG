#include <stdio.h>
#include <string.h>
int compara (char pais[], char paisusuario[]){            ;
    return strcmp(pais, paisusuario);                
}
    
int main () {
    int c = 0;
    int boleano = 0;
    char pais[23][50] = { "brasil",  "portugal" ,"alemanha" , "austria" , "coreia" , "argentina", "chile" , "mexico" , "grecia",
    "estados-unidos" , "inglaterra", "australia", "suecia", "turquia", "argentina", "irlanda", "belgica", "italia",
    "siria", "japao" 
    };
    char frases[23][100] = { "Feliz Natal!", "Feliz Natal!", "Frohliche Weihnachten!", "Frohe Weihnacht!", "Chuk Sung Tan!",
    "Feliz Navidad!", "Feliz Navidad!", "Feliz Navidad!", "Kala Christougena!", "Merry Christmas!", "Merry Christmas!","Merry Christmas!", "God Jul!", "Mutlu Noeller", "Feliz Navidad!", "Nollaig Shona Dhuit!", "Zalig Kerstfeest!", "Zalig Kerstfeest!",
    "Buon Natale!", "Buon Natale!",    "Milad Mubarak!", "Milad Mubarak!", "Merii Kurisumasu!"
    };
    char paisusuario[50];
    while(EOF != scanf("%[^\n]%*c", paisusuario)){
        for (c = 0; c < 24; c++){
            if(compara(pais[c],paisusuario) == 0){
                boleano = 1;
                printf("%s\n", frases[c]);
                break;
                }
        }
        if(boleano == 0) {
            printf("-- NOT FOUND --\n");
        } 
        boleano = 0;
    }        
    return 0;        
}
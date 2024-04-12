#include <stdio.h>
#include <math.h>
#define max 10000

int row = 0;
int column = 0;
int lenght = 0;
int binario[max][max];
int AuxBin[8];
char word[max];

void BinToChar()
{
    int indice = 0;
    for (int row = 0; row < lenght; row++)
    {
        int number = 0;
        int potencia = 0;
        int pot = 0;

        for (int column = 0; column <= 7; column++)
        {
            pot = pow(2, potencia);
            number += binario[row][column] * pow(2, potencia);
            potencia++;
        }

        potencia = 0;
        word[indice] = number;
        indice++;
        number = 0;
    }
    word[indice] = '\0';
}

void CharToBin(char *vetor)
{
    int indice = 0;
    for (int i = 0; vetor[i] != '\0'; i++)
    {
        int number = vetor[i];
        while (number != 0)
        {
            binario[row][column] = number % 2;
            number /= 2;
            column++;
        }
        row++;
        column = 0;
    }
    lenght = row;
}

void DecimalToBin(int decimal)
{
    int indice = 0;
    while (decimal != 0)
    {
        AuxBin[indice] = decimal % 2;
        decimal /= 2;
        indice++;
    }
}

int BinToDecimal() {
    int potencia = 0;
    int decimal = 0;
    for (int i = 7; i >= 0; i--) {
        decimal += AuxBin[i] << potencia; // Shift left é equivalente a multiplicar por 2^potencia
        potencia++;
    }
    return decimal;
}


int main()
{
    int indice = 0;
    FILE *Img_Bin = fopen("images.png", "rb+");
    char brabiha[] = {"lucas"};
    int ByteModificado = 0;
    int byte;
    CharToBin(brabiha);
    BinToChar();
    /*
    for (int k = 0; k < lenght; k++) {
        for (int i = 7; i >= 0; i--) {
            printf("%d", binario[k][i]);
        }
        printf("\n");
    }*/
    // Lê os bytes do arquivo e faz o processamento necessário
    // Exemplo: leitura do conteúdo do arquivo e exibição dos primeiros 10 bytes
    for (int row = 0; row < lenght; row++)
    {
        for (int column = 7; column >= 0; column--)
        {

            byte = fgetc(Img_Bin);
            // printf("\n%d <= \n", byte);

            if (byte == EOF)
            {
                printf("Erro de leitura do arquivo.\n");
                break;
            }
            DecimalToBin(byte);
            /*
            for(int i = 0; i < 8; i++) {
                  printf("%d", AuxBin[i]);
            }*/

            // printf("%d numero que vai no ultimo bit ", binario[i][row]);
            AuxBin[7] = binario[row][column];
            // printf("resultado final = ");            
            //printf("%d-", AuxBin[7]);
            
            fseek(Img_Bin, indice, SEEK_CUR); // Move o ponteiro do arquivo de volta para a posição atual
            ByteModificado = BinToDecimal();
            fputc(ByteModificado, Img_Bin); // Esc      

            printf("%d\n", ByteModificado);
            indice++;
        }
    }
    /*
    
    for (int row = 0; row < lenght; row++)
    {
        for (int column = 7; column >= 0; column--)
        {
            printf("%d", binario[row][column]);
        }
    }
    
    */
    printf("------\n\n");
    fseek(Img_Bin, 0, SEEK_CUR); // Move the file pointer back one byte
    indice = 0;
    for (int i = 0; i < lenght; i++) {
        for (int k = 7; k >= 0; k--) {
            fseek(Img_Bin, indice, SEEK_CUR); // Move the file pointer back one byte
            byte = fgetc(Img_Bin);
            DecimalToBin(byte);
            printf("%d\n", byte);
            indice++;
        }

    }
    fclose(Img_Bin);
    
    
    return 0;
}
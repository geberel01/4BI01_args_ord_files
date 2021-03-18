//ESERCIZIO:
//DARE IN INGRESSO IL NOME DI UN FILE TXT
//CON STRINGHE NUMERICHE E DI CARATTERI
//E IL NOME DI UN FILE DI TESTO DA CREARE
//CON TUTTE LE STRINGHE NUMERICHE
//CONVERTITE IN BINARIO
//E LE STRINGHE DI CARATTERI
//IN ORDINE CRESCENTE

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int i;
FILE *FileIn;
FILE *FileOut;
char stringhe[20][20];
char string[20];
char c;

int num(char *str)
{
    int isdigit=1;
    int i=0;
    for (i=0;i<strlen(str);i++)
        if(isalpha(str[i]))
            isdigit=0;
    return isdigit;
}

int main(int argc, char *argv[])
{
    if(argc>3)
    {
        fprintf(stderr,"Troppi parametri\n");
        return 1;
    }
    
   if ((FileIn=fopen(argv[1],"r"))==NULL)
   {
       fprintf(stderr,"Errore fopen File Input\n");
       return 2;
   }
    if ((FileOut=fopen(argv[2],"w"))==NULL)
    {
        fprintf(stderr,"Errore fopen File Output\n");
        return 2;
    }
    
    i=0;
    while (( fscanf(FileIn,"%s\n",stringhe[i] ) ) != EOF)
    {
        printf("ho letto: %s\n",stringhe[i]);
        if ( num(stringhe[i]) )
        {
            printf("is number\n");
           
        }
        
    }


    
    fclose(FileIn);
    fclose(FileOut);

}

// ES. PROT. ORDINAMENTO:
// for(i=0)
//   for(j=1+1)
//    if arr[j]<arr[i] -> swap;
   
// ES. PROT. SWAP:
//     swap(char primo[20], char secondo[20])
//     {
//       char temp[20];
//       strcpy(primo,temp);
//       strcpy(secondo,primo);
//       strcpy(temp,secondo);
//     }
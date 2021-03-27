//ESERCIZIO:
//DARE IN INGRESSO IL NOME DI UN FILE TXT
//CON STRINGHE NUMERICHE E DI CARATTERI
//E IL NOME DI UN FILE DI TESTO DA CREARE
//CON TUTTE LE STRINGHE DI CARATTERI
//IN ORDINE CRESCENTE
//E STAMPARE A VIDEO LE STRINGHE NUMERICHE
//CONVERTITE IN BINARIO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int i;
FILE *FileIn;
FILE *FileOut;
char stringhe[20][30];
char string[30];
char c;

int isnum(char *str);
int str2bin();

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
    
    while (( fscanf(FileIn,"%s\n",string ) ) != EOF)
    {
        printf("ho letto: %s\n",string);
        
        if ( isnum(string) )
        {
            printf("conversione-> ");
            str2bin(string);
           
        }
        else
        {
          strcpy(stringhe[i],string);
          i++;
        }
        

    }
    printf("array di stringhe da ordinare:\n");
    for(i=0;i<=strlen(stringhe[0]);i++)
    printf("stringa: %s\n",stringhe[i]);
    // sotto else devo copiare le stringhe
    
    fclose(FileIn);
    fclose(FileOut);
    
    
  return 0;

}


int isnum(char *str)
{
    int isdigit=1;
    int i=0;
    for (i=0;i<strlen(str);i++)
        if(isalpha(str[i])) // correggere tipo e valore logico
            isdigit=0;
    return isdigit;
}



int str2bin(char string[])
{

    int dec;
    int i;
    char* ptr;
    dec=strtol(&string[0],&ptr,10);
//    printf("VAL: %d\n",dec);
    
//      METODO POTENZE
//    int resto,div,bin=0;
//    int cont=0;
//    double pot;
//    do{
//        div=dec/2;
//        resto=(dec%2);
//        dec=div;
//        pot=pow(10,cont);
//        bin=bin+(resto*pot);
//        cont=cont+1;
//    }while(dec!=0);
//    printf("Il numero convertito e' %d\n", bin);
    
//      METODO ARRAY DI CARATTERI 0/1
    char strbin[30];
    for(i=0;i<30;i++)
    strbin[i]=0;
        i=0;
        do{
            strbin[i]=(dec%2)+48; // vedi tabella ASCII
            i=i+1;
            dec=dec/2;
        }while(dec!=0);

    int n=strlen(strbin);
        i=0;
        for(i=n-1;i>=0;i--)
          printf("%c",strbin[i]);
        
        printf("\n");
    
    
    
    return 0;
}


// ES. PROT. ORDINAMENTO:
// for(i=0)
//   for(j=1+1)
//    if arr[j] < arr[i] -> swap;

//strcmp(stringa1,stringa2) --> -1,0,+1
   
// ES. PROT. SWAP:
//     swap(char primo[20], char secondo[20])
//     {
//       char temp[20];
//       strcpy(primo,temp);
//       strcpy(secondo,primo);
//       strcpy(temp,secondo);
//     }
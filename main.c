//ESERCIZIO:
//DARE IN INGRESSO IL NOME DI UN FILE TXT
//CON STRINGHE NUMERICHE E DI CARATTERI
//E IL NOME DI UN FILE DI TESTO DA CREARE
//CON TUTTE LE STRINGHE NUMERICHE
//CONVERTITE IN BINARIO
//E LE STRINGHE DI CARATTERI
//IN ORDINE CRESCENTE

#include <stdio.h>

int main(int argc, char *argv[]) {
  for(i=0;i<argc;i++)
    {
      printf("Pos %d\t stringa: %s\n",i,argv[i]);
    }
    printf("somma: %d\n",sum);
  return 0;
  strcp
}

ES. PROT. ORDINAMENTO:
for(i=0)
  for(j=1+1)
   if arr[j]<arr[i] -> swap;
   
ES. PROT. SWAP:
    swap(char primo[20], char secondo[20])
    {
      char temp[20];
      strcpy(primo,temp);
      strcpy(secondo,primo);
      strcpy(temp,secondo);
    }
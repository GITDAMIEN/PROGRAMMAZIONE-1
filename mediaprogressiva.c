/*Scrivere un programma in linguaggio C che legga da tastiera una sequenza di lunghezza ignota a priori di numeri interi positivi. Il programma, a partire dal primo numero introdotto, stampa ogni volta la media di tutti i numeri introdotti. Terminare quando il numero inserito è negativo.  */

#include<stdio.h>

int main(){
  int num, somma=0, tot=0;
  float media;
  
  printf("Inserisci sequenza di numeri positivi: ");
  do{
    scanf("%d", &num);
    somma+=num;
    tot++;
    media=(float)somma/tot;
    if(num>=0)
      printf("Media progressiva: %.2f\n", media);
  }while(num>=0);
  
  if(num<0)
    printf("Fine programma.\n");
    
  return 0;
}
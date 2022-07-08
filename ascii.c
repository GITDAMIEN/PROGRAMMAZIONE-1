/*Si scriva un programma in linguaggio C che legga da tastiera un numero intero A, lo riduca ad un valore compreso tra 0 e 127 mediante sottrazione ripetuta di un adeguato numero di volte del valore 128 (non si utilizzi l’operatore modulo o and), lo interpreti come caratteri ASCII e lo stampi sul video. */

#include<stdio.h>

int main (){
  int A, n=128;
  char B;
  
  printf("Inserisci valore intero positivo superiore a 127: ");
  do{
    scanf("%d", &A);
    if(A<128)
      printf("\nValore non valido. Inserisci valore intero positivo superiore a 127: ");
  }while(A<128);
  
  while(A>127)
    A-=128;
  
  B=A;
  
  printf("\nEsito: %c\n", B);
  
  return 0;
}
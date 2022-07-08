/*Scrivere un programma che inizializzi un array di 10 elementi con numeri casuali compresi tra due valori min e max inseriti dall'utente.
Il valore max non può essere minore del valore min. Il programma deve stampare l'array come da esempio:
Inserisci un valore min: 1
Inserisci un valore max: 0
Inserisci un valore max: 100
23 56 100 78 1 24 8 12 77 64
*/

#include<stdio.h>
#include<stdlib.h>
#define N 10

int main(){
  int min, max, i, arr[N];
  srand(1);
  
  printf("Inserisci un valore min: ");
  scanf("%d", &min);
  
  do{
    printf("Inserisci un valore max: ");
    scanf("%d", &max);
  }while(max<min);
  
  for(i=0;i<N;i++)
    arr[i]=rand()%(max-min+1)+min;
  
  printf("Esito: ");
  for(i=0;i<N;i++)
    printf("%3d", arr[i]);
  printf("\n");
  
  return 0;
}





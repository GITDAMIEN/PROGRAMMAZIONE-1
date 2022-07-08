/*Scrivere un programma in linguaggio C che legga da tastiera una sequenza di numeri positivi e ad ogni numero letto ne stampi la somma progressiva. Il programma termina quando si introduce un numero minore o uguale a zero. */

#include<stdio.h>

int main(){
  int num, somma=0;
  
  printf("Inserisci sequenza di numeri positivi: ");
  do{
    scanf("%d", &num);
    somma+=num;
    if(num>0)
      printf("Somma progressiva: %d\n", somma);
  }while(num>0);
  
  if(num<=0)
    printf("Fine programma.\n");
    
  return 0;
}
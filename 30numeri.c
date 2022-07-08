/*Scrivere un programma in linguaggio C che riceve in ingresso una sequenza di N numeri interi. I numeri sono memorizzati in un vettore. Il valore N è inserito dall’utente, ma il vettore può contenere al massimo 30 numeri. Terminato l’inserimento della sequenza di numeri, il programma deve verificare se gli elementi del vettore sono tutti uguali tra loro.*/

#include<stdio.h>

int main (){
  int N, arr[N], i, flag=1;
  
  printf("Inserisci dimensione del vettore: ");
  do{
    scanf("%d", &N);
    if(N>30)
      printf("Valore non valido. Dimensione massima: 30. Inserisci dimensione del vettore: ");
  }while(N>30);
  
  printf("Ok, ora inserisci la sequenza di numeri interi: ");
  for(i=0;i<N;i++)
    scanf("%d", &arr[i]);
  
  for(i=0;i<N-1;i++)
    if(arr[i]!=arr[i+1])
      flag=0;
  
  if(flag)
    printf("\nTutti i valori inseriti sono uguali.\n");
  else
    printf("\nI valori non sono tutti uguali.\n");
  
  
  return 0;
}
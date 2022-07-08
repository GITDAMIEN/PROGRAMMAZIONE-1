/*Scrivere un sottoprogramma simmetrico che ricevuto in ingresso un array di interi e la sua dimensione effettiva, restituisce 1 se l’array è simmetrico (ossia uguale se i suoi valori sono letti nei due versi) 0 altrimenti. Ad esempio, l’array {2, 5, 2} è simmetrico (la funzione restituirà 1), mentre l’array {2, 5, 4, 2} non lo è (la funzione restituirà 0). */

#include<stdio.h>
#define N 5

int simmetrico (int arr[], int n);

int main(){
  int i, arr[N];
  
  printf("Inserisci i valori dell'array: ");
  for(i=0;i<N;i++)
    scanf("%d", &arr[i]);
  
  printf("\nSimmetrico? %d\n", simmetrico(arr,N));
  
  return 0;
}

int simmetrico(int arr[N], int n){
  int i, res=1;
  
  for(i=0;i<n/2;i++)
    if(arr[i]!=arr[n-1-i])
      res=0;

  
  return res;
}
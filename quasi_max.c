/*Si completi il seguente programma scrivendo la funzione quasi_max che riceve un array di interi e la sua lunghezza e ritorna il quasi massimo dell'array, cioè il più grande numero contenuto nell'array che non sia il massimo. Per esempio, sotto dovrà venire stampato 23, che è il quasi massimo di arr.
Nota: per semplicità si assuma che il quasi massimo dell'array esista, quindi non ci si preoccupi di gestire i casi in cui esso non esiste, per esempio quando l'array è vuoto o ha un solo elemento.
Suggerimento: definite funzioni ausiliarie, se vi risultano di aiuto.
*/

#include<stdio.h>

int quasi_max(int [], int);

int main(void){
  int arr[]={28,10,7,9,14,22,23,28,-4,23};
  printf("Quasi massimo: %d\n", quasi_max(arr,10));
  return 0;
}

int quasi_max(int m[], int dim){
  int i, max=m[0], min=m[0], quasimax;

  for(i=0;i<dim;i++)
    if(m[i]>max)
      max=m[i];
  
  for(i=0;i<dim;i++)
    if(m[i]<min)
      min=m[i];
  
  quasimax=min;
  
  for(i=0;i<dim;i++){
    if(m[i]>quasimax&&m[i]<max)
      quasimax=m[i];
  }

  return quasimax;
}

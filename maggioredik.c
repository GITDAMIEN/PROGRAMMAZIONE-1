/*Scrivere un sottoprogramma maggioredik che ricevuto in ingresso un array di interi, la sua dimensione effettiva e un intero k, restituisca il piu` piccolo valore strettamente maggiore di k che si presenta nell’array, oppure -1 se tale valore non esiste.
Ad esempio, se a[] = {5,4,3,6,3,5} e k = 3, allora la funzione deve restituire 4.*/

#include<stdio.h>
#define D 6

int maggioredik (int a[], int dim, int k);

int main(){
  int a[D]={5,4,3,6,3,5};
  int k;
  
  printf("Inserisci valore k: ");
  scanf("%d", &k);
  
  printf("Esito: %d\n", maggioredik(a, D, k));
  
  
  return 0;
}

int maggioredik(int a[D], int dim, int k){
  int i, flag=0, esito=0;
  
  for(i=0;i<dim;i++)
    if(a[i]>k){
      flag=1;
      if(esito!=0){
        if(a[i]<esito)
          esito=a[i];
      }
      else
        esito=a[i];
    }
    
  if(flag)
    return esito;
  else
    return -1;
}











/*scrivere un sottoprogramma che riceve in ingresso un array di interi v e qualsiasi altro parametro ritenuto necessario, ed altri due valori interi da e a.
Il sottoprogramma verifica se nell'array sono presenti tutti e soli i valori inclusi nell'intervallo [da,a], senza ripetizioni. In caso positivo il sottoprogramma restituisce 1, 0 in caso contrario.*/

#include<stdio.h>
#define N 10

void intervallo(int [], int, int);

int main(){
  int arr[N], i, da, a;
  
  printf("Inserisci valori dell'array: ");
  for(i=0;i<N;i++)
    scanf("%d", &arr[i]);
  
  printf("Inserisci valori d'intervallo:\nDa: ");
  scanf("%d", &da);
  printf("A: ");
  scanf("%d", &a);

  intervallo(arr,da,a);
  
  return 0;
}

void intervallo(int arr[], int da, int a){
  int esito=1, i, j;
  
  /*int count=0;
  
  count=a-da+1;
  */
  
  for(i=0;i<N&&esito;i++)
    if(arr[i]<da||arr[i]>a)
      esito=0;
    else
      for(j=0;j<i;j++)
        if(arr[i]==arr[j])
          esito=0;
  
  printf("Esito: %d\n", esito);
  
}
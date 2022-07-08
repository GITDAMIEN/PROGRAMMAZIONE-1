#include<stdio.h>
#define D 10

int main (){
  int arr[D], i;
  
  printf("Inserisci i 10 valori dell'array:\n");
  for(i=0;i<D;i++)
    scanf("%d", &arr[i]);
  
  //stampo l'array
  for(i=0;i<D;i++)
    printf("%3d", arr[i]);
  printf("\n");
  
  //stampo la somma di ogni elemento dell'array con il precedente (tranne arr[0])
  for(i=1;i<D;i++)
    printf("%3d", arr[i]+arr[i-1]);
  printf("\n");
  
  return 0;
}
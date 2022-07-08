/*Scrivere programma C che dati due array di interi ORDINATI (al massimo di 10 elementi), costruisce un terzo array ordinato che è la fusione dei due di partenza*/

#include<stdio.h>
#define N 10

int main(){
  int a[N]={1,2,4,5,6,7,8,9,11,13}, b[N]={2,3,4,5,6,7,8,9,10,11}, c[N];
  int i;

  printf("\nArray a:");
  for(i=0;i<N;i++)
    printf("%3d", a[i]);
    
  printf("\nArray b:");
  for(i=0;i<N;i++)
    printf("%3d", b[i]);
    
  printf("\nArray fusione:");
  for(i=0;i<N;i++){
    c[i]=a[i]*b[i];
    printf("%5d", c[i]);
  }
  printf("\n");
  
  return 0;
}
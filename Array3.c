#include<stdio.h>
#define N 10

int main (){
  //dichiarazioni
  int A[N]={1,-3,1,4,-3,-4,2,-3};
  int x, i, cont;
  
  //leggo x
  printf("Inserisci valore da cercare: ");
    scanf("%d", &x);
  
  //verifico le ricorrenze
  cont=0;
  for(i=0;i<N;i++)
    if(x==A[i])
      cont++;
  
  //stampo quante ricorrenze ho trovato
  printf("Il valore %d è presente %d volte\n", x, cont);
  
  return 0;
}
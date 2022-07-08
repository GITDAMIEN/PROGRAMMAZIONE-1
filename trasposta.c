/*Scrivere un programma che, data un matrice quadrata, ne crea la trasposta dove N[i][j]=M[j][i] per ogni j e ogni i */

#include<stdio.h>
#define D 4

int main (){
  int M[D][D], N[D][D];
  int i, j;
  
  printf("Inserisci i valori della prima matrice quadrata:\n");
  for(i=0;i<D;i++)
    for(j=0;j<D;j++)
      scanf("%d", &M[i][j]);
  
  //creo la matrice trasposta
  for(i=0;i<D;i++)
    for(j=0;j<D;j++)
      N[i][j]=M[j][i];
  
  //stampo la prima matrice
  printf("La matrice originale M è:\n");
  for(i=0;i<D;i++){
    for(j=0;j<D;j++)
      printf("%3d", M[i][j]);
    printf("\n");
  }
  printf("\n");
  
  //stampo la seconda matrice
  printf("La matrice trasposta N è:\n");
  for(i=0;i<D;i++){
    for(j=0;j<D;j++)
      printf("%3d", N[i][j]);
    printf("\n");
  }
  printf("\n");
  
  return 0;
}
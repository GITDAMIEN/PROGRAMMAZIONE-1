/*Scrivere un programma che somma 2 matrici di pari dimensioni in una terza matrice*/

#include<stdio.h>
#define D 5

int main(){
  int a1[D][D]={
    {1,1,1,1,1},
    {2,2,2,2,2},
    {3,3,3,3,3},
    {4,4,4,4,4},
    {5,5,5,5,5}},
      a2[D][D]={
    {2,2,2,2,2},
    {3,3,3,3,3},
    {4,4,4,4,4},
    {5,5,5,5,5},
    {6,6,6,6,6}},
      a3[D][D];
  int i, j;
  
  for(i=0;i<D;i++)
    for(j=0;j<D;j++)
      a3[i][j]=a1[i][j]+a2[i][j];
  
  printf("Prima matrice:\n");
  for(i=0;i<D;i++){
    for(j=0;j<D;j++)
      printf("%3d", a1[i][j]);
    printf("\n");
  }
  
  printf("\nSeconda matrice:\n");
  for(i=0;i<D;i++){
    for(j=0;j<D;j++)
      printf("%3d", a2[i][j]);
    printf("\n");
  }
  
  printf("\nTerza matrice:\n");
  for(i=0;i<D;i++){
    for(j=0;j<D;j++)
      printf("%3d", a3[i][j]);
    printf("\n");
  }
  
  return 0;
}
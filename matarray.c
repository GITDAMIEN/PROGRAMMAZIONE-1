/*Scrivi un programma che memorizza tutte le righe di una matrie di interi 4x6 in un unico array di interi lungo 24*/

#include<stdio.h>
#define R 4
#define C 6

int main(){
  int mat[R][C]={{1,4,5,2,3,6},{4,5,4,1,1,1},{7,3,2,3,4,5},{2,2,6,6,0,1}};
  int arr[R*C];
  int i, j, k=0;
  
  /*SE VOGLIO CHIEDERE DA INPUT I VALORI DELLA MATRICE
  printf("Inserisci i valori della matrice:\n");
  for(i=0;i<R;i++)
    for(j=0;j<C;j++){
      scanf("%d", &mat[i][j]);
      arr[k]=mat[i][j];
      k++;
    }
  */
  
  for(i=0;i<R;i++)
    for(j=0;j<C;j++){
      arr[k]=mat[i][j];
      k++;
    }
  
  printf("La matrice è:\n");
  for(i=0;i<R;i++){
    for(j=0;j<C;j++)
      printf("%3d", mat[i][j]);
    printf("\n");
  }
  
  printf("\nL'array ottenuto è: ");
  for(k=0;k<R*C;k++)
    printf("%3d", arr[k]);
  printf("\n");
      
  return 0;
}
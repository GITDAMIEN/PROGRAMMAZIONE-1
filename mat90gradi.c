#include<stdio.h>
#define N 3

/*Inserisci da tastiera una matrice 3x3 e costruisci una seconda matrice che è la prima matrice ruotata
di 90° in senso antiorario */

int main (){
  int mat1[N][N], mat2[N][N];
  int i, j;
  
  //leggo la matrice 1
  printf("Inserisci i valori della matrice1:\n");
  for(i=0; i<N; i++)
    for(j=0; j<N; j++)
      scanf("%d", &mat1[i][j]);
  
  //creo la matrice 2  ruotando la 1 di 90 gradi in senso antiorario
  for(i=0;i<N;i++)
    for(j=0;j<N;j++)
      mat2[N-1-j][i]=mat1[i][j];
  
  //stampo la matrice1
  printf("La matrice1 è:\n");
  for(i=0;i<N;i++){
    for(j=0;j<N;j++)
      printf("%3d", mat1[i][j]);
    printf("\n");
  }
  printf("\n");
  
  //stampo la matrice2
  printf("La matrice2 è:\n");
  for(i=0;i<N;i++){
    for(j=0;j<N;j++)
      printf("%3d", mat2[i][j]);
    printf("\n");
  }  
  printf("\n");
  
  return 0;
}
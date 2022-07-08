/*Scrivere un programma che data una matrice int A[M][M] verifichi se per ogni elemento x della diagonale principale
esiste almeno un elemento y della diagonale secondaria tale che y>x.*/

#include<stdio.h>
#define M 5

int main (){
  int A[M][M];
  int i, j, h, flag, cont=0;
  
  printf("Inserisci i valori della matrice:\n");
  for(i=0;i<M;i++)
    for(j=0;j<M;j++)
      scanf("%d", &A[i][j]);
  
  for(i=0;i<M;i++)
    for(j=0;j<M;j++)
      for(h=0,flag=0;h<M;h++){
        if(i==j&&A[i][j]<A[h][M-1-h])
          flag=1;
        if(flag)
          cont++;
      }
  
  if(cont==M)
    printf("Per ogni elemento della diagonale principale esiste un elemento della diagonale secondaria superiore ad esso.\n");
  else
    printf("Non ogni elemento della diagonale principale ha un elemento della diagonale secondaria che gli sia superiore.\n");

  return 0;
}
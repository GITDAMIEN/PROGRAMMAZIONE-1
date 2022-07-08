/*Scrivi un programma che chiede all'utente di inserire i valori di una matrice di interi 3x3.
Il programma stampa a video il valore 1 se la matrice contiene tutti gli interi a partire da 0 gino al numero di celle matrice -1, 0 in caso contrario.
Ad esempio: con la matrice   1  0  2
                             3  4  6
                             5  7  8
Il programma stamperà a video il valore 1.*/

#include<stdio.h>
#define D 3

int main(){
  int mat[D][D];
  int i, j, val=0, cont=0;
  
  printf("Inserisci i valori della matrice:\n");
  for(i=0;i<D;i++)
    for(j=0;j<D;j++)
      scanf("%d", &mat[i][j]);
  
  //verifico se tutti gli interi da 0 a D-1 compaiono nella matrice
  for(i=0;i<D;i++)
    for(j=0;j<D;j++)
      for(val=0;val<D;val++)
        if(mat[i][j]==val)
          cont++;
  
  printf("Tutti i valori presenti? ");
  if(cont==D)
    printf("1.\n");
  else
    printf("0.\n");
      
      
  return 0;
}
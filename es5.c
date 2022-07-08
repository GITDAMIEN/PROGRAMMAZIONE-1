/*Scrivere un programma che permette all’utente di inserire una matrice di valori interi di dimensione NxN (con N pari a 5). Il programma deve poi calcolare e stampare l’indice della colonna in cui la massima differenza (in valore assoluto) ottenuta tra due suoi elementi, sia massima. Nel caso ci sia più̀di una colonna con uguale differenza massima, stamperà l'indice della prima colonna trovata.
Ad esempio, se la matrice inserita fosse:
                                             2  5 10 15 18
                                            11  7  7 20 15
                                             5  5  7 11 22
                                             6  1  3 16 19
                                             7  1  2 10 18
Il programma stamperà l’indice 3: tale colonna ha come massima differenza 10 (diff. tra 20 e 10), ed èmaggiore della differenza
massima delle altre quattro colonne, rispettivamente 9, 6, 8 e 7. */

#include<stdio.h>
#define N 5

int main(){
  int mat[N][N];
  int i, j, k, maxl=0, maxt=0, col=0;
  
  printf("Inserisci i valori della matrice:\n");
  for(i=0;i<N;i++)
    for(j=0;j<N;j++)
      scanf("%d", &mat[i][j]);
  
  printf("Ecco la matrice inserita:\n");
  for(i=0;i<N;i++){
    for(j=0;j<N;j++)
      printf("%3d", mat[i][j]);
    printf("\n");
  }
  printf("\n");
  
  //verifico per ciascuna colonna la differenza massima tra i suoi elementi
  for(j=0;j<N;j++){
    for(i=0;i<N;i++)
      for(k=1;k<N;k++)
        if(mat[k][j]-mat[i][j]>maxl)
          maxl=mat[k][j]-mat[i][j];
    if(maxl>maxt){
      maxt=maxl;
      col=j;
    }
  }
  
  //stampo risultato
  printf("La colonna in cui c'è la differenza massima tra 2 valori è quella con indice %d\n", col);
  
  return 0;
}









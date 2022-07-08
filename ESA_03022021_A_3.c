/*Si completi il file ESA 03022021 A 3.c in modo che che il programma:
-) dichiari una matrice di nome Matrix, di dimensione NxM (dove N e M sono definiti a inizio programma come N=2, M=3), di numeri interi;
-) dichiari due vettore di interi di nome SumR e SumC di dimensione N e M rispettivamente;
-) inizializzi la matrice t.c. le righe pari (incluso riga 0) abbiano numeri random pari e le righe dispari abbiano numeri random dispari, sia pari che dispari compresi tra 0 e 10 (si ricorda che 2*x `e sempre un numero pari e che 2*x+1 `e sempre un numero dispari);
-) implementi la somma per righe e per colonne salvando i risultati in SumR (SumR[0] conterr`a la somma degli interi di Matrix riga 0, SumR[1] la somma di riga 1 etc.) e SumC (SumC[0] conterr`a la somma degli interi di Matrix colonna 0, SumC[1] la somma di colonna 1, etc.);
-) stampi Matrix e Sum.

Un esempio con N=3, M=2, e il seguente:

Matrix:
2 2 10
3 7 3

SumR:
14 13

SumC:
5 9 13
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
 ulteriori direttive di pre-processing
*/
#define N 2
#define M 3

int main(void) {
/*
dichiarazioni
*/
  int mat[N][M];
  int sumr[N]={0}, sumc[M]={0};
  int i, j;
  srand(time(NULL));
/*
inizializzazione Matrix:
*/
  for(i=0;i<N;i++)
    for(j=0;j<M;j++)
      if(i%2==0)
        mat[i][j]=rand()%6*2;
      else
        mat[i][j]=rand()%5*2+1;
/*
somma per righe
*/
  for(i=0;i<N;i++)
    for(j=0;j<M;j++)
      sumr[i]+=mat[i][j];
/*
somma per colonne
*/
  for(i=0;i<N;i++)
    for(j=0;j<M;j++)
      sumc[j]+=mat[i][j];
/*
stampe di Matrix, SumR e SumC
*/
  //matrix
  printf("Matrix: \n");
  for(i=0;i<N;i++){
    for(j=0;j<M;j++)
      printf("%3d", mat[i][j]);
    printf("\n");
  }
  printf("\n");
  
    //sumr
  printf("SumR: \n");
  for(i=0;i<N;i++)
      printf("%3d", sumr[i]);
  printf("\n");
 
    //sumc
  printf("\nSumC: \n");
  for(j=0;j<M;j++)
      printf("%3d", sumc[j]);
    printf("\n");

  
    
  return 0;
}
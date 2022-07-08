/*Si completi il file ESA 03022021 C 3.c in modo che il programma:
-) dichiari una matrice costante di nome A, di dimensione NxM (dove N e M sono definiti a inizio programma come N=2 e M=3), di numeri interi;
-) dichiari una matrice di interi B di dimensione NxM;
-) inizializzi A come segue:
A:
18 -1 -21
26 33 -49
-) chieda all’utente l’inserimento di tutti i valori interi per B;
-) calcoli la somma A+B e la salvi in una matrice Sum;
-) stampi la matrice Sum, il suo valore massimo e gli indici del valore massimo. Ad esempio, con i seguenti valori inseriti dall’utente: 1, 1, 1, 2, 2, 2 il programma stamper`a:
Sum:
[ 19][ 0][-20]
[ 28][ 35][-47]
Il valore massimo `e 35 e si trova in Sum[1][1]
*/

//ESA_03022021_C_3.c
#include <stdio.h>
#include <stdlib.h>
/*
 ulteriori direttive di pre-processing
*/
#define N 2
#define M 3

int main(void){
    /*
    dichiarazioni
    */
  int A[N][M]={
    {18,-1,-21},
    {26,33,-49}};
  int B[N][M], i, j;
  int Sum[N][M], max, maxi, maxj;
    
    
    /*
     inserimento valori in B da tastiera:
    */
    printf("Inserisci i valori della matrice B:\n");
    for(i=0;i<N;i++)
      for(j=0;j<M;j++)
        scanf("%d", &B[i][j]);
      
    /*
     calcolo somma tra matrici
     */
    for(i=0;i<N;i++)
      for(j=0;j<M;j++)
        Sum[i][j]=A[i][j]+B[i][j];
    /*
     stampa Sum
     */
    printf("\nSum:\n");
    for(i=0;i<N;i++){
      for(j=0;j<M;j++)
        printf(" [%2d]", Sum[i][j]);
      printf("\n");
    }
    printf("\n");
  
    /*
     calcolo e stampa del valore massimo e degli indici del valore massimo in Sum
     */
    max=Sum[0][0];
    maxi=0;
    maxj=0;
    for(i=0;i<N;i++)
      for(j=0;j<M;j++)
        if(Sum[i][j]>max){
          max=Sum[i][j];
          maxi=i;
          maxj=j;
        }
    
    printf("Il valore massimo è %d e si trova in Sum[%d][%d].\n", max, maxi, maxj);
  
    return 0;
};
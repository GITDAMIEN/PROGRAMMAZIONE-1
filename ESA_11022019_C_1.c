/*Si completi il file ESA 11022019 C 1.c in modo che il programma implementi il prodotto tra matrici quadrate
di interi. In particolare, il programma dovr`a:
-) dichiarare e inizializzare due matrici A e B di dimensione NxN (ove N `e definito all’inizio del programma
come N=3) con i seguenti valori interi costanti:
A: B:
1 1 1 1 2 3
2 2 2 1 2 3
3 3 3 1 2 3
-) dichiarare e allocare una matrice risultato R di dimensioni NxN;
-) calcolare il prodotto tra matrici R=A x B;
-) stampi la matrice risultato;
-) NB: si deve completare il file di riferimento nei punti contrassegnati da commenti (//). NON si deve
modificare il resto del codice esistente;
-) Si ricorda che il prodotto tra due matrici NxN `e implementato dal seguente pseudocodice:
for i=1,N
for j=1,N
tmp =0;
for k=1,N
tmp = tmp+A[i,k]*B[k,j];
R[i,j]=tmp;
Si stampi il loro prodotto che, se tutto corretto, risulter`a come segue:
3 6 9
6 12 18
9 18 27
*/

#include<stdio.h>
#define N 3

int main (){
  int A[N][N]={{1,1,1},
               {2,2,2},
               {3,3,3}};
  int B[N][N]={{1,2,3},
               {1,2,3},
               {1,2,3}};
  int R[N][N]={0};
  int i, j, h, k;
  
  
  for(i=0;i<N;i++)
    for(j=0;j<N;j++)
      for(k=0;k<N;k++)
        R[i][j]+=A[i][k]*B[k][j];
      
  
  printf("Matrice risultato:\n");
  for(i=0;i<N;i++){
    for(j=0;j<N;j++)
      printf("%3d", R[i][j]);
    printf("\n");
  }
  printf("\n");
  
  
  return 0;
}
















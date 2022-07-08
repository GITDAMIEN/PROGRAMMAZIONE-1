/*Scrivere un programma C che chiede all’utente un numero intero n. Il programma inizializza il contenuto della matrice seguendo il seguente schema:
  n n+1 n+2 n+3 n+4
n+1 n+1 n+2 n+3 n+4
n+2 n+2 n+2 n+3 n+4
n+3 n+3 n+3 n+3 n+4
n+4 n+4 n+4 n+4 n+4

Per esempio se n=5, il programma popolerà la matrice come segue:

5 6 7 8 9
6 6 7 8 9
7 7 7 8 9
8 8 8 8 9
9 9 9 9 9
*/

#include<stdio.h>
#define N 5

int main(){
  int mat[N][N];
  int i, j, n;
  
  printf("Inserisci valore intero: ");
  scanf("%d", &n);
  
  for(i=0;i<N;i++)
    for(j=0;j<N;j++)
      if(j>i)
        mat[i][j]=n+j;
      else
        mat[i][j]=n+i;
  
  printf("Ecco la matrice generata:\n");
  for(i=0;i<N;i++){
    for(j=0;j<N;j++)
      printf("%3d", mat[i][j]);
    printf("\n");
  }
  printf("\n");
  
  return 0;
}

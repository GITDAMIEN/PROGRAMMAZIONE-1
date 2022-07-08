/*Scrivere un sottoprogramma C che riceve come parametri due matrici quadrate 4x4 di numeri interi, chiamate m1 e m2. Il sottoprogramma calcola e restituisce al chiamante il numero di volte che il valore m1[i][j]=m2[i][j]
Esempio: Date in ingresso le due matrici sotto il sottoprogramma restituirà il valore 4.
9 4 9 2    1 2 3 4
3 4 6 8    3 4 1 1
5 2 3 4    1 1 7 4
3 4 5 2    3 6 7 8
*/

#include<stdio.h>
#define N 4

int uguali(int [][N], int [][N]);

int main(){
  int m1[N][N]={
    {9, 4, 9, 2},
    {3, 4, 6, 8},
    {5, 2, 3, 4},
    {3, 4, 5, 2}};
  int m2[N][N]={
    {1, 2, 3, 4},
    {3, 4, 1, 1},
    {1, 1, 7, 4},
    {3, 6, 7, 8}};
  
  printf("I valori di m1 e m2 che coincidono sono: %d\n", uguali(m1, m2));
  
  return 0;
}


int uguali(int m1[][N], int m2[][N]){
  int cont=0;
  int i, j;
  
  for(i=0;i<N;i++)
    for(j=0;j<N;j++)
      if(m1[i][j]==m2[i][j])
        cont++;
    
  return cont;
}

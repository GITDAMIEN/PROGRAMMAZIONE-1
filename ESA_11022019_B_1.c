/*Si completi il file ESA 11022019 B 1.c in modo che che il programma:
-) dichiari un array di numeri decimali di nome Array di dimensione N;
-) dichiari una matrice di nome M, di dimensione NxN (dove N `e definito a inizio programma come N=3), di numeri decimali;
-) chieda all’utente l’inserimento dei N valori per Array;
-) inizializzi la matrice t.c. le righe pari (incluso riga 0) abbiano numeri random compresi tra 0.00 e 20.00 mentre le righe dispari abbiano numeri random compresi tra 0.00 e 10.00;
-) stampi M e Array. Un esempio con N=3 e 0.5, 1.5, 2.5 inseriti dall’utente per Array `e il seguente:
M:
14.00 14.00 3.00
1.00 4.00 6.00
18.00 15.00 15.00
Array:
0.5 1.5 2.5
-) implementi il prodotto matrice x vettore e stampi il risultato. Si ricorda che il risultato `e dato da un vettore Result[] di dimensione N, ove ogni elemento `e calcolato come segue:
for i=1,N
for j=1,N
Result[i] = Result[i] + M[i,j] * Filter [j];
Ad esempio, il risultato del prodotto tra matrice e vettore dell’esempio sopra `e il seguente:
Result:
35.50 21.50 69.00
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 3

int main(){
  float array[N];
  float M[N][N];
  int i, j;
  srand(time(NULL));
  float Result[N]={0};
  
  printf("Prego inserisci i valori di array:\n");
  for(i=0;i<N;i++)
    scanf("%f", &array[i]);
  
  //inizializzazione matrice
  for(i=0;i<N;i++)
    for(j=0;j<N;j++)
      if(i%2==0)
        M[i][j]=rand()%21;
      else
        M[i][j]=rand()%11;
  
  //stampa di M
  printf("\nM:\n");
  for(i=0;i<N;i++){
    for(j=0;j<N;j++)
      printf("%.2f  ", M[i][j]);
    printf("\n");
  }
  printf("\n");

  //stampa di array
  printf("Array: \n");
  for(i=0;i<N;i++)
    printf("%.1f ", array[i]);
  printf("\n");

  //prodotto matrice per vettore
  for(i=0;i<N;i++){
    for(j=0;j<N;j++)
      Result[i]+=M[i][j]*array[j];
  }
      
  //stampa di Result
  printf("\nResult: \n");
  for(i=0;i<N;i++)
    printf("%.2f ", Result[i]);
  printf("\n");
  
  
  return 0;
}

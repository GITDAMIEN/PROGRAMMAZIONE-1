/*Si scriva un programma C che permetta all’utente di inizializzare una matrice di interi di dimensione NxN (con N dato) con numeri interi compresi tra 0 e 99 (estremi inclusi). Dopo aver stampato la matrice a video, il programma deve chiedere all’utente di inserire il valore di un intero val e deve poi contare e stampare a video le occorrenze di val di ogni riga della matrice. Infine, il programma deve sostituire con uno 0 le occorrenze di val nelle sole righe della matrice con più di due occorrenze di val.
Ad esempio, dato N=4, se l’utente inserisce la seguente matrice:
11 42  0 47
55  3 45 12
55 23 55 55
 1  5  7  0
Il programma, dopo averla visualizzata a video, deve chiedere all’utente il valore della variabile val. Se l’utente digita il numero 55 il programma stampa a video:
Occorrenze di 55 nelle righe della matrice:
riga 1: 0 occorrenze
riga 2: 1 occorrenza
riga 3: 3 occorrenze
riga 4: 0 occorrenze
Matrice modificata:
11 42  0 47
55  3 45 12
 0 23  0  0
 1  5  7  0
*/

#include<stdio.h>
#define N 4

void stampa(int [][N], int, int [], int );

int main(){
  int i, j, val, mat[N][N];
  int cont=0;
  int arr[N];

  printf("Inserisci i valori della matrice %dx%d (compresi tra 0 e 99):\n", N, N);
  for(i=0;i<N;i++)
    for(j=0;j<N;j++)
      do{
        scanf("%d", &mat[i][j]);
        if(mat[i][j]>99||mat[i][j]<0)
          printf("Valore non valido, dev'essere compreso tra 0 e 99.\n");
      }while(mat[i][j]>99||mat[i][j]<0);
  
  printf("Matrice inserita:\n");
  stampa(mat, N, arr, val);

  printf("Inserisci valore da cercare (compreso tra 0 e 99): ");
  do{
    scanf("%d", &val);
    if(val>99||val<0)
      printf("Valore non valido, dev'essere compreso tra 0 e 99.\n");
  }while(val>99||val<0);
  
  for(i=0;i<N;i++){
    for(j=0;j<N;j++)
      if(mat[i][j]==val)
        cont++;
    if(cont==1)
      printf("Riga %d: %d occorrenza\n", i, cont);
    else
      printf("Riga %d: %d occorrenze\n", i, cont);
    if(cont>2)
      arr[i]=0;
    else
      arr[i]=1;
    cont=0;
  }
  printf("\n");
  
  for(i=0;i<N;i++)
    printf("%3d\n", arr[i]);

  printf("Matrice modificata:\n");
  stampa(mat, N, arr, val);
  
  return 0;
}



void stampa(int m[][N], int dim, int a[], int val){
  int i, j;
  
  for(i=0;i<dim;i++){
    for(j=0;j<dim;j++)
      if(m[i][j]==val&&!a[i])
        printf("  0");
      else
        printf("%3d", m[i][j]);
    printf("\n");
  }
  printf("\n");
  
}

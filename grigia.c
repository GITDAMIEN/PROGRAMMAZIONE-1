/*Si scriva un programma C che permetta all’utente di inizializzare una matrice di interi di dimensione NxN (con N fissato).
Dopo aver stampato la matrice a video, il programma deve richiedere all’utente le coordinate x e y (comprese tra 0 e N1) di un elemento della matrice (rifiutando eventuali valori non validi come coordinate) e stampare la somma degli elementi compresi nel rettangolo avente come angolo inferiore destro l’elemento identificato dalle coordinate x e y. Ad esempio, se N=6 e l’utente inserisce la seguente matrice e come coordinate 2,3 (riga di indice 2 e colonna di indice 3):
 1 3 2 4 7 7
 3 2 1 7 6 6
 1 2 3 4 5 5
 9 8 7 6 5 5
 1 3 2 4 7 7
 3 2 1 7 6 6
Il programma, dopo averla visualizzata a video, stamperà la somma degli elementi contenuti nella parte grigia della matrice (ossia il valore 33). Nel caso l’utente inserisca le coordinate 0,0 la sottomatrice da considerare sarà composta solo dal valore 1. */

#include<stdio.h>
#define N 6

void stampa(int [][N], int);

int main(){
  int m[N][N];
  int i, j, x, y, somma=0;
  
  printf("Inserisci valori matrice:\n");
  for(i=0;i<N;i++)
    for(j=0;j<N;j++)
      scanf("%d", &m[i][j]);
  
  printf("Matrice inserita:\n");
  stampa(m, N);
  
  printf("Inserisci coordinate x e y (comprese tra 0 e %d):\n", N-1);
  do{
    scanf("%d", &x);
  }while(x<0||x>N-1);
  do{
    scanf("%d", &y);
  }while(x<0||x>N-1);
  
  for(i=0;i<N;i++)
    for(j=0;j<N;j++)
      if(i<=x&&i>=0&&j<=y&&j>=0)
        somma+=m[i][j];
  
  printf("Somma dei valori compresi nelle coordinate: %d\n", somma);
  
  return 0;
}


void stampa(int m[][N], int dim){
  int i, j;
  
  for(i=0;i<dim;i++){
    for(j=0;j<dim;j++)
      printf("%3d", m[i][j]);
    printf("\n");
  }
  printf("\n");
  
}






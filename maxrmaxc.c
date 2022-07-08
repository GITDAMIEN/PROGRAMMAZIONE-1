/*Scrivere due sottoprogrammi maxr e maxc che prendono in ingresso una matrice 3X3 di interi e restituiscono rispettivamente al chiamante l’indice della riga/colonna in cui la somma di tutti gli elementi è massima. 
*/

#include<stdio.h>
#define N 3

void stampa(int [][N]);
int maxr(int [][N]);
int maxc(int [][N]);

int main(){
  int mat[N][N];
  int riga, col;
  
  printf("Inserisci matrice: ");
  for(riga=0;riga<N;riga++)
    for(col=0;col<N;col++)
      scanf("%d", &mat[riga][col]);
  
  stampa(mat);
  
  printf("Indice di riga con somma massima: %d\n", maxr(mat));
  printf("Indice di colonna con somma massima: %d\n", maxc(mat));
  
  return 0;
}


void stampa(int m[][N]){
  int i, j;
  
  printf("Matrice:\n");
  for(i=0;i<N;i++){
    for(j=0;j<N;j++)
      printf("%3d", m[i][j]);
    printf("\n");
  }
  printf("\n");
 
}


int maxr(int m[][N]){
  int r, i, j, sumt, sump; //sumt=somma massima, sump=somma parziale
  
  r=0; //indico che la riga con somma massima per ora è la prima
  sumt=0; //e che la somma massima per ora è zero
  
  for(i=0;i<N;i++){
    sump=0;
    for(j=0;j<N;j++)
      sump+=m[i][j];
    if(sump>sumt){
      sumt=sump;
      r=i;
    }
  }
      
      
  return r;
}

int maxc(int m[][N]){
  int c, i, j, sumt, sump; //sumt=somma massima, sump=somma parziale
  
  c=0; //indico che la colonna con somma massima per ora è la prima
  sumt=0; //e che la somma massima per ora è zero
  
  for(i=0;i<N;i++){
    sump=0;
    for(j=0;j<N;j++)
      sump+=m[j][i];
    if(sump>sumt){
      sumt=sump;
      c=i;
    }
  }
      
      
  return c;
}






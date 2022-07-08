/*In un concorso di bruttezza, n giudici esprimono il loro giudizio su m candidati. Il giudizio è un valore numerico tra 0 e 5 (più altro il voto più brutto il candidato). I risultati sono organizzati in una matrice int R[N][M].
Si scriva un programma in linguaggio C per determinare il candidato più brutto ed il giudice più cattivo (ovvero quello che attribuisce i più alti voti di bruttezza).*/

#include<stdio.h>
#define N 3
#define M 6

int main (){
  int R[N][M]={{5,5,5,5,5,5},{1,1,1,1,1,1},{3,3,3,3,3,3}};
  int i, j, somma1=0, somma2=0, cat1=0, cat2=0, brutto=0, cattivo=0;
  
  //determino il candidato più brutto
  for(j=0;j<M;j++){
    for(i=0, somma1=0;i<N;i++)
      somma1=somma1+R[i][j];
    if(somma1>somma2){
      brutto=j;
      somma2=somma1;
    }
  }
  
  //determino il giudice più cattivo
  for(i=0;i<N;i++){
    for(j=0, cat1=0;j<M;j++)
      cat1=cat1+R[i][j];
    if(cat1>cat2){
      cattivo=i;
      cat2=cat1;
    }
  }  
  
  printf("Il candidato più brutto è il numero %d\n", brutto+1);
  printf("Il giudice più cattivo è il numero %d\n", cattivo+1);
    
  return 0;
}
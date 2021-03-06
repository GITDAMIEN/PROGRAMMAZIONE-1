#include<stdio.h>
#include<stdlib.h>
#define N 2
#define M 3

int main(){
  int Matrix[N][M];
  float Filter[M];
  float Result[N]={0};
  int i, j;
  srand(1);
  
  for(i=0;i<N;i++)
    for(j=0;j<M;j++)
      if(i%2==0)
        Matrix[i][j]=rand()%6*2;
      else
        Matrix[i][j]=rand()%5*2+1;
  
  printf("Inserisci i valori di Filter:\n");
  for(i=0;i<M;i++)
    scanf("%f", &Filter[i]);
  
  printf("Matrix:\n");
  for(i=0;i<N;i++){
    for(j=0;j<M;j++)
      printf("%d  ", Matrix[i][j]);
    printf("\n");
    }
  
  printf("\nFilter:\n");
  for(i=0;i<M;i++)
    printf("%.1f  ", Filter[i]);
  printf("\n");
  
  //implemento i valori di Result[N]
  for(i=0;i<N;i++)
    for(j=0;j<M;j++)
      Result[i]=Result[i]+Matrix[i][j]*Filter[j];
    
  //stampo
  printf("\nResult:\n");
  for(i=0;i<N;i++)
    printf("%.1f  ", Result[i]);
  printf("\n");
  
  
  return 0;
}

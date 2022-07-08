#include<stdio.h>
#define D 5

int main (){
  int mat[D][D];
  int i, j, flag=1;
  
  printf("Inserisci i dati della matrice:\n");
  for(i=0;i<D;i++)
    for(j=0;j<D;j++)
      scanf("%d", &mat[i][j]);
  
  for(i=0;i<D&&flag;i++)
    for(j=0;j<i&&flag;j++)
      if(mat[i][j]!=mat[j][i])
        flag=0;

  printf("Questa è la matrice inserita:\n");
  for(i=0;i<D;i++){
    for(j=0;j<D;j++)
      printf("%3d", mat[i][j]);
    printf("\n");
  }
  
  if(flag)
    printf("La matrice è simmetrica.\n");
  else
    printf("La matrice NON è simmetrica.\n");
  
  return 0;
}
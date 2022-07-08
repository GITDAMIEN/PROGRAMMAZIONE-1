#include<stdio.h>
#define D 8

int main(){
  int mat[D][D];
  int i, j, flag=1;
  
  printf("Inserisci i valori della matrice:\n");
  for(i=0;i<D;i++)
    for(j=0;j<D;j++)
      scanf("%d", &mat[i][j]);           //RIVEDERE CODICE//
  
  for(i=0;i<D&&flag;i++)
    for(j=0;j<D&&flag;j++){
      if(i!=j&&mat[i][j]!=0)
        flag=0;
      if(i==j&&mat[i][j]!=1)
        flag=0;
    }
  
  printf("Questa è la matrice inserita:\n");
  for(i=0;i<D;i++){
    for(j=0;j<D;j++)
      printf("%3d", mat[i][j]);
    printf("\n");
  }
  
  if(flag)
    printf("La matrice è identità\n");
  else
    printf("La matrice NON è identità\n");
  
  return 0;
}
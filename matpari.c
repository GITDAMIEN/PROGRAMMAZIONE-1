#include<stdio.h>
#define D 3

int main (){
  int mat[D][D];
  int i, j, flag=1;
  
  //chiedo i valori della matrice
  printf("Inserisci i valori della matrice:\n");
  for(i=0;i<D;i++)
    for(j=0;j<D;j++)
      do{
        scanf("%d", &mat[i][j]);
        if(mat[i][j]<0)
          printf("Inserisci solo valori maggiori o uguali a zero!\n");
      }while(mat[i][j]<0);
  
  //stampo la matrice
  printf("La matrice inserita è:\n");
  for(i=0;i<D;i++){
    for(j=0;j<D;j++)
      printf("%3d", mat[i][j]);
    printf("\n");
  }
  printf("\n");
      
  //verifico se la matrice è composta da soli valori pari
  for(i=0;i<D;i++)
    for(j=0;j<D;j++)
      if(mat[i][j]%2!=0)
        flag=0;
  
  printf("\nMatrice pari? ");
  if(flag)
    printf("1.\n");
  else
    printf("0.\n");
  
  return 0;
}
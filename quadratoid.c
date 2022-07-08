#include<stdio.h>

int main (){
  int a, i, j;
  int mat[a][a];
  
  printf("Inserisci la dimensione del lato del quadrato: ");
  scanf("%d", &a);
  
  printf("\n");
  for(i=0;i<a;i++){
    for(j=0;j<a;j++){
      if(j==i)
        printf(" X");
      else
        printf(" *");
    }
  printf("\n");
  }
  printf("\n");
  
  return 0;
}
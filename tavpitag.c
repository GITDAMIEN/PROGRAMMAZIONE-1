#include<stdio.h>

int main (){
  int j, i;
  
  printf("Ecco la tavola pitagorica:\n");
  for(i=1;i<11;i++){
    for(j=1;j<11;j++)
      printf("%4d", j*i);
    printf("\n");
  }
  printf("\n");
  
  return 0;
}
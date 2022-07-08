#include<stdio.h>
int main (){
  int a, b;
  int i, j;
  
  printf("Inserisci due numeri:\n");
  do{
    scanf("%d", &a);
    if(a<=0)
      printf("Numero non valido, reinserire:\n");
  }while(a<=0);
  
  do{
    scanf("%d", &b);
    if(b<=0)
      printf("Numero non valido, reinserire:\n");
  }while(b<=0);
  
  for(i=a;i>0;i--){
    for(j=b;j>0;j--)
      printf("*");
    printf("\n");
  }
  
  return 0;
}
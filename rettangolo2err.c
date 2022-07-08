#include<stdio.h>
int main (){
  int a, b;
  int i, j, f;
  
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
  
  
  f=1;
  for(j=b;j>0;j--)
    printf("*");
    printf("\n");
  for(i=a-1;i>0;i--){
    for(j=b;j>=f;j--)
      if(j==f||j==a||j==b)
        printf("*");
      else
        printf("x");
    printf("\n");
  }
  for(j=b;j>0;j--)
    printf("*");
    printf("\n");
  
  return 0;
}
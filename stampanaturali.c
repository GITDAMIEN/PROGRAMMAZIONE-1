#include<stdio.h>

int main (){
  int num, i;
  
  do{
    printf("Inserisci un numero intero positivo:\n");
    scanf("%d", &num);
  }while(num<=0);
  
  i=0;
  while(i<=num){
    printf("%3d", i);
    i++;
  }
  printf("\n");
  
  return 0;
}
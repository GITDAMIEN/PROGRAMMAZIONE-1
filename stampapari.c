#include<stdio.h>

int main (){
  int num, i;
  
  do{
    printf("Inserisci un numero intero positivo:\n");
    scanf("%d", &num);
  }while(num<=0);
    
  for(i=0;i<=num;i++){
    if(i%2==0)
      printf("%3d", i);
  }
  printf("\n");
  
  return 0;
}
#include<stdio.h>

int main (){
  int num, i, col;
  
  do{
    printf("Inserisci un numero intero positivo:\n");
    scanf("%d", &num);
  }while(num<=0);
  
  for(i=1;i<=num;i++){
    for(col=1;col<=num;col++){
      printf("%3d", i*col);
    }
    printf("\n");
  }
  return 0;
}
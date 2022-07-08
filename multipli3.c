#include<stdio.h>

int main (){
  int num, i, tot=0;
  
  do{
    printf("Inserisci un numero intero positivo:\n");
    scanf("%d", &num);
  }while(num<=0);
    
  for(i=1;i<=num;i++){
    if(i%3==0)
      tot++;
  }
  printf("Tra 0 e %d ci sono %d multipli di 3.\n", num, tot);
  
  return 0;
}
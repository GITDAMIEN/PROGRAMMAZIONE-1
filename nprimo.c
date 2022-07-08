#include<stdio.h>

int main(){
  int num, cont;
  
  do{
    printf("Inserisci numero maggiore di 0:\n");
    scanf("%d", &num);
    
  }while(num<=0);
  
  cont=num-1;
  while(num%cont!=0&&cont>1)
    cont--;
  
  if(cont>1)
    printf("Numero non primo\n");
  else
    printf("Numero primo\n");
    
  return 0;
  
}
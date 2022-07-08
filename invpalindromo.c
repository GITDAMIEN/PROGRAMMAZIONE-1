#include<stdio.h>

int main (){
  int num, num2, resto;
  
  printf("Inserisci numero:\n");
  scanf("%d", &num);
  
  resto=0;
  num2=num;
  while(num2>0){
    resto=resto*10+num2%10;
    num2=num2/10;
  }
  
  printf("\nIl numero inserito è: %d", num);
  printf("\nIl numero invertito è: %d", resto);
  if(resto==num)
    printf("\nIl numero inserito è palindromo\n");
  else
    printf("\nIl numero inserito NON è palindromo\n");
  
    
  return 0;
}
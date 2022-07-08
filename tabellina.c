#include<stdio.h>

int main (){
  int n, i;
  
  printf("Inserisci numero: ");
  do{
    scanf("%d", &n);
    if(n<=0)
      printf("Numero non valido\n");
  }while(n<=0);
  
  printf("\nEcco la tabellina del %d: ", n);
  for(i=1;i<11;i++)
    printf("%4d", n*i);
  printf("\n");
  
  return 0;
}
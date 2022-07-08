#include<stdio.h>
int main(){
  //dichiarazioni
  int a;
  printf("Inserisci numero intero\n");
  scanf("%d", &a);
  if(a==0)
    printf("\n%d è nullo\n", a);
  else
    if(a>0)
      printf("\n%d è positivo\n", a);
    else
      printf("\n%d è negativo\n", a);
  
  
return 0;
}
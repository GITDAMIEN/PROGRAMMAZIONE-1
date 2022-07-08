#include<stdio.h>

int main (){
  int n, r, q;
  
  printf("Inserisci numero da 2 in sù:\n");
  do{
    scanf("%d", &n);
    if(n<=1)
      printf("Numero non valido");
  }while(n<=1);
  
  q=0;
  r=n;
  while(r>0){
    q=q+r;
    r--;
  }
  
  printf("Il numero trangolare di %d è: %d\n", n, q);
  
  return 0;
}
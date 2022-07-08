#include<stdio.h>

int main (){
  int a, b, num, resto, prodotto=1;
  
  printf("Inserisci 2 numeri: ");
  do{
    scanf("%d", &a);
    if(a<=0)
      printf("\nNumero non valido. Inserisci numero positivo: ");
  }while(a<=0);
  
  do{
    scanf("%d", &b);
    if(b<=0)
      printf("\nNumero non valido. Inserisci numero positivo: ");
  }while(b<=0);
  
  if(a!=b){
    num=a;
    while(num>0){
      resto=num%10;
      prodotto=prodotto*resto;
      num=num/10;
    }
    num=b;
    while(num>0){
      resto=num%10;
      prodotto=prodotto*resto;
      num=num/10;
    }
    if(prodotto==a+b)
      printf("Numeri affiatati.\n");
    else
      printf("Numeri non affiatati.\n");
  }
  else
    printf("Numeri non affiatati.\n");
  
  return 0;
}
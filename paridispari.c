#include<stdio.h>

int main(){
  int num;
  int cont=0, pari=0, dispari=0;
  
  printf("Inserisci 10 numeri interi positivi:\n");
  
  while(cont<10){
      do{
      scanf("%d", &num);
      if(num<=0)
        printf("Valore non valido, inserisci numero positivo\n");
    }while(num<=0);
      if(num%2==0)
        pari++;
      else
        dispari++;
    cont++;
  }
  printf("I numeri pari inseriti sono:%d\n", pari);
  printf("I numeri dispari inseriti sono:%d\n", dispari);
  
  return 0;
}
/*Scrivere un sottoprogramma che riceve due numeri interi positivi e calcola l'elevamento alla potenza del primo rispetto al secondo, resituendo il risultato*/

#include<stdio.h>

int potenza(int, int);

int main(){
  int b, e;
  
  printf("Inserisci base: ");
  scanf("%d", &b);
  printf("Inserisci esponente: ");
  scanf("%d", &e);
  
  printf("%d elevato alla %d, fa: %d\n", b, e, potenza(b, e));
  
  
  return 0;
}

int potenza(int b, int e){
  int res=1;
  
  while(e>0){
    res=res*b;
    e--;
  }
  
  return res;
}
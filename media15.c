#include<stdio.h>

int main(){
  int num, i=0, somma=0;
  float media;
  
  printf("Inserisci 15 valori:\n");
  do{
    scanf("%d", &num);
    somma=somma+num;
    i++;
  }while(i<15);
  
  media=(float)somma/15;
  printf("La media dei numeri è:%.2f", media);
  
  return 0;
}
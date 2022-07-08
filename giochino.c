/*Generare un numero a caso e chiedere all'utente un numero fino a quando non e' uguale a quello generato casualmente. Dire ogni volta se il numero immesso e' > o < di quello iniziale. Per generare un numero a caso invocare la funzione rand(). Ad esempio se r è una variabile intera r = rand(); assegna a r un valore casuale.*/

#include<stdio.h>
#include<stdlib.h>

int main(){
  srand(1);
  int num, r;
  
  r=rand();
  printf("Inserisci numero: ");
  
  do{
    scanf("%d", &num);
    if(num<r)
      printf("Il numero inserito è inferiore a quello da indovinare. Ritenta: ");
    else
      if(num>r)
        printf("Il numero inserito è superiore a quello da indovinare. Ritenta: ");
  }while(num!=r);
  
  
  printf("Complimenti, hai indovinato!! :)\n");
  
  return 0;
}
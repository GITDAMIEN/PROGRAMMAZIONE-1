#include<stdio.h>
#define D 10

int main (){
  int x, i, arr[D], somma=0, prodotto=1;
  
  //chiedo un indice x
  printf("Inserisci numero tra 0 e 9: ");
  do{
    scanf("%d", &x);
    if(x<0||x>9)
      printf("\nNumero non valido. Inserisci numero tra 0 e 9:");
  }while(x<0||x>9);
  
  //chiedo 10 valori interi e li salvo nell'array
  printf("\nInserisci 10 numeri interi: ");
  for(i=0;i<D;i++)
    do{
      scanf("%d", &arr[i]);
      if(arr[i]<0)
        printf("\nNumero non valido. Inserisci numero intero:");
    }while(arr[i]<0);
  
  //faccio la somma di tutti i numeri in posizioni minori di x
  for(i=0;i<x;i++)
    somma=somma+arr[i];
  
  //faccio il prodotto di tutti i numeri in posizioni maggiori di x
  for(i=x+1;i<D;i++)
    prodotto=prodotto*arr[i];
  
  //stampo la somma e il prodotto
  printf("La somma dei numeri in posizioni minori di %d è: %d\n", x, somma);
  printf("Il prodotto dei numeri in posizioni maggiori di %d è: %d\n", x, prodotto);
  
  
  return 0;
}
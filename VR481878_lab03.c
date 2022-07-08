#include<stdio.h>
#define D 5 //definisco a 5 la dimensione della costante D

int main (){
  int arr[D]; //dichiaro l'array di dimensione D
  int i, j, max; //dichiaro 2 indici i e j e una variabile max in cui inserisco il valore massimo dell'array
  
  //chiedo all'utente di inserire i valori
  printf("Inserisci 5 valori interi non negativi:\n");
    
  //lettura valori array con controllo di validità, segnalato all'utente in caso di valore non valido
  for(i=0;i<D;i++)
    do{
      scanf("%d", &arr[i]);
      if(arr[i]<0){
        printf("Errore: hai inserito un valore negativo. Fine del programma.\n");
        return 0;
      }
    }while(arr[i]<0);
  
  max=arr[0]; //definisco il primo valore dell'array come il massimo trovato finora e lo sostituisco se ne trovo uno maggiore nell'array
  for(i=0;i<D;i++)
    if(arr[i]>max)
      max=arr[i];
  
  printf("\nEcco l'istogramma richiesto:\n\n");
  
  //stampa istogramma verticale
  for(i=max;i>0;i--){
    for(j=0;j<D;j++)
      if(arr[j]>=i)
        printf(" *");
      else
        printf("  ");
    printf("\n");
  }
  
  //stampa dei numeri inseriti alla base dell'istogramma
  for(i=0;i<D;i++)
    printf("%2d", arr[i]);
  printf("\n");  
  
  return 0;
}
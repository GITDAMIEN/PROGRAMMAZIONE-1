/*Scrivere una funzione che riceve come parametri un array di interi e due indici i,j,
la funzione restituisce al chiamante il valor medio degli elementi dell’array in posizione i e j.*/


#include<stdio.h>
#define D 10

float media(int [], int, int);

int main(){
  int arr[D];
  int i, j;
  
  printf("Inserisci valori dell'array: ");
  for(i=0;i<D;i++)
    scanf("%d", &arr[i]);
  
  printf("Inserisci indice i: ");
  scanf("%d", &i);
  printf("Inserisci indice j: ");
  scanf("%d", &j);
  
  printf("La media tra i valori degli elementi tra la posizione di indice %d e %d è: %.2f\n", i, j, media(arr,i,j));
  
  
  return 0;
}



float media(int arr[D], int i, int j){
  int x, somma=0, tot=0;
  float med;
  
  if(i<j)
    for(x=i;x<=j;x++){
      somma+=arr[x];
      tot++;
    }
  
  else
    for(x=j;x<=i;x++){
      somma+=arr[x];
      tot++;
    }
  
  med=(float)somma/tot;
  
  return med;
}











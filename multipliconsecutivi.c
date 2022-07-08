/*Dato un array di N interi, scrivere l’algoritmo e il frammento di programma C per chiedere all’utente l’inserimento di un numero intero x e un numero y compreso tra 0 e N, e verificare se nell’array vi sono y multipli di x consecutivi. Stampare un opportuno messaggio a video che indica dove sono stati trovati i primi y multipli di x (a partire da quale posizione). Se tali multipli non esistono nell’array stampare a video un opportuno messaggio.*/

#include<stdio.h>
#define N 5

int main (){
  int arr[N]={8,8,9,18,27};
  int x, y, index, cont=0, posizione, flag=0;
  
  printf("Inserisci valore x: ");
  scanf("%d", &x);
  printf("Inserisci valore y (compreso tra 0 e %d): ", N);
  do{
    scanf("%d", &y);
    if(y<0||y>N)
      printf("Y dev'essere compreso tra 0 e %d", N);
  }while(y<0||y>N);
  
  for(index=0;index<N&&!flag;index++){
    while(arr[index]==x*(cont+2)){
      cont++;
      if(cont==1)
        posizione=index;
      index++;
    }
    if(cont>=y){
      printf("Nell'array ci sono %d multipli di %d consecutivi.\n", y, x);
      printf("I multipli consecutivi iniziano dalla posizione %d.\n", posizione);
      flag=1;
    }
    /*stampa di test:
    printf("Cont: %d\n", cont);
    */
    cont=0;
  }
  
  /*stampa di test
  printf("Posizione: %d\n", posizione);
  */
  
  if(!flag)
    printf("Nell'array NON ci sono %d multipli di %d consecutivi.\n", y, x);
  
  return 0;
}
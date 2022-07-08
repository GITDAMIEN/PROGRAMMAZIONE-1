/* troviamo il piu' grande di un insieme di numeri (e chiedo all'utente quanti ne vuole inserire) */

#include<stdio.h>

int main(){
  int quanti, num, max, i;
  
  printf("Quanti numeri vuoi inserire?(Inserisci un valore >=1) ");
  scanf("%d",&quanti);
  while(quanti<1){
    printf("\n Ti avevo detto maggiore di 1");
    scanf("%d",&quanti);
  }
    // quanti contiene un valore >=1
  printf("Inserisci i tuoi valori: ");
  i=1;
  scanf("%d",&num);
  max=num; //leggo il primo numero e lo ricordo
  while(i<quanti){
    scanf("%d",&num);
    i++;
    if(num>max)
      max=num; /*aggiorno max se il nuovo valore inserito è piu' grande di quello che stavo ricordando */
  }
  printf("\n Il piu' grande valore e': %5d\n ",max);
  
}
/*Scrivete un programma che legga un carattere, uno spazio e quindi una sequenza di caratteri minuscoli terminati da . e che stampi quanto ha letto dopo il primo spazio, ma sostituendo tutte le vocali minuscole con il primo carattere letto (la stampa avverrà dopo ogni carattere letto). Per farlo, definite una funzione cambia che, dati due caratteri, restituisca il primo carattere se il secondo è una vocale minuscola, altrimenti restituisca il secondo carattere.*/

#include<stdio.h>

char cambia(char, char);

int main(){
  char car1, car2, res, trash;
  
  printf("Inserisci un sequenza di caratteri, di cui il primo separato da uno spazio: ");
  scanf("%c%c", &car1, &trash);
  scanf("%c%c", &car2, &trash);
  while(car2!='.'){
    res=cambia(car1, car2);
    printf("Esito: %c", res);
    printf("\nProssimo carattere: ");
    scanf("%c%c", &car2, &trash);
  }
  
  return 0;
}

char cambia(char car1, char car2){
  char res;
  
  if(car2=='a'||car2=='e'||car2=='i'||car2=='o'||car2=='u')
    res=car1;
  else
    res=car2;
    
  return res;
}
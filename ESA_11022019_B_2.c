/*Un numero `e detto “divibile dispari destro” se il numero stesso e tutti i numeri ottenuti rimuovendo successivamente la cifra pi`u a destra ammettono almeno un divisore dispari diverso da 1. Scrivere nel file ESA 11022019 B 2.c il sottoprogramma int rightodd(int val) che ricevuto in ingresso un intero val sicuramente positivo restituisce 1 se il numero `e divisibile dispari destro, 0 altrimenti. Ad esempio, se al sottoprogramma viene passato in ingresso il numero 65 esso restituir`a 1, infatti 65 ha 5 come divisore dispari e 6 ha 3 come divisore dispari.
*/


#include<stdio.h>

int rightodd(int val);

int main(){
  int val;
  
  printf("Inserisci valore positivo: ");
  do{
    scanf("%d", &val);
    if(val<=0)
      printf("Valore non valido. Inserisci valore positivo: ");
  }while(val<=0);
  
  printf("\nEsito: %d\n", rightodd(val));
  
  return 0;
}


int rightodd(int val){
  int i, flag, tot=0, totp=0;
  
  while(val>0){
    tot++;
    for(i=3, flag=0;i<val&&!flag;i+=2)
      if(val%i==0)
        flag=1;
    if(flag)
      totp++;
    val/=10;
  }
  
  printf("\n%d,%d\n", tot, totp);
  
  if(totp==tot)
    return 1;
  else
    return 0;
}
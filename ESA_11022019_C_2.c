/*Scrivere nel file ESA 11022019 C 2.c il sottoprogramma int cifra(int val) che ricevuto in ingresso un valore intero sicuramente positivo restituisce il numero intero ottenuto cifrando ogni cifra di val mediante sostituzione con la cifra successiva (la cifra 9 verr`a cifrata con uno 0). Ad esempio, se al sottoprogramma viene passato in ingresso il numero 135 restituir`a il numero 246, se viene passato il numero 49 restituir`a il numero 50.
*/

#include<stdio.h>

int cifra(int val);

int main (){
  int v;
  
  printf("Inserisci valore intero positivo: ");
  do{
    scanf("%d", &v);
    if(v<=0)
      printf("Valore errato. Inserisci valore intero positivo: ");
  }while(v<=0);
  
  printf("\nRisultato: %d.\n", cifra(v));
  
  return 0;
}


int cifra (int val){
  int r=0, resto, x=1;
  
  while(val>0){
    resto=val%10;
    if(resto>=0&&resto<9)
      resto++;
    else if(resto==9)
      resto=0;
    val/=10;
    r=resto*x+r;
    x*=10;
  }
  
  return r;
}













#include<stdio.h>
int main (){
  //Dichiarazione
  int voto, somma, media, max, min, quanti;
  
  //chiedo di inserire i voti
  printf("Inserisci voti da 18 a 30\n");
  scanf("%d", &voto);
  
  //definisco i valori di partenza delle mie variabili
  quanti=0;
  somma=0;
  max=0;
  min=31;
  
  //controllo che il voto sia all'interno del campo di esistenza corretto
  if(voto>=18&&voto<=30){
    while(voto>=18&&voto<=30){
      if(voto>max) //se il voto inserito è maggiore dell'attuale massimo, aggiorno il massimo
        max=voto;
      if(voto<min) //se il voto inserito è minore dell'attuale minimo, aggiorno il minimo
        min=voto;
      quanti++; //incremento di 1 il contatore dei voti inseriti
      somma=somma+voto; //aggiorno la somma dei voti inseriti
      scanf("%d", &voto); //chiedo nuovo numero
      
    }
    media=somma/quanti; //calcolo la media dei voti inseriti
    
    //stampe
    printf("Hai inserito %d voti validi\n", quanti);
    printf("Il voto minimo inserito è: %d\n", min);
    printf("Il voto massimo inserito è: %d\n", max);
    printf("La media dei voti inseriti è: %d\n", media);
  }
  
  else //altrimenti restituisco messaggio di errore
    printf("Valore non corretto\n");
  //fine del programma
}

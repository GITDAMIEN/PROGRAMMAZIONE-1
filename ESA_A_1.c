#include<stdio.h>

/* prototipi */
int valido(int, int, int, int *, int);

int main() {
  int cifre[]={5, 0, 2};
  int num,min,max,r;
  
  printf("\n Inserisci un intero positivo: ");
  do{
	  scanf("%d",&num);
  }while(num<=0);
  
  printf("\n Inserisci il numero minimo di cifre: ");
  do{
	  scanf("%d",&min);
  }while(min<=0);
  
  printf("\n Inserisci il numero massimo di cifre: ");
  do{
	  scanf("%d",&max);
  }while(max<min);
  
  r=valido(num,min,max,cifre,3);
  printf("\n Esito funzione: %d",r);
  
  return (0);
}


int valido(int num, int min, int max, int speciali[], int dim){
  int indice; //indice per scorrere l'array
  int cifra; //variabile in cui salvo cifra per cifra per confrontarla con l'array
  int cont=0; //contatore per contare il numero di cifre
  int vero=0; //variabile che mi conteggia quante condizioni sono soddisfatte
  int flag=0; //flag che metto ad 1 se almeno una volta trovo in num una delle cifre contenute nell'array
  
  while(num>0){ //ciclo while fintantoché num è maggiore di 0
    cifra=num%10; //salvo su cifra la cifra più a destra di num
    for(indice=0;indice<dim;indice++) //scorro l'array
      if(cifra==speciali[indice]) //verifico se la cifra che sto analizzando è uguale ad uno dei valori dell'array
        flag=1; //in tal caso, metto il flag ad 1
    cont++; //incremento il contatore delle cifre
    num/=10; //elimino la cifra più a destra di num
  }
  
  if(cont>=min) //verifico la prima condizione (numero minimo di cifre)
    vero++; //se vera, incremento il contatore delle condizioni vere
  if(cont<=max) // verifico la seconda condizione (numero massimo di cifre)
    vero++; //se vera, incremento il contatore delle condizioni vere
  if(flag) // verifico la terza condizione (almeno una cifra uguale ad una di quelle dell'array)
    vero++; // se vera, incremento il contatore delle condizioni vere
  
  if(vero==3) //se ho tutte 3 le condizioni soddisfatte
    return 1; //restituisco 1 al main
  else //altrimenti
    return 0; //restituisco 0
	
}













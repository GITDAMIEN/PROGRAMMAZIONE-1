/* Scrivere la funzione listaFattori che, 
ricevendo un parametro intero positivo val, restituisca
al chiamante una lista di interi che contenga, disposti in ordine crescente, 
tutti i numeri interi x divisori di val (se il numero val è primo la lista deve essere vuota).
Per esempio, ricevendo come parametro il numero 30, la funzione restituisce la lista che contiene,
nell’ordine, i valori 2, 3, 5, 6, 10, 15.
*/
#include <stdio.h>
#include <stdlib.h>

//definizione della struttura per la lista concatenata
typedef struct elem_{
  int num;
  struct elem_ *next;
} elem;

elem* inserisciInTesta(elem*, int);
elem* listaFattori(int);
void visualizza(elem*);

int main(int argc, char* argv[]){
int num;
elem *lista;

do{
	scanf("%d",&num);
}while(num<=0);

lista=listaFattori(num);
visualizza(lista);

return(0);

}

elem* listaFattori (int val)


elem* inserisciInTesta(elem* lista, int num){
  
  
  
}

void visualizza(elem* lista){
  
}

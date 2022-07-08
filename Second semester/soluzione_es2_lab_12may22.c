/* Si scriva una funzione C che ricevendo in ingresso un puntatore alla lista modifichi la stessa, memorizzando nell’ultimo nodo il prodotto del penultimo ed ultimo nodo, nel penultimo il prodotto del terzultimo e del penultimo e così via. Il primo nodo non deve essere modificato (perché non ha un precedente). 
Ad esempio, una lista contenente la sequenza di interi 
4 6 2 3 9 verrà modificata dalla funzione nella lista 
4 24 12 6 27. 

  */

#include <stdio.h>
#include <stdlib.h>

/*definizione della struttura per la lista concatenata*/

struct nodo{ 
		int valore; 
		struct nodo *next; 
	}; 

typedef struct nodo elem;

elem* inserisciInCoda(elem*, int);
void visualizza(elem*);
void prodottonodi(elem*); //la lista 


int main( ){
  int val;
  elem* listav=NULL; 
  
  do
  {
	scanf("%d", &val);
    if(val!=-1)
    listav=inserisciInCoda(listav, val);
  }while(val!=-1);
  
  visualizza(listav);
  prodottonodi(listav);
  
  visualizza(listav);
  

  return 0;
}



/*inserisce un nuovo numero in coda alla lista*/
elem* inserisciInCoda(elem* lista, int num){
  elem *prec;
  elem *tmp;

  tmp = (elem*) malloc(sizeof(elem));
  if(tmp != NULL){
    tmp->next = NULL;
    tmp->valore = num;
    if(lista == NULL)
      lista = tmp;
    else{
      /*raggiungi il termine della lista*/
      for(prec=lista;prec->next!=NULL;prec=prec->next);
      prec->next = tmp;
    }
  } else
      printf("Memoria esaurita!\n");
  return lista;
}

void visualizza(elem* lista){
  while(lista != NULL){
    printf("%d ", lista->valore);
    lista = lista->next;
  }
  printf("\n");  
}


void prodottonodi(elem* lista){
	int prod,precvalue,currvalue;
	elem *current, *prec;
	
	
	prec=lista;
	precvalue=prec->valore;
	while(prec->next!=NULL)
	{	
		current=prec->next;	
		currvalue=current->valore;
		current->valore*=precvalue;
		precvalue=currvalue;
		prec=current;
	}
    
}

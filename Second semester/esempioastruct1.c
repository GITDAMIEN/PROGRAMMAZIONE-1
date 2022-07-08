/* Scrivere un programma C in grado di:
1.	Acquisire in ingresso dall'utente i valori di un vettore vet di 10 elementi.
2.	Stampare gli elementi del vettore. 
3.	Determinare il valore massimo e minimo e la relativa posizione (salvando le informazioni in 2 struct).
4.  Ordinare il vettore.
4.  Stampare il vettore ordinato.
*/
# include <stdio.h>
# define MAXDIM 10

int main()
{ typedef struct{
          int val;
          int pos;
          }info;
  int vet[MAXDIM];
  info min,max;
  int i,j;
  int scambio;
  char scelta;
  char invio;

  printf("Inserisci 10 interi \n");
  for(i=0;i<MAXDIM;i++){
    printf("\n Inserisci il numero da memorizzare nella cella %d:",i);
    scanf("%d",&vet[i]);
  }
  
  printf("\nI valori inseriti sono: \n");
  for(i=0; i<MAXDIM; i++)
     		printf("%4d",vet[i]);

  min.val=vet[0];
  min.pos=0;
  max.val=vet[0];
  max.pos=0;
  for(i=1; i < MAXDIM; i++)
  {         if(vet[i]<min.val){
              min.val=vet[i];
              min.pos=i;
           }
           if(vet[i]>max.val){
              max.val=vet[i];
              max.pos=i;
           }
   }
   printf("\n Il massimo e' %d in posizione %d",max.val,max.pos);
   printf("\n Il minimo e' %d in posizione %d",min.val,min.pos);
  
   for(i=0; i < MAXDIM-1; i++)
   for(j=0; j < MAXDIM-1; j++)
    if(vet[j]>vet[j+1])
     { 
      /* Scambia il contenuto dei due elementi */
      scambio=vet[j];
      vet[j]=vet[j+1];
      vet[j+1]=scambio;    
     }
  printf("\nI valori ordinati sono: \n");
  for(i=0; i<MAXDIM; i++)
     		printf("%4d",vet[i]);
  
          
	printf("\nVuoi uscire? ");
	scanf("%c",&scelta);
	scanf("%c",&invio);

}

  
  
  









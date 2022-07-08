/* Scrivere un programma che svolge le seguenti operazioni:
     Acquisisce informazioni relative a 5 atleti.
     Ogni atleta e' caratterizzato da nome, cognome, peso e altezza. 

     Terminata la fase di acquisizione, calcola l'altezza media e stampa
     le informazioni degli atleti con altezza superiore alla media.

*/

#include <stdio.h>
#define MAX 5

int main()
{ typedef struct{
  char nome[10];
  char cognome[20];
  int peso;
  int altezza;
  }info_atleta;
  info_atleta a[MAX]; 
  int i;
  int somma=0;
  float media;
  char scelta;
  char invio;

  /* acquisizione dati */
  printf("Inserisci le informazioni di 5 atleti\n"); 
  for(i=0;i<MAX;i++)
    {
      printf("Nome: ");
      scanf("%s", a[i].nome);
      printf("Cognome: ");
      scanf("%s", a[i].cognome);
      printf("Peso: ");
      scanf("%d", &a[i].peso);
      printf("Altezza: ");
      scanf("%d", &a[i].altezza);
     }
      
  /* calcolo altezza media */

  for (i=0; i<MAX; i++)
     somma+=a[i].altezza; 
  media=(float)somma/MAX;
  
  printf("\n L'altezza media e' %f \n", media);
  
  for(i=0;i<MAX;i++)
     if(a[i].altezza>media){
         printf("Nome: %s\n",a[i].nome);
         printf("Cognome: %s\n",a[i].cognome);
         printf("Altezza: %d\n",a[i].altezza);

      }
          
	printf("\nVuoi uscire? ");
	scanf("%c",&scelta);
	scanf("%c",&invio);

}

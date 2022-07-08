/*sottoprogramma che calcola area e perimetro di un cerchio di raggio dato.
Il sottoprogramma riceve un numero in virgola mobile che rappresenta il raggio del cerchio e altri due parametri sempre in virgola mobile in cui verranno salvati i due risultati richiesti.
Scrivere un programma che chiede all'utente la lunghezza del raggio del cerchio, calcola mediante la funzione sopra e visualizza il perimetro e l'area del cerchio.
In seguito il programma chiede all'utente se vuole continuare o meno (0 per continuare, qualsiasi altro valore per terminare).*/

#include <stdio.h>
#define pi 3.14

void cerchio(float, float *, float*);

void main(){
	float raggio, area, perimetro;
	int continua=0;
	
	do{
		printf("Inserisci raggio del cerchio: ");
		scanf("%f", &raggio);
		
		cerchio(raggio, &area, &perimetro);
		
		printf("Area: %.2f\nPerimetro: %.2f", area, perimetro);
		
		printf("\nVuoi continuare? (0=s�, altro tasto=no)\n");
		scanf("%d", &continua);
	}while(!continua);
	
	printf("Programma terminato.\n");
	
}

void cerchio (float r, float *a, float *p){
	*a=r*r*pi;
	*p=2*pi*r;
}

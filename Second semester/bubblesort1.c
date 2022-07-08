/* BUBBLE SORT */
#include <stdio.h>
#define N 7

/* prototipo */
void bubble_sort (int vet[], int);

int main ()
{
	int i;
 	int a[N];
	printf ("Scrivi %d numeri interi\n", N);
 	for (i = 0; i < N; i++)
 	  scanf ("%d", &a[i]); 
 	
	bubble_sort(a,N);
 	printf("Il vettore ordinato è: \n ");
 	for (i = 0; i<N; i++)
 	   printf(" %3d",a[i]); 
	printf("\n");
}

/* ordinamento crescente: maggiore all'ultimo posto, poi diminuisco la dim di 1 e continuo a confrontare coppie adiacenti. Ad ogni iterazione
il piu' grande in fondo e quindi non serve controllare la coda dell'array.  */
void bubble_sort (int v[],int dim)
{
	int i;
	int ordinato = 0; /* suppongo non sia ordianto */
	int temp;
	/* La dimensione dell’array cala di 1 a ogni iterazione */
	while (dim>1 && !ordinato) {
		ordinato = 1; /* dico che e' gia' ordinato, verifico */
		for (i=0; i<dim-1; i++)
		     if (v[i]>v[i+1]) {
				 temp=v[i];
				 v[i]=v[i+1];
				 v[i+1]=temp;	
				 ordinato = 0; /* ho fatto uno scambio, ricontrolla */
			 }
		
		dim--; /* la dimensione cala, sto ottimizzando. Ad ogni iterazione, in coda all'array ho l'ordine corretto */
	} 
}


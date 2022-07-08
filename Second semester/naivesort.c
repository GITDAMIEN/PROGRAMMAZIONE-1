/* NAIVE SORT */
#include <stdio.h>
#define N 7

/* prototipo */
void naive_sort (int vet[], int);
int trovaPosMax(int v[], int);

int main ()
{
	int i;
 	int a[N];
	printf ("Scrivi %d numeri interi\n", N);
 	for (i = 0; i < N; i++)
 	  scanf ("%d", &a[i]); 
 	
	naive_sort(a,N);
 	printf("Il vettore ordinato è: \n ");
 	for (i = 0; i<N; i++)
 	   printf(" %3d",a[i]); 
	printf("\n");
}

/* ordinamento crescente: maggiore all'ultimo posto, poi diminuisco la dim di 1 e continuo a spostare il piu' grande in fondo */
void naive_sort (int v[],int dim)
{
	int p;
	int temp;
	/* La dimensione dell’array cala di 1 a ogni iterazione */
	while (dim>1) {
		p = trovaPosMax(v,dim);
		if (p<dim-1) {
		    temp=v[p];
			v[p]=v[dim-1];
			v[dim-1]=temp;
		}
		
		dim--;
	} 
}

int trovaPosMax(int v[], int n)
{
	int i, posMax=0;
    for (i=1; i<n; i++)
    	if (v[posMax]<v[i]) 
			posMax=i;
	return posMax;
}